//*****************************************************************************
// main.c
// Author: Michael He
//*****************************************************************************
#include "lab_buttons.h"

#define MOVE_PIXELS   1

// Turn Debuggin off
#undef DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x) do {} while (0)
#endif

#define UP_BUTTON 0x01
#define RIGHT_BUTTON 0x02
#define LEFT_BUTTON 0x03

#define LOCAL_ID     0x43
#define REMOTE_ID    0x44


/******************************************************************************
 * Global Variables
 *****************************************************************************/
	uint16_t mychoice = 0;
	uint16_t mychoiceSave = 0;
	uint16_t rx_data = 0;
//*****************************************************************************
//*****************************************************************************
void print_msg1(){
		ece210_lcd_add_msg("CONTROLS:", TERMINAL_ALIGN_CENTER, LCD_COLOR_GREEN);
		ece210_lcd_add_msg("UP BUTTON: RELOAD", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
		ece210_lcd_add_msg("LEFT BUTTON: SHOOT", TERMINAL_ALIGN_CENTER, LCD_COLOR_BLUE);
		ece210_lcd_add_msg("RIGHT BUTTON: SHIELD", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
		ece210_lcd_add_msg("DOWN BUTTON: DISPLAY SCORE", TERMINAL_ALIGN_CENTER, LCD_COLOR_WHITE);
		ece210_lcd_add_msg("---------------------------------", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
}
//*****************************************************************************
int 
main(void)
{
	char msg[80];
  uint32_t rx_data;
  uint32_t tx_data;
  uint8_t buttons;
  
  ece210_initialize_board();
  ece210_wireless_init(LOCAL_ID,REMOTE_ID);
	
	ece210_lcd_add_msg("Welcome to Medieval Shootout", TERMINAL_ALIGN_CENTER, LCD_COLOR_GREEN);
	uint16_t myScore = 0;
	uint16_t theirScore = 0;
	int ammo = 0;

	
	print_msg1();
	
  		char buffer[15];
		
		
  while(1) {
		
		if (myScore == 3) { 
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("YOU WON!", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			break;
		}
		else if(theirScore == 3) {
						ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			ece210_lcd_add_msg("YOU LOST!", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			break;
		}

		if(AlertButtons)
		 {
      AlertButtons = false;
			if(btn_up_pressed())			// if UP then increase the selected color by
      {					
				mychoice = 1;
			}	
			else if( btn_left_pressed())			// if UP then increase the selected color by
      {	
				mychoice = 2; 
			}
			
			else if( btn_right_pressed())			// if UP then increase the selected color by
      {	
				mychoice = 3; 
			}
			else if(btn_down_pressed()) {
				sprintf(buffer, "Your Score: %d", myScore);
				ece210_lcd_add_msg(buffer, TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
				sprintf(buffer, "Opponent Score: %d", theirScore);
				ece210_lcd_add_msg(buffer, TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
				sprintf(buffer, "Arrows: %d", ammo);
				ece210_lcd_add_msg(buffer, TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
				ece210_lcd_add_msg("---------------------------------", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
	
			}
		}
		 
		if(mychoice != 0) {
			mychoiceSave = mychoice;
			
			if(mychoiceSave == 1) {
				ece210_lcd_add_msg("You Reloaded", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
				ammo++;
			}
			else if(mychoiceSave == 2) {
				if (ammo == 0) {
					ece210_lcd_add_msg("You have no ammo", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
					mychoice = 4; 
					mychoiceSave = 4; 
				}
				else {
				ece210_lcd_add_msg("You Shot", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
				ammo--;
				}
			}
			else{
				ece210_lcd_add_msg("You Shielded", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			}
			
			ece210_wireless_send(mychoice);
			mychoice = 0;
		}
		
		if(ece210_wireless_data_avaiable())
    {
      rx_data = ece210_wireless_get();
			if(rx_data == 1)
      {
				ece210_lcd_add_msg("The opponent reloaded", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			}
			else if(rx_data == 2)
      {
				ece210_lcd_add_msg("The opponent shot", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			}
			else if(rx_data == 4)
      {
				ece210_lcd_add_msg("The opponent tried to shoot without ammo", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			}
			else {
      {
				ece210_lcd_add_msg("The opponent shielded", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
			}
		}
		
		if(rx_data != 0 && mychoiceSave != 0) {
			if(rx_data == 1 && mychoiceSave == 1) {
				ece210_lcd_add_msg("Both of you reloaded", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			else if(rx_data == 1 && mychoiceSave == 2) {
				ece210_lcd_add_msg("You killed your opponent", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
				myScore++;
			}
			else if(rx_data == 1 && mychoiceSave == 3) {
				ece210_lcd_add_msg("no shots were taken", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			else if(rx_data == 2 && mychoiceSave == 1) {
				ece210_lcd_add_msg("Your opponent killed you", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
				theirScore++;
			}
			else if(rx_data == 2 && mychoiceSave == 2) {
				ece210_lcd_add_msg("Draw! You killed each other", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
				if (myScore > 0) { myScore--; }
				if (theirScore > 0) { theirScore--; }
			}
			else if(rx_data == 2 && mychoiceSave == 3) {
				ece210_lcd_add_msg("You blocked your opponent's shot", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			else if(rx_data == 3 && mychoiceSave == 1) {
				ece210_lcd_add_msg("no shots were taken", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			else if(rx_data == 3 && mychoiceSave == 2) {
				ece210_lcd_add_msg("Your opponent blocked your shot", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			else if(rx_data == 3 && mychoiceSave == 3) {
				ece210_lcd_add_msg("no shots were taken", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			
			else if(rx_data == 1 && mychoiceSave == 4) {
				ece210_lcd_add_msg("no shots were taken", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			else if(rx_data == 2 && mychoiceSave == 4) {
				ece210_lcd_add_msg("Your opponent killed you", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
				theirScore++;
			}
			else if(rx_data == 3 && mychoiceSave == 4) {
				ece210_lcd_add_msg("no shots were taken", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			else if(rx_data == 4 && mychoiceSave == 1) {
				ece210_lcd_add_msg("no shots were taken", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			else if(rx_data == 4 && mychoiceSave == 2) {
				ece210_lcd_add_msg("you killed your opponent", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
				myScore++;
			}
			else if(rx_data == 4 && mychoiceSave == 3) {
				ece210_lcd_add_msg("no shots were taken", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			else if(rx_data == 4 && mychoiceSave == 4) {
				ece210_lcd_add_msg("no shots were taken", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);
			}
			ece210_lcd_add_msg("---------------------------------", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
		}
			rx_data = 0;
				mychoiceSave = 0;
		
	}
}
	}

