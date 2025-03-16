/*
 * * MY_PROJECT (IDEA FROM EPITECH)
 * * File: formatting.cpp
 * * MY_LS
 * * Author: Enam KODJOH-KPAKPASSOU
 * * Email: eakodjoh-kpakpassou.st.ug.edu.gh
 * * Description: 
 */

#include "../include/my.h"

//Get terminal characters width
int tcharwidth(void)
{
    struct winsize terminal;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal) == -1) {
        return 80; // Default width if retrieval fails
    }
    return terminal.ws_col;
}

void maxi(std::vector<int>& list, int size)
{
    int bait = 0;

    for(int i = 0; i < (size - 1); i++){
        if(list[i] < list[i + 1]){
            bait = list[i];
            list[i] = list[i + 1];
            list[i + 1] = bait;
        }
    }
}

int longstring(std::vector<std::string> content)
{
    int size = content.size();
    std::vector<int> array(size, 0);
    int longest = 0;

    for(int i = 0; i < size; i++){
        array[i] = content[i].size();
    }
    for(int j = 0; j < size; j++){
        maxi(array, size);
    }
    longest = array[0];
    return longest + 3;
}

int step(std::vector<std::string> astring)
{
    int column = tcharwidth();
    int lstring = longstring(astring);
    int step = column / lstring;

    if(step > 7){
        step = 7;
    }
    return step;
}
