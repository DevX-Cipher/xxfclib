/* ECMA-335 II.22/II.24 and dotnet/runtime PortablePdb-Metadata.md.
 * Internal declarative schema shared by the bounded row decoder. */
enum md_code { MC_RESOLUTION, MC_TYPE, MC_MEMBER, MC_CONSTANT, MC_ATTRIBUTE,
    MC_ATTRIBUTE_TYPE, MC_MARSHAL, MC_SECURITY, MC_SEMANTICS, MC_METHOD,
    MC_FORWARDED, MC_IMPLEMENTATION, MC_OWNER, MC_DEBUG };
enum md_blob { MB_RAW, MB_METHOD, MB_FIELD, MB_PROPERTY, MB_LOCAL,
    MB_TYPE, MB_INSTANTIATION, MB_CONSTANT, MB_ATTRIBUTE };
typedef struct md_field { const char *name; xx_dotnet_metadata_kind kind; unsigned arg, width; } md_field;
typedef struct md_schema { const char *name; unsigned count; md_field fields[9]; } md_schema;
#define U16(n) {n,XX_DOTNET_METADATA_INTEGER,0,2}
#define U32(n) {n,XX_DOTNET_METADATA_INTEGER,0,4}
#define F16(n) {n,XX_DOTNET_METADATA_FLAGS,0,2}
#define F32(n) {n,XX_DOTNET_METADATA_FLAGS,0,4}
#define S(n) {n,XX_DOTNET_METADATA_STRING,0,0}
#define G(n) {n,XX_DOTNET_METADATA_GUID,0,0}
#define B(n,a) {n,XX_DOTNET_METADATA_BLOB,MB_##a,0}
#define T(n,t) {n,XX_DOTNET_METADATA_TABLE,XX_DOTNET_MDT_##t,0}
#define L(n,t,p) {n,XX_DOTNET_METADATA_LIST,XX_DOTNET_MDT_##t|(XX_DOTNET_MDT_##p<<8),0}
#define C(n,c) {n,XX_DOTNET_METADATA_CODED,MC_##c,0}
#define TOK(n) {n,XX_DOTNET_METADATA_TOKEN,0,4}
static const md_schema md_schemas[64] = {
    [0x00]={"Module",5,{U16("Generation"),S("Name"),G("Mvid"),G("EncId"),G("EncBaseId")}},
    [0x01]={"TypeRef",3,{C("ResolutionScope",RESOLUTION),S("TypeName"),S("TypeNamespace")}},
    [0x02]={"TypeDef",6,{F32("Flags"),S("TypeName"),S("TypeNamespace"),C("Extends",TYPE),L("FieldList",Field,FieldPtr),L("MethodList",MethodDef,MethodPtr)}},
    [0x03]={"FieldPtr",1,{T("Field",Field)}},
    [0x04]={"Field",3,{F16("Flags"),S("Name"),B("Signature",FIELD)}},
    [0x05]={"MethodPtr",1,{T("Method",MethodDef)}},
    [0x06]={"MethodDef",6,{U32("RVA"),F16("ImplFlags"),F16("Flags"),S("Name"),B("Signature",METHOD),L("ParamList",Param,ParamPtr)}},
    [0x07]={"ParamPtr",1,{T("Param",Param)}},
    [0x08]={"Param",3,{F16("Flags"),U16("Sequence"),S("Name")}},
    [0x09]={"InterfaceImpl",2,{T("Class",TypeDef),C("Interface",TYPE)}},
    [0x0a]={"MemberRef",3,{C("Class",MEMBER),S("Name"),B("Signature",METHOD)}},
    [0x0b]={"Constant",3,{U16("Type"),C("Parent",CONSTANT),B("Value",CONSTANT)}},
    [0x0c]={"CustomAttribute",3,{C("Parent",ATTRIBUTE),C("Type",ATTRIBUTE_TYPE),B("Value",ATTRIBUTE)}},
    [0x0d]={"FieldMarshal",2,{C("Parent",MARSHAL),B("NativeType",RAW)}},
    [0x0e]={"DeclSecurity",3,{U16("Action"),C("Parent",SECURITY),B("PermissionSet",RAW)}},
    [0x0f]={"ClassLayout",3,{U16("PackingSize"),U32("ClassSize"),T("Parent",TypeDef)}},
    [0x10]={"FieldLayout",2,{U32("Offset"),T("Field",Field)}},
    [0x11]={"StandAloneSig",1,{B("Signature",LOCAL)}},
    [0x12]={"EventMap",2,{T("Parent",TypeDef),L("EventList",Event,EventPtr)}},
    [0x13]={"EventPtr",1,{T("Event",Event)}},
    [0x14]={"Event",3,{F16("EventFlags"),S("Name"),C("EventType",TYPE)}},
    [0x15]={"PropertyMap",2,{T("Parent",TypeDef),L("PropertyList",Property,PropertyPtr)}},
    [0x16]={"PropertyPtr",1,{T("Property",Property)}},
    [0x17]={"Property",3,{F16("Flags"),S("Name"),B("Type",PROPERTY)}},
    [0x18]={"MethodSemantics",3,{F16("Semantics"),T("Method",MethodDef),C("Association",SEMANTICS)}},
    [0x19]={"MethodImpl",3,{T("Class",TypeDef),C("MethodBody",METHOD),C("MethodDeclaration",METHOD)}},
    [0x1a]={"ModuleRef",1,{S("Name")}},
    [0x1b]={"TypeSpec",1,{B("Signature",TYPE)}},
    [0x1c]={"ImplMap",4,{F16("MappingFlags"),C("MemberForwarded",FORWARDED),S("ImportName"),T("ImportScope",ModuleRef)}},
    [0x1d]={"FieldRVA",2,{U32("RVA"),T("Field",Field)}},
    [0x1e]={"ENCLog",2,{TOK("Token"),U32("FuncCode")}},
    [0x1f]={"ENCMap",1,{TOK("Token")}},
    [0x20]={"Assembly",9,{U32("HashAlgId"),U16("MajorVersion"),U16("MinorVersion"),U16("BuildNumber"),U16("RevisionNumber"),F32("Flags"),B("PublicKey",RAW),S("Name"),S("Culture")}},
    [0x21]={"AssemblyProcessor",1,{U32("Processor")}},
    [0x22]={"AssemblyOS",3,{U32("OSPlatformId"),U32("OSMajorVersion"),U32("OSMinorVersion")}},
    [0x23]={"AssemblyRef",9,{U16("MajorVersion"),U16("MinorVersion"),U16("BuildNumber"),U16("RevisionNumber"),F32("Flags"),B("PublicKeyOrToken",RAW),S("Name"),S("Culture"),B("HashValue",RAW)}},
    [0x24]={"AssemblyRefProcessor",2,{U32("Processor"),T("AssemblyRef",AssemblyRef)}},
    [0x25]={"AssemblyRefOS",4,{U32("OSPlatformId"),U32("OSMajorVersion"),U32("OSMinorVersion"),T("AssemblyRef",AssemblyRef)}},
    [0x26]={"File",3,{F32("Flags"),S("Name"),B("HashValue",RAW)}},
    [0x27]={"ExportedType",5,{F32("Flags"),U32("TypeDefId"),S("TypeName"),S("TypeNamespace"),C("Implementation",IMPLEMENTATION)}},
    [0x28]={"ManifestResource",4,{U32("Offset"),F32("Flags"),S("Name"),C("Implementation",IMPLEMENTATION)}},
    [0x29]={"NestedClass",2,{T("NestedClass",TypeDef),T("EnclosingClass",TypeDef)}},
    [0x2a]={"GenericParam",4,{U16("Number"),F16("Flags"),C("Owner",OWNER),S("Name")}},
    [0x2b]={"MethodSpec",2,{C("Method",METHOD),B("Instantiation",INSTANTIATION)}},
    [0x2c]={"GenericParamConstraint",2,{T("Owner",GenericParam),C("Constraint",TYPE)}},
    [0x30]={"Document",4,{B("Name",RAW),G("HashAlgorithm"),B("Hash",RAW),G("Language")}},
    [0x31]={"MethodDebugInformation",2,{T("Document",Document),B("SequencePoints",RAW)}},
    [0x32]={"LocalScope",6,{T("Method",MethodDef),T("ImportScope",ImportScope),L("VariableList",LocalVariable,LocalVariable),L("ConstantList",LocalConstant,LocalConstant),U32("StartOffset"),U32("Length")}},
    [0x33]={"LocalVariable",3,{F16("Attributes"),U16("Index"),S("Name")}},
    [0x34]={"LocalConstant",2,{S("Name"),B("Signature",RAW)}},
    [0x35]={"ImportScope",2,{T("Parent",ImportScope),B("Imports",RAW)}},
    [0x36]={"StateMachineMethod",2,{T("MoveNextMethod",MethodDef),T("KickoffMethod",MethodDef)}},
    [0x37]={"CustomDebugInformation",3,{C("Parent",DEBUG),G("Kind"),B("Value",RAW)}}
};
#undef U16
#undef U32
#undef F16
#undef F32
#undef S
#undef G
#undef B
#undef T
#undef L
#undef C
#undef TOK
typedef struct md_coded_schema { unsigned bits,count; unsigned tables[32]; } md_coded_schema;
static const md_coded_schema md_codes[] = {
    {2,4,{0,26,35,1}}, {2,3,{2,1,27}}, {3,5,{2,1,26,6,27}}, {2,3,{4,8,23}},
    {5,22,{6,4,1,2,8,9,10,0,14,23,20,17,26,27,32,35,38,39,40,42,44,43}},
    {3,4,{255,255,6,10}}, {1,2,{4,8}}, {2,3,{2,6,32}}, {1,2,{20,23}},
    {1,2,{6,10}}, {1,2,{4,6}}, {2,3,{38,35,39}}, {1,2,{2,6}},
    {5,27,{6,4,1,2,8,9,10,0,14,23,20,17,26,27,32,35,38,39,40,42,44,43,48,50,51,52,53}}
};
