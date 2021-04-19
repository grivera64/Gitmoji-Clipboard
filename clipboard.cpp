/*

    Name: clipboard.cpp
    Purpose: Copies data to keyboard
    Author: El virtuos

*/

#include <iostream>
#include <windows.h>
#include "clipboard.h"

/* Reference: https://stackoverflow.com/questions/55334538/text-to-clipboard?noredirect=1&lq=1 */
void copy_to_clipboard(const char *input)
{

    /* Attempt to open the clipboard */
    if(OpenClipboard(NULL))
    {

        /* Create a memory location for the clipboard's data */
        HGLOBAL heap;
        EmptyClipboard();

        /* make movable/init at 0 | allow storage of string + \0 char */
        heap = GlobalAlloc(GHND, strlen(input) + 1);                           //Allocate globally in memory

        if (heap)
        {

            /* Coverts heap to pointer */
            char *board = (char *) GlobalLock(heap);

            if (board)
            {
                /* Copy data to heap */
                strcpy(board, input);
                GlobalUnlock(heap);

                /* Copy heap to clipboard */
                SetClipboardData(CF_TEXT, heap);
            }

            GlobalFree(heap);

        }
        
        CloseClipboard();
    }

}