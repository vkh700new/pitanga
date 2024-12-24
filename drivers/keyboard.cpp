#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "io.h"
#include "keyboard.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler"
#endif

int KB_SH = 0;
int KB_CL = 0;
int KB_CT = 0;
int KB_H = 0;

int get_kb_sh() {
  return KB_SH;
}

int get_kb_cl() {
  return KB_CL;
}

int get_kb_ct() {
  return KB_CT;
}

int get_kb_h() {
  return KB_H;
}

// get keyboard key
// -1 Nothing
char get_kbk() {
  uint8_t key = inb(0x60);
  
  switch (key) {
    case 0x1E:
      return 'A';
      break;
    case 0x30:
      return 'B';
      break;
    case 0x2E:
      return 'C';
      break;
    case 0x20:
      return 'D';
      break;
    case 0x12:
      return 'E';
      break;
    case 0x21:
      return 'F';
      break;
    case 0x22:
      return 'G';
      break;
    case 0x23:
      return 'H';
      break;
    case 0x17:
      return 'I';
      break;
    case 0x24:
      return 'J';
      break;
    case 0x25:
      return 'K';
      break;
    case 0x26:
      return 'L';
      break;
    case 0x32:
      return 'M';
      break;
    case 0x31:
      return 'N';
      break;
    case 0x18:
      return 'O';
      break;
    case 0x19:
      return 'P';
      break;
    case 0x10:
      return 'Q';
      break;
    case 0x13:
      return 'R';
      break;
    case 0x1F:
      return 'S';
      break;
    case 0x14:
      return 'T';
      break;
    case 0x16:
      return 'U';
      break;
    case 0x2F:
      return 'V';
      break;
    case 0x11:
      return 'W';
      break;
    case 0x2D:
      return 'X';
      break;
    case 0x15:
      return 'Y';
      break;
    case 0x2C:
      return 'Z';
      break;
    case 0x39:
      return ' ';
      break;
    case 0x1C:
      return '\n';
      break;
  }
  
  return -1;
}
