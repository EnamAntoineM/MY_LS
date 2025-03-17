/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** recursive.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

std::vector<std::string> append_path(std::vector<std::string> file, std::vector<std::string> path, int i)
{
    for (std::string& in_array : file) {
        in_array.insert(0, path[i] + "/");
    }
    return file;
}

std::vector<std::string> recursive(std::vector<std::string> filelist, std::vector<std::string> path, int i)
{
    struct stat utility;
    struct dirent *rep = NULL;
    DIR *r = NULL;
    std::vector<std::string> directories = append_path(filelist, path, i);

    for (size_t i = 0; i < directories.size();) {
        lstat(directories[i].c_str(), &utility);
        if (!S_ISDIR(utility.st_mode)) {
            directories.erase(directories.begin() + i); //the erase method requires an iterator.
            //Directories.begin() points at the beginning of the array and + i specifies the elemnt that has to be deleted.
        } else {
            i++;
        }
    }
    return directories;
}
