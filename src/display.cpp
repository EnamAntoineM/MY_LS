/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** display.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void printspace(std::vector<std::string> indir, int see)
{
    if(indir.size() < 10){
        see = 2;
    }
    for(int j = 0; j < see; j++){
        cout << " ";
    }
}

void print_it(int limit, int control, std::vector<std::string> indir, size_t see, int& format, size_t& i)
{
    if (format < limit) {
        see = control - indir[i].size() + 2;
        cout << indir[i];
        printspace(indir, see);
        format++;
    } else {
        cout << endl;
        format = 0;
        i--;
    }
}

void display(std::vector<std::string> indir, flag flags)
{
    int limit = step(indir, flags);
    int control = longstring(indir, flags);
    size_t see = 0;
    int format = 0;

    if (!indir.empty()) {
        for(size_t i = 0; i < indir.size(); i++) {
            if (flags.a) {
                if (indir[i][0] == '.') {
                    continue;
                } else {
                    print_it(limit, control, indir, see, format, i);
                }
            } else {
                print_it(limit, control, indir, see, format, i);
            }
        }
    }
}

void simple_print(std::vector<std::string> to_print)
{
    for (size_t i = 0; i < to_print.size(); i++) {
        cout << to_print[i] << endl;
    }
}
