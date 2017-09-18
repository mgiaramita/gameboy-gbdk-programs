/*
 * GameBoy cursor movement demo
 */

#include <gb/gb.h>
#include <stdio.h>

#define CURSOR_UP    0
#define CURSOR_RIGHT 1
#define CURSOR_DOWN  2
#define CURSOR_LEFT  3

#define CURSOR_ULEFT  4
#define CURSOR_URIGHT 5
#define CURSOR_DRIGHT 6
#define CURSOR_DLEFT  7

extern UBYTE cursor[];
UINT8 x,y;

void setupCursor();
void controlCursor();
void moveCursor(UINT8 orientation);

void main()
{
    printf("GameBoy Cursor Demo!\n\n");

    x = 75;
    y = 75;

    setupCursor();

    SHOW_SPRITES;

    controlCursor();
}

void setupCursor(){
    SPRITES_8x8;

    //Push 8 8x8 sprites onto sprite data at 0
    set_sprite_data(0, 8, cursor);

    //Load Up cursor sprite into tile 0
    set_sprite_tile(0, 0);

    //set cursor to starting location
    move_sprite(0, x, y);
}

void controlCursor(){
    while(1){
        switch(joypad()){
            case J_UP :
                y--;
                moveCursor(CURSOR_UP);
                break;
            case J_DOWN :
                y++;
                moveCursor(CURSOR_DOWN);
                break;
            case J_LEFT :
                x--;
                moveCursor(CURSOR_LEFT);
                break;
            case J_RIGHT :
                x++;
                moveCursor(CURSOR_RIGHT);
                break;
            case (J_UP | J_LEFT) :
                x--; y--;
                moveCursor(CURSOR_ULEFT);
                break;
            case (J_UP | J_RIGHT) :
                x++; y--;
                moveCursor(CURSOR_URIGHT);
                break;
            case (J_DOWN | J_LEFT) :
                x--; y++;
                moveCursor(CURSOR_DLEFT);
                break;
            case (J_DOWN | J_RIGHT) :
                x++; y++;
                moveCursor(CURSOR_DRIGHT);
                break;
        }
    }
}

void moveCursor(UINT8 orientation){
    set_sprite_tile(0, orientation);
    move_sprite(0, x, y);
    delay(10);
}

unsigned char cursor[] =
{
  0x10,0x10,0x10,0x10,0x28,0x38,0x24,0x3C,
  0x24,0x3C,0x42,0x7E,0x5A,0x7E,0x66,0x66,
  0x00,0x00,0xE0,0xE0,0x9C,0xFC,0x43,0x7F,
  0x44,0x7C,0x98,0xF8,0xE0,0xE0,0x00,0x00,
  0x66,0x66,0x5A,0x7E,0x42,0x7E,0x24,0x3C,
  0x24,0x3C,0x14,0x1C,0x08,0x08,0x08,0x08,
  0x00,0x00,0x07,0x07,0x19,0x1F,0x22,0x3E,
  0xC2,0xFE,0x39,0x3F,0x07,0x07,0x00,0x00,
  0x00,0x00,0x80,0x80,0x70,0x70,0x4E,0x7E,
  0x21,0x3F,0x12,0x1E,0x14,0x1C,0x08,0x08,
  0x02,0x02,0x0C,0x0C,0x14,0x1C,0x64,0x7C,
  0x88,0xF8,0x48,0x78,0x28,0x38,0x10,0x10,
  0x10,0x10,0x28,0x38,0x48,0x78,0x84,0xFC,
  0x72,0x7E,0x0E,0x0E,0x01,0x01,0x00,0x00,
  0x08,0x08,0x14,0x1C,0x12,0x1E,0x11,0x1F,
  0x26,0x3E,0x28,0x38,0x30,0x30,0x40,0x40
};

