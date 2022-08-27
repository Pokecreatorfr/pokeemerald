#include "gba/gba.h"
#include "siirtc.h"

static struct SiiRtcInfo Time;
u8 region_map[28][16];
u8 weather_keypoints_coords[4][2] = {{5,9} , {10,9} , {5,18} , {10,18}};
u8 weather_keypoints_offset[4][2] = {{0,0} , {1,0}, {0,1} , {1,1}};

struct Weather_Map
{
    u8 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 map[28][16];
};

u8 pseudo_random_id(u8 day ,u8 month, u8 year ,u8 hour,u8 var);
void calc_weather (struct Weather_Map *weather_map);
void weather_zone (struct Weather_Map *weather_map,u8 type ,u8 zone ,u8 S);
