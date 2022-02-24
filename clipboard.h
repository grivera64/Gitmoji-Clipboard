/*

    Name: clipboard.h
    Purpose: Includes implementation of clipboard.cpp into other .cpp files
    Authors: grivera64 and El virtuos

*/

#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <iostream>
#include <string>

void copy_to_clipboard(const char *data);

#ifndef _WIN32
std::string exec(const char* cmd);
#endif

#endif