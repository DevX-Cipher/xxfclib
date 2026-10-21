# Reusable command history

`xx_history` is a UI-independent undo/redo algorithm for reversible commands.
Its public API is in `include/xxfclib/history/xx_history.h`. A command provides
undo and redo callbacks, an owned payload, an optional disposer and a label.
An editor can retain changed bytes in that payload; another application can
retain object properties or other information needed to reverse its change.
The history does not interpret the payload or retain the replay context.

The algorithm keeps commands in a doubly linked list, with a cursor at the last
applied command. Undo calls that command's undo callback and moves the cursor
back on success. Redo calls the next command's redo callback and moves the cursor
forward on success. A failed replay preserves the cursor and both counts; its
callback must leave external state unchanged, typically through its own rollback.
Single-command navigation takes constant time. Committing after undo discards
the redo branch. An optional entry limit evicts the oldest commands; zero means
unlimited. Commands are disposed exactly once when discarded, aborted, cleared,
evicted or destroyed. Payload size and storage policy remain the caller's choice.

## Reserve before changing data

1. Fill an `xx_history_command` with two replay callbacks and an owned payload.
2. Call `xx_history_prepare(history, &command, &entry)`. It allocates the node and
   copies the label. Failure leaves payload ownership with the caller. Success
   transfers it to the history, while leaving the redo branch untouched.
3. Apply the initial change. If it fails, restore any partial external change
   and call `xx_history_abort(history, entry)` to release the prepared payload.
4. On success call `xx_history_commit(history, entry)`. Commit allocates nothing,
   publishes the command and releases the old redo branch. This ensures an
   allocation failure cannot occur after a successful mutation.

`xx_history_push_applied` is a prepare/commit convenience for callers that have
already applied a command and can handle failure to allocate its history entry.
Neither prepare nor commit invokes undo or redo. A successful commit or abort
consumes the entry handle. Only the exact pending entry from the same history
is accepted. While one entry is pending, another prepare, clear, undo or redo
returns `XX_HISTORY_BUSY`. Destroying an idle history also aborts its pending entry.

Replay callbacks receive the context passed to `xx_history_undo` or
`xx_history_redo`; it can carry a current document, progress/cancellation state
or application-specific error details. A nonzero callback result maps to
`XX_HISTORY_APPLY_FAILED`; the context can preserve a more specific error.

## Lifetime and synchronization

The library calls a command's disposer once and never uses its payload afterward.
It copies a non-NULL label, so the original label can be released immediately
after prepare succeeds. Returned labels are borrowed until the next successful
history mutation or destruction. A NULL label remains NULL. Committed counts
exclude a pending entry. `can_undo` and `can_redo` are false during preparation
and callback execution, while counts and labels describe the committed list.

`xx_history_undo_command` and `xx_history_redo_command` borrow the next command
for inspection. An editor can check command-specific permissions without
encoding behavior into its label. These queries return NULL while busy or
pending. The command and payload stay owned by the history and remain valid
only until its next successful mutation or destruction. Replay through the
history API so the cursor continues to match the external state.

The caller serializes all access. There are no platform or thread dependencies.
Mutating operations invoked reentrantly from replay callbacks or disposers return
`XX_HISTORY_BUSY`. Reentrant destroy of that same active history is a no-op;
callbacks must not attempt to destroy it. These guards also cover cleanup while
discarding a redo branch or evicting entries. Use separate histories per document,
and clear or replace a document's history when its external state is replaced.

`xxhistory.cmake` provides the source and include paths for standalone consumers.
The implementation uses the shared `xx_mem_*` and `xx_rt_*` primitives, making it
usable with xxfclib's minimal runtime profiles. Focused tests, including allocation
failure and reentrancy, are in `tests/history`.
