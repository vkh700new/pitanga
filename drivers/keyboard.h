#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "io.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler"
#endif

int get_kb_sh();
int get_kb_cl();
int get_kb_ct();
int get_kb_h();

char get_kbk();
