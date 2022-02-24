/*

    Name: EmojiList.cpp
    Purpose: Implements the functions declared in EmojiList.h
    AUthor: grivera64

*/

#include "EmojiList.h"
#include <iostream>
#include <string>
#include <vector>

/* Adds a single entry to the list */
void EmojiList::add(int order, std::string detail, std::string label)
{

    insertOrder = order;

    details.push_back(detail);
    labels.push_back(label);

}

/* Returns the number of entries in the list */
int EmojiList::getSize()
{

    return details.size();

}

/* Returns the detail of the Emoji entry as a string based on its position */
std::string EmojiList::getDetail(int pos)
{

    if (details.size() < pos) return NULL;

    /* Look for matching position */
    int currPos = 0;
    for (auto data : details)
    {

        if (currPos++ == pos) return data;

    }

    return NULL;

}

/* Returns the label for the GitMoji as a string for copying */
std::string EmojiList::getLabel(int pos)
{

    pos--;

    if (labels.size() < pos) return NULL;

    int currPos = 0;

    /* Looks for matching position */
    for (auto data : labels)
    {

        if (currPos++ == pos) return data;

    }

    return NULL;

}