/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** tflag.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void stime(std::vector<std::string>& files, std::vector<std::string> copy)
{
    std::vector<int> indices(files.size());
    std::vector<std::string> sortedFiles(files.size());
    struct stat time1;
    struct stat time2;

    for (size_t i = 0; i < files.size(); ) {
        indices[i] = i;
        i++;
    }
    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
        lstat(copy[a].c_str(), &time1);
        lstat(copy[b].c_str(), &time2);
        return time1.st_mtime > time2.st_mtime;
    });
    for (size_t i = 0; i < files.size(); i++) {
        sortedFiles[i] = files[indices[i]];
    }
    files = sortedFiles;
}


