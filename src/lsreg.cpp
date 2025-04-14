/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** lsreg.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void f_or_d (std::vector<std::string> parameter, std::vector<std::string> &files, std::vector<std::string> &directories)
{
    struct stat type;

    for (size_t i = 0; i < parameter.size(); i++) {
        if (lstat(parameter[i].c_str(), &type) != -1) {
            if (!S_ISDIR(type.st_mode)) {
                files.emplace_back(parameter[i]);
            } else {
                directories.emplace_back(parameter[i]);
            }
        } else {
            cout << parameter[i] << endl;
            perror("my_ls");
        }
    }
}

void ls_files(std::vector<std::string> files, flag flags)
{
    if (!files.empty()) {
        regsort(files, flags);
        if (flags.t) {
            stime(files, files);
        }
        if (flags.r) {
            reverse(files);
        }
        if (flags.l) {
            info(files, true);
        }
        if (flags.R || flags.d) {
            display(files, flags);
        }
        cout << endl;
    }
}

int my_ls_a(std::vector<std::string> parameter, flag flags)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    std::vector<std::string> files;
    std::vector<std::string> directories;
    std::vector<std::string> content;
    std::vector<std::string> lflag;
    std::vector<std::string> tflags;
    std::vector<std::string> copy;

    f_or_d(parameter, files, directories);
    ls_files(files, flags);
    for (size_t i = 0; i < directories.size(); i++) {
        r = opendir(directories[i].c_str());
        rep = readdir(r);
        while(rep != NULL){
            content.emplace_back(rep->d_name);
            rep = readdir(r);
        }
        closedir(r);
        regsort(content, flags);
        copy = content;
        if (flags.d) {
            display(directories, flags);
        }
        if (flags.t) {
            if (parameter.size() > 1 || !files.empty()) cout << parameter[i] << endl;
            tflags = get_file_path(copy, parameter[i]);
            stime(content, copy);
            cout << endl;
        }
        if (flags.l) {
            if (directories.size() > 1) cout << directories[i] << endl;
            lflag = get_file_path(content, directories[i]);
            info(lflag, false);
            printf("\n");
            lflag.clear();
            content.clear();
        }
        if (flags.R) {
            display(content, flags);
            recursive(content, directories, i, flags);
            content.clear();
        }
    }
    exit(0);
}

int my_ls(std::vector<std::string> parameter, flag flags)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    struct stat type;
    std::vector<std::string> files;
    std::vector<std::string> directories;
    std::vector<std::string> content;
    std::vector<std::string> lflag;
    std::vector<std::string> tflags;
    std::vector<std::string> copy;

    if (flags.a) my_ls_a(parameter, flags);
    f_or_d(parameter, files, directories);
    ls_files(files, flags);
    for (size_t i = 0; i < directories.size(); i++) {
        r = opendir(directories[i].c_str());
        rep = readdir(r);
        while(rep != NULL){
            content.emplace_back(rep->d_name);
            rep = readdir(r);
        }
        closedir(r);
        regsort(content, flags);
        if (flags.t) {
           tflags = get_file_path(copy, parameter[i]);
           stime(content, copy); 
        }
        if (flags.r) {
            reverse(content);
        }
        copy = content;
        if (flags.d) {
            display(directories, flags);
        }
        if (flags.l) {
            if (directories.size() > 1) cout << directories[i] << endl;
            lflag = get_file_path(content, directories[i]);
            info(lflag, false);
            printf("\n");
            lflag.clear();
            content.clear();
        }
        if (flags.R) {
            display(content, flags);
            recursive(content, directories, i, flags);
            content.clear();
        }
    }
    return 0;
}
