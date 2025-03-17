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
    if(argc == 1){
        parameter = {"."};
        cout << "Hey my_ls is working bro" << endl;
        my_ls(parameter);
    }
    else{
        parameter = std::vector<std::string>(argv + 1, argv + argc); //skipping the first element of argv which is the program name
        my_ls(parameter);
    }
    return 0;
}

//write a function that delete every entry that starts with "."
//Have a function that if the flag -R is detected look for the directories in the array of files and put them in a different array
//
