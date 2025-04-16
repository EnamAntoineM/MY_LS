/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** display.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void simple_print(std::vector<std::string> to_print)
{
    for (size_t i = 0; i < to_print.size(); i++) {
        cout << to_print[i] << endl;
    }
}

void display(std::vector<std::string> indir)
{
    int control = longstring(indir);
    int limit = step(control);
    size_t rows = 0;
    size_t index = 0;

    if (indir.empty()) return;
    rows = (indir.size() + limit - 1) / limit;
    for (size_t row = 0; row < rows; row++) {
        for (int col = 0; col < limit; col++) {
            if (index < indir.size()) {
                std::cout << std::left << std::setw(control) << indir[index];
            }
            index++;
        }
        std::cout << endl;
    }
}
