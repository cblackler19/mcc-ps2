#include <gsKit.h>
#include <gsToolkit.h>
#include <gsInline.h>
#include <dmaKit.h>

int main(void)
{
    GSGLOBAL *gsGlobal;
    GSTEXTURE dirt;
    GSPRIMUVPOINT vertices[2];

    dmaKit_init(
        D_CTRL_RELE_ON,
        D_CTRL_MFD_OFF,
        D_CTRL_STS_UNSPEC,
        D_CTRL_STD_OFF,
        D_CTRL_RCYC_8,
        0
    );

    dmaKit_chan_init(DMA_CHANNEL_GIF);

    gsGlobal = gsKit_init_global();
    gsKit_init_screen(gsGlobal);

    if (gsKit_texture_png(
            gsGlobal,
            &dirt,
            "host:assets/textures/dirt.png"
        ) != 0)
    {
        return 1;
    }

    gsKit_set_clamp(gsGlobal, GS_CMODE_REPEAT);

    vertices[0].rgbaq = color_to_RGBAQ(64, 64, 64, 255, 0.0f);
    vertices[0].uv.coord.u = 0;
    vertices[0].uv.coord.v = 0;
    vertices[0].uv.tag = GS_UV;
    vertices[0].xyz2 = vertex_to_XYZ2(
        gsGlobal,
        0.0f,
        0.0f,
        0
    );

    vertices[1].rgbaq = color_to_RGBAQ(64, 64, 64, 255, 0.0f);
    vertices[1].uv.coord.u = 320 * 16;
    vertices[1].uv.coord.v = 256 * 16;
    vertices[1].uv.tag = GS_UV;
    vertices[1].xyz2 = vertex_to_XYZ2(
        gsGlobal,
        (float)gsGlobal->Width,
        (float)gsGlobal->Height,
        0
    );

    gskit_prim_list_sprite_texture_uv_3d(
        gsGlobal,
        &dirt,
        2,
        vertices
    );

    gsKit_queue_exec(gsGlobal);
    gsKit_sync_flip(gsGlobal);

    for (;;)
        __asm__ volatile("nop");

    return 0;
}
