//**** 0. Documentation Section
//  This program calculates the area of square shaped rooms
//  Author: Ramesh Yerraballi & Jon Valvano
//  Date: 6/28/2013
//
// 1. Pre-processor Directives Section
#include <stdio.h>  // Diamond braces for sys lib: Standard I/O
#include <stdbool.h>
#include <stdint.h>
#include "uart.h"   // Quotes for user lib: UART lib

// 2. Global Declarations section
// 3. Subroutines Section
// MAIN: Mandatory routine for a C program to be executable
int main(void) {
  UART_Init();  // call subroutine to initialize the uart
  printf("This program calculates areas of square-shaped rooms\n");
}
