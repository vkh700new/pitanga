#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "timer.h"
#include "io.h"

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler"
#endif

#define PIT_FREQUENCY 1193182
#define PIT_COMMAND_PORT 0x43
#define PIT_CHANNEL0_PORT 0x40

void wait(uint32_t ms) {
    uint32_t divisor = PIT_FREQUENCY / 10 * ms;

    outb(PIT_COMMAND_PORT, 0x36);

    outb(PIT_CHANNEL0_PORT, divisor & 0xFF);
    outb(PIT_CHANNEL0_PORT, (divisor >> 8) & 0xFF);
    
    for (uint32_t i = 0; i < divisor * 10; i++) {
        asm volatile ("nop");
    }
}

