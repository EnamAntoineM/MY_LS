/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** recursive.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void sort_it_for_R(std::vector<std::string> &content, std::string &parameter, std::vector<std::string> &tflags, flag &flags)
{
    std::vector<std::string> copy;

    regsort(content, flags);
    copy = content;
    if (flags.t) {
        tflags = get_file_path(copy, parameter);
        stime(content, copy);
        tflags.clear();
    }
    if (flags.r) {
        reverse(content);
    }
}

void get_dir_content(std::string parameter, flag &flags)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    struct stat type;
    std::vector<std::string> content;
    std::vector<std::string> lcontinue;
    std::vector<std::string> lflag;
    std::vector<std::string> tflags;

    lstat(parameter.c_str(), &type);
    if(lstat(parameter.c_str(), &type) == -1){
        perror("my_ls");
    } else if (S_ISDIR(type.st_mode)) {
        r = opendir(parameter.c_str());
        if (r == NULL) {
            perror(("my_ls: Cannot open " + parameter).c_str());
        } else {
            rep = readdir(r);
            while(rep != NULL){
                content.emplace_back(rep->d_name);
                rep = readdir(r);
            }
        }
        closedir(r);
        sort_it_for_R(content, parameter, tflags, flags);
        if (flags.l) {
            lflag = get_file_path(content, parameter);
            info(lflag, false);
            lflag.clear();
        }
        if (!flags.l) {
            display(content);
            lcontinue = get_dir2(content, parameter);
        } else {lcontinue = content;}

        if (!lcontinue.empty()) {
            for (size_t i = 0; i < lcontinue.size(); i++) {
                if (lstat(lcontinue[i].c_str(), &type) == -1) {
                    perror("my_ls");
                } else if (S_ISDIR(type.st_mode) && lcontinue[i].back() != '.') {
                    std::cout << endl << lcontinue[i] << endl;
                    get_dir_content(lcontinue[i], flags);
                }
            }
        }
    }
}

void recursive(std::vector<std::string> filelist, std::vector<std::string> path, int i, flag &flags)
{
    std::vector<std::string> directories = get_dir1(filelist, path, i);
    struct stat type;

    regsort1(directories, flags);
    cout << endl;
    if (!directories.empty()) {
        for (size_t j = 0; j < directories.size(); j++) {
            lstat(directories[j].c_str(), &type);
            if (S_ISDIR(type.st_mode) && directories[j].back() != '.') {
                cout << endl << directories[j] << endl;
                get_dir_content(directories[j], flags); 
            }
        }
    }
}
