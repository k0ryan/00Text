#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  gfxInitDefault();
  PrintConsole topScreen, bottomScreen;
  consoleInit(GFX_BOTTOM, &bottomScreen);
  consoleInit(GFX_TOP, &topScreen);
  // Declare variables
  int number = 0;
  int max = 0;
  int min = 0;
  int group = 0;
  int pos = 1;
  int first_press = 1;
  int text_lenght = pos;
  char text[13000];
  char abecedario[] = "aABCDEFGHIJKLMNOPQRSTUVWXYZ";
  // Main loop
  while (aptMainLoop())
  {
    hidScanInput();
    u32 kDown = hidKeysDown();
    text_lenght = pos;
    if(kDown & KEY_DUP)//abc
    {
      if (group != 1)
      {
        first_press = 1;
        group = 1;
      }
      if(first_press == 1)
      {
        number = 0;
      }
      first_press = 0;
      min = 1;
      max = 3;
      if(number == max)
      {
        number = min;
      }
      else if(number < max){
        number++;
      }
      consoleSelect(&bottomScreen);
      consoleClear();
      printf("%c", abecedario[number]);


    }
    if(kDown & KEY_DRIGHT)//def
    {
      if (group != 2)
      {
        first_press = 1;
        group = 2;
      }
      if(first_press == 1)
      {
        number = 3;
      }
      first_press = 0;
      min = 4;
      max = 6;
      if(number == max)
      {
        number = min;
      }
      else if(number < max){
        number++;
      }
      consoleSelect(&bottomScreen);
      consoleClear();
      printf("%c", abecedario[number]);

    }
    if(kDown & KEY_DDOWN)//ghi
    {
      if (group != 3)
      {
        first_press = 1;
        group = 3;
      }
      if(first_press == 1)
      {
        number = 6;
      }
      first_press = 0;
      min = 7;
      max = 9;
      if(number == max)
      {
        number = min;
      }
      else if(number < max){
        number++;
      }
      consoleSelect(&bottomScreen);
      consoleClear();
      printf("%c", abecedario[number]);

    }
    if(kDown & KEY_DLEFT)//jkl
    {
      if (group != 4)
      {
        first_press = 1;
        group = 4;
      }
      if(first_press == 1)
      {
        number = 9;
      }
      first_press = 0;
      min = 10;
      max = 12;
      if(number == max)
      {
        number = min;
      }
      else if(number < max){
        number++;
      }
      consoleSelect(&bottomScreen);
      consoleClear();
      printf("%c", abecedario[number]);

    }
    if(kDown & KEY_X)//mno
    {
      if (group != 5)
      {
        first_press = 1;
        group = 5;
      }
      if(first_press == 1)
      {
        number = 12;
      }
      first_press = 0;
      min = 13;
      max = 15;
      if(number == max)
      {
        number = min;
      }
      else if(number < max){
        number++;
      }
      consoleSelect(&bottomScreen);
      consoleClear();
      printf("%c", abecedario[number]);

    }
    if(kDown & KEY_A)//pqrs
    {
      if (group != 6)
      {
        first_press = 1;
        group = 6;
      }
      if(first_press == 1)
      {
        number = 15;
      }
      first_press = 0;
      min = 16;
      max = 19;
      if(number == max)
      {
        number = min;
      }
      else if(number < max){
        number++;
      }
      consoleSelect(&bottomScreen);
      consoleClear();
      printf("%c", abecedario[number]);

    }
    if(kDown & KEY_B)//tuv
    {
      if (group != 7)
      {
        first_press = 1;
        group = 7;
      }
      if(first_press == 1)
      {
        number = 19;
      }
      first_press = 0;
      min = 20;
      max = 22;
      if(number == max)
      {
        number = min;
      }
      else if(number < max){
        number++;
      }
      consoleSelect(&bottomScreen);
      consoleClear();
      printf("%c", abecedario[number]);

    }
    if(kDown & KEY_Y)//wxyz
    {
      if (group != 8)
      {
        first_press = 1;
        group = 8;
      }
      if(first_press == 1)
      {
        number = 23;
      }
      first_press = 0;
      min = 24;
      max = 26;
      if(number == max)
      {
        number = min;
      }
      else if(number < max){
        number++;
      }
      consoleSelect(&bottomScreen);
      consoleClear();
      printf("%c", abecedario[number]);

    }
    if(kDown & KEY_R)
    {
      pos--;
      consoleSelect(&topScreen);
      consoleClear();
      for(int i = 1; i < pos; i++)
      {
        printf ("%c", text[i]);
      }
    }

    if(kDown & KEY_SELECT)
    {
      consoleSelect(&topScreen);
      consoleClear();
      printf("min --> %d", min);
      printf("  //  ");
      printf("num --> %d", number);
      printf("  //  ");
      printf("max --> %d", max);
      printf("  //  ");
      printf("pos --> %d", pos);
      printf("  //  ");
      printf("fst --> %d", first_press);
      printf("  //  ");
    }
    if(kDown & KEY_L)
    {
      consoleSelect(&topScreen);
      printf("%c", abecedario[number]);
      text[pos] = abecedario[number];
      pos++;
      first_press = 1;
    }
    if(kDown & KEY_ZL)
    {
      consoleSelect(&topScreen);
      printf(" ");
      //text[pos] = " ";

    }
    if(kDown & KEY_ZR)
    {
      consoleSelect(&topScreen);
      consoleClear();
      for(int i = 1; i < pos; i++)
      {
        printf ("%c", text[i]);
      }
    }

  /*if(kDown & KEY_SELECT)
  {
    consoleSelect(&topScreen);
    consoleClear();
  }*/

  if (kDown & KEY_START)
    {
      /*FILE * file_ptr;
      file_ptr = fopen ("file1.txt", "w+");
      for(int i = 0; i <= pos; i++)
      {
        character = text[i];
        fprintf(file_ptr, character);
      }
      fclose(file_ptr);*/
      break;
    }
    gfxFlushBuffers();
    gfxSwapBuffers();
    //Wait for VBlank
    gspWaitForVBlank();
  }
  // Exit services
  gfxExit();

  return 0;
  }
