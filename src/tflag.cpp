/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** tflag.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void stime_f(std::vector<std::string>& files, bool& swap)
{
    std::string bait;
    struct stat time1;
    struct stat time2;

    for(size_t i = 0; i < (files.size() - 1); i++){
        lstat(files[i].c_str(), &time1);
        lstat(files[i+1].c_str(), &time2);
        if(time1.st_mtime < time2.st_mtime){
            bait = files[i];
            files[i] = files[i + 1];
            files[i + 1] = bait;
            swap = true;
        }
    }
}

void stime(std::vector<std::string>& files)
{
    bool swap = true;

    for(size_t i = 0; i < files.size(); i++){
        stime_f(files, swap);
        if (!swap) {
            break;
        }
    }
}


