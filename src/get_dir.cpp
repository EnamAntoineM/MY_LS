/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** get_dir.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

std::vector<std::string> get_dir1(std::vector<std::string>& file, std::vector<std::string> path, int i)
{
    for (std::string& in_array : file) {
        in_array.insert(0, path[i] + "/");
    }
    return file;
}

std::vector<std::string> get_dir2(std::vector<std::string> file, std::string path)
{
    for (std::string& in_array : file) {
        in_array.insert(0, path + "/");
    }
    return file;
}

std::vector<std::string> get_file_path(std::vector<std::string>& file, std::string path)
{
    for (std::string& in_array : file) {
        in_array.insert(0, path + "/");
    }
    return file;
}

