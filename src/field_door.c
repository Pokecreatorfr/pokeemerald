#include "global.h"
#include "event_data.h"
#include "field_door.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "task.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

#define DOOR_SOUND_NORMAL  0
#define DOOR_SOUND_SLIDING 1
#define DOOR_SOUND_ARENA   2

struct DoorGraphics
{
    u16 metatileNum;
    u8 sound;
    u8 size;
    const void *tiles;
    const void *palette;
};

struct DoorAnimFrame
{
    u8 time;
    u16 offset;
};

static bool8 ShouldUseMultiCorridorDoor(void);


static const u8 sDoorAnimTiles_4G_PokeMart[] = INCBIN_U8("graphics/door_anims/4G_pokemart_door.4bpp");
static const u16 sDoorNullPalette1[16] = {};
static const u8 sDoorAnimTiles_4G_PokeCenter[] = INCBIN_U8("graphics/door_anims/4G_pokecenter_door.4bpp");
static const u16 sDoorNullPalette2[16] = {};
static const u8 sDoorAnimTiles_4G_Gym[] = INCBIN_U8("graphics/door_anims/4G_gym_door.4bpp");
static const u16 sDoorNullPalette3[16] = {};
static const u8 sDoorAnimTiles_4G_wood_door[] = INCBIN_U8("graphics/door_anims/4G_wood_door.4bpp");
static const u16 sDoorNullPalette4[16] = {};
static const u8 sDoorAnimTiles_4G_house_door[] = INCBIN_U8("graphics/door_anims/4G_house_door.4bpp");
static const u16 sDoorNullPalette5[16] = {};
static const u8 sDoorAnimTiles_4G_house_door2[] = INCBIN_U8("graphics/door_anims/4G_house_door2.4bpp");
static const u16 sDoorNullPalette6[16] = {};
static const u8 sDoorAnimTiles_4G_house_door3[] = INCBIN_U8("graphics/door_anims/4G_house_door3.4bpp");
static const u16 sDoorNullPalette7[16] = {};

static const struct DoorAnimFrame sDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x100},
    {4, 0x200},
    {0, 0},
};

static const struct DoorAnimFrame sDoorCloseAnimFrames[] =
{
    {4, 0x200},
    {4, 0x100},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const struct DoorAnimFrame sSmallDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x100},
    {4, 0x100},
    {0, 0},
};

static const struct DoorAnimFrame sSmallDoorCloseAnimFrames[] =
{
    {4, 0x100},
    {4, 0x100},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x200},
    {4, 0x400},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorCloseAnimFrames[] =
{
    {4, 0x400},
    {4, 0x200},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const u8 sDoorAnimPalettes_4G_PokeMart[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_4G_PokeCenter[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_4G_Gym[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_4G_wood_door[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_4G_house_door[] = {12, 12, 12, 12, 12, 12, 12, 12};
static const u8 sDoorAnimPalettes_4G_house_door2[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_4G_house_door3[] = {11, 11, 11, 11, 11, 11, 11, 11};

static const struct DoorGraphics sDoorAnimGraphicsTable[] =
{
    {METATILE_4g_tileset_exterior_pokemart_door,            DOOR_SOUND_SLIDING, 3, sDoorAnimTiles_4G_PokeMart, sDoorAnimPalettes_4G_PokeMart},
    {METATILE_4g_tileset_exterior_pokemart_door2,            DOOR_SOUND_SLIDING, 3, sDoorAnimTiles_4G_PokeMart, sDoorAnimPalettes_4G_PokeMart},
    {METATILE_4g_tileset_exterior_pokecenter_door,          DOOR_SOUND_SLIDING, 3, sDoorAnimTiles_4G_PokeCenter, sDoorAnimPalettes_4G_PokeCenter},
    {METATILE_4g_tileset_exterior_gym_door,                 DOOR_SOUND_SLIDING, 3, sDoorAnimTiles_4G_Gym, sDoorAnimPalettes_4G_Gym},
    {METATILE_4g_tileset_exterior_gym_door2,                 DOOR_SOUND_SLIDING, 3, sDoorAnimTiles_4G_Gym, sDoorAnimPalettes_4G_Gym},
    {METATILE_4g_tileset_exterior_wood_door,                 DOOR_SOUND_NORMAL, 3, sDoorAnimTiles_4G_wood_door, sDoorAnimPalettes_4G_wood_door},
    {METATILE_4g_tileset_exterior_wood_door2,                 DOOR_SOUND_NORMAL, 3, sDoorAnimTiles_4G_wood_door, sDoorAnimPalettes_4G_wood_door},
    {METATILE_4g_tileset_exterior_house_door,                 DOOR_SOUND_NORMAL, 3, sDoorAnimTiles_4G_house_door, sDoorAnimPalettes_4G_house_door},
    {METATILE_4g_tileset_exterior_house_doorbis,                 DOOR_SOUND_NORMAL, 3, sDoorAnimTiles_4G_house_door, sDoorAnimPalettes_4G_house_door},
    {METATILE_4g_tileset_exterior_house_door2,                 DOOR_SOUND_NORMAL, 3, sDoorAnimTiles_4G_house_door2, sDoorAnimPalettes_4G_house_door2},
    {METATILE_4g_tileset_exterior_house_door3,                 DOOR_SOUND_NORMAL, 3, sDoorAnimTiles_4G_house_door3, sDoorAnimPalettes_4G_house_door3},
    {},
};

static void CopyDoorTilesToVram(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame)
{
    if (gfx->size == 2)
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7E00), 0x80);
    else if (gfx->size == 2)
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7F00), 0x20);
    else
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7F00), 0x40);
}

static void door_build_blockdef(u16 *a, u16 b, const u8 *c)
{
    int i;
    u16 unk;

    for (i = 0; i < 4; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk | (b + i);
    }
    for (; i < 8; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk;
    }
}

static void DrawCurrentDoorAnimFrame(const struct DoorGraphics *gfx, u32 x, u32 y, const u8 *pal)
{
    u16 arr[24];

    if (gfx->size == 2)
    {
        door_build_blockdef(&arr[8], 0x3F0, pal);
        DrawDoorMetatileAt(x, y - 1, &arr[8]);
        door_build_blockdef(&arr[8], 0x3F4, pal + 4);
        DrawDoorMetatileAt(x, y, &arr[8]);
        door_build_blockdef(&arr[8], 0x3F8, pal);
        DrawDoorMetatileAt(x + 1, y - 1, &arr[8]);
        door_build_blockdef(&arr[8], 0x3FC, pal + 4);
        DrawDoorMetatileAt(x + 1, y, &arr[8]);
    }
    else if (gfx->size == 3)
    {
        door_build_blockdef(&arr[0], 0x3F8, pal);
        DrawDoorMetatileAt(x, y, &arr[0]);
    }
    else
    {
        door_build_blockdef(&arr[0], 0x3F8, pal);
        DrawDoorMetatileAt(x, y - 1, &arr[0]);
        door_build_blockdef(&arr[0], 0x3FC, pal + 4);
        DrawDoorMetatileAt(x, y, &arr[0]);
    }
}

static void DrawClosedDoorTiles(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    CurrentMapDrawMetatileAt(x, y - 1);
    CurrentMapDrawMetatileAt(x, y);

    if (gfx->size == 2)
    {
        CurrentMapDrawMetatileAt(x + 1, y - 1);
        CurrentMapDrawMetatileAt(x + 1, y);
    }
}

static void DrawDoor(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame, u32 x, u32 y)
{
    if (frame->offset == 0xFFFF)
    {
        DrawClosedDoorTiles(gfx, x, y);
        if (ShouldUseMultiCorridorDoor())
            DrawClosedDoorTiles(gfx, gSpecialVar_0x8004 + MAP_OFFSET, gSpecialVar_0x8005 + MAP_OFFSET);
    }
    else
    {
        CopyDoorTilesToVram(gfx, frame);
        DrawCurrentDoorAnimFrame(gfx, x, y, gfx->palette);
        if (ShouldUseMultiCorridorDoor())
            DrawCurrentDoorAnimFrame(gfx, gSpecialVar_0x8004 + MAP_OFFSET, gSpecialVar_0x8005 + MAP_OFFSET, gfx->palette);
    }
}

#define tFramesHi data[0]
#define tFramesLo data[1]
#define tGfxHi data[2]
#define tGfxLo data[3]
#define tFrameId data[4]
#define tCounter data[5]
#define tX data[6]
#define tY data[7]

// Draws a single frame of the door animation, or skips drawing to wait between frames.
// Returns FALSE when the final frame has been reached
static bool32 AnimateDoorFrame(struct DoorGraphics *gfx, struct DoorAnimFrame *frames, s16 *data)
{
    if (tCounter == 0)
        DrawDoor(gfx, &frames[tFrameId], tX, tY);

    if (tCounter == frames[tFrameId].time)
    {
        tCounter = 0;
        tFrameId++;
        if (frames[tFrameId].time == 0)
            return FALSE;
        else
            return TRUE;
    }
    tCounter++;
    return TRUE;
}

static void Task_AnimateDoor(u8 taskId)
{
    u16 *data = gTasks[taskId].data;
    struct DoorAnimFrame *frames = (struct DoorAnimFrame *)(tFramesHi << 16 | tFramesLo);
    struct DoorGraphics *gfx = (struct DoorGraphics *)(tGfxHi << 16 | tGfxLo);

    if (AnimateDoorFrame(gfx, frames, data) == FALSE)
        DestroyTask(taskId);
}

static const struct DoorAnimFrame *GetLastDoorFrame(const struct DoorAnimFrame *frame, const void *unused)
{
    while (frame->time != 0)
        frame++;
    return frame - 1;
}

static const struct DoorGraphics *GetDoorGraphics(const struct DoorGraphics *gfx, u16 metatileNum)
{
    while (gfx->tiles != NULL)
    {
        if (gfx->metatileNum == metatileNum)
            return gfx;
        gfx++;
    }
    return NULL;
}

static s8 StartDoorAnimationTask(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frames, u32 x, u32 y)
{
    if (FuncIsActiveTask(Task_AnimateDoor) == TRUE)
        return -1;
    else
    {
        u8 taskId = CreateTask(Task_AnimateDoor, 0x50);
        s16 *data = gTasks[taskId].data;

        tX = x;
        tY = y;

        tFramesLo = (u32)frames;
        tFramesHi = (u32)frames >> 16;

        tGfxLo = (u32)gfx;
        tGfxHi = (u32)gfx >> 16;

        return taskId;
    }
}

static void DrawClosedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    DrawClosedDoorTiles(gfx, x, y);
}

static void DrawOpenedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx != NULL && gfx->size != 3)
        DrawDoor(gfx, GetLastDoorFrame(sDoorOpenAnimFrames, sDoorOpenAnimFrames), x, y);
    else if (gfx != NULL && gfx->size == 3)
        DrawDoor(gfx, GetLastDoorFrame(sSmallDoorOpenAnimFrames, sSmallDoorOpenAnimFrames), x, y);
}


static s8 StartDoorOpenAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
    {
        return -1;
    }
    else
    {
        if (gfx->size == 2)
            return StartDoorAnimationTask(gfx, sBigDoorOpenAnimFrames, x, y);
        else if (gfx->size == 3)
            return StartDoorAnimationTask(gfx, sSmallDoorOpenAnimFrames, x, y);
        else
            return StartDoorAnimationTask(gfx, sDoorOpenAnimFrames, x, y);
    }
}

static s8 StartDoorCloseAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else if (gfx->size == 3)
        return StartDoorAnimationTask(gfx, sSmallDoorCloseAnimFrames, x, y);
    else
        return StartDoorAnimationTask(gfx, sDoorCloseAnimFrames, x, y);
}

static s8 GetDoorSoundType(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else
        return gfx->sound;
}

// Unused. Debug? Same as FieldAnimateDoorOpen but doesnt return or check if metatile is actually a door
static void Debug_FieldAnimateDoorOpen(u32 x, u32 y)
{
    StartDoorOpenAnimation(sDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorOpened(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawOpenedDoor(sDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorClosed(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawClosedDoor(sDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorClose(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorCloseAnimation(sDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorOpen(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorOpenAnimation(sDoorAnimGraphicsTable, x, y);
}

bool8 FieldIsDoorAnimationRunning(void)
{
    return FuncIsActiveTask(Task_AnimateDoor);
}

u32 GetDoorSoundEffect(u32 x, u32 y)
{
    int sound = GetDoorSoundType(sDoorAnimGraphicsTable, x, y);

    if (sound == DOOR_SOUND_NORMAL)
        return SE_DOOR;
    else if (sound == DOOR_SOUND_SLIDING)
        return SE_SLIDING_DOOR;
    else if (sound == DOOR_SOUND_ARENA)
        return SE_REPEL;
    else
        return SE_DOOR;
}

// Opens the Battle Tower multi partner's door in sync with the player's door
static bool8 ShouldUseMultiCorridorDoor(void)
{
    if (FlagGet(FLAG_ENABLE_MULTI_CORRIDOR_DOOR))
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR)
            && gSaveBlock1Ptr->location.mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR))
        {
            return TRUE;
        }
    }
    return FALSE;
}
