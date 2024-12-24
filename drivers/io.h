#include <stdbool.h> 
#include <stddef.h> 
#include <stdint.h> 

#if defined(__linux__) 
#error "You are not using a cross-compiler, you will most certainly run into trouble" 
#endif 
#if !defined(__i386__) 
#error "This needs to be compiled with a ix86-elf compiler" 
#endif 

void outb(uint16_t port, uint8_t val); 
uint8_t inb(uint16_t port);
