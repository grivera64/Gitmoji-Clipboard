/*

    Name: gitmojiClipboard.cpp
    Purpose: Runs the main program
    Author: grivera64

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <ctype.h>
#include <fstream>
#include "EmojiList.h"
#include "clipboard.h"
#include "clear.h"

#define PAGE_SIZE 10

// Represents the Emoji List user-defined Map Data Structure
// that tracks insertion order
EmojiList elist;

void readFile(std::string fileName);
void printChart(int pos);
void printInstructions();

/* Main Function */
int main(void)
{

    int startPos = 0;

    readFile("Emojis.txt"); // Read Emojis.txt

    /* Infinite loop for application while navigating until copied something */
    for (;;)
    {

        clrscr();

        std::cout << "grivera64's Gitmoji Application" << std::endl << std::endl;

        printChart(startPos);

        printInstructions();

        std::cout << "Please enter your selection: ";

        /* Get user input */
        std::string strselect;

        std::getline(std::cin, strselect);

        int selection;

        /* Convert to int if possible */
        try
        {

            selection = std::stoi(strselect);
        
        }
        /* Get first char as an int if not all an int */
        catch(const std::exception& e)
        {
            
            selection = strselect.front();

        }

        /* Check user selection */
        switch (selection)
        {

            // Next
            case 'N':
            case 'n':
                startPos += (startPos + PAGE_SIZE > elist.getSize()) ? 0 : PAGE_SIZE;
                break;
            // Previous
            case 'P':
            case 'p':
                startPos -= (startPos - PAGE_SIZE < 0) ? 0 : PAGE_SIZE;;
                break;
            // Exit
            case 'E':
            case 'e':
                return 0;
            // Copy
            default:

                if (isalpha(selection)) break;

                const char *arr = elist.getLabel(selection).c_str();

                if (arr)
                {

                    copy_to_clipboard(arr);
                    std::cout << "Saved " << elist.getLabel(selection) << " to clipboard!" << std::endl;
                
                }

                return 0; // Terminate Program

        }

    }

    return 0; // Terminate Program

}

/* Read file */
void readFile(std::string fileName)
{

    /* Open Input File Stream */
    std::ifstream file(fileName);

    /* Temp vals */
    std::string curr, next;
    int currPos = 0;

    /* Store data into elist */
    while (std::getline(file, curr))
    {

        if (std::getline(file, next))
        {

            elist.add(currPos++, curr, next);
        
        }
        else
        {

            break;

        }

    }

    /* Return void */
    return;

}

/* Print data to user */
void printChart(int pos)
{

    /* Set max and min data to show for the current page */
    int maxShow;
    
    if (pos < 0)
    {

        pos = 0;

    }

    if (pos > elist.getSize() || pos + PAGE_SIZE > elist.getSize())
    {

        pos = elist.getSize() - PAGE_SIZE - 1;
        maxShow = elist.getSize();

    }
    else
    {

        maxShow = pos + PAGE_SIZE;

    }

    for (int currPos = pos; currPos < maxShow; currPos++)
    {

        std::cout << currPos + 1 << ". " << elist.getDetail(currPos) << std::endl;

    }

}

/* Print user's options */
void printInstructions()
{

    std::cout << std::endl << "(N)ext, (P)revious, (##) Selection, (E)xit" << std::endl;

}