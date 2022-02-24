/*

    Name: EmojiList.h
    Purpose: Stores the EmojiList class for storing read data of Emojis.txt
    Author: grivera64

*/

#ifndef EMOJILIST_H
#define EMOJILIST_H

#include <iostream>
#include <string>
#include <vector>

class EmojiList
{

    int insertOrder;

public:
    std::vector <std::string> details;
    std::vector <std::string> labels;

    void add(int order, std::string detail, std::string label);
    int getSize();
    std::string getDetail(int pos);
    std::string getLabel(int pos);


};

#endif