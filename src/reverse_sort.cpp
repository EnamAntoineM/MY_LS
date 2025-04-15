/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** reverse_sort.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void reverse(std::vector<std::string>& array)
{
    std::vector<std::string> decoy = array;
    size_t re = array.size() - 1;

    for(size_t j = 0; j != array.size(); j++){
        array[j] = decoy[re];
        re--;
    }
}
