#include "neslib.h"
#include <string.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

const char* words[] = {
  "HELLO, WORLD!",
  " ",
  "NAME:   Phyllis",
  "CITY:   Aurora",
  "SCHOOL: IMSA",
  " ",
  "FAVORITES",
  "  COLOR:    Green",
  "  SUBJECT:  Programming",
  "  SPORT:    Badminton",
  "  SEASON:   Summer",
  "  FOOD:     Sushi",
  "  DRINK:    Bubble Tea",
};

#define WORD_COUNT (sizeof(words) / sizeof(words[0]))

// main function, run after console reset
void main(void) {
  char i;

  // set palette colors
  pal_col(0, 0x14);  // background color
  pal_col(1, 0x0F);  // Black
  pal_col(2, 0x30);  // Fuchsia
  pal_col(3, 0x30);  // Fuchsia
  
  // Disable rendering before updating VRAM
  ppu_off();

  for (i = 0; i < WORD_COUNT; i++) {
      vram_adr(NTADR_A(2, (i+1)*2));
      // Write the current word to VRAM
      vram_write(words[i], strlen(words[i]));
  }

  // enable PPU rendering (turn on screen)
  ppu_on_all();

  // infinite loop
  while (1) ;
}