#pragma once

#include <bid/ast/iface.h>
#include <bid/ast/types.h>

bool bid_type_in_interface(BidIface const *iface, Str name);

bool bid_type_is_handle(BidType *type);
