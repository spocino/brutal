#include <bal/abi.h>
#include <bal/helpers.h>
#include <brutal/debug.h>

BrResult brh_close(BrHandle handle)
{
    return br_close(&(BrCloseArgs){
        .handle = handle,
    });
}

BrResult brh_unmap(BrSpace space, void *base, size_t len)
{
    return br_unmap(&(BrUnmapArgs){
        space,
        (uintptr_t)base,
        len,
    });
}

static BrGlobalInfo *global_infos = nullptr;

BrGlobalInfo *brh_global_info(void)
{
    if (global_infos == nullptr)
    {
        BrMapArgs g_map = {
            .space = BR_SPACE_SELF,
            .mem_obj = BR_MEM_OBJ_GINFO,
        };

        assert_br_success(br_map(&g_map));
        global_infos = (BrGlobalInfo *)g_map.vaddr;
    }

    return global_infos;
}

static BrLocalInfo *local_infos = nullptr;

BrLocalInfo *brh_local_info(void)
{
    if (global_infos == nullptr)
    {
        BrMapArgs l_map = {
            .space = BR_SPACE_SELF,
            .mem_obj = BR_MEM_OBJ_LINFO,
        };

        assert_br_success(br_map(&l_map));
        local_infos = (BrLocalInfo *)l_map.vaddr;
    }

    return local_infos;
}
