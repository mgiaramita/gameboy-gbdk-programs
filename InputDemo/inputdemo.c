/*
 * GameBoy input testing demo
 */

#include <gb/gb.h>
#include <stdio.h>

void inputCheck();
void inputDisplayLoop();

void main()
{
	printf("GameBoy Input Demo\n\n");

    inputCheck();

    inputDisplayLoop();
}

void inputCheck(){
	printf("Press Up");
    waitpad(J_UP);
    printf("       -- OK");

    printf("Press Down");
    waitpad(J_DOWN);
    printf("     -- OK");

    printf("Press Left");
    waitpad(J_LEFT);
    printf("     -- OK");

    printf("Press Right");
    waitpad(J_RIGHT);
    printf("    -- OK");

    printf("Press A");
    waitpad(J_A);
    printf("        -- OK");

    printf("Press B");
    waitpad(J_B);
    printf("        -- OK");

    printf("Press Start");
    waitpad(J_START);
    printf("    -- OK");

    printf("Press Select");
    waitpad(J_SELECT);
    printf("   -- OK");

    printf("\n");
}

void inputDisplayLoop(){
	UINT8 key;

	while(1){
    	key = joypad();

    	if(key == J_UP){
    		printf("Input: Up\n");
    	}
    	else if(key == J_DOWN){
    		printf("Input: Down\n");
    	}
    	else if(key == J_LEFT){
    		printf("Input: Left\n");
    	}
    	else if(key == J_RIGHT){
    		printf("Input: Right\n");
    	}
    	else if(key == J_A){
    		printf("Input: A\n");
    	}
    	else if(key == J_B){
    		printf("Input: B\n");
    	}
    	else if(key == J_START){
    		printf("Input: Start\n");
    	}
    	else if(key == J_SELECT){
    		printf("Input: Select\n");
    	}

    	delay(20);
    }
}
