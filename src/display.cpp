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
        cout << to_print[i] << endl;
    }
}

void print_it(int limit, int control, std::vector<std::string> indir, size_t see, int& format, size_t& i, std::string& sorted)
{
    if (format < limit) {
        see = control - indir[i].size();
        if(indir.size() < 10){
            see = 2;
        }
        std::string spaces(see, ' ');
        indir[i].append(spaces);
        sorted.append(indir[i]);
        format++;
    } else {
        see = control - indir[i].size();
        if(indir.size() < 10){
            see = 2;
        }
        std::string spaces(see, ' ');
        indir[i].insert(0, "\n").append(spaces);
        sorted.append(indir[i]);
        format = 0;
    }
    printf("%s",sorted.c_str());
}

void display(std::vector<std::string> indir, flag flags, size_t i, std::string& sorted, int& format)
{
    int control = longstring(indir, flags);
    int limit = step(indir, flags, control);
    size_t see = 0;

    if (indir.empty()) return;
    print_it(limit, control, indir, see, format, i, sorted);
}
