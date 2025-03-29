/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** display.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void simple_print(std::vector<std::string> to_print, flag flags)
{
    for (size_t i = 0; i < to_print.size(); i++) {
        if (!flags.a) {
            if (to_print[i][to_print[i].size() - 1] == '.') {
                continue;
            } else {
                cout << to_print[i] << endl;
            }
        }
    }
}

void print_it(int limit, int control, std::vector<std::string> indir, size_t see, int& format, size_t& i)
{
    if (format < limit) {
        see = control - indir[i].size();
        cout << indir[i];
        if(indir.size() < 10){
            see = 2;
        }
        for(int j = 0; j < see; j++){
            cout << " ";
        }
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

    if (indir.empty()) return;
    if (flags.l) {
        simple_print(indir, flags);
    } else {
        for(size_t i = 0; i < indir.size(); i++) {
            if (!flags.a && indir[i].back() == '.') continue;
            print_it(limit, control, indir, see, format, i);
        }
    }
}