/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** fileinfo.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

std::vector<std::string> ftype(std::vector<std::string>& indir, struct stat file, int i)
{
    if (S_ISREG(file.st_mode)) indir[i] = '-';
    else if (S_ISDIR(file.st_mode)) indir[i] = 'd';
    else if (S_ISBLK(file.st_mode)) indir[i] = 'b';
    else if (S_ISCHR(file.st_mode)) indir[i] = 'c';
    else if (S_ISSOCK(file.st_mode)) indir[i] = 's';
    else if (S_ISLNK(file.st_mode)) indir[i] = 'l';
    else if (S_ISFIFO(file.st_mode)) indir[i] = 'p';
}

std::vector<std::string> info(std::vector<std::string> indir)
{
    struct stat file;
    std::vector<std::string> permissions;
    for(size_t i = 0; i < indir.size(); i++) {
        lstat(indir[i].c_str(), &file);
        if(lstat(indir[i].c_str(), &file) == -1){fprintf(stderr, "my_ls : Cannot access: No such file or directory\n");}
    }
}
