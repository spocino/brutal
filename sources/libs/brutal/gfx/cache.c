#include <brutal/gfx/cache.h>

void gfx_cache_init(GfxCache *self, Alloc *alloc)
{
    linear_buf_init(&self->commands, alloc);

    grid_init(&self->front_hashgrid, 16, 16, alloc);
    grid_init(&self->back_hashgrid, 16, 16, alloc);
}

void gfx_cache_deinit(GfxCache *self)
{
    grid_deinit(&self->back_hashgrid);
    grid_deinit(&self->front_hashgrid);

    linear_buf_deinit(&self->commands);
}

void gfx_cache_begin(GfxCache *self, GfxSurface surface)
{
    grid_resize(
        &self->front_hashgrid,
        MIN(surface.width / GFX_CACHE_CELL_SIZE, 1),
        MIN(surface.height / GFX_CACHE_CELL_SIZE, 1));

    grid_resize(
        &self->back_hashgrid,
        MIN(surface.width / GFX_CACHE_CELL_SIZE, 1),
        MIN(surface.height / GFX_CACHE_CELL_SIZE, 1));
}

void gfx_cache_end(GfxCache *self, MAYBE_UNUSED GfxSurface surface)
{
    linear_buf_foreach(command, &self->commands)
    {
        switch (command->type)
        {
        case GFX_COMMAND_RECT:
            panic$("Implement RECT command.");
            break;

        case GFX_COMMAND_LINE:
            panic$("Implement LINE command.");
            break;

        case GFX_COMMAND_TEXT:
            panic$("Implement TEXT command.");
            break;

        case GFX_COMMAND_POLY:
            panic$("Implement POLY command.");
            break;

        default:
            panic$("Unknown command {}", command->type);
            break;
        }
    }

    linear_buf_clear(&self->commands);
}

void gfx_cache_invalidate(GfxCache *self)
{
    grid_fill(&self->front_hashgrid, 0x0);
    grid_fill(&self->back_hashgrid, 0x0);
}

void gfx_cache_rect(GfxCache *self, Rectf rect, GfxStroke stroke, GfxPaint fill, MAYBE_UNUSED Trans2 trans)
{
    GfxRectCommand command = (GfxRectCommand){
        .base = (GfxCommand){
            .type = GFX_COMMAND_RECT,
            .bound = rect,
            .stroke = stroke,
            .fill = fill,
        },
        .rect = rect,
    };

    linear_buf_push(&self->commands, command);
}

// void gfx_cache_line(GfxCache *self, Edgef line, GfxStroke stroke, Trans2 transform)
// {
// }
//
// void gfx_cache_text(GfxCache *self, Str str, GfxPaint fill, Trans2 transform)
// {
// }
//
// void gfx_cache_poly(GfxCache *self, Edges edges, GfxStroke stroke, GfxPaint fill, Trans2 transform)
// {
// }
