/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** formatting.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
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

void maxi(std::vector<int>& list, int size, bool& swap) {
    swap = false;

    for (int i = 0; i < size - 1; i++) {
        if (list[i] < list[i + 1]) {
            std::swap(list[i], list[i + 1]);
            swap = true;
        }
    }
}

int longstring(std::vector<std::string> content)
{
    int size = content.size();
    bool swap;
    if (size == 0) return 3;
    std::vector<int> array(size, 0);

    for (int i = 0; i < size; i++) {
        if (!content[i].empty()) {
            array[i] = content[i].size();
        }
    }
    for (int j = 0; j < size - 1; j++) {
        maxi(array, size, swap);
        if (!swap) {
            break;
        }
    }
    return array[0] + 3;
}

int step(int lstring)
{
    int column = tcharwidth();
    int step = column / lstring;

    if(step > 7){
        step = 6;
    }
    return step;
}
