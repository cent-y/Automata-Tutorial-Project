#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>

char nav = 'I';
char menuchoice = ' ';
void PrintAssistant(int x_cord, int y_cord, int pos, int wave);
void ClearAssistant(int x_cord, int y_cord);
void AssistantDialogBorder(int x_cord, int y_cord, int length, int height);
void DFAFirstExample();
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//black = 0, blue = 1, green = 2, cyan = 3, red = 4, magenta = 5
//brown = 6, lightgray = 7, darkgray = 8, lightblue = 9, lightgreen = 10
//lightcyan = 11, lightred = 12, lightmagenta = 13, yellow = 14, white = 15
void textcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ExitProgram()
{
	system("cls");
	char exitstr[23] = "Thank you! Come again.";
	
	PrintAssistant(28,9,2,0);
	AssistantDialogBorder(35,10,30,6);
	
	gotoxy(37,13); printf("Exiting program");
	for(int i = 0; i < 3; i++)
	{ 
		gotoxy(52,13); textcolor(0);  printf("...");
		gotoxy(52,13); textcolor(15); printf("."); Sleep(400); printf("."); Sleep(400); printf("."); Sleep(400); 
	}
	
	for(int i = 0; i < 23; i++){ gotoxy(37+i,14); printf("%c",exitstr[i]); Sleep(8); }
	gotoxy(1,26); exit(0);
}

void NavigationMenu(char ch)
{
	gotoxy(3,2);
	textcolor(11); printf("["); textcolor(15); printf("M"); textcolor(11); printf("]");
	textcolor(15); printf("ENU");
	
	if(toupper(ch) == 'M')
	{
		char strmenu1[33] = "ACKGROUND ON THEORY OF COMPUTING";
		char strmenu2[13] = "ERMINOLOGIES";
		char strmenu3[29] = "ETERMINISTIC FINITE AUTOMATA";
		char strmenu4[33] = "ON-DETERMINISTIC FINITE AUTOMATA";
		char strmenu5[10] = "SSESSMENT";
		char strmenu6[14] = "EFERENCE PAGE";
		char strmenu7[6]  = "ANCEL";
		char strmenu8[4]  = "XIT";
		
		gotoxy(3,3);
		textcolor(11); printf(">"); Sleep(3); printf("> "); Sleep(3);
		printf("["); Sleep(3); textcolor(15); printf("B"); Sleep(3); textcolor(11); printf("]"); Sleep(3); textcolor(15);
		for(int i = 0; i < 12; i++){ printf("%c", strmenu1[i]); Sleep(3); }
		gotoxy(5,4); for(int i = 0; i < 10; i++){ printf("%c", strmenu1[12+i]); Sleep(3); }  
		gotoxy(5,5); for(int i = 0; i < 10; i++){ printf("%c", strmenu1[22+i]); Sleep(3); } //THEORY OF COMPUTING PRINT 
		
		gotoxy(3,6);
		textcolor(11); printf(">"); Sleep(3); printf("> "); Sleep(3);
		textcolor(11); printf("["); Sleep(3); textcolor(15); printf("T"); Sleep(3); textcolor(11); printf("]"); Sleep(3); textcolor(15);
		for(int i = 0; i < 13; i++){ printf("%c", strmenu2[i]); Sleep(3); } //TERMINILOGIES PRINT
		
		gotoxy(3,7);
		textcolor(11); printf(">"); Sleep(3); printf("> "); Sleep(3);
		textcolor(11); printf("["); Sleep(3); textcolor(15); printf("D"); Sleep(3); textcolor(11); printf("]"); Sleep(3); textcolor(15);
		for(int i = 0; i < 13; i++){ printf("%c", strmenu3[i]); Sleep(3); }  
		gotoxy(5,8); for(int i = 0; i < 17; i++){ printf("%c", strmenu3[12+i]); Sleep(3); } //DFA PRINT
		
		gotoxy(3,9);
		textcolor(11); printf(">"); Sleep(3); printf("> "); Sleep(3);
		textcolor(11); printf("["); Sleep(3); textcolor(15); printf("N"); Sleep(3); textcolor(11); printf("]"); Sleep(3); textcolor(15);
		for(int i = 0; i < 16; i++){ printf("%c", strmenu4[i]); Sleep(3); }  
		gotoxy(5,10); for(int i = 0; i < 16; i++){ printf("%c", strmenu4[16+i]); Sleep(3); } //NFA PRINT
		
		gotoxy(3,11);
		textcolor(10); printf(">"); Sleep(3); printf("> "); Sleep(3);
		textcolor(10); printf("["); Sleep(3); textcolor(15); printf("A"); Sleep(3); textcolor(10); printf("]"); Sleep(3); textcolor(15);
		for(int i = 0; i < 9; i++){ printf("%c", strmenu5[i]); Sleep(3); }  //ASSESSMENT PRINT
		
		gotoxy(3,12);
		textcolor(10); printf(">"); Sleep(3); printf("> "); Sleep(3);
		textcolor(10); printf("["); Sleep(3); textcolor(15); printf("R"); Sleep(3); textcolor(10); printf("]"); Sleep(3); textcolor(15);
		for(int i = 0; i < 13; i++){ printf("%c", strmenu6[i]); Sleep(3); }  //REFERENCE PAGE PRINT
		
		gotoxy(3,13);
		textcolor(12); printf(">"); Sleep(3); printf("> "); Sleep(3);
		textcolor(11); textcolor(12); printf("["); Sleep(3); textcolor(15); printf("C"); Sleep(3); textcolor(12); printf("]"); Sleep(3); textcolor(15); 
		for(int i = 0; i < 6; i++){ printf("%c", strmenu7[i]); Sleep(3); }  //CANCEL PRINT
				
		gotoxy(3,14);
		textcolor(12); printf(">"); Sleep(3); printf("> "); Sleep(3);
		textcolor(12); printf("["); Sleep(3); textcolor(15); printf("E"); Sleep(3); textcolor(12); printf("]"); Sleep(3);
		textcolor(15); for(int i = 0; i < 4; i++){ printf("%c", strmenu8[i]); Sleep(3); } //EXIT PRINT
		
		do
		{
			menuchoice = getch(); fflush(stdin);
			if(toupper(menuchoice) == 'D' || toupper(menuchoice) == 'N' || toupper(menuchoice) == 'B' || toupper(menuchoice) == 'T' ||
		       toupper(menuchoice) == 'A' || toupper(menuchoice) == 'R' || toupper(menuchoice) == 'C' || toupper(menuchoice) == 'E')
			{
				switch(toupper(menuchoice))
				{
					case 'B': case 'T': case 'D': case 'N': case 'A': case 'R': nav = menuchoice; break;
					case 'C': for(int i = 0; i < 12; i++)
						  	  {
						  		for(int j = 0; j < 22; j++)
						  		{
						  			gotoxy(24-j,14-i); printf(" "); Sleep(1);
								}
						  	  }	 
						  	  break;
					case 'E': ExitProgram();
				}
			}
		}while(toupper(menuchoice) != 'D' && toupper(menuchoice) != 'N' && toupper(menuchoice) != 'B' && toupper(menuchoice) != 'T' &&
		       toupper(menuchoice) != 'A' && toupper(menuchoice) != 'R' && toupper(menuchoice) != 'C' && toupper(menuchoice) != 'E');
		
	}
}

//pos = 1 left arm up, pos = 2 right arm up, pos = 3 wtf, pos = 4 point right arm up, pos = 5 point left arm up
void PrintAssistant(int x_cord, int y_cord, int pos, int wave) 
{
	textcolor(15);
	
	gotoxy(x_cord,y_cord);   printf(" ___");
	gotoxy(x_cord,y_cord+1); printf("/   \\");
	gotoxy(x_cord,y_cord+2); printf("\\___/");
	gotoxy(x_cord,y_cord+3); printf(" _|_");
	gotoxy(x_cord,y_cord+4); printf("/ | \\");
	gotoxy(x_cord,y_cord+5); printf(" / \\");
	if(wave == 1) Sleep(350);
	
	if(pos == 1)
	{
		ClearAssistant(x_cord,y_cord);
		gotoxy(x_cord,y_cord);   printf(" ___");
		gotoxy(x_cord,y_cord+1); printf("/   \\");
		gotoxy(x_cord,y_cord+2); printf("\\___/");
		gotoxy(x_cord,y_cord+3); printf("\\_|_");
		gotoxy(x_cord,y_cord+4); printf("  | \\");
		gotoxy(x_cord,y_cord+5); printf(" / \\ ");
		if(wave == 1) Sleep(350);
	}
	
	else if(pos == 2)
	{
		ClearAssistant(x_cord,y_cord);
		gotoxy(x_cord,y_cord);   printf(" ___");
		gotoxy(x_cord,y_cord+1); printf("/   \\");
		gotoxy(x_cord,y_cord+2); printf("\\___/");
		gotoxy(x_cord,y_cord+3); printf(" _|_/");
		gotoxy(x_cord,y_cord+4); printf("/ |  ");
		gotoxy(x_cord,y_cord+5); printf(" / \\ ");
		if(wave == 1) Sleep(350);
	}
	
	else if(pos == 3)
	{
		ClearAssistant(x_cord,y_cord);
		gotoxy(x_cord,y_cord);   printf("  ___");
		gotoxy(x_cord,y_cord+1); printf(" /   \\");
		gotoxy(x_cord,y_cord+2); printf("_\\___/_");
		gotoxy(x_cord,y_cord+3); printf(" \\_|_/");
		gotoxy(x_cord,y_cord+4); printf("   |");
		gotoxy(x_cord,y_cord+5); printf("  / \\");
		if(wave == 1) Sleep(350);
	}
	
	else if(pos == 4)
	{
		ClearAssistant(x_cord,y_cord);
		gotoxy(x_cord,y_cord);   printf(" ___");
		gotoxy(x_cord,y_cord+1); printf("/   \\");
		gotoxy(x_cord,y_cord+2); printf("\\___/_");
		gotoxy(x_cord,y_cord+3); printf(" _|_/");
		gotoxy(x_cord,y_cord+4); printf("/ |");
		gotoxy(x_cord,y_cord+5); printf(" / \\");
		if(wave == 1) Sleep(350);
	}
	
	else if(pos == 5)
	{
		ClearAssistant(x_cord,y_cord);
		gotoxy(x_cord,y_cord);   printf("  ___");
		gotoxy(x_cord,y_cord+1); printf(" /   \\");
		gotoxy(x_cord,y_cord+2); printf("_\\___/");
		gotoxy(x_cord,y_cord+3); printf(" \\_|_");
		gotoxy(x_cord,y_cord+4); printf("   | \\");
		gotoxy(x_cord,y_cord+5); printf("  / \\");
		if(wave == 1) Sleep(350);
	}
}

void ClearAssistant(int x_cord, int y_cord)
{
	gotoxy(x_cord,y_cord);   printf("    ");
	gotoxy(x_cord,y_cord+1); printf("        ");
	gotoxy(x_cord,y_cord+2); printf("        ");
	gotoxy(x_cord,y_cord+3); printf("        ");
	gotoxy(x_cord,y_cord+4); printf("        ");
	gotoxy(x_cord,y_cord+5); printf("        ");
}

void PrintState(int x_cord, int y_cord, char state_char, int final_flag, int color/*, int direction, int loop*/)
{
	textcolor(15);
	if(color == 1) textcolor(10);
	if(color == 2) textcolor(12);
	gotoxy(x_cord,y_cord); printf("%c%c%c%c%c",218,196,196,196,191);
	gotoxy(x_cord,y_cord+1); printf("%c %c %c",179,state_char,179);
	gotoxy(x_cord,y_cord+2); printf("%c%c%c%c%c",192,196,196,196,217);
	
	if(final_flag == 1)
	{
		gotoxy(x_cord-2,y_cord-1); printf("%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,191);
		gotoxy(x_cord-2,y_cord); printf("%c",179); gotoxy(x_cord+6,y_cord); printf("%c",179);
		gotoxy(x_cord-2,y_cord+1); printf("%c",179); gotoxy(x_cord+6,y_cord+1); printf("%c",179);
		gotoxy(x_cord-2,y_cord+2); printf("%c",179); gotoxy(x_cord+6,y_cord+2); printf("%c",179);
		gotoxy(x_cord-2,y_cord+3); printf("%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,217);
	}
	
	/*do
	{
	textcolor(11);
	if(direction == 1) //arrow pointing right
	{
		gotoxy(x_cord+5,y_cord+1); printf("%c%c%c>",196,196,196);
	}
	
	else if(direction == 3 && loop == 1) //loop up
	{
		for(int i = 0; i < 2; i++){ gotoxy(x_cord,y_cord-1-i); printf("%c",179); }
		gotoxy(x_cord,y_cord-3); printf("%c%c%c%c%c",218,196,196,196,191);
		gotoxy(x_cord+4,y_cord-2); printf("%c",179);
		gotoxy(x_cord+4,y_cord-1); printf("v");
	}
	
	else if(direction == 2) //arrow pointing down
	{
		for(int i = 0; i < 3; i++){ gotoxy(x_cord+2,y_cord+3+i); printf("%c",179); }
		gotoxy(x_cord+2,y_cord+6); printf("v");
	}
	
	else if(direction == 3) //arrow pointing up
	{
		for(int i = 0; i < 3; i++){ gotoxy(x_cord+2,y_cord-1-i); printf("%c",179); }
		gotoxy(x_cord+2,y_cord-4); printf("^");
	}
	
	else if(direction == 4) //arrow pointing up and down
	{
		for(int i = 0; i < 3; i++){ gotoxy(x_cord+2,y_cord+3+i); printf("%c",179); gotoxy(x_cord+2,y_cord-1-i); printf("%c",179); }
		gotoxy(x_cord+2,y_cord+6); printf("v");
		gotoxy(x_cord+2,y_cord-4); printf("^");
	}
	
	else if(direction == 5) //arrow pointing right and down
	{
		gotoxy(x_cord+5,y_cord+1); printf("%c%c%c>",196,196,196);
		for(int i = 0; i < 3; i++){ gotoxy(x_cord+2,y_cord+3+i); printf("%c",179); }
		gotoxy(x_cord+2,y_cord+6); printf("v");
	}
	
	if(final_flag == 0 && loop == 1) //loop right
	{
		gotoxy(x_cord+5,y_cord); printf("%c%c%c%c",196,196,196,191);
		gotoxy(x_cord+8,y_cord+1); printf("%c",179);
		gotoxy(x_cord+5,y_cord+2); printf("<%c%c%c",196,196,217);
	}
	
	else if(final_flag == 1 && loop == 1) //loop going right
	{
		gotoxy(x_cord+7,y_cord); printf("%c%c%c%c",196,196,196,191);
		gotoxy(x_cord+10,y_cord+1); printf("%c",179);
		gotoxy(x_cord+7,y_cord+2); printf("<%c%c%c",196,196,217);
	}
}while(0);
*/
}

void ClearState(int x_cord, int y_cord, int final_flag)
{
	gotoxy(x_cord,y_cord);   printf("     ");
	gotoxy(x_cord,y_cord+1); printf("     ");
	gotoxy(x_cord,y_cord+2); printf("     ");
	
	if(final_flag == 1)
	{
		gotoxy(x_cord-2,y_cord-1); printf("         ");
		gotoxy(x_cord-2,y_cord);   printf("         "); 
		gotoxy(x_cord-2,y_cord+1); printf("         "); 
		gotoxy(x_cord-2,y_cord+2); printf("         "); 
		gotoxy(x_cord-2,y_cord+3); printf("         ");
	}
}

void ArrowUp(int x, int y)
{
	for(int i = 0; i < 2; i++){ gotoxy(x,y-i); printf("%c",179); }
	gotoxy(x,y-2); printf("^");
}

void ArrowRight(int x, int y)
{
	gotoxy(x,y); printf("%c%c%c>",196,196,196);
}

void ArrowDown(int x, int y)
{
	for(int i = 0; i < 2; i++){ gotoxy(x,y+i); printf("%c",179); }
	gotoxy(x,y+2); printf("v");
}

void ArrowLoopUp(int x, int y)
{
	for(int i = 0; i < 2; i++){ gotoxy(x,y-i); printf("%c",179); }
	gotoxy(x,y-2); printf("%c%c%c%c%c",218,196,196,196,191);
	gotoxy(x+4,y-1); printf("%c",179);
	gotoxy(x+4,y); printf("v");
}

void ArrowLoopRight(int x, int y)
{
	gotoxy(x,y); printf("%c%c%c%c",196,196,196,191);
	gotoxy(x+3,y+1); printf("%c",179);
	gotoxy(x,y+2); printf("<%c%c%c",196,196,217);
}

void ArrowLoopDown(int x, int y)
{
	gotoxy(x,y); printf("^");
	gotoxy(x,y+1); printf("%c",179);
	gotoxy(x,y+2); printf("%c%c%c%c%c",192,196,196,196,217);
	gotoxy(x+4,y+1); printf("%c",179);
	gotoxy(x+4,y); printf("%c",179);
}

void ArrowLoopLeft(int x, int y)
{
	gotoxy(x-3,y);   printf("%c%c%c%c",192,196,196,196);
	gotoxy(x-3,y-1); printf("%c",179);
	gotoxy(x-3,y-2); printf("%c%c%c>",218,196,196,196);
}

void AnimatedTitleScreen()
{
	system("cls");
	textcolor(119);
	int bspeed = 6, tspeed = 2;
	gotoxy(0,0); printf("%c",201); Sleep(bspeed);
	for(int i = 0; i < 98; i++) { gotoxy(1+i,0); printf("%c",205); Sleep(bspeed);}
	gotoxy(99,0); printf("%c",187); Sleep(bspeed);
	for(int i = 0; i < 28; i++) { gotoxy(98,1+i); printf("%c%c",186,186); Sleep(bspeed); }
	gotoxy(99,29); printf("%c",188); Sleep(bspeed);
	for(int i = 0; i < 98; i++) { gotoxy(98-i,29); printf("%c",205); Sleep(bspeed); }
	gotoxy(0,29); printf("%c%c",200); Sleep(bspeed);
	for(int i = 0; i < 28; i++) { gotoxy(0,28-i); printf("%c%c",186,186); Sleep(bspeed); }
	
	char first[60]      = "  ______ _       _ _            _____ _        _       ";
	char second[60]     = " |  ____(_)     (_) |          / ____| |      | |      ";
	char third[60]      = " | |__   _ _ __  _| |_ ___    | (___ | |_ __ _| |_ ___ ";
	char fourth[60]     = " |  __| | | '_ \\| | __/ _ \\    \\___ \\| __/ _` | __/ _ \\";
	char fifth[60]      = " | |    | | | | | | ||  __/    ____) | || (_| | ||  __/";
	char sixth[60]      = " |_|    |_|_| |_|_|\\__\\___|   |_____/ \\__\\__,_|\\__\\___|";
	char seventh[55]    = "                _                        _        ";
	char eighth[55]     = "     /\\        | |                      | |       ";
	char ninth[55]      = "    /  \\  _   _| |_ ___  _ __ ___   __ _| |_ __ _ ";
	char tenth[55]      = "   / /\\ \\| | | | __/ _ \\| '_ ` _ \\ / _` | __/ _` |";
	char eleventh[55]   = "  / ____ \\ |_| | || (_) | | | | | | (_| | || (_| |";
	char twelfth[55]    = " /_/    \\_\\__,_|\\__\\___/|_| |_| |_|\\__,_|\\__\\__,_|";
	char thirteenth[75] = "A BASIC TUTORIAL ON DETERMINISTIC AND NON-DETERMINISTIC FINITE AUTOMATA";
	
	textcolor(11);
	gotoxy(23,3); for(int i = 0; i < 60; i++){ printf("%c",first[i]);  Sleep(tspeed); }
	gotoxy(23,4); for(int i = 0; i < 60; i++){ printf("%c",second[i]); Sleep(tspeed); }
	gotoxy(23,5); for(int i = 0; i < 60; i++){ printf("%c",third[i]);  Sleep(tspeed); }
	gotoxy(23,6); for(int i = 0; i < 60; i++){ printf("%c",fourth[i]); Sleep(tspeed); }
	gotoxy(23,7); for(int i = 0; i < 60; i++){ printf("%c",fifth[i]);  Sleep(tspeed); }
	gotoxy(23,8); for(int i = 0; i < 60; i++){ printf("%c",sixth[i]);  Sleep(tspeed); }
	
	gotoxy(26,10); for(int i = 0; i < 55; i++){ printf("%c",seventh[i]);  Sleep(tspeed); }
	gotoxy(26,11); for(int i = 0; i < 55; i++){ printf("%c",eighth[i]);   Sleep(tspeed); }
	gotoxy(26,12); for(int i = 0; i < 55; i++){ printf("%c",ninth[i]);    Sleep(tspeed); }
	gotoxy(26,13); for(int i = 0; i < 55; i++){ printf("%c",tenth[i]);    Sleep(tspeed); }
	gotoxy(26,14); for(int i = 0; i < 55; i++){ printf("%c",eleventh[i]); Sleep(tspeed); }
	gotoxy(26,15); for(int i = 0; i < 55; i++){ printf("%c",twelfth[i]);  Sleep(tspeed); }
	
	textcolor(15);
	gotoxy(17,18); for(int i = 0; i < 75; i++){ printf("%c",thirteenth[i]); Sleep(tspeed+7); }
	nav = 'H';
}

void AssistantIntroDialogBorder()
{
	int x = 20, y = 15;
	textcolor(11);
	for(int i = 0; i < 60; i++){ gotoxy(x+i,y); printf("%c",205); }
	gotoxy(x+9,y); printf("%c",203);
	gotoxy(x-1,y); printf("%c",201); gotoxy(x+60,y); printf("%c",187);
	gotoxy(x-1,y+1); printf("%c         %c                                                  %c",186,186,186);
	gotoxy(x-1,y+2); printf("%c                                                            %c",204,186);
	gotoxy(x-1,y+2); printf("%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,188);
	gotoxy(x-1,y+3); printf("%c                                                            %c",186,186);
	gotoxy(x-1,y+4); printf("%c                                                            %c",186,186);
	gotoxy(x-1,y+5); printf("%c                                                            %c",186,186);
	for(int i = 0; i < 60; i++){ gotoxy(x+i,y+6); printf("%c",205); }
	gotoxy(x-1,y+6); printf("%c",200); gotoxy(x+60,y+6); printf("%c",188);
	textcolor(15);
	gotoxy(x+19,y+7); printf("Press enter to continue");
}

void AssistantDialogBorder(int x_cord, int y_cord, int length, int height) //height = 5 1 line only for text (adjust accordingly)
{
	textcolor(11);
	gotoxy(x_cord,y_cord); printf("%c",201);
	for(int i = 0; i < length-2; i++){ gotoxy(x_cord+i+1,y_cord); printf("%c",205); }
	gotoxy(x_cord+length-1,y_cord); printf("%c",187);
	for(int i = 0; i < height-2; i++){ gotoxy(x_cord,y_cord+i+1); printf("%c",186); gotoxy(x_cord+length-1,y_cord+i+1); printf("%c",186); }
	gotoxy(x_cord,y_cord+height-1); printf("%c",200);
	for(int i = 0; i < length-2; i++){ gotoxy(x_cord+i+1,y_cord+height-1); printf("%c",205); }
	gotoxy(x_cord+length-1,y_cord+height-1); printf("%c",188);
	
	gotoxy(x_cord,y_cord+2); printf("%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,188);
	gotoxy(x_cord+10,y_cord); printf("%c",203); gotoxy(x_cord+10,y_cord+1); printf("%c",186);
	
	textcolor(15); gotoxy(x_cord+2,y_cord+1); printf("RAYMUND");
}

void ClearDialogBorder(int x_cord, int y_cord, int length, int height)
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < length; j++)
		{
		 	gotoxy(x_cord+j,y_cord+i); printf(" ");
		}
	}
}

void AssistantIntro()
{
	int ctr = 0; char ch = ' ';

	do
	{
		switch(ctr)
		{
			case 0: 
					do
					{
						while(!kbhit())
						{ 
							AssistantIntroDialogBorder();
							gotoxy(21,16); printf("  ???");
							gotoxy(21,18); printf("Hello there! Allow me to introduce myself. My name is");
							gotoxy(21,19); printf("Raymund and I will be your virtual assistant for learning");
							gotoxy(21,20); printf("deterministic and non-deterministic finite automata...");
							PrintAssistant(48,7,1,1);
						} 
						ch = getch();
					}while(int(ch) != 13); break;	
					
			case 1: 
					do
					{
						while(!kbhit())
						{ 
							AssistantIntroDialogBorder();
							gotoxy(21,16); printf("RAYMUND");
							gotoxy(21,18); printf("This program was created under the assumption that you, the");
							gotoxy(21,19); printf("user, already has basic knowledge on Discrete Structures");
							gotoxy(21,20); printf("and computer programming...");
							PrintAssistant(48,7,1,1);
						}
						ch = getch();
					}while(int(ch) != 13); break;	
			
			case 2: 
					do
					{
						while(!kbhit())
						{  
							AssistantIntroDialogBorder();
							gotoxy(21,16); printf("RAYMUND");
							gotoxy(21,18); printf("In the case that I fail to clarify misconceptions that");
							gotoxy(21,19); printf("might arise, please feel free to contact my creators and do");
							gotoxy(21,20); printf("not hesitate to search on the web...");
							PrintAssistant(48,7,1,1);
						}
						ch = getch();
					}while(int(ch) != 13); break;
					
			case 3: 
					do
					{
						while(!kbhit())
						{  
							AssistantIntroDialogBorder();
							gotoxy(21,16); printf("RAYMUND");
							gotoxy(21,18); printf("Simply press enter to progress through the program. But do");
							gotoxy(21,19); printf("note that the menu will be available anytime at the title");
							gotoxy(21,20); printf("screen for you to be able to navigate through the program..");
							PrintAssistant(48,7,1,1);
						}
						ch = getch();
					}while(int(ch) != 13); break;		
			
			case 4: 
					do
					{
						while(!kbhit())
						{  
							AssistantIntroDialogBorder();
							gotoxy(21,16); printf("RAYMUND");
							gotoxy(21,18); printf("To be able to navigate, press the corresponding letter");
							gotoxy(21,19); printf("inside the bracket [ ]...");
							PrintAssistant(48,7,1,1);
						}
						ch = getch();
					}while(int(ch) != 13); break;
					
			case 5: 
					do
					{
						while(!kbhit())
						{  
							AssistantIntroDialogBorder();
							gotoxy(21,16); printf("RAYMUND");
							gotoxy(21,18); printf("Additionally, please do not resize the screen as this");
							gotoxy(21,19); printf("action will cause the program to be disoriented. You would");
							gotoxy(21,20); printf("need to restart it to fix the orientation...");
							PrintAssistant(48,7,1,1);
						}
						ch = getch();
					}while(int(ch) != 13); break;		
			
			case 6: 
					do
					{
						while(!kbhit())
						{  
							AssistantIntroDialogBorder();
							gotoxy(21,16); printf("RAYMUND");
							gotoxy(21,18); printf("Alright! I believe we can start with the tutorial. Please");
							gotoxy(21,19); printf("press enter on the keyboard to begin...");
							gotoxy(39,22); printf("                       ");
							PrintAssistant(48,7,1,1);
						}
						ch = getch();
					}while(int(ch) != 13); break;
		}
		ctr++;
	}while(ctr != 7);
	AnimatedTitleScreen();
}

void SetBorder()
{ 
	textcolor(14);
	system("cls");
	//printf("lol wat bakit kapag may ganito gumagana");
	textcolor(119);
	gotoxy(0,0); printf("%c",201); 
	for(int i = 0; i < 98; i++) { gotoxy(1+i,0); printf("%c",205); }
	gotoxy(99,0); printf("%c",187);
	for(int i = 0; i < 28; i++) { gotoxy(98,1+i); printf("%c%c",186,186); }
	gotoxy(99,30); printf("%c",188); 
	for(int i = 0; i < 98; i++) { gotoxy(2+i,30); printf("%c",205);  }
	gotoxy(0,30); printf("%c",200); 
	for(int i = 0; i < 28; i++) { gotoxy(0,1+i); printf("%c%c",186,186);  }
}

void Finite(int x_cord, int y_cord)
{ 
	gotoxy(x_cord, y_cord);   printf("  ______ _       _ _       ");
	gotoxy(x_cord, y_cord+1); printf(" |  ____(_)     (_) |      ");
	gotoxy(x_cord, y_cord+2); printf(" | |__   _ _ __  _| |_ ___ ");
	gotoxy(x_cord, y_cord+3); printf(" |  __| | | '_ \\| | __/ _ \\");
	gotoxy(x_cord, y_cord+4); printf(" | |    | | | | | | ||  __/");
	gotoxy(x_cord, y_cord+5); printf(" |_|    |_|_| |_|_|\\__\\___|");
}

void State(int x_cord, int y_cord)
{
	gotoxy(x_cord, y_cord);   printf("   _____ _        _       ");
	gotoxy(x_cord, y_cord+1); printf("  / ____| |      | |      ");
	gotoxy(x_cord, y_cord+2); printf(" | (___ | |_ __ _| |_ ___ ");
	gotoxy(x_cord, y_cord+3); printf("  \\___ \\| __/ _` | __/ _ \\");
	gotoxy(x_cord, y_cord+4); printf("  ____) | || (_| | ||  __/");
	gotoxy(x_cord, y_cord+5); printf(" |_____/ \\__\\__,_|\\__\\___|");
}

void Automata(int x_cord, int y_cord)
{
	gotoxy(x_cord, y_cord);   printf("                _                        _        ");
	gotoxy(x_cord, y_cord+1); printf("     /\\        | |                      | |       ");
	gotoxy(x_cord, y_cord+2); printf("    /  \\  _   _| |_ ___  _ __ ___   __ _| |_ __ _ ");
	gotoxy(x_cord, y_cord+3); printf("   / /\\ \\| | | | __/ _ \\| '_ ` _ \\ / _` | __/ _` |");
	gotoxy(x_cord, y_cord+4); printf("  / ____ \\ |_| | || (_) | | | | | | (_| | || (_| |");
	gotoxy(x_cord, y_cord+5); printf(" /_/    \\_\\__,_|\\__\\___/|_| |_| |_|\\__,_|\\__\\__,_|");
}

void HomeScreen()
{
	char ch = ' ';
	do
	{
		system("cls");
	
		SetBorder();
		
		textcolor(11);
		Finite(24,3);
		State(53,3);
		Automata(26,10);
		
		textcolor(15);
		gotoxy(17,18); printf("A BASIC TUTORIAL ON DETERMINISTIC AND NON-DETERMINISTIC FINITE AUTOMATA");
		gotoxy(47,21); printf("CREATED BY");
		gotoxy(28,23); printf("Caro, Vincent Gerard B. & Reyes, Carl Lorenz V.");
		gotoxy(48,24); printf("BSCS 2-2");
		
		PrintAssistant(79,10,0,0);
		NavigationMenu(ch);
		if(toupper(nav) == 'D' || toupper(nav) == 'N' || toupper(nav) == 'B' || toupper(nav) == 'T' || toupper(nav) == 'A' || toupper(nav) == 'R') break;
		if(toupper(nav) != 'D' || toupper(nav) != 'N' || toupper(nav) != 'B' || toupper(nav) != 'T' || toupper(nav) != 'A' || toupper(nav) != 'R') ch = getch();
		if(int(ch) == 13) nav = 'B';
	}while(int(ch) != 13); 
	if(int(ch) == 13) nav = 'B';
}

void TheoryOfComputingBackground() //1st lesson
{
	char ch = ' ';
	do
	{
		system("cls");
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("AUTOMATA THEORY");
		
		gotoxy(3,4);   printf("The Automata Theory ");         textcolor(11); printf("(");
		textcolor(15); printf("or The Theory of Computation"); textcolor(11); printf(") ");
		textcolor(15); printf("deals with automatons' ");      textcolor(11); printf("(");
		textcolor(15); printf("machines'");					   textcolor(11); printf(") ");
		textcolor(15); printf("logical");
		
		gotoxy(3,5);   printf("process. Through automata, computer scientists were able to understand how machines solve"); 
		gotoxy(3,6);   printf("problems, compute functions, and determine whether a function is computable ");
		textcolor(11); printf("("); textcolor(15); printf("equations"); textcolor(11); printf(") ");
		textcolor(15); printf("or"); 
		gotoxy(3,7);   printf("decidable "); textcolor(11); printf("("); textcolor(15); printf("conditions"); textcolor(11); printf(") ");
		printf("("); textcolor(15); printf("Dar Aziz, Cackler, & Yung, 2004"); textcolor(11); printf(")"); textcolor(15); printf("."); //end 1st paragraph print

		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		PrintAssistant(5,9,3,0);
		AssistantDialogBorder(15,10,29,5);
		gotoxy(17,13); printf("But what is an automaton?"); //end raymund print
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		textcolor(11); gotoxy(3,17); printf("%c ",178);
		textcolor(15); printf("AUTOMATON"); 
		
		gotoxy(3,19);  printf("Merriam-Webster Dictionary "); textcolor(11); printf("(");
		textcolor(15); printf("2019");						  textcolor(11); printf(") ");
		textcolor(15); printf("defines automaton as ");		  textcolor(11); printf("\"");
		textcolor(15); printf("a machine or control mechanism ");
		gotoxy(3,20);  printf("designed to follow automatically a predetermined sequence of operations or respond to ");
		gotoxy(3,21);  printf("encoded instructions.");       textcolor(11); printf("\" ");
		textcolor(15); printf("A common word to this would be robot. An automaton is a machine that ");
		gotoxy(3,22);  printf("brings an input and processes it through a series of steps and conditions. ");
		gotoxy(3,23);  printf("A transition-function determines whether which step is to be taken by the ");
		gotoxy(3,24);  printf("machine. The machine accepts the input once it transitions to the accepting state."); //end 2nd paragraph print
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		textcolor(11);
		gotoxy(58,12); printf("%c%c%c%c%c>",196,196,196,196,196);
		gotoxy(64,11); printf("%c%c%c%c%c%c%c%c%c%c%c%c>",218,196,196,196,196,196,196,196,191,218,196,196);
		gotoxy(64,12); printf("%c       %c%c",179,195,180);
		gotoxy(64,13); printf("%c%c%c%c%c%c%c%c%c%c%c%c>",192,196,196,196,196,196,196,196,217,192,196,196);
		gotoxy(59,14); printf("%c ",178);
		textcolor(15);
		gotoxy(66,12); printf("THINK"); gotoxy(77,11); printf("YES"); gotoxy(77,13); printf("NO"); gotoxy(61,14); printf("Automaton Diagram"); //end diagram print
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
	}while(int(ch) != 13 && toupper(nav) != 'H'); 
	if(int(ch) == 13) nav = 'T';
}

void DefineAlphabet()
{
	char ch = ' ';
	
	do
	{
		gotoxy(3,20); textcolor(11); printf("%c ",254); textcolor(15); printf("Alphabet");
		char stralphabet1[60] = "An Alphabet is a collection of Symbols. It is denoted by a";
		char stralphabet2[10] = " (sigma).";
		char stralphabet3[39] = "e.g. {1,b} , {r,a,c,l} , {0,1,9,a,z,d}";
		
		PrintAssistant(8,21,4,0);
		AssistantDialogBorder(17,22,43,6);
		
		for(int i = 0; i < 39; i++)
		{
			gotoxy(19+i,25); printf("%c",stralphabet1[i]); Sleep(8);
		}
		
		for(int i = 0; i < 18; i++)
		{
			gotoxy(19+i,26); printf("%c",stralphabet1[40+i]); Sleep(8);
		}
		
		printf(" %c",228); Sleep(8);
		
		for(int i = 0; i < 9; i++)
		{
			gotoxy(40+i,26); printf("%c",stralphabet2[1+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		for(int i = 0; i < 2; i++) //clear box
		{
			for(int j = 0; j < 39; j++)
			{
				gotoxy(19+j,25+i); printf(" ");
			}
		}
		
		for(int i = 0; i < 38; i++)
		{
			gotoxy(20+i,25); printf("%c",stralphabet3[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
	}while(int(ch) != 13 && toupper(nav) != 'H');
}

void DefineString()
{
	char ch = ' ';
	
	do
	{
		gotoxy(3,20); textcolor(11); printf("%c ",254); textcolor(15); printf("String");
		char strstring1[107] = "A String is a sequence of Symbols. A Symbol can either stand alone or could be grouped with other symbols.";
		char strstring2[32]  = "e.g. 1, b, z, carl, azd901, za9";
	
		PrintAssistant(8,21,4,0);
		AssistantDialogBorder(17,22,80,6); 
		
		for(int i = 0; i < 75; i++)
		{
			gotoxy(19+i,25); printf("%c",strstring1[i]); Sleep(8);
		}
		
		for(int i = 0; i < 31; i++)
		{
			gotoxy(18+i,26); printf("%c",strstring1[75+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		for(int i = 0; i < 2; i++) //clear box
		{
			for(int j = 0; j < 76; j++)
			{
				gotoxy(19+j,25+i); printf(" ");
			}
		}
	
		for(int i = 0; i < 31; i++)
		{
			gotoxy(42+i,25); printf("%c",strstring2[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
	}while(int(ch) != 13 && toupper(nav) != 'H');
}

void DefineLanguage()
{
	char ch = ' ';
	
	do
	{
		gotoxy(3,20); textcolor(11); printf("%c ",254); textcolor(15); printf("Language");
		char strlanguage1[204] = "A Language is a set of Strings. A Language can have one or multiple conditions to limit the amount of Strings it has. Conditions however may also cause the Language to have an infinite number of Strings.";
		char strlanguage2[124] = "All this helping is exhausting! I shall take a break and be back later. The program will now provide examples for Language.";
		PrintAssistant(8,21,4,0);
		AssistantDialogBorder(17,21,80,7); 
		
		for(int i = 0; i < 67; i++)
		{
			gotoxy(19+i,24); printf("%c",strlanguage1[i]); Sleep(8);
		}
		
		for(int i = 0; i < 73; i++)
		{
			gotoxy(18+i,25); printf("%c",strlanguage1[67+i]); Sleep(8);
		}
		
		for(int i = 0; i < 64; i++)
		{
			gotoxy(18+i,26); printf("%c",strlanguage1[140+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		for(int i = 0; i < 3; i++) //clear box
		{
			for(int j = 0; j < 76; j++)
			{
				gotoxy(19+j,24+i); printf(" ");
			}
		}
		
		for(int i = 0; i < 75; i++)
		{
			gotoxy(19+i,24); printf("%c",strlanguage2[i]); Sleep(8);
		}
		
		for(int i = 0; i < 49; i++)
		{
			gotoxy(18+i,25); printf("%c",strlanguage2[75+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		for(int i = 0; i < 7; i++) //clear
		{
			for(int j = 0; j < 94; j++)
			{
				gotoxy(3+j,21+i); printf(" ");
			}
		}
		
		gotoxy(5,22); printf("e.g. #1 "); textcolor(11); printf("%c ",228); textcolor(15); printf("= ");
		textcolor(11); printf("{"); textcolor(15); printf("0,1"); textcolor(11); printf("}");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		textcolor(15); gotoxy(5,22); printf("e.g. #2 ");
		printf("Let "); textcolor(11); printf("L1 "); textcolor(15); printf("be the set of all Strings of length 2");
		
		gotoxy(13,23); printf("Let "); textcolor(11); printf("L2 "); textcolor(15); printf("be the Set of all Strings of length 3 that starts with the number 0.");
		
		gotoxy(13,24); printf("Let "); textcolor(11); printf("L3 "); textcolor(15); printf("be the Set of all Strings that starts and ends with 1.");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		gotoxy(13,26); textcolor(11); printf("L1 "); textcolor(15); printf("= "); textcolor(11); printf("{");
		textcolor(15); printf("01, 10, 11, 00"); textcolor(11); printf("}     ");
		
		textcolor(11); printf("L2 "); textcolor(15); printf("= "); textcolor(11); printf("{");
		textcolor(15); printf("001, 011, 010, 000"); textcolor(11); printf("}  ");
		
		printf("%c>  ",196); textcolor(15); printf("Finite Sets");
		
		gotoxy(13,27); textcolor(11); printf("L3 "); textcolor(15); printf("= "); textcolor(11); printf("{");
		textcolor(15); printf("11, 101, 1011, 1101, 100001,..."); textcolor(11); printf("}               ");
		
		printf("%c>  ",196); textcolor(15); printf("Infinite Set");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
	}while(int(ch) != 13 && toupper(nav) != 'H');
}

void DefineLengthOfString()
{
	char ch = ' ';
	
	do
	{
		gotoxy(3,20); textcolor(11); printf("%c ",254); textcolor(15); printf("Length of String");
		char strlos1[54]  = "Alright I'm back! Proceeding with Length of String...";
		char strlos2[141] = "The Length pertains to the number of symbols a String has. It is denoted by |S|. The symbol for lambda is used to represent an empty String.";
		char strlos3[76]  = "e.g.  1 = {a,b,c}                                        | 1| = 3";
		char strlos4[70]  = "2 = {aa, bb, cc, ab, ac, ba, bc, ca, cb}           | 2| = 9";
		
		PrintAssistant(8,21,4,0);
		AssistantDialogBorder(17,21,80,7); 
		
		for(int i = 0; i < 54; i++)
		{
			gotoxy(19+i,24); printf("%c",strlos1[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		for(int i = 0; i < 3; i++) //clear box
		{
			for(int j = 0; j < 76; j++)
			{
				gotoxy(19+j,24+i); printf(" ");
			}
		}
		
		for(int i = 0; i < 76; i++)
		{
			gotoxy(19+i,24); printf("%c",strlos2[i]); Sleep(8);
		}
		
		for(int i = 0; i < 64; i++)
		{
			gotoxy(19+i,25); printf("%c",strlos2[76+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		for(int i = 0; i < 3; i++) //clear box
		{
			for(int j = 0; j < 76; j++)
			{
				gotoxy(19+j,24+i); printf(" ");
			}
		}
		
		for(int i = 0; i < 75; i++)
		{
			gotoxy(19+i,25); printf("%c",strlos3[i]); Sleep(8);
			if(i == 5)  { gotoxy(24,25); printf("%c",228); }
			if(i == 60) { gotoxy(77,25); printf("%c",228); }
		}
		
		gotoxy(24,26); printf("%c",228);
		for(int i = 0; i < 70; i++)
		{
			gotoxy(25+i,26); printf("%c",strlos4[i]); Sleep(8);
			if(i == 53) { gotoxy(77,26); printf("%c",228); }
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
	}while(int(ch) != 13 && toupper(nav) != 'H');
}

void DefineKleeneStar()
{
	char ch = ' ';
	
	do
	{
		gotoxy(3,20); textcolor(11); printf("%c ",254); textcolor(15); printf("Kleene Star");
		char strkstar1[139] = "The Kleene Star is the union of all the sets of Strings that gives the infinite set of all possible Strings of all possible Lengths or...";
		char strkstar2[23]  = "* =  1 U  2 U  3 U ...";
		char strkstar3[75]  = "e.g.  * = {'lambda', a, b, c, aa, ab, ac, bb, bc, ba, cc, ca, cb, cbc,...}";
		PrintAssistant(8,21,4,0);
		AssistantDialogBorder(17,21,80,7); 
		
		for(int i = 0; i < 71; i++)
		{
			gotoxy(19+i,24); printf("%c",strkstar1[i]); Sleep(8);
		}
		
		for(int i = 0; i < 68; i++)
		{
			gotoxy(19+i,25); printf("%c",strkstar1[71+i]); Sleep(8);
		}
		
		for(int i = 0; i < 23; i++)
		{
			gotoxy(20+i,26); printf("%c",strkstar2[i]); Sleep(8); 
			if(i == 0 || i % 5 == 0) { gotoxy(19+i,26); printf("%c",228); }
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		for(int i = 0; i < 3; i++) //clear box
		{
			for(int j = 0; j < 76; j++)
			{
				gotoxy(19+j,24+i); printf(" ");
			}
		}
		
		
		for(int i = 0; i < 75; i++)
		{
			gotoxy(20+i,25); printf("%c",strkstar3[i]); Sleep(8);
			if(i == 5) { gotoxy(25,25); printf("%c",228); }
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(int(ch) == 13) nav = 'D';
	}while(int(ch) != 13 && toupper(nav) != 'H');
}

void DefinitionOfTerms() //2nd lesson
{
	char ch = ' ';
	do
	{
		system("cls");
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("TERMINOLOGIES");
		
		gotoxy(3,4); printf("Input, Output, and State");
		gotoxy(3,6); printf("The three most important things of automata is the "); 
		
		textcolor(11); printf("input"); textcolor(15); printf(", the "); textcolor(11); printf("output");
		textcolor(15); printf(", and the "); textcolor(11); printf("states"); textcolor(15); printf(". Dar Aziz");
		
		gotoxy(3,7); printf("et al, "); textcolor(11); printf("("); textcolor(15); printf("2004"); textcolor(11); printf(") ");
		textcolor(15); printf("defined these three as the following "); textcolor(11); printf("(");
		textcolor(15); printf("in order"); textcolor(11); printf(")"); textcolor(15); printf(":"); //end intro print
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		gotoxy(8,9); textcolor(11); printf("%c ",254); 
		textcolor(15); printf("Inputs: assumed to be the sequences of symbols selected from a finite set "); textcolor(11); printf("I ");
		textcolor(15); printf("of input"); 
		
		gotoxy(10,10); printf("signals. Namely, set "); textcolor(11); printf("I "); textcolor(15); printf("is the set ");
		textcolor(11); printf("{"); textcolor(15); printf("x1,x2,x3...xk"); textcolor(11); printf("} ");
		textcolor(15); printf("where k is the number of inputs."); //end input print

		gotoxy(8,12); textcolor(11); printf("%c ",254); 
		textcolor(15); printf("Outputs: sequences of symbols selected from a finite set "); textcolor(11); printf("Z");
		textcolor(15); printf(". Namely, set "); textcolor(11); printf("Z "); textcolor(15); printf("is the set");
		
		gotoxy(10,13); textcolor(11); printf("{"); textcolor(15); printf("y1,y2,y3...ym"); textcolor(11); printf("} ");
		textcolor(15); printf("where m is the number of inputs"); //end output print
		
		gotoxy(8,15); textcolor(11); printf("%c ",254); 
		textcolor(15); printf("States: finite set "); textcolor(11); printf("Q"); textcolor(15); printf(", whose definition depends on the type of automaton.");
		//end states print
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		gotoxy(3,18); printf("Finite-State Automata Pre-requisites:");
		
		int ctr = 1;
		
		do
		{
			gotoxy(10,20); textcolor(11); printf("["); textcolor(15); printf("1"); textcolor(11); printf("]"); textcolor(15); printf(" - ");
			printf("Alphabet"); 
			
			gotoxy(10,22); textcolor(11); printf("["); textcolor(15); printf("2"); textcolor(11); printf("]"); textcolor(15); printf(" - ");
			printf("String");
		
			gotoxy(10,24); textcolor(11); printf("["); textcolor(15); printf("3"); textcolor(11); printf("]"); textcolor(15); printf(" - ");
			printf("Language");
		
			gotoxy(30,20); textcolor(11); printf("["); textcolor(15); printf("4"); textcolor(11); printf("]"); textcolor(15); printf(" - ");
			printf("Length of string");
		
			gotoxy(30,22); textcolor(11); printf("["); textcolor(15); printf("5"); textcolor(11); printf("]"); textcolor(15); printf(" - ");
			printf("Kleene Star");
	
			ch = getch();
			if(toupper(ch) == 'H') { nav = 'H'; break; }
			
			if(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || int(ch) == 13) //clear choices
			{
				for(int i = 0; i < 8; i++)
				{
					for(int j = 0; j < 94; j++)
					{
						gotoxy(3+j,20+i); printf(" ");
					}
				}
			}
			
			if(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5')
			{
				switch(ch)
				{
					case '1': DefineAlphabet();       ctr = 2; break;
					case '2': DefineString();         ctr = 3; break;
					case '3': DefineLanguage();       ctr = 4; break;
					case '4': DefineLengthOfString(); ctr = 5; break;
					case '5': DefineKleeneStar();     ctr = 6; break;
				}
			}
			
			else if(int(ch) == 13)
			{
				switch(ctr)
				{
					case 1: DefineAlphabet(); break;
					case 2: DefineString(); break;
					case 3: DefineLanguage(); break;
					case 4: DefineLengthOfString(); break;
					case 5: DefineKleeneStar(); break;
				}
				ctr++;
			}
			
			for(int i = 0; i < 8; i++)
			{
				for(int j = 0; j < 94; j++)
				{
					gotoxy(3+j,20+i); printf(" ");
				}
			}
		}while(toupper(nav) != 'H' && ctr != 6 && toupper(nav) != 'D');
		if(toupper(nav) == 'D') break;
	}while(int(ch) != 13 && toupper(nav) != 'H');
	if(int(ch) == 13) nav = 'D';
}

void NFA() //4th lesson
{
	char ch = ' ';
	
	do
	{
		system("cls");
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("NON-DETERMINISTIC FINITE AUTOMATA");
		
		gotoxy(3,4); textcolor(11); printf("Non-Determinism "); textcolor(15); printf("is the exact opposite of "); textcolor(11); printf("Determinism");
		textcolor(15); printf(". "); printf("An NFA may have "); textcolor(11); printf("multiple states"); textcolor(15); printf(". ");
		
		gotoxy(3,5); textcolor(15); printf("The next state may either be chosen at "); textcolor(11); printf("random ");
		textcolor(15); printf("or all chosen in "); textcolor(11); printf("parallel "); textcolor(11); printf("("); textcolor(15); printf("i.e. the user");
		
		gotoxy(3,6); printf("may choose all the next states simultaneously"); textcolor(11); printf(")"); textcolor(15); printf(". ");
		textcolor(15); printf("An NFA also accepts "); textcolor(11); printf("null inputs"); textcolor(15); printf("."); 
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		gotoxy(3,8); printf("Below is an example of a machine that accepts all strings that end with 0:");
		
		textcolor(11); ArrowRight(10,14); PrintState(14,13,'A',0,0); textcolor(11); ArrowRight(19,14); PrintState(25,13,'B',1,0);
		textcolor(11); ArrowLoopUp(14,12);
		textcolor(15); gotoxy(15,11); printf("0,1"); gotoxy(20,13); printf("0");
		
		PrintAssistant(5,16,0,0); AssistantDialogBorder(3,22,75,7);
		
		char strnfa1[69]  = "Basically, NFA is the same as DFA, but without all the restrictions.";
		char strnfa2[92]  = "It accepts inputs and for different simulations, the transitions it traverses also differs.";
		char strnfa3[130] = "If you can see at the diagram above, if the machine gets an input of 0, it can either loop back to state A or proceed to state B.";
		char strnfa4[59]  = "This implies that one simulation can differ from the next.";
		char strnfa5[72]  = "Additionally, the use of dead / trap states won't be necessary anymore.";
		char strnfa6[97]  = "NFAs have the property of its states to be able to receive input and not do anything afterwards.";
		
		int x = 5, y = 25;
		
		textcolor(15);
		for(int i = 0; i < 69; i++)
		{
			gotoxy(x+i,y); printf("%c",strnfa1[i]); Sleep(8);
		} 
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		ClearDialogBorder(x,y,72,3);
		
		for(int i = 0; i < 67; i++)
		{
			gotoxy(x+i,y); printf("%c",strnfa2[i]); Sleep(8);
		} 
		
		for(int i = 0; i < 23; i++)
		{
			gotoxy(x+i,y+1); printf("%c",strnfa2[68+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		ClearDialogBorder(x,y,72,3); ClearAssistant(5,16);
		PrintAssistant(5,16,2,0);
		
		for(int i = 0; i < 71; i++)
		{
			gotoxy(x+i,y); printf("%c",strnfa3[i]); Sleep(8);
		}
		
		textcolor(14); gotoxy(15,11); printf("0"); gotoxy(20,13); printf("0");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		textcolor(15); gotoxy(15,11); printf("0"); gotoxy(20,13); printf("0");
		for(int i = 0; i < 35; i++)
		{
			gotoxy(x+i,y+1); printf("%c",strnfa3[72+i]); Sleep(8);
		}
		
		PrintState(14,13,'A',0,1);
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		PrintState(14,13,'A',0,0);
		
		for(int i = 0; i < 23; i++)
		{
			gotoxy(x+35+i,y+1); printf("%c",strnfa3[107+i]); Sleep(8);
		}
		
		PrintState(25,13,'B',1,1);
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		PrintState(25,13,'B',1,0);
		
		for(int i = 0; i < 12; i++)
		{
			gotoxy(x+58+i,y+1); printf("%c",strnfa4[i]); Sleep(8);
		}
		
		for(int i = 0; i < 45; i++)
		{
			gotoxy(x+i,y+2); printf("%c",strnfa4[13+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		ClearDialogBorder(x,y,72,3); ClearAssistant(5,16);
		PrintAssistant(5,16,0,0);
		
		for(int i = 0; i < 71; i++)
		{
			gotoxy(x+i,y); printf("%c",strnfa5[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		for(int i = 0; i < 68; i++)
		{
			gotoxy(x+i,y+1); printf("%c",strnfa6[i]); Sleep(8);
		}
		
		for(int i = 0; i < 28; i++)
		{
			gotoxy(x+i,y+2); printf("%c",strnfa6[69+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		ClearDialogBorder(x,y,72,3); ClearAssistant(5,16);
		PrintAssistant(55,16,2,0);
		
		gotoxy(x+65,y-15); printf("Q "); textcolor(11); printf(" = {"); textcolor(15); printf("A,B"); textcolor(11); printf("}");
		gotoxy(x+65,y-14); textcolor(15); printf("%c ",228); textcolor(11); printf(" = {"); textcolor(15); printf("0,1"); textcolor(11); printf("}");
		gotoxy(x+65,y-13); textcolor(15); printf("q%c ",249); textcolor(11); printf("= {"); textcolor(15); printf("A"); textcolor(11); printf("}");
		gotoxy(x+65,y-12); textcolor(15); printf("F "); textcolor(11); printf(" = {"); textcolor(15); printf("B"); textcolor(11); printf("}");
		gotoxy(x+65,y-11);  textcolor(15); printf("%c ",235); textcolor(11); printf(" = "); textcolor(15); printf("???");
		char strnfa7[73] = "Lastly, the 5 tuples also apply to NFAs; but with the difference of its ";
		
		for(int i = 0; i < 72; i++)
		{
			gotoxy(x+i,y); printf("%c",strnfa7[i]); Sleep(8);
		}
		
		gotoxy(x,y+1); printf("%c.",235);
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		gotoxy(x+65,y-11);  textcolor(15); printf("%c ",235); textcolor(11); printf(" = "); textcolor(15); printf("Q ");
		textcolor(11); printf("x "); textcolor(15); printf("%c ",228); textcolor(11); printf("-> "); textcolor(15); printf("2^Q");
		
		char strnfa8[145] = "The representation is now different because of the NFAs property of having identical inputs on different transitions coming from a single state.";
		
		ClearDialogBorder(x,y,72,3);
		for(int i = 0; i < 67; i++)
		{
			gotoxy(x+i,y); printf("%c", strnfa8[i]); Sleep(8);
		}
		
		for(int i = 0; i < 70; i++)
		{
			gotoxy(x+i,y+1); printf("%c", strnfa8[68+i]); Sleep(8);
		}
		
		for(int i = 0; i < 6; i++)
		{
			gotoxy(x+i,y+2); printf("%c", strnfa8[138+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		ClearDialogBorder(x,y,72,3); //ClearDialogBorder(x+65,y-15,17,5);
		
		char strnfa9[105]  = "And that sums up the lectures for this tutorial! My creators and I sincerely hope you learned something.";
		char strnfa11[122] = "Unfortunately, we weren't able to create a simulator for the NFA. But please feel free to search for one on the internet!";
		
		for(int i = 0; i < 69; i++)
		{
			gotoxy(x+i,y); printf("%c",strnfa11[i]); Sleep(8);
		}
		
		for(int i = 0; i < 51; i++)
		{
			gotoxy(x+i,y+1); printf("%c",strnfa11[70+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		ClearDialogBorder(x,y,72,3);
		ClearAssistant(55,16); PrintAssistant(45,16,0,0);
		
		for(int i = 0; i < 66; i++)
		{
			gotoxy(x+i,y); printf("%c",strnfa9[i]); Sleep(8);
		}
		
		for(int i = 0; i < 37; i++)
		{
			gotoxy(x+i,y+1); printf("%c",strnfa9[67+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
	}while(int(ch) != 13 && toupper(nav) != 'H');
	if(int(ch) == 13) nav = 'A';
}

void DFASecondExample()
{
	char ch = ' ', str[4];
	int animatespeed = 0, x = 3, y = 2;
	do
	{
		SetBorder(); 
		
		//textcolor(11); for(int i = 0; i < 22; i++){ gotoxy(x+44,y+4+i); printf("%c",186); }
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("DFA EXAMPLE #2");
		
		gotoxy(x,y+2); printf("Below is an example of a machine that would accept all strings that start with zero (0)");
		PrintState(x+11,y+4,'A',0,0); textcolor(11); ArrowRight(x+7,y+5); ArrowRight(x+16,y+5); ArrowDown(x+13,y+7);
		PrintState(x+22,y+4,'B',1,0); textcolor(11); ArrowLoopRight(x+29,y+4);
		PrintState(x+11,y+10,'C',0,0); textcolor(11); ArrowLoopRight(x+16,y+10);
		textcolor(15); gotoxy(x+17,y+4); printf("0"); gotoxy(x+33,y+5); printf("0,1"); 
		gotoxy(x+14,y+8); printf("1"); gotoxy(x+20,y+11); printf("0,1");
		
		gotoxy(x+4,y+16); printf("Q "); textcolor(11); printf(" = {"); textcolor(15); printf("A,B,C"); textcolor(11); printf("}");
		gotoxy(x+4,y+17); textcolor(15); printf("%c ",228); textcolor(11); printf(" = {"); textcolor(15); printf("0,1"); textcolor(11); printf("}");
		gotoxy(x+4,y+18); textcolor(15); printf("q%c ",249); textcolor(11); printf("= {"); textcolor(15); printf("A"); textcolor(11); printf("}");
		gotoxy(x+4,y+19); textcolor(15); printf("F "); textcolor(11); printf(" = {"); textcolor(15); printf("B"); textcolor(11); printf("}");	
		
		textcolor(15); gotoxy(x+20,y+16); printf("%c ",235); textcolor(11); printf(" = ");
		gotoxy(x+25,y+16); textcolor(11); printf("%c%c%c%c%c%c%c%c%c",218,196,196,196,194,196,196,196,191);
		gotoxy(x+25,y+17); printf("%c   %c   %c",179,179,179);  gotoxy(x+25,y+18); printf("%c%c%c%c%c%c%c%c%c",195,196,196,196,197,196,196,196,180);
		gotoxy(x+25,y+19); printf("%c   %c   %c",179,179,179);  gotoxy(x+25,y+20); printf("%c%c%c%c%c%c%c%c%c",195,196,196,196,197,196,196,196,180); 
		gotoxy(x+25,y+21); printf("%c   %c   %c",179,179,179);  gotoxy(x+25,y+22); printf("%c%c%c%c%c%c%c%c%c",195,196,196,196,197,196,196,196,180);
		gotoxy(x+25,y+23); printf("%c   %c   %c",179,179,179);  gotoxy(x+25,y+24); printf("%c%c%c%c%c%c%c%c%c",192,196,196,196,193,196,196,196,217);

		textcolor(15);
		gotoxy(x+27,y+15); printf("0   1");
		gotoxy(x+24,y+17);  printf("A"); gotoxy(x+24,y+19); printf("B"); gotoxy(x+24,y+21); printf("C"); gotoxy(x+24,y+23); printf("D");
		gotoxy(x+27,y+17); printf("B"); gotoxy(x+31,y+17); printf("B");
		gotoxy(x+27,y+19); printf("C"); gotoxy(x+31,y+19); printf("C");
		gotoxy(x+27,y+21); printf("D"); gotoxy(x+31,y+21); printf("D");
		gotoxy(x+27,y+23); printf("D"); gotoxy(x+31,y+23); printf("D");
		
		textcolor(11); gotoxy(x+50,y+8); printf("NOTE: "); 
		textcolor(15); gotoxy(x+50,y+9); printf("1. \"1\" represents all other values aside");
		gotoxy(x+53,y+10); printf("from zero(0)");
		gotoxy(x+50,y+11); printf("2. "); textcolor(14); printf("Yellow "); textcolor(15); printf("text in the simulation represents");
		gotoxy(x+53,y+12); printf("your input");
		gotoxy(x+50,y+14); printf("Input string (max of 4): "); 
		gotoxy(x+50,y+15); printf("Set animate speed (in ms): "); 
		
		do
		{
			gotoxy(x+75,y+14); gets(str);
			if(strlen(str) > 4)
			{
				for(int i = 0; i < strlen(str); i++){ gotoxy(x+75+i,y+14); printf(" "); }
			}
		}while(strlen(str) > 4);
		gotoxy(x+77,y+15); scanf("%d",&animatespeed); fflush(stdin);
		
		for(int i = 0; i < strlen(str); i++)
		{
			gotoxy(x+75+i,y+14); textcolor(14); printf("%c",str[i]);
			if(i != 0) { gotoxy(x+74+i,y+14); textcolor(15); printf("%c",str[i-1]); }
			if(i == 0)
			{
				if(str[i] == '0')
				{
					gotoxy(x+17,y+3); textcolor(14); printf("%c",str[i]); Sleep(animatespeed);
				}
				
				else
				{
					gotoxy(x+16,y+8); textcolor(14); printf("%c",str[i]); Sleep(animatespeed);
				}
			}
			
			else
			{
				if(str[0] == '0')
				{
					gotoxy(x+36+i,y+5); textcolor(14); printf("%c",str[i]); Sleep(animatespeed);
				}
				
				else
				{
					gotoxy(x+23+i,y+11); textcolor(14); printf("%c",str[i]); Sleep(animatespeed);
				}
				
			}
		}
		
		if(str[0] == '0')
		{
			PrintState(25,6,'B',1,1); 
			gotoxy(x+50,y+17); textcolor(15); printf("The string ended in the final state"); 
			gotoxy(x+50,y+18); printf("Input is ");
			textcolor(10); printf("valid"); textcolor(15); printf("!");
		}
		
		else
		{
			PrintState(14,12,'C',0,2);
			gotoxy(x+50,y+17); textcolor(15); printf("The string did not end in the final state."); 
			gotoxy(x+50,y+18); printf("Input is ");
			textcolor(12); printf("invalid"); textcolor(15); printf("!");
		}
		
		gotoxy(25,2); textcolor(15); printf("EXAMPLE "); textcolor(10); printf("["); textcolor(15); printf("1"); textcolor(10); printf("]"); 
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
	}while(int(ch) != 13 && toupper(nav) != 'T');
	if(int(ch) == 13) NFA();
}	

void DFAFirstExample()
{
	char ch = ' ', str[8];
	int animatespeed = 0, x = 3, y = 2;
	do
	{
		SetBorder();
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("DFA EXAMPLE #1");
		
		gotoxy(x,y+2); printf("Below is an example of a deterministic finite automata");
		gotoxy(x,y+3); printf("that accepts all strings over ");
		textcolor(11); printf("{"); textcolor(15); printf("0,1"); textcolor(11); printf("} "); textcolor(15); printf("of length 2:");
		textcolor(11); ArrowRight(x,y+7); ArrowRight(x+11,y+7);  ArrowRight(x+9,y+7); ArrowRight(x+18,y+7); ArrowRight(x+31,y+7); ArrowLoopRight(x+40,y+6);
		PrintState(x+4,y+6,'A',0,0);
		PrintState(x+13,y+6,'B',0,0); 
		PrintState(x+24,y+6,'C',1,0); 
		PrintState(x+35,y+6,'D',0,0); 
		textcolor(15); gotoxy(x+9,y+6); printf("0,1"); gotoxy(x+18,y+6); printf("0,1"); gotoxy(x+31,y+6); printf("0,1"); gotoxy(x+44,y+7); printf("0,1");
		
		gotoxy(x+5,y+11); printf("Q "); textcolor(11); printf(" = {"); textcolor(15); printf("A,B,C,D"); textcolor(11); printf("}");
		gotoxy(x+5,y+12); textcolor(15); printf("%c ",228); textcolor(11); printf(" = {"); textcolor(15); printf("0,1"); textcolor(11); printf("}");
		gotoxy(x+5,y+13); textcolor(15); printf("q%c ",249); textcolor(11); printf("= {"); textcolor(15); printf("A"); textcolor(11); printf("}");
		gotoxy(x+5,y+14); textcolor(15); printf("F "); textcolor(11); printf(" = {"); textcolor(15); printf("C"); textcolor(11); printf("}");	
		
		textcolor(15); gotoxy(x+5,y+16); printf("%c ",235); textcolor(11); printf(" = ");
		gotoxy(x+10,y+16); textcolor(11); printf("%c%c%c%c%c%c%c%c%c",218,196,196,196,194,196,196,196,191);
		gotoxy(x+10,y+17); printf("%c   %c   %c",179,179,179);  gotoxy(x+10,y+18); printf("%c%c%c%c%c%c%c%c%c",195,196,196,196,197,196,196,196,180);
		gotoxy(x+10,y+19); printf("%c   %c   %c",179,179,179);  gotoxy(x+10,y+20); printf("%c%c%c%c%c%c%c%c%c",195,196,196,196,197,196,196,196,180); 
		gotoxy(x+10,y+21); printf("%c   %c   %c",179,179,179);  gotoxy(x+10,y+22); printf("%c%c%c%c%c%c%c%c%c",195,196,196,196,197,196,196,196,180);
		gotoxy(x+10,y+23); printf("%c   %c   %c",179,179,179);  gotoxy(x+10,y+24); printf("%c%c%c%c%c%c%c%c%c",192,196,196,196,193,196,196,196,217);

		textcolor(15);
		gotoxy(x+12,y+15); printf("0   1");
		gotoxy(x+9,y+17);  printf("A"); gotoxy(x+9,y+19); printf("B"); gotoxy(x+9,y+21); printf("C"); gotoxy(x+9,y+23); printf("D");
		gotoxy(x+12,y+17); printf("B"); gotoxy(x+16,y+17); printf("B");
		gotoxy(x+12,y+19); printf("C"); gotoxy(x+16,y+19); printf("C");
		gotoxy(x+12,y+21); printf("D"); gotoxy(x+16,y+21); printf("D");
		gotoxy(x+12,y+23); printf("D"); gotoxy(x+16,y+23); printf("D");
		
		textcolor(11); gotoxy(x+50,y+11); printf("NOTE: "); 
		textcolor(15); gotoxy(x+50,y+12); printf("1. \"0,1\" represents all string values");
		gotoxy(x+50,y+13); printf("2. "); textcolor(14); printf("Yellow "); textcolor(15); printf("text in the simulation represents");
		gotoxy(x+53,y+14); printf("your input.");
		gotoxy(x+50,y+16); printf("Input string (max of 8): "); 
		gotoxy(x+50,y+17); printf("Set animate speed (in ms): ");
		
		do
		{
			gotoxy(x+75,y+16); gets(str);
			if(strlen(str) > 8)
			{
				for(int i = 0; i < strlen(str); i++){ gotoxy(x+75+i,y+16); printf(" "); }
			}
		}while(strlen(str) > 8);
		gotoxy(x+77,y+17); scanf("%d",&animatespeed); fflush(stdin);
		
		for(int i = 0; i < strlen(str); i++)
		{
			gotoxy(x+75+i,y+16); textcolor(14); printf("%c",str[i]);
			if(i != 0) { gotoxy(x+74+i,y+16); textcolor(15); printf("%c",str[i-1]); }
			if(i == 0)
			{
				gotoxy(x+9,y+5); textcolor(14); printf("%c",str[i]); Sleep(animatespeed);
			}
			
			else if(i == 1)
			{
				gotoxy(x+18,y+5); textcolor(14); printf("%c",str[i]); Sleep(animatespeed);
			}
			
			else if(i == 2)
			{
				gotoxy(x+31,y+5); textcolor(14); printf("%c",str[i]); Sleep(animatespeed);
			}
			
			else if(i >= 3)
			{
				gotoxy(x+48+i-3,y+7); textcolor(14); printf("%c",str[i]); Sleep(animatespeed);
			}
			
		}
		
		if(strlen(str) == 2)
		{
			PrintState(x+24,y+6,'C',1,1); 
			gotoxy(x+50,y+19); textcolor(15); printf("The string ended in the final state."); 
			gotoxy(x+50,y+20); printf("Input is ");
			textcolor(10); printf("valid"); textcolor(15); printf("!");
		}
		
		else
		{
			if(strlen(str) == 1) PrintState(x+13,y+6,'B',0,2); 
			else if(strlen(str) >= 3) PrintState(x+35,y+6,'D',0,2); 
		
			gotoxy(x+50,y+19); textcolor(15); printf("The string did not end in the final state."); 
			gotoxy(x+50,y+20); printf("Input is ");
			textcolor(12); printf("invalid"); textcolor(15); printf("!");
		}
		
		gotoxy(25,2); textcolor(15); printf("EXAMPLE "); textcolor(10); printf("["); textcolor(15); printf("2"); textcolor(10); printf("]"); 
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '2') { DFASecondExample(); break; }
	}while(int(ch) != 13 && toupper(nav) != 'T');
	if(int(ch) == 13) DFASecondExample();
}

void DFA() //3rd lessons
{
	char ch = ' ';
	
	do
	{
		system("cls");
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		gotoxy(37,2); textcolor(15); printf("EXAMPLE "); textcolor(10); printf("["); textcolor(15); printf("1"); textcolor(10); printf("]"); 
		gotoxy(50,2); textcolor(15); printf("EXAMPLE "); textcolor(10); printf("["); textcolor(15); printf("2"); textcolor(10); printf("]"); 
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("DETERMINISTIC FINITE AUTOMATA");
		
		gotoxy(3,4); printf("The word "); textcolor(11); printf("determinism "); textcolor(15); printf("is very important to extinguish what DFA is. ");
		textcolor(11); printf("Determinism "); textcolor(15); printf("guarantees what");
		
		gotoxy(3,5); printf("the next unique state will be. It has only one unique next state. "); textcolor(11); printf("Determinism ");
		textcolor(15); printf("also guarantees ");
		
		gotoxy(3,6); printf("that there is no randomness and there are no choices "); textcolor(11); printf("(");
		textcolor(15); printf("i.e. the transition between states is"); 
		
		gotoxy(3,7); printf("fixed"); textcolor(11); printf(")"); textcolor(15); printf(".");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		gotoxy(3,9); printf("In DFA, the program reads "); textcolor(11); printf("only one input string at a time");
		textcolor(15); printf(". The program will not continue ");
		gotoxy(3,10); printf("or it ");
		textcolor(11); printf("will not change state if the input is null"); textcolor(15); printf(". Lastly, the DFA may have "); textcolor(11); printf("one or more final");
		gotoxy(3,11); printf("states "); textcolor(15); printf("depending on the conditions set.");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		//Start discuss parts
		gotoxy(3,13); printf("Below is an example of a deterministic finite automata that accepts"); 
		gotoxy(3,14); printf("all strings over "); textcolor(11); printf("{"); textcolor(15); printf("0,1");
		textcolor(11); printf("} "); textcolor(15); printf("of length 2:");
		
		int x = 24, y = 17;
		textcolor(11); ArrowRight(x,y);  ArrowRight(x+9,y); ArrowRight(x+18,y); ArrowRight(x+31,y); ArrowLoopRight(x+40,y-1);
		PrintState(x+4,y-1,'A',0,0);
		PrintState(x+13,y-1,'B',0,0); 
		PrintState(x+24,y-1,'C',1,0); 
		PrintState(x+35,y-1,'D',0,0); 
		textcolor(15); gotoxy(x+9,y-1); printf("0,1"); gotoxy(x+18,y-1); printf("0,1"); gotoxy(x+31,y-1); printf("0,1"); gotoxy(x+44,y); printf("0,1");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		PrintAssistant(x,y+1,2,0); PrintState(x+4,y-1,'A',0,1);
		AssistantDialogBorder(x-1,y+7,50,5);
		gotoxy(x+1,y+10); printf("This");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		ClearAssistant(x,y+1); PrintState(x+4,y-1,'A',0,0); PrintState(x+13,y-1,'B',0,1);
		PrintAssistant(x+9,y+1,2,0); 
		gotoxy(x+5,y+10); printf(", this");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		PrintState(x+13,y-1,'B',0,0); PrintState(x+24,y-1,'C',1,1);
		textcolor(15); gotoxy(x+11,y+10); printf(", that");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		ClearAssistant(x+9,y+1); PrintState(x+13,y-1,'B',0,0); PrintState(x+24,y-1,'C',1,0); PrintState(x+35,y-1,'D',0,1);
		PrintAssistant(x+31,y+1,2,0); 
		
		gotoxy(x+17,y+10); printf(", and this");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		char strdfa1[19] = "are called states.";
		
		for(int i = 0; i < 19; i++)
		{
			gotoxy(x+28+i,y+10); printf("%c",strdfa1[i]); Sleep(8);
		}
		
		PrintState(x+4,y-1,'A',0,1); PrintState(x+13,y-1,'B',0,1); PrintState(x+24,y-1,'C',1,1); gotoxy(x+46,y+10);
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 50; j++)
			{
			 	gotoxy(x-1+j,y+7+i); printf(" "); //clear dialog box 
			}
		}
		ClearAssistant(x+31,y+1); PrintState(x+4,y-1,'A',0,0); PrintState(x+13,y-1,'B',0,0); PrintState(x+24,y-1,'C',1,0); PrintState(x+35,y-1,'D',0,0); 
		PrintAssistant(x+10,y+3,2,0);
		
		AssistantDialogBorder(x-21,y-1,20,13);
		
		char strdfa2[110] = "Now, the arrows are the transitions from one state to the next. The labels of these arrows are called inputs.";
		
		for(int i = 0; i < 8; i++)
		{
			gotoxy(x-19+i,y+2); printf("%c", strdfa2[i]); Sleep(8);
		}
		
		for(int i = 0; i < 14; i++)
		{
			gotoxy(x-19+i,y+3); printf("%c", strdfa2[9+i]); Sleep(8);
		}
		
		for(int i = 0; i < 16; i++)
		{
			gotoxy(x-19+i,y+4); printf("%c", strdfa2[24+i]); Sleep(8);
		}
		
		for(int i = 0; i < 17; i++)
		{
			gotoxy(x-19+i,y+5); printf("%c", strdfa2[41+i]); Sleep(8);
		}
		
		for(int i = 0; i < 9; i++)
		{
			gotoxy(x-19+i,y+6); printf("%c", strdfa2[54+i]); Sleep(8);
		}
		
		textcolor(10); ArrowRight(x,y);  ArrowRight(x+9,y); ArrowRight(x+18,y); ArrowRight(x+31,y); ArrowLoopRight(x+40,y-1);
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		textcolor(11); ArrowRight(x,y);  ArrowRight(x+9,y); ArrowRight(x+18,y); ArrowRight(x+31,y); ArrowLoopRight(x+40,y-1);
		
		textcolor(15);
		for(int i = 0; i < 4; i++)
		{
			gotoxy(x-10+i,y+6); printf("%c", strdfa2[63+i]); Sleep(8);
		}
		
		for(int i = 0; i < 16; i++)
		{
			gotoxy(x-19+i,y+7); printf("%c", strdfa2[68+i]); Sleep(8);
		}
		
		for(int i = 0; i < 10; i++)
		{
			gotoxy(x-19+i,y+8); printf("%c", strdfa2[84+i]); Sleep(8);
		}
		
		for(int i = 0; i < 14; i++)
		{
			gotoxy(x-19+i,y+9); printf("%c", strdfa2[95+i]); Sleep(8);
		}
		
		ClearAssistant(x+10,y+3);
		PrintAssistant(x+47,y-2,1,0);
		textcolor(10); gotoxy(x+9,y-1); printf("0,1"); gotoxy(x+18,y-1); printf("0,1"); gotoxy(x+31,y-1); printf("0,1"); gotoxy(x+44,y); printf("0,1");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		textcolor(15); gotoxy(x+9,y-1); printf("0,1"); gotoxy(x+18,y-1); printf("0,1"); gotoxy(x+31,y-1); printf("0,1"); gotoxy(x+44,y); printf("0,1");
		ClearAssistant(x+47,y-2);
		for(int i = 0; i < 13; i++)
		{
			for(int j = 0; j < 20; j++)
			{
			 	gotoxy(x-21+j,y-1+i); printf(" "); //clear dialog box 
			}
		}
		
		AssistantDialogBorder(x-21,y+4,80,8); PrintAssistant(x+52,y-2,0,0);
		char strdfa3[118] = "Following what has been said, if we go to state A and get an input of either 0 or 1, we will then proceed to state B.";
		char strdfa4[156] = "If you look at state A, you can see at its left that there is an arrow coming from nowhere. This simply means that state A is the initial / starting state.";
		char strdfa5[114] = "Everytime you see an arrow coming from nowhere pointing to a state, it shows that that state is a starting state.";
		char strdfa6[81]  = "And if you take a look at state C, you can see that it is enclosed by 2 squares.";
		char strdfa7[153] = "Any state enclosed by 2 squares, well, preferably a circle, is a final state. Additionally, if an input ends in the final state, it is considered valid.";
		//so like, input talaga gagamitin nating term? then valid siya if sa final state nag-end???
		
		for(int i = 0; i < 50; i++)
		{
			gotoxy(x-19+i,y+8); printf("%c",strdfa3[i]); Sleep(8);
		}
		while(!kbhit()){ ClearState(x+4,y-1,0); Sleep(200); PrintState(x+4,y-1,'A',0,1); Sleep(200); }
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		for(int i = 0; i < 27; i++)
		{
			textcolor(15); gotoxy(x+30+i,y+8); printf("%c",strdfa3[49+i]); Sleep(8);
		}
		
		for(int i = 0; i < 6; i++)
		{
			textcolor(15); gotoxy(x-19+i,y+9); printf("%c",strdfa3[77+i]); Sleep(8);
		}
		while(!kbhit()){ gotoxy(x+9,y-1); printf("   "); Sleep(200); textcolor(14); gotoxy(x+9,y-1); printf("0,1"); Sleep(200); }
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		for(int i = 0; i < 34; i++)
		{
			textcolor(15); gotoxy(x-13+i,y+9); printf("%c",strdfa3[83+i]); Sleep(8);
		}
		PrintState(x+13,y-1,'B',0,1);
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		ClearDialogBorder(x-19,y+8,76,2);
		PrintState(x+4,y-1,'A',0,0); textcolor(15); gotoxy(x+9,y-1); printf("0,1"); PrintState(x+13,y-1,'B',0,0);
		
		ClearAssistant(x+52,y-2); PrintAssistant(x-8,y-2,4,0);
		for(int i = 0; i < 70; i++)
		{
			gotoxy(x-19+i,y+7); printf("%c",strdfa4[i]); Sleep(8);
		}
		
		for(int i = 0; i < 20; i++)
		{
			gotoxy(x-19+i,y+8); printf("%c",strdfa4[71+i]); Sleep(8);
		}
		while(!kbhit()){ gotoxy(x,y); printf("    "); Sleep(200); textcolor(11); ArrowRight(x,y); Sleep(200); }
		
		for(int i = 0; i < 47; i++)
		{
			textcolor(15); gotoxy(x+2+i,y+8); printf("%c",strdfa4[92+i]); Sleep(8);
		}
		
		for(int i = 0; i < 15; i++)
		{
			gotoxy(x-19+i,y+9); printf("%c",strdfa4[140+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		for(int i = 0; i < 60; i++)
		{
			gotoxy(x-3+i,y+9); printf("%c",strdfa5[i]); Sleep(8);
		}
		
		for(int i = 0; i < 52; i++)
		{
			gotoxy(x-19+i,y+10); printf("%c",strdfa5[61+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		ClearDialogBorder(x-19,y+7,76,4);
		ClearAssistant(x-8,y-2); PrintAssistant(x-8,y-2,0,0);
		
		for(int i = 0; i < 72; i++)
		{
			gotoxy(x-19+i,y+7); printf("%c",strdfa6[i]); Sleep(8);
		}
		
		for(int i = 0; i < 8; i++)
		{
			gotoxy(x-19+i,y+8); printf("%c",strdfa6[72+i]); Sleep(8);
		}
		while(!kbhit()){ ClearState(x+24,y-1,1); Sleep(200); PrintState(x+24,y-1,'C',1,1); Sleep(200); }
		
		for(int i = 0; i < 65; i++)
		{
			textcolor(15); gotoxy(x-10+i,y+8); printf("%c",strdfa7[i]); Sleep(8);
		}
		
		for(int i = 0; i < 12; i++)
		{
			gotoxy(x-19+i,y+9); printf("%c",strdfa7[65+i]); Sleep(8);
		}
		
		getch();
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		for(int i = 0; i < 56; i++)
		{
			gotoxy(x-6+i,y+9); printf("%c",strdfa7[78+i]); Sleep(8);
		}
		
		for(int i = 0; i < 17; i++)
		{
			gotoxy(x-19+i,y+10); printf("%c",strdfa7[135+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		ClearDialogBorder(x-19,y+7,76,4); PrintState(x+24,y-1,'C',1,0);
		ClearAssistant(x-8,y-2); PrintAssistant(x+49,y-2,5,0);
		
		char strdfa8[119] = "As you can see in state D, it is a state that loops within itself and restricts any further access to the final state.";
		char strdfa9[137] = "This kind of state is called the dead / trap state. Any input that doesn't reach the final state is invalid and rejected by the machine.";
		
		for(int i = 0; i < 69; i++)
		{
			gotoxy(x-19+i,y+7); printf("%c",strdfa8[i]); Sleep(8);
		}
		
		for(int i = 0; i < 49; i++)
		{
			gotoxy(x-19+i,y+8); printf("%c",strdfa8[70+i]); Sleep(8);	
		}
		while(!kbhit()){ ClearState(x+35,y-1,0); Sleep(200); PrintState(x+35,y-1,'D',0,1); Sleep(200); }
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		for(int i = 0; i < 21; i++)
		{
			textcolor(15); gotoxy(x+30+i,y+8); printf("%c",strdfa9[i]); Sleep(8);
		}
		
		for(int i = 0; i < 29; i++)
		{
			gotoxy(x-19+i,y+9); printf("%c",strdfa9[22+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		for(int i = 0; i < 44; i++)
		{
			gotoxy(x+11+i,y+9); printf("%c",strdfa9[52+i]); Sleep(8);
		}
		
		for(int i = 0; i < 40; i++)
		{
			gotoxy(x-19+i,y+10); printf("%c",strdfa9[97+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		PrintState(x+35,y-1,'D',0,0);
		//End discuss parts
		
		//Start discuss 5 tuples
		char str5tup1[64] = "Furthermore, every DFA can be defined using 5 tuples which are:";
		
		ClearDialogBorder(x-19,y+7,76,4);
		ClearAssistant(x+49,y-2); gotoxy(x+53,y-2); printf(" "); PrintAssistant(x-8,y-2,0,0);
		
		for(int i = 0; i < 64; i++)
		{
			gotoxy(x-19+i,y+7); printf("%c",str5tup1[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		gotoxy(x-19,y+8); printf("1. "); Sleep(16); printf("Q   "); Sleep(16); printf("2. "); Sleep(16); printf("%c   ",228); Sleep(16);
		printf("3. "); Sleep(16); printf("q%c   ",249); Sleep(16); printf("4. "); Sleep(16); printf("F   "); Sleep(16);
		printf("5. "); Sleep(16); printf("%c",235); Sleep(16);
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		ClearDialogBorder(x-19,y+7,76,4);
		
		char str5tup2[37] = "Q - represents the set of all states";
		char str5tup3[24] = "- represents the inputs";
		char str5tup4[29] = "- represents the start state";
		char str5tup5[39] = "F - represents the set of final states";
		char str5tup6[70] = "- represents a transition function that maps from Q x sigma -> (to) Q";
		
		for(int i = 0; i < 37; i++)
		{
			gotoxy(x-19+i,y+7); printf("%c",str5tup2[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		gotoxy(x+50,y-2); printf("Q "); textcolor(11); printf(" = {"); textcolor(15); printf("A,B,C,D"); textcolor(11); printf("}");
		
		textcolor(15); gotoxy(x+19,y+7); printf("%c ",228); Sleep(8);
		for(int i = 0; i < 24; i++)
		{
			gotoxy(x+21+i,y+7); printf("%c",str5tup3[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		gotoxy(x+50,y-1); printf("%c ",228); textcolor(11); printf(" = {"); textcolor(15); printf("0,1"); textcolor(11); printf("}");
			
		textcolor(15); gotoxy(x-19,y+8); printf("q%c ",249); Sleep(8);
		for(int i = 0; i < 29; i++)
		{
			gotoxy(x-16+i,y+8); printf("%c",str5tup4[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		gotoxy(x+50,y); printf("q%c ",249); textcolor(11); printf("= {"); textcolor(15); printf("A"); textcolor(11); printf("}");
		
		textcolor(15); gotoxy(x-19,y+8); printf("q%c ",249); Sleep(8);
		for(int i = 0; i < 39; i++)
		{
			gotoxy(x+19+i,y+8); printf("%c",str5tup5[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		gotoxy(x+50,y+1); printf("F "); textcolor(11); printf(" = {"); textcolor(15); printf("C"); textcolor(11); printf("}");
		
		textcolor(15); gotoxy(x-19,y+9); printf("%c ",235); Sleep(8);
		for(int i = 0; i < 70; i++)
		{
			gotoxy(x-17+i,y+9); printf("%c",str5tup6[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		gotoxy(x+56,y+3); printf("%c ",235); textcolor(11); printf("= ");
		gotoxy(x+62,y+2); textcolor(11); printf("%c%c%c%c%c%c%c%c%c",218,196,196,196,194,196,196,196,191);
		gotoxy(x+62,y+3); printf("%c   %c   %c",179,179,179);  gotoxy(x+62,y+4); printf("%c%c%c%c%c%c%c%c%c",195,196,196,196,197,196,196,196,180);
		gotoxy(x+62,y+5); printf("%c   %c   %c",179,179,179);  gotoxy(x+62,y+6); printf("%c%c%c%c%c%c%c%c%c",195,196,196,196,197,196,196,196,180); 
		gotoxy(x+62,y+7); printf("%c   %c   %c",179,179,179);  gotoxy(x+62,y+8); printf("%c%c%c%c%c%c%c%c%c",195,196,196,196,197,196,196,196,180);
		gotoxy(x+62,y+9); printf("%c   %c   %c",179,179,179); gotoxy(x+62,y+10); printf("%c%c%c%c%c%c%c%c%c",192,196,196,196,193,196,196,196,217);
		
		textcolor(15);
		gotoxy(x+64,y+1); printf("0   1");
		gotoxy(x+61,y+3); printf("A"); gotoxy(x+61,y+5); printf("B"); gotoxy(x+61,y+7); printf("C"); gotoxy(x+61,y+9); printf("D");
		gotoxy(x+64,y+3); printf("B"); gotoxy(x+68,y+3); printf("B");
		gotoxy(x+64,y+5); printf("C"); gotoxy(x+68,y+5); printf("C");
		gotoxy(x+64,y+7); printf("D"); gotoxy(x+68,y+7); printf("D");
		gotoxy(x+64,y+9); printf("D"); gotoxy(x+68,y+9); printf("D");
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		ClearDialogBorder(x-19,y+7,76,4);
		
		char strbreak1[78] =  "Alright! I'll be off then. Try to simulate different inputs for this machine.";
		char strbreak2[154] = "Feel free to choose between going back to the home screen then proceeding with Non-Deterministic Finite Automata and going to example 2. Happy learnings!";
		
		for(int i = 0; i < 77; i++)
		{
			gotoxy(x-19+i,y+7); printf("%c",strbreak1[i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		
		for(int i = 0; i < 73; i++)
		{
			gotoxy(x-19+i,y+8); printf("%c",strbreak2[i]); Sleep(8);
		}
		
		for(int i = 0; i < 69; i++)
		{
			gotoxy(x-19+i,y+9); printf("%c",strbreak2[74+i]); Sleep(8);
		}
		
		for(int i = 0; i < 10; i++)
		{
			gotoxy(x-19+i,y+10); printf("%c",strbreak2[143+i]); Sleep(8);
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; } 
		else if(ch == '1') { DFAFirstExample(); break; }
		else if(ch == '2') { DFASecondExample(); break; }
		//End discuss 5 tuples
	}while(int(ch) != 13 && toupper(nav) != 'H'); 
	
	if(int(ch) == 13) DFAFirstExample();
}

void Assessment()
{
	char ch = ' ', ans[15], correct[15];
	do
	{
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		gotoxy(3,4); printf("This is designed to "); textcolor(11); printf("test "); textcolor(15); printf("your skills on the basics of Finite-State Automata. The exam will");
		
		
		gotoxy(3,5); printf("consist of "); textcolor(11); printf("ten "); textcolor(15); printf("items with "); textcolor(11); printf("half "); 
		textcolor(15); printf("of it as "); textcolor(11); printf("identification test "); textcolor(15); printf("while the other half as a");
		
		gotoxy(3,6); textcolor(11); printf("multiple-choice test.");
	
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		textcolor(15); gotoxy(28,19); printf("Shall we get started then?");
		PrintAssistant(47,10,2,0);
		AssistantDialogBorder(25,16,50,5);
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		int ctr = 0;
		
		//1st Question
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		gotoxy(3,5); textcolor(11);printf("1. "); textcolor(15);printf("A machine designed to follow a predetermined sequence of operations or respond to");
		gotoxy(3,7);printf("encoded instructions.");
		gotoxy(10,9); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		if(stricmp(ans,"automaton") ==  0)
		{
			gotoxy(10,11); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,11); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("AUTOMATON");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//2nd Question
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		gotoxy(3,5); textcolor(11);printf("2. "); textcolor(15);printf("It deals with the automatons' logical process.");
		gotoxy(10,7); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		if(stricmp(ans,"automata theory") ==  0)
		{
			gotoxy(10,9); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,9); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("AUTOMATA THEORY");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//3rd Question
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		gotoxy(3,5); textcolor(11);printf("3. "); textcolor(15);printf("This is part of the 5-tuple and it represents the set of all states.");
		gotoxy(10,7); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		if(strcmp(ans, "Q") == 0)
		{
			gotoxy(10,9); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,9); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("Q");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//4th Question
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		gotoxy(3,5); textcolor(11);printf("4. "); textcolor(15);printf("It is a set of Strings.");
		gotoxy(10,7); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		if(stricmp(ans, "language") == 0)
		{
			gotoxy(10,9); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,9); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("LANGUAGE");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//5th Question
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		gotoxy(3,5); textcolor(11);printf("5. "); textcolor(15);printf("This is the state where the output is released.");
		gotoxy(10,7); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		if(stricmp(ans, "final state") == 0)
		{
			gotoxy(10,9); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,9); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("FINAL STATE");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//6th question
		SetBorder();
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		gotoxy(3,5); textcolor(11);printf("6. "); textcolor(15);printf("Define the illustration below:");
		gotoxy(3,7); textcolor(11);printf("a. "); textcolor(15);printf("A DFA that accepts all strings over {a,b} that contains the string aabb in it.");
		gotoxy(3,8); textcolor(11);printf("b. "); textcolor(15);printf("A DFA that accepts all strings over {a,b} that does not contain the string aabb in it.");
		gotoxy(3,9); textcolor(11);printf("c. "); textcolor(15);printf("A DFA that accepts all strings over {a,b} that contains the string bbab in it.");
		gotoxy(3,10); textcolor(11);printf("d. "); textcolor(15);printf("A DFA that accepts all strings over {a,b} that does not contain the string bbab in it.");
		
		textcolor(11); ArrowRight(3,17);  PrintState(7,16,'A',0,0);  textcolor(11); ArrowRight(12,17); PrintState(16,16,'B',0,0);
		textcolor(11); ArrowRight(21,17); PrintState(25,16,'C',0,0); textcolor(11); ArrowRight(30,17); PrintState(34,16,'D',0,0);
		textcolor(11); ArrowRight(39,17); PrintState(45,16,'E',1,0);
		
		textcolor(11); ArrowLoopUp(7,15); ArrowLoopUp(25,15); ArrowLoopRight(52,16);
		ArrowDown(18,19); gotoxy(18,22); printf(" "); gotoxy(9,21); printf("%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217);
		gotoxy(9,20); printf("%c",179); gotoxy(9,19); printf("^");
		ArrowDown(36,19); gotoxy(36,22); printf(" "); gotoxy(27,21); printf("%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217);
		gotoxy(27,20); printf("%c",179); gotoxy(27,19); printf("^");
		
		textcolor(15); gotoxy(9,12); printf("b"); gotoxy(27,12); printf("a");
		gotoxy(13,16); printf("a"); gotoxy(22,16); printf("a"); gotoxy(31,16); printf("b");
		gotoxy(40,16); printf("b"); gotoxy(56,17); printf("a,b");
		gotoxy(13,22); printf("b"); gotoxy(31,22); printf("a");
		gotoxy(10,25); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		
		if(stricmp(ans,"A") == 0)
		{
			gotoxy(10,27); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,27); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("A.");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//7th question
		SetBorder();
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		gotoxy(3,5); textcolor(11);printf("7. "); textcolor(15);printf("Which here is an acceptable input of the automata below:");
		gotoxy(3,7); textcolor(11);printf("a. "); textcolor(15);printf("abaaaabaaaa");
		gotoxy(3,8); textcolor(11);printf("b. "); textcolor(15);printf("bbaabaa");
		gotoxy(3,9); textcolor(11);printf("c. "); textcolor(15);printf("aaabbababba");
		gotoxy(3,10); textcolor(11);printf("d. "); textcolor(15);printf("babbaa");
		
		textcolor(11); ArrowRight(3,17);  PrintState(7,16,'A',0,0);  textcolor(11); ArrowRight(12,17); PrintState(16,16,'B',0,0);
		textcolor(11); ArrowRight(21,17); PrintState(25,16,'C',0,0); textcolor(11); ArrowRight(30,17); PrintState(34,16,'D',0,0);
		textcolor(11); ArrowRight(39,17); PrintState(45,16,'E',1,0);
		
		textcolor(11); ArrowLoopUp(7,15); ArrowLoopUp(25,15); ArrowLoopRight(52,16);
		ArrowDown(18,19); gotoxy(18,22); printf(" "); gotoxy(9,21); printf("%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217);
		gotoxy(9,20); printf("%c",179); gotoxy(9,19); printf("^");
		ArrowDown(36,19); gotoxy(36,22); printf(" "); gotoxy(27,21); printf("%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217);
		gotoxy(27,20); printf("%c",179); gotoxy(27,19); printf("^");
		
		textcolor(15); gotoxy(9,12); printf("b"); gotoxy(27,12); printf("a");
		gotoxy(13,16); printf("a"); gotoxy(22,16); printf("a"); gotoxy(31,16); printf("b");
		gotoxy(40,16); printf("b"); gotoxy(56,17); printf("a,b");
		gotoxy(13,22); printf("b"); gotoxy(31,22); printf("a");
		gotoxy(10,25); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		
		if(stricmp(ans,"C") == 0)
		{
			gotoxy(10,27); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,27); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("C.");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//8th question
		SetBorder();
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		gotoxy(3,5); textcolor(11);printf("8. "); textcolor(15);printf("Define the illustration below:");
		gotoxy(3,7); textcolor(11);printf("a. "); textcolor(15);printf("A DFA that accepts the string 01 and 1001");
		gotoxy(3,8); textcolor(11);printf("b. "); textcolor(15);printf("A DFA that accepts the string 0 and 1");
		gotoxy(3,9); textcolor(11);printf("c. "); textcolor(15);printf("A DFA that accepts the string 01 or at least one '1' followed by a '0'");
		gotoxy(3,10); textcolor(11);printf("d. "); textcolor(15);printf("A DFA that accepts the string  01 or 10");
		
		textcolor(11); ArrowRight(3,18); PrintState(7,17,'A',0,0); textcolor(11); ArrowUp(9,16); ArrowDown(9,20);
		PrintState(7,11,'B',0,0);  textcolor(11); ArrowLoopLeft(6,13); PrintState(7,23,'C',0,0); textcolor(11); ArrowRight(12,12); ArrowRight(12,24);
		PrintState(18,12,'D',1,0); PrintState(18,22,'E',1,0); 
		
		gotoxy(8,15); printf("1"); gotoxy(8,21); printf("0"); gotoxy(13,11); printf("0"); gotoxy(13,23); printf("1"); gotoxy(4,12); printf("1");
		gotoxy(10,26); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		if(stricmp(ans, "C") == 0)
		{
			gotoxy(10,28); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,28); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("\"C\"");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		//9th Question
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		textcolor(11); ArrowRight(37,6); PrintState(42,5,'A',0,0); textcolor(11); ArrowLoopDown(42,8);
		textcolor(11); ArrowRight(48,6); PrintState(55,5,'B',1,0); 
		gotoxy(49,5); printf("1"); gotoxy(43,11);printf("0,1");
		
		gotoxy(3,14); textcolor(11);printf("9. "); textcolor(15);printf("Define the illustration above:");
		gotoxy(10,16); printf("a. An NFA that accepts all strings that ends with '1'");
		gotoxy(10,18); printf("b. An NFA that accepts '1' only");
		gotoxy(10,20); printf("c. An NFA that accepts all strings that ends with '0'");
		gotoxy(10,22); printf("d. An NFA that only accepts strings with '0' to start");
		gotoxy(10,24); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		if(stricmp(ans, "a") == 0)
		{
			gotoxy(10,26); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,26); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("\"A\"");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//10th Question
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		textcolor(11); ArrowRight(37,6); PrintState(42,5,'A',0,0); textcolor(11); ArrowLoopDown(42,8);
		textcolor(11); ArrowRight(48,6); PrintState(55,5,'B',1,0); 
		gotoxy(49,5); printf("1"); gotoxy(43,11);printf("0,1");
		
		gotoxy(3,14); textcolor(11);printf("10. "); textcolor(15);printf("Which here is an acceptable input of the automata?");
		gotoxy(10,16); printf("a. 1000001");
		gotoxy(10,18); printf("b. 100");
		gotoxy(10,20); printf("c. 10101000");
		gotoxy(10,22); printf("d. 0");
		gotoxy(10,24); textcolor(11); printf("ANSWER => ");
		textcolor(15); gets(ans);
		if(stricmp(ans, "a") == 0)
		{
			gotoxy(10,26); textcolor(11); printf("CORRECT");
			ctr++;
		}
		else
		{
			gotoxy(10,26); textcolor(11); printf("INCORRECT. ");
			textcolor(15); printf("The correct answer is => "); textcolor(11); printf("\"A\"");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//Results
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		PrintAssistant(47,10,2,0);
		AssistantDialogBorder(25,16,50,5);
		textcolor(15); gotoxy(28,19); printf("You got a score of %d out of 10.",ctr);	
		
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
		//Assessment
		SetBorder();
		
		gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
		textcolor(11); gotoxy(3,2); printf("%c ",178);
		textcolor(15); printf("ASSESSMENT");
		
		PrintAssistant(47,10,2,0);
		AssistantDialogBorder(25,16,50,5);
		textcolor(15); gotoxy(28,19); 
		if(ctr>=0 && ctr<=4)
		{
			printf("Looks like you need to work on your skills.");	
		}
		else if (ctr>=5 && ctr <= 7)
		{
			printf("You passed! It needs work but you passed!");
		}
		else if (ctr>= 8 && ctr<=10)
		{
			printf("Great work! You know you way around this now.");
		}
		
		ch = getch();
		if(toupper(ch) == 'H') { nav = 'H'; break; }
		
	}while(int (ch) != 13 && toupper(nav) != 'H');
	if(int(ch) == 13) { nav = 'R'; }
}

void ReferencePage()
{
	char ch = ' ';
	SetBorder();
	
	gotoxy(83,28); textcolor(11); printf("["); textcolor(15); printf("H"); textcolor(11); printf("]"); textcolor(15); printf("OME SCREEN");
		
	textcolor(11); gotoxy(3,2); printf("%c ",178);
	textcolor(15); printf("REFERENCES");
		
	textcolor(11); gotoxy(5,4); printf("%c ",254); gotoxy(5,7); printf("%c ",254); gotoxy(5,11); printf("%c ",254); 
	gotoxy(5,14);  printf("%c ",254); gotoxy(5,18); printf("%c ",254); 
	gotoxy(3,22);  printf("%c ",178); gotoxy(5,24); printf("%c ",254); gotoxy(40,24); printf("%c ",254); 
	
	textcolor(15); 
	
	gotoxy(7,4);   printf("automaton. 2019. In Merriam-Webster.com. Retrieved November 26, 2019, from");
	gotoxy(12,5);  printf("https://www.merriam-webster.com/dictionary/automata");
	
	gotoxy(7,7);   printf("Dar Aziz, A., Cackler, J., & Yung, R. (2004, September). Basics of Automata Theory.");
	gotoxy(12,8);  printf("Stanford University. Retrieved from https://cs.stanford.edu/people/eroberts/");
	gotoxy(12,9); printf("courses/soco/mprojects/2004-05/automata-theory/basics.html");
	
	gotoxy(7,11);  printf("Deterministic Finite Automaton. (2019). Tutorials Point. Retrieved from ");
	gotoxy(12,12); printf("https://www.geeksforgeeks.org/introduction-of-finite-automata/");
	
	gotoxy(7,14);  printf("Neso Academy. (2019, October 24). Theory of Computation & Automata Theory.");
	gotoxy(12,15); printf("[Youtube Playlist]. Neso Academy. Retrieved from");
	gotoxy(12,16); printf("https://www.youtube.com/playlist?list=PLBlnK6fEyqRgp46KUv4ZY69yXmpwKOIev");
	
	gotoxy(7,18);  printf("Non-Deterministic Finite Automaton. (2019). Tutorials Point. Retrieved from");
	gotoxy(12,19); printf("https://www.tutorialspoint.com/automata_theory/non_deterministic");
	gotoxy(12,20); printf("_finite_automaton.htm");
	
	gotoxy(5,22);  printf("CONTACT DETAILS");
	gotoxy(7,24);  printf("VINCENT GERARD CARO");
	gotoxy(7,25); printf("vincentcaro4@gmail.com");
	gotoxy(42,24);  printf("CARL LORENZ REYES");
	gotoxy(42,25); printf("carllorenzreyes@gmail.com");
	
	ch = getch();
	nav = 'H';
}

main()
{
	system("mode con: cols=100 lines=30");
	do
	{
		switch(toupper(nav))
		{
			case 'I': AssistantIntro(); break;
			case 'H': HomeScreen(); break;
			case 'B': TheoryOfComputingBackground(); break;
			case 'T': DefinitionOfTerms(); break;
			case 'D': DFA(); break;
			case 'N': NFA(); break;
			case 'A': Assessment(); break;
			case 'R': ReferencePage(); break; 
			case 'E': ExitProgram(); break;
		}
	}while(nav != 'Z');
}
