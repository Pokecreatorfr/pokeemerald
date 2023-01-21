const struct Tileset gTileset_SecretBaseBrownCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBrownCave,
    .palettes = gTilesetPalettes_SecretBaseBrownCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseTree =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseTree,
    .palettes = gTilesetPalettes_SecretBaseTree,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseShrub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseShrub,
    .palettes = gTilesetPalettes_SecretBaseShrub,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBlueCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBlueCave,
    .palettes = gTilesetPalettes_SecretBaseBlueCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseYellowCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseYellowCave,
    .palettes = gTilesetPalettes_SecretBaseYellowCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseRedCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseRedCave,
    .palettes = gTilesetPalettes_SecretBaseRedCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBase =
{
    .isCompressed = FALSE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SecretBase,
    .palettes = gTilesetPalettes_SecretBase,
    .metatiles = gMetatiles_SecretBasePrimary,
    .metatileAttributes = gMetatileAttributes_SecretBasePrimary,
    .callback = NULL,
};

const struct Tileset * const gTilesetPointer_SecretBase = &gTileset_SecretBase;
const struct Tileset * const gTilesetPointer_SecretBaseRedCave = &gTileset_SecretBaseRedCave;


const struct Tileset gTileset_4g_tileset_exterior =
{
	.isCompressed =  TRUE ,
	.isSecondary =  FALSE ,
	.tiles =  gTilesetTiles_4g_tileset_exterior,
	.palettes =  gTilesetPalettes_4g_tileset_exterior,
	.metatiles =  gMetatiles_4g_tileset_exterior,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_exterior,
	.callback =  InitTilesetAnim_4g_tileset_exterior,
};

const struct Tileset gTileset_4g_tileset_outdoor_town =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_outdoor_town,
	.palettes =  gTilesetPalettes_4g_tileset_outdoor_town,
	.metatiles =  gMetatiles_4g_tileset_outdoor_town,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_outdoor_town,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_outdoor_town2 =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_outdoor_town2,
	.palettes =  gTilesetPalettes_4g_tileset_outdoor_town2,
	.metatiles =  gMetatiles_4g_tileset_outdoor_town2,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_outdoor_town2,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_outdoor_city =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_outdoor_city,
	.palettes =  gTilesetPalettes_4g_tileset_outdoor_city,
	.metatiles =  gMetatiles_4g_tileset_outdoor_city,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_outdoor_city,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_outdoor_forest_house =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_outdoor_forest_house,
	.palettes =  gTilesetPalettes_4g_tileset_outdoor_forest_house,
	.metatiles =  gMetatiles_4g_tileset_outdoor_forest_house,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_outdoor_forest_house,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_Burned_Tower =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_Burned_Tower,
	.palettes =  gTilesetPalettes_4g_tileset_Burned_Tower,
	.metatiles =  gMetatiles_4g_tileset_Burned_Tower,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_Burned_Tower,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_indoor =
{
	.isCompressed =  TRUE ,
	.isSecondary =  FALSE ,
	.tiles =  gTilesetTiles_4g_tileset_indoor,
	.palettes =  gTilesetPalettes_4g_tileset_indoor,
	.metatiles =  gMetatiles_4g_tileset_indoor,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_indoor,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_bedroom =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_bedroom,
	.palettes =  gTilesetPalettes_4g_tileset_bedroom,
	.metatiles =  gMetatiles_4g_tileset_bedroom,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_bedroom,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_lab =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_lab,
	.palettes =  gTilesetPalettes_4g_tileset_lab,
	.metatiles =  gMetatiles_4g_tileset_lab,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_lab,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_pokecenter =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_pokecenter,
	.palettes =  gTilesetPalettes_4g_tileset_pokecenter,
	.metatiles =  gMetatiles_4g_tileset_pokecenter,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_pokecenter,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_cave =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_cave,
	.palettes =  gTilesetPalettes_4g_tileset_cave,
	.metatiles =  gMetatiles_4g_tileset_cave,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_cave,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_mart =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_mart,
	.palettes =  gTilesetPalettes_4g_tileset_mart,
	.metatiles =  gMetatiles_4g_tileset_mart,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_mart,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_indoor1 =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_indoor1,
	.palettes =  gTilesetPalettes_4g_tileset_indoor1,
	.metatiles =  gMetatiles_4g_tileset_indoor1,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_indoor1,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_flyarena =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_flyarena,
	.palettes =  gTilesetPalettes_4g_tileset_flyarena,
	.metatiles =  gMetatiles_4g_tileset_flyarena,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_flyarena,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_woodtower =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_woodtower,
	.palettes =  gTilesetPalettes_4g_tileset_woodtower,
	.metatiles =  gMetatiles_4g_tileset_woodtower,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_woodtower,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_underground =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_underground,
	.palettes =  gTilesetPalettes_4g_tileset_underground,
	.metatiles =  gMetatiles_4g_tileset_underground,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_underground,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_indoor2 =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_indoor2,
	.palettes =  gTilesetPalettes_4g_tileset_indoor2,
	.metatiles =  gMetatiles_4g_tileset_indoor2,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_indoor2,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_indoor3 =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_indoor3,
	.palettes =  gTilesetPalettes_4g_tileset_indoor3,
	.metatiles =  gMetatiles_4g_tileset_indoor3,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_indoor3,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_ruins =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_ruins,
	.palettes =  gTilesetPalettes_4g_tileset_ruins,
	.metatiles =  gMetatiles_4g_tileset_ruins,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_ruins,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_park =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_park,
	.palettes =  gTilesetPalettes_4g_tileset_park,
	.metatiles =  gMetatiles_4g_tileset_park,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_park,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_dojo =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_dojo,
	.palettes =  gTilesetPalettes_4g_tileset_dojo,
	.metatiles =  gMetatiles_4g_tileset_dojo,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_dojo,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_flower_bike_store =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_flower_bike_store,
	.palettes =  gTilesetPalettes_4g_tileset_flower_bike_store,
	.metatiles =  gMetatiles_4g_tileset_flower_bike_store,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_flower_bike_store,
	.callback =  NULL,
};

const struct Tileset gTileset_4g_tileset_subsoil =
{
	.isCompressed =  TRUE ,
	.isSecondary =  TRUE ,
	.tiles =  gTilesetTiles_4g_tileset_subsoil,
	.palettes =  gTilesetPalettes_4g_tileset_subsoil,
	.metatiles =  gMetatiles_4g_tileset_subsoil,
	.metatileAttributes =  gMetatileAttributes_4g_tileset_subsoil,
	.callback =  NULL,
};

