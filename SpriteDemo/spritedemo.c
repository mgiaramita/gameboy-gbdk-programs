/*
 * GameBoy sprite animation demo
 */

#include <gb/gb.h>
#include <stdio.h>
#include "leftwalk.c"

void setDefaultSprite();
void walkLoop();

void main()
{
	printf("GameBoy Sprite Demo!\n\n");

	SPRITES_8x8;

	//Load 8 8x8 sprites startint at 0
	set_sprite_data(0, 8, leftwalk);

	//Lhead, Lfeet, Rhead, Rfeet of 1st frame
	set_sprite_tile(0, 0);
	set_sprite_tile(1, 1);
	set_sprite_tile(2, 2);
	set_sprite_tile(3, 3);	

	setDefaultSprite();

	SHOW_SPRITES;

	walkLoop();
}

void setDefaultSprite(){
	//Set top left (head)
	move_sprite(0, 75, 75);
	
	//Set bottom left (foot)
	move_sprite(1, 75, 75+8);

	//Set top right (head)
	move_sprite(2, 75+8, 75);

	//Set bottom right (foot)
	move_sprite(3, 75+8, 75+8);


}

void walkLoop(){
	UINT8 key;

	while(1){
		key = joypad();

		if(key == J_LEFT){
			//Set feet as walking feet
			set_sprite_tile(1, 5);
			set_sprite_tile(3, 7);
			delay(240);

			//Set back to default feet
			set_sprite_tile(1, 1);
			set_sprite_tile(3, 3);
			delay(240);
		}

		delay(20);
	}
}
