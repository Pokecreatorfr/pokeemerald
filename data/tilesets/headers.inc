	.align 2
gTileset_SecretBaseBrownCave::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseBrownCave
	.4byte gTilesetPalettes_SecretBaseBrownCave
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseTree::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseTree
	.4byte gTilesetPalettes_SecretBaseTree
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseShrub::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseShrub
	.4byte gTilesetPalettes_SecretBaseShrub
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseBlueCave::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseBlueCave
	.4byte gTilesetPalettes_SecretBaseBlueCave
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseYellowCave::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseYellowCave
	.4byte gTilesetPalettes_SecretBaseYellowCave
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBaseRedCave::
	.byte FALSE @ is compressed
	.byte TRUE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBaseRedCave
	.4byte gTilesetPalettes_SecretBaseRedCave
	.4byte gMetatiles_SecretBaseSecondary
	.4byte gMetatileAttributes_SecretBaseSecondary
	.4byte NULL @ animation callback

	.align 2
gTileset_SecretBase::
	.byte FALSE @ is compressed
	.byte FALSE @ is secondary tileset
	.2byte 0 @ padding
	.4byte gTilesetTiles_SecretBase
	.4byte gTilesetPalettes_SecretBase
	.4byte gMetatiles_SecretBasePrimary
	.4byte gMetatileAttributes_SecretBasePrimary
	.4byte NULL @ animation callback

	.align 2
gTilesetPointer_SecretBase::
	.4byte gTileset_SecretBase

	.align 2
gTilesetPointer_SecretBaseRedCave::
	.4byte gTileset_SecretBaseRedCave

	.align 2
gTileset_4g_tileset_exterior::
	.byte TRUE @ is compressed
	.byte FALSE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_exterior
	.4byte gTilesetPalettes_4g_tileset_exterior
	.4byte gMetatiles_4g_tileset_exterior
	.4byte gMetatileAttributes_4g_tileset_exterior
	.4byte InitTilesetAnim_4g_tileset_exterior

	.align 2
gTileset_4g_tileset_outdoor_town::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_outdoor_town
	.4byte gTilesetPalettes_4g_tileset_outdoor_town
	.4byte gMetatiles_4g_tileset_outdoor_town
	.4byte gMetatileAttributes_4g_tileset_outdoor_town
	.4byte NULL

	.align 2
gTileset_4g_tileset_outdoor_town2::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_outdoor_town2
	.4byte gTilesetPalettes_4g_tileset_outdoor_town2
	.4byte gMetatiles_4g_tileset_outdoor_town2
	.4byte gMetatileAttributes_4g_tileset_outdoor_town2
	.4byte NULL

	.align 2
gTileset_4g_tileset_outdoor_city::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_outdoor_city
	.4byte gTilesetPalettes_4g_tileset_outdoor_city
	.4byte gMetatiles_4g_tileset_outdoor_city
	.4byte gMetatileAttributes_4g_tileset_outdoor_city
	.4byte NULL

	.align 2
gTileset_4g_tileset_outdoor_forest_house::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_outdoor_forest_house
	.4byte gTilesetPalettes_4g_tileset_outdoor_forest_house
	.4byte gMetatiles_4g_tileset_outdoor_forest_house
	.4byte gMetatileAttributes_4g_tileset_outdoor_forest_house
	.4byte NULL


	.align 2
gTileset_4g_tileset_Burned_Tower::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_Burned_Tower
	.4byte gTilesetPalettes_4g_tileset_Burned_Tower
	.4byte gMetatiles_4g_tileset_Burned_Tower
	.4byte gMetatileAttributes_4g_tileset_Burned_Tower
	.4byte NULL

	.align 2
gTileset_4g_tileset_indoor::
	.byte TRUE @ is compressed
	.byte FALSE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_indoor
	.4byte gTilesetPalettes_4g_tileset_indoor
	.4byte gMetatiles_4g_tileset_indoor
	.4byte gMetatileAttributes_4g_tileset_indoor
	.4byte NULL

	.align 2
gTileset_4g_tileset_bedroom::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_bedroom
	.4byte gTilesetPalettes_4g_tileset_bedroom
	.4byte gMetatiles_4g_tileset_bedroom
	.4byte gMetatileAttributes_4g_tileset_bedroom
	.4byte NULL


	.align 2
gTileset_4g_tileset_lab::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_lab
	.4byte gTilesetPalettes_4g_tileset_lab
	.4byte gMetatiles_4g_tileset_lab
	.4byte gMetatileAttributes_4g_tileset_lab
	.4byte NULL

	.align 2
gTileset_4g_tileset_pokecenter::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_pokecenter
	.4byte gTilesetPalettes_4g_tileset_pokecenter
	.4byte gMetatiles_4g_tileset_pokecenter
	.4byte gMetatileAttributes_4g_tileset_pokecenter
	.4byte NULL

	.align 2
gTileset_4g_tileset_cave::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_cave
	.4byte gTilesetPalettes_4g_tileset_cave
	.4byte gMetatiles_4g_tileset_cave
	.4byte gMetatileAttributes_4g_tileset_cave
	.4byte NULL


	.align 2
gTileset_4g_tileset_mart::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_mart
	.4byte gTilesetPalettes_4g_tileset_mart
	.4byte gMetatiles_4g_tileset_mart
	.4byte gMetatileAttributes_4g_tileset_mart
	.4byte NULL

	.align 2
gTileset_4g_tileset_indoor1::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_indoor1
	.4byte gTilesetPalettes_4g_tileset_indoor1
	.4byte gMetatiles_4g_tileset_indoor1
	.4byte gMetatileAttributes_4g_tileset_indoor1
	.4byte NULL


	.align 2
gTileset_4g_tileset_flyarena::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_flyarena
	.4byte gTilesetPalettes_4g_tileset_flyarena
	.4byte gMetatiles_4g_tileset_flyarena
	.4byte gMetatileAttributes_4g_tileset_flyarena
	.4byte NULL

	.align 2
gTileset_4g_tileset_woodtower::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_woodtower
	.4byte gTilesetPalettes_4g_tileset_woodtower
	.4byte gMetatiles_4g_tileset_woodtower
	.4byte gMetatileAttributes_4g_tileset_woodtower
	.4byte NULL

	.align 2
gTileset_4g_tileset_underground::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_underground
	.4byte gTilesetPalettes_4g_tileset_underground
	.4byte gMetatiles_4g_tileset_underground
	.4byte gMetatileAttributes_4g_tileset_underground
	.4byte NULL

	.align 2
gTileset_4g_tileset_indoor2::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_indoor2
	.4byte gTilesetPalettes_4g_tileset_indoor2
	.4byte gMetatiles_4g_tileset_indoor2
	.4byte gMetatileAttributes_4g_tileset_indoor2
	.4byte NULL

	.align 2
gTileset_4g_tileset_indoor3::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_indoor3
	.4byte gTilesetPalettes_4g_tileset_indoor3
	.4byte gMetatiles_4g_tileset_indoor3
	.4byte gMetatileAttributes_4g_tileset_indoor3
	.4byte NULL

	.align 2
gTileset_4g_tileset_ruins::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_ruins
	.4byte gTilesetPalettes_4g_tileset_ruins
	.4byte gMetatiles_4g_tileset_ruins
	.4byte gMetatileAttributes_4g_tileset_ruins
	.4byte NULL

	.align 2
gTileset_4g_tileset_park::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_park
	.4byte gTilesetPalettes_4g_tileset_park
	.4byte gMetatiles_4g_tileset_park
	.4byte gMetatileAttributes_4g_tileset_park
	.4byte NULL

	.align 2
gTileset_4g_tileset_dojo::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_dojo
	.4byte gTilesetPalettes_4g_tileset_dojo
	.4byte gMetatiles_4g_tileset_dojo
	.4byte gMetatileAttributes_4g_tileset_dojo
	.4byte NULL

	.align 2
gTileset_4g_tileset_flower_bike_store::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_flower_bike_store
	.4byte gTilesetPalettes_4g_tileset_flower_bike_store
	.4byte gMetatiles_4g_tileset_flower_bike_store
	.4byte gMetatileAttributes_4g_tileset_flower_bike_store
	.4byte NULL

	.align 2
gTileset_4g_tileset_subsoil::
	.byte TRUE @ is compressed
	.byte TRUE @ is secondary
	.2byte 0
	.4byte gTilesetTiles_4g_tileset_subsoil
	.4byte gTilesetPalettes_4g_tileset_subsoil
	.4byte gMetatiles_4g_tileset_subsoil
	.4byte gMetatileAttributes_4g_tileset_subsoil
	.4byte NULL
