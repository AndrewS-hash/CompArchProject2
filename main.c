#include "stdlib.h"
#define printf R_printf

#include "dhry_bin.h"

int main()
{
    // Initialize pointer pointing at 0x4000 and start of instr array
    uint32_t dhry_addr = 0x00004000;
    uint32_t* cpy2 = (uint32_t*)dhry_addr;
    uint32_t cnt;
    uint32_t size = sizeof(instr) / 4;

    printf("Project 2, Bootloader Version 0.1, CS 4200 Computer Architecture, Spring 2022.\n\n");

    // Loop through each value in instr[], store it in address location addrPtr, incurment both
    for (cnt = 0; cnt < size; cnt++)
    {
        *(cpy2 + cnt) = instr[cnt];
    }

    //Declare function start at 0x4000, call function for execution
    /*
    void (*fun_ptr)(void) = (void*)dhry_addr;
    (*fun_ptr)();
    */

    goto *cpy2;

    //asm volatile("j   0x4000\n\t");

}
