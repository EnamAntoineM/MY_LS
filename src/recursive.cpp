/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** recursive.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

std::vector<std::string> get_dir1(std::vector<std::string> file, std::vector<std::string> path, int i)
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

std::vector<std::string> get_dir2(std::vector<std::string> file, std::string path)
{
    struct stat utility;

    for (std::string& in_array : file) {
        in_array.insert(0, path + "/");
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

void get_dir_content(std::string parameter)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    std::vector<std::string> content;
    std::vector<std::string> lcontinue;

    std::cout << endl << parameter << endl;
    r = opendir(parameter.c_str());
    if(r == NULL){
        fprintf(stderr, "my_ls : Cannot access: No such file or directory\n");
    }
    rep = readdir(r);
    while(rep != NULL){
        content.emplace_back(rep->d_name);
        rep = readdir(r);
    }
    closedir(r);
    regsort(content);
    display(content);
    cout << endl;
    lcontinue = get_dir2(content, parameter);
    if (!lcontinue.empty()) {
        for (size_t i = 2; i < lcontinue.size(); i++) {
            get_dir_content(lcontinue[i]);
        }
    }
}

void recursive(std::vector<std::string> filelist, std::vector<std::string> path, int i)
{
    struct stat utility;
    struct dirent *rep = NULL;
    DIR *r = NULL;
    std::vector<std::string> directories = get_dir1(filelist, path, i);

    cout << endl;
    if (!directories.empty()) {
        for (size_t j = 0; j < directories.size(); j++) {
            if (directories[j][0] != '.') {
                get_dir_content(directories[j]);
            }
        }
    }
}
