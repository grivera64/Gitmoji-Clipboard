/*

    Name: clear.h
    Purpose: Adjusts the clear_screen() function
             for different OS
    Author: grivera64

*/

#include <cstdlib>

/* Clear's the screen */
void clear_screen()
{
#ifdef _WIN32
    // Assume WindowsOS
    system("cls");
#else
    // Assume Linux or MacOS
    system ("clear");
#endif
}