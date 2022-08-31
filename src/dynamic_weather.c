#include "global.h"
#include "random.h"
#include "rtc.h"
#include "dynamic_weather.h"
#include "tv.h"

u8 pseudo_random_id(u8 day ,u8 month, u8 year ,u8 hour,u8 var)
{
    return ((1103515245 * month*hour*(var+1) - day + GetPlayerIDAsU32() - year ) & (255 <<hour) >>hour);
}

void calc_weather (struct Weather_Map *weather_map)
{
    u8 i;
    u8 x;
    u8 y;   
    u8 weather_keypoints_coords[4][2] = {{5,9} , {10,9} , {5,18} , {10,18}};
    u8 weather_keypoints_offset[4][2] = {{0,0} , {1,0}, {0,1} , {1,1}};
    for (i = 0 ; i < sizeof(weather_keypoints_coords) ; i++)
    {
        if (pseudo_random_id(weather_map -> day,weather_map -> month,weather_map -> year,weather_map -> hour, i) < 175)
        {
            for (x = 0 ; x < 8 ; x++)
            {
                for (y = 0 ; y < 14 ; y++)
                {
                    weather_map -> map[weather_keypoints_offset[i][0]*8+x][weather_keypoints_offset[i][1]*14+y] = 1;
                }
            }
            if (pseudo_random_id(weather_map -> day,weather_map -> month,weather_map -> year,weather_map -> hour, i+4) < 100)
            {
                if (pseudo_random_id(weather_map -> day,weather_map -> month,weather_map -> year,weather_map -> hour, i+5) > 150)
                {
                    weather_zone(weather_map, 3 , i , 1);
                }
                else if (pseudo_random_id(weather_map -> day,weather_map -> month,weather_map -> year,weather_map -> hour, i+5) < 30)
                {
                    weather_zone(weather_map, 3 , i , 2);
                }
                else
                {
                    weather_zone(weather_map, 3 , i , 0);
                }
            }
        }
        else
        {
            for (x = 0 ; x < 8 ; x++)
            {
                for (y = 0 ; y < 14 ; y++)
                {
                    weather_map -> map[weather_keypoints_offset[i][0]*8+x][weather_keypoints_offset[i][1]*14+y] = 2;
                }
            }
        }
    }
}

void weather_zone (struct Weather_Map *weather_map,u8 type ,u8 zone ,u8 S)
{
    u8 i;
    u8 x;
    u8 size[3][8] = {{0,1,2,3,3,2,1,0},{1,2,3,5,5,3,2,1},{8,8,8,8,8,8,8,8}};
    u8 weather_keypoints_coords[4][2] = {{5,9} , {10,9} , {5,18} , {10,18}};
    u8 weather_keypoints_offset[4][2] = {{0,0} , {1,0}, {0,1} , {1,1}};
    for (i = 0; i < 8 ; i++)
    {
        for (x = 0 ; x < size[S][i] ; x++)
        {
            weather_map ->map[weather_keypoints_offset[zone][0]*8+i][weather_keypoints_offset[zone][1]*14+6+x] = type;
            weather_map ->map[weather_keypoints_offset[zone][0]*8+i][weather_keypoints_offset[zone][1]*14+6-x] = type;
        }
    }
}

u8
u8 returnmapposx(u8 mapsec)
{
    return gRegionMapEntries[mapsec].x
}

u8 returnmapposy(u8 mapsec)
{
    return gRegionMapEntries[mapsec].x
}