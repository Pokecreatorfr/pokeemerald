#include "global.h"
#include "graphics.h"
#include "palette.h"
#include "util.h"
#include "battle_transition.h"
#include "task.h"
#include "battle_transition.h"
#include "fieldmap.h"

static EWRAM_DATA struct {
    const u16 *src;
    u16 *dest;
    u16 size;
} sTilesetDMA3TransferBuffer[20] = {0};

static u8 sTilesetDMA3TransferBufferSize;
static u16 sPrimaryTilesetAnimCounter;
static u16 sPrimaryTilesetAnimCounterMax;
static u16 sSecondaryTilesetAnimCounter;
static u16 sSecondaryTilesetAnimCounterMax;
static void (*sPrimaryTilesetAnimCallback)(u16);
static void (*sSecondaryTilesetAnimCallback)(u16);

static void _InitPrimaryTilesetAnimation(void);
static void _InitSecondaryTilesetAnimation(void);
static void TilesetAnim_4g_tileset_exterior(u16);
static void QueueAnimTiles__4g_tileset_flower_anim(u16);
static void QueueAnimTiles__4g_tileset_Water_Anim(u16);

const u16 gTilesetAnims_4g_tileset_exterior_flower_anim_step0[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/flowers/flower_anim_step0.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_flower_anim_step1[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/flowers/flower_anim_step1.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_flower_anim_step2[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/flowers/flower_anim_step2.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_flower_anim_step3[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/flowers/flower_anim_step3.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_flower_anim_step4[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/flowers/flower_anim_step4.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_flower_anim_step5[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/flowers/flower_anim_step5.4bpp" );

const u16 * const gTilesetAnims_4g_tileset_flower_anim[] = {
    gTilesetAnims_4g_tileset_exterior_flower_anim_step0,
    gTilesetAnims_4g_tileset_exterior_flower_anim_step1,
    gTilesetAnims_4g_tileset_exterior_flower_anim_step2,
    gTilesetAnims_4g_tileset_exterior_flower_anim_step3,
    gTilesetAnims_4g_tileset_exterior_flower_anim_step4,
    gTilesetAnims_4g_tileset_exterior_flower_anim_step5,
    gTilesetAnims_4g_tileset_exterior_flower_anim_step4,
    gTilesetAnims_4g_tileset_exterior_flower_anim_step3,
    gTilesetAnims_4g_tileset_exterior_flower_anim_step2,
    gTilesetAnims_4g_tileset_exterior_flower_anim_step1
};

const u16 gTilesetAnims_4g_tileset_exterior_Water_Anim_Step0[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/water/Water_Anim_Step0.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_Water_Anim_Step1[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/water/Water_Anim_Step1.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_Water_Anim_Step2[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/water/Water_Anim_Step2.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_Water_Anim_Step3[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/water/Water_Anim_Step3.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_Water_Anim_Step4[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/water/Water_Anim_Step4.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_Water_Anim_Step5[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/water/Water_Anim_Step5.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_Water_Anim_Step6[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/water/Water_Anim_Step6.4bpp" );
const u16 gTilesetAnims_4g_tileset_exterior_Water_Anim_Step7[] = INCBIN_U16( "data/tilesets/primary/4g_tileset_exterior/anim/water/Water_Anim_Step7.4bpp" );

const u16 * const gTilesetAnims_4g_tileset_Water_Anim[] = {
    gTilesetAnims_4g_tileset_exterior_Water_Anim_Step0,
    gTilesetAnims_4g_tileset_exterior_Water_Anim_Step1,
    gTilesetAnims_4g_tileset_exterior_Water_Anim_Step2,
    gTilesetAnims_4g_tileset_exterior_Water_Anim_Step3,
    gTilesetAnims_4g_tileset_exterior_Water_Anim_Step4,
    gTilesetAnims_4g_tileset_exterior_Water_Anim_Step5,
    gTilesetAnims_4g_tileset_exterior_Water_Anim_Step6,
    gTilesetAnims_4g_tileset_exterior_Water_Anim_Step7,
};

u16 *const gTilesetAnims_Mauville_Flower1_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 96)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 100)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 104)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 108)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 112)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 116)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 120)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 124))
};

u16 *const gTilesetAnims_Mauville_Flower2_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 128)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 132)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 136)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 140)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 144)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 148)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 152)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 156))
};


u16 *const gTilesetAnims_Rustboro_WindyWater_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 128)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 132)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 136)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 140)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 144)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 148)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 152)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 156))
};

u16 *const gTilesetAnims_EverGrande_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 224)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 228)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 232)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 236)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 240)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 244)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 248)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 252))
};

static void ResetTilesetAnimBuffer(void)
{
    sTilesetDMA3TransferBufferSize = 0;
    CpuFill32(0, sTilesetDMA3TransferBuffer, sizeof sTilesetDMA3TransferBuffer);
}

static void AppendTilesetAnimToBuffer(const u16 *src, u16 *dest, u16 size)
{
    if (sTilesetDMA3TransferBufferSize < 20)
    {
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].src = src;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].dest = dest;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].size = size;
        sTilesetDMA3TransferBufferSize ++;
    }
}

void TransferTilesetAnimsBuffer(void)
{
    int i;

    for (i = 0; i < sTilesetDMA3TransferBufferSize; i ++)
        DmaCopy16(3, sTilesetDMA3TransferBuffer[i].src, sTilesetDMA3TransferBuffer[i].dest, sTilesetDMA3TransferBuffer[i].size);

    sTilesetDMA3TransferBufferSize = 0;
}

void InitTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    _InitPrimaryTilesetAnimation();
    _InitSecondaryTilesetAnimation();
}

void InitSecondaryTilesetAnimation(void)
{
    _InitSecondaryTilesetAnimation();
}

void UpdateTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    if (++sPrimaryTilesetAnimCounter >= sPrimaryTilesetAnimCounterMax)
        sPrimaryTilesetAnimCounter = 0;
    if (++sSecondaryTilesetAnimCounter >= sSecondaryTilesetAnimCounterMax)
        sSecondaryTilesetAnimCounter = 0;

    if (sPrimaryTilesetAnimCallback)
        sPrimaryTilesetAnimCallback(sPrimaryTilesetAnimCounter);
    if (sSecondaryTilesetAnimCallback)
        sSecondaryTilesetAnimCallback(sSecondaryTilesetAnimCounter);
}

static void _InitPrimaryTilesetAnimation(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 0;
    sPrimaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->primaryTileset && gMapHeader.mapLayout->primaryTileset->callback)
        gMapHeader.mapLayout->primaryTileset->callback();
}

static void _InitSecondaryTilesetAnimation(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 0;
    sSecondaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->secondaryTileset && gMapHeader.mapLayout->secondaryTileset->callback)
        gMapHeader.mapLayout->secondaryTileset->callback();
}

void InitTilesetAnim_4g_tileset_exterior(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 256;
    sPrimaryTilesetAnimCallback = TilesetAnim_4g_tileset_exterior;
}

static void TilesetAnim_4g_tileset_exterior(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles__4g_tileset_flower_anim(timer / 16);

    if (timer % 4 == 0)
        QueueAnimTiles__4g_tileset_Water_Anim(timer / 16);
}

static void QueueAnimTiles__4g_tileset_flower_anim(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_4g_tileset_flower_anim); 
    AppendTilesetAnimToBuffer(gTilesetAnims_4g_tileset_flower_anim[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(467)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles__4g_tileset_Water_Anim(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_4g_tileset_Water_Anim); 
    AppendTilesetAnimToBuffer(gTilesetAnims_4g_tileset_Water_Anim[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(436)), 4 * TILE_SIZE_4BPP);
}