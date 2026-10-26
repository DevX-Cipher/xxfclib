/* SPDX-License-Identifier: MIT
 * An explicitly typed final text field may occupy the remainder of an entry.
 * Existing fixed-size fields retain their original validation. No public ABI. */
int64_t sx_variable_field_limit(const wchar_t *type)
{
    if (!type) return 0;
    if (!xx_rt_wcsncmp(type,L"stuffitx_p2_",12) && type[12]>=L'0' && type[12]<=L'7' && !type[13]) return 17;
    if (!xx_rt_wcscmp(type,L"char") || !xx_rt_wcscmp(type,L"utf8") || !xx_rt_wcscmp(type,L"bias33_char")) return 4096;
    if (!xx_rt_wcscmp(type,L"ascii_signed") || !xx_rt_wcscmp(type,L"ascii_real") || !xx_rt_wcscmp(type,L"ascii_fortran_real")) return 128;
    if (!xx_rt_wcscmp(type,L"ascii_nastran_real")) return 128;
    if (!xx_rt_wcscmp(type,L"ascii_hex")) return 24;
    if (!xx_rt_wcscmp(type,L"uint8") || !xx_rt_wcscmp(type,L"uint16")) return 4096;
    if (!xx_rt_wcscmp(type,L"ascii_decimal")) return 24;
    return 0;
}
static bool sx_expand_field(const sx_layout *layout, size_t index, int64_t entry_size,
                            xx_data_struct_field_desc *out, wchar_t type[64])
{
    if (!layout || !layout->fields || index>=layout->field_count || !out || !type || entry_size<=0) return false;
    const xx_data_struct_field_desc *field=&layout->fields[index];
    if (!field->name || !*field->name || !field->type || !*field->type || field->rel_offset<0 || field->rel_offset>=entry_size || field->size<0) return false;
    *out=*field;
    if (field->size) return field->size<=entry_size-field->rel_offset;
    int64_t limit=sx_variable_field_limit(field->type), size=entry_size-field->rel_offset;
    if (!limit || index+1!=layout->field_count || size>limit) return false;
    for (size_t i=0;i<index;i++) {
        const xx_data_struct_field_desc *prior=&layout->fields[i];
        if (prior->rel_offset<0 || prior->size<=0 || prior->rel_offset>field->rel_offset || prior->size>field->rel_offset-prior->rel_offset) return false;
    }
    int64_t elements=size;
    if (!xx_rt_wcscmp(field->type,L"uint16")) {
        if (size&1) return false;
        elements=size/2;
    }
    char digits[24];int count=xx_rt_snprintf(digits,sizeof(digits),"[%lld]",(long long)elements);
    size_t length=xx_rt_wcslen(field->type);
    if (count<=0 || count>=(int)sizeof(digits) || length+(size_t)count>=64) return false;
    for(size_t i=0;i<length;i++)type[i]=field->type[i];
    for(int i=0;i<=count;i++)type[length+(size_t)i]=(unsigned char)digits[i];
    out->type=type;out->size=size;return true;
}
