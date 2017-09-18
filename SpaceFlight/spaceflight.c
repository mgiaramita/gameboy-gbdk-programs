/*
 * GameBoy space flight demo. Sprites + background
 */

#include <gb/gb.h>
#include <stdio.h>
#include "spacemap.c"
#include "spaceship.c"
#include "spacetiles.c"
#include "titletext.c"


#define NUM_BKG_TILES  0x08U
#define NUM_SPR_TILES  0x08U

#define SCREEN_WIDTH   0x14U
#define SCREEN_HEIGHT  0x16U

#define TITLE_XPOS     0x2FU
#define TITLE_YPOS     0xA0U

#define CURSOR_UP      0x00U
#define CURSOR_RIGHT   0x01U
#define CURSOR_DOWN    0x02U
#define CURSOR_LEFT    0x03U
#define CURSOR_ULEFT   0x04U
#define CURSOR_URIGHT  0x05U
#define CURSOR_DRIGHT  0x06U
#define CURSOR_DLEFT   0x07U


void displayTitle();
void setupBackground();
void setupSprites();

void controlShip();
void moveShip(UINT8 orientation);


//Ship coordinates
UINT8 x, y;
//Loop variables
UINT8 i, j;

void main()
{
    DISPLAY_ON;

    displayTitle();

    setupBackground();

    setupSprites();

    controlShip();
}

void displayTitle(){
    SPRITES_8x16;

    //Load the 20 sprites that create the title logo
    set_sprite_data(0, 20, titletext);

    //Set sprites to tile numbers so they can be displayed
    for(i = 0; i != 10; i++){
        set_sprite_tile(i, i * 2);
        move_sprite(i, TITLE_XPOS + (8 * i), TITLE_YPOS);
    }

    //Set background to all black
    set_bkg_data(8, 1, blacktile);
    set_bkg_tiles(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, deepspace);

    SHOW_BKG;
    SHOW_SPRITES;

    //Scroll up animation
    for(i = 0; i != 100; i++){
        for(j = 0; j != 10; j++){
            scroll_sprite(j, 0, -1);
        }
        delay(20);
    }

    delay(2000);

    HIDE_SPRITES;
    HIDE_BKG;

    //Move logo off screen
    for(i = 0; i != 10; i++){
        move_sprite(i, 0, 0);
    }
}

void setupBackground(){
    //Set spacetiles into background mem
    set_bkg_data(0, NUM_BKG_TILES, spacetiles);

    //Set background layout as defined in spacemap
    set_bkg_tiles(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, spacemap);

    SHOW_BKG;
}

void setupSprites(){
    x = 75;
    y = 75;

    SPRITES_8x8;

    //Push 8 8x8 sprites onto sprite data at 0
    set_sprite_data(0, NUM_SPR_TILES, spaceship);

    //Load "Up" ship sprite into tile 0
    set_sprite_tile(0, 0);

    //Set ship to starting location
    move_sprite(0, x, y);

    SHOW_SPRITES;
}

void controlShip(){
    while(1){
        switch(joypad()){
            case J_UP :
                y--;
                moveShip(CURSOR_UP);
                break;

            case J_DOWN :
                y++;
                moveShip(CURSOR_DOWN);
                break;

            case J_LEFT :
                x--;
                moveShip(CURSOR_LEFT);
                break;

            case J_RIGHT :
                x++;
                moveShip(CURSOR_RIGHT);
                break;

            case (J_UP | J_LEFT) :
                x--; y--;
                moveShip(CURSOR_ULEFT);
                break;

            case (J_UP | J_RIGHT) :
                x++; y--;
                moveShip(CURSOR_URIGHT);
                break;

            case (J_DOWN | J_LEFT) :
                x--; y++;
                moveShip(CURSOR_DLEFT);
                break;

            case (J_DOWN | J_RIGHT) :
                x++; y++;
                moveShip(CURSOR_DRIGHT);
                break;
        }
    }
}

void moveShip(UINT8 orientation){
    set_sprite_tile(0, orientation);
    move_sprite(0, x, y);
    delay(30);
}
