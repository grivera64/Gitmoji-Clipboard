/*

    Name: clear.h
    Purpose: Adjusts the clear_screen() function
             for different OS
    Author: grivera64

*/

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif