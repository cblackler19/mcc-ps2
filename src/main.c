#include <dmaKit.h>
#include <gsKit.h>

int main(void) {
    GSGLOBAL *gsGlobal;

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

    gsKit_clear(gsGlobal, GS_SETREG_RGBAQ(255, 0, 255, 0x80, 0));

    gsKit_queue_exec(gsGlobal);
    gsKit_sync_flip(gsGlobal);

    for (;;) {
        __asm__ volatile("nop");
    }

    return 0;
}
