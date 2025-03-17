/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** recursive.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

std::vector<std::string> get_dir(std::vector<std::string> file, std::vector<std::string> path, int i)
{
    struct stat utility;

    for (std::string& in_array : file) {
        in_array.insert(0, path[i] + "/");
    }
    for (size_t j = 0; j < file.size();) {
        lstat(file[j].c_str(), &utility);
        if (!S_ISDIR(utility.st_mode)) {
            file.erase(file.begin() + j); //the erase method requires an iterator.
            //file.begin() points at the beginning of the array and + i specifies the elemnt that has to be deleted.
        } else {
            j++;
        }
    }

    return file;
}

std::vector<std::string> recursive(std::vector<std::string> filelist, std::vector<std::string> path, int i)
{
    struct stat utility;
    struct dirent *rep = NULL;
    DIR *r = NULL;
    std::vector<std::string> directories = get_dir(filelist, path, i);

    return directories;
}
