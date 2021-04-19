/*

    Name: EmojiList.h
    Purpose: Stores the EmojiList class for storing read data of Emojis.txt
    Author: grivera64

*/

#include <iostream>
#include <vector>
#ifndef EMOJILIST_H
#define EMOJILIST_H
    class EmojiList
    {

        public:
            int insertOrder;
            std::vector <std::string> details;
            std::vector <std::string> labels;

            void add(int order, std::string detail, std::string label);
            int getSize();
            std::string getDetail(int pos);
            std::string getLabel(int pos);


    };
#endif