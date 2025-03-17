/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** main.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    std::vector<std::string> parameter;
    bool all = false;
    if(argc = 1){
        parameter = {"."};
        cout << "Hey my_ls is working bro" << endl;
        my_ls();
    }
    else{
        parameter = std::vector<std::string>(argv + 1, argv + argc); //skipping the first element of argv which is the program name
    }
    return 0;
}
