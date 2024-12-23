#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler"
#endif

KB_SH = 0
KB_CL = 0
KB_CT = 0

void get_states() {
  return {KB_SH,KB_CL,KB_CT};
}

char get_kbk() {
  
  return -1;
}
