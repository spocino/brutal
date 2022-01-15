#pragma once

#include <cc/ast.h>
#include <idl/ast.h>

/* --- Types ---------------------------------------------------------------- */

CType idl_cgen_decl_primitive(IdlType type);

CType idl_cgen_decl_enum(IdlType type, Alloc *alloc);

CType idl_cgen_decl_struct(IdlType type, Alloc *alloc);

CType idl_cgen_decl_vec(IdlType type, Alloc *alloc);

CType idl_cgen_decl_type(IdlType type, Alloc *alloc);

/* --- Pack ----------------------------------------------------------------- */

Str idl_cgen_pack_name(Str name, Alloc *alloc);

CExpr idl_cgen_pack_ref(Str name, Alloc *alloc);

CType idl_cgen_pack_type(IdlAlias alias, Alloc *alloc);

void idl_cgen_pack_body(CStmt *block, IdlType type, CExpr path, Alloc *alloc);

CDecl idl_cgen_pack_func(IdlAlias alias, Alloc *alloc);

/* --- Unpack --------------------------------------------------------------- */

Str idl_cgen_unpack_name(Str name, Alloc *alloc);

CExpr idl_cgen_unpack_ref(Str name, Alloc *alloc);

CType idl_cgen_unpack_type(IdlAlias alias, Alloc *alloc);

void idl_cgen_unpack_body(CStmt *block, IdlType type, CExpr path, Alloc *alloc);

CDecl idl_cgen_unpack_func(IdlAlias alias, Alloc *alloc);

/* --- Bindings ------------------------------------------------------------- */

CExpr idl_cgen_binding(IdlMethod method, IdlIface const iface, Alloc *alloc);

/* --- Methodes ------------------------------------------------------------- */

CType idl_cgen_method_type(IdlMethod method, IdlIface const iface, Alloc *alloc);

CStmt idl_cgen_method_body(IdlMethod method, IdlIface const iface, Alloc *alloc);

/* --- Provider ------------------------------------------------------------- */

CType idl_cgen_provider_type(IdlIface const iface, Alloc *alloc);

CDecl idl_cgen_provider_func(IdlIface const iface, Alloc *alloc);

/* --- Dispatch ------------------------------------------------------------- */

CType idl_cgen_dispatch_type(Alloc *alloc);

CExpr idl_cgen_dispatch_handler(IdlMethod method, Alloc *alloc);

void idl_cgen_dispatch_case(CStmt *block, IdlMethod method, IdlIface const iface, Alloc *alloc);

CStmt idl_cgen_dispatch_body(IdlIface const iface, Alloc *alloc);

CDecl idl_cgen_dispatch_func(IdlIface const iface, Alloc *alloc);

/* --- Source & Header ------------------------------------------------------ */

CUnit idl_cgen_header(MAYBE_UNUSED IdlIface const iface, Alloc *alloc);

CUnit idl_cgen_source(MAYBE_UNUSED IdlIface const iface, Alloc *alloc);