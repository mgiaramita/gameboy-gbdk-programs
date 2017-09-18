/*
 * GameBoy background display demo
 */

#include <gb/gb.h>
#include <stdio.h>
#include "spacetiles.c"
#include "spacemap.c"

#define NUM_TILES      8
#define SCREEN_WIDTH   20
#define SCREEN_HEIGHT  18

void main()
{
    printf("GameBoy Bkgrnd Demo!\n\n");
    delay(2000);

    //Set 8 tiles from spacetiles into background mem
    set_bkg_data(0, NUM_TILES, spacetiles);

    //Set background layout as defined in spacemap
    set_bkg_tiles(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, spacemap);

    SHOW_BKG;
}