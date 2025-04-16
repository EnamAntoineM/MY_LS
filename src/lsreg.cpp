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
            if (S_ISDIR(type.st_mode) || S_ISLNK(type.st_mode)) {
                directories.emplace_back(parameter[i]);
            } else {
                files.emplace_back(parameter[i]);
            }
        } else {
            cout << parameter[i] << endl;
            perror("my_ls");
        }
    }
}

void ls_files(std::vector<std::string> files, std::vector<std::string> directories, flag flags)
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
            display(files);
        }
        if (!directories.empty()) cout << endl;
    }
}

void sort_it(size_t i, std::vector<std::string> &content, std::vector<std::string> &parameter, std::vector<std::string> &tflags, flag flags)
{
    std::vector<std::string> copy;

    regsort(content, flags);
    copy = content;
    if (flags.t) {
        tflags = get_file_path(copy, parameter[i]);
        stime(content, copy);
    }
    if (flags.r) {
        reverse(content);
    }
}

void lsd_n_co(std::vector<std::string> &parameter, flag flags)
{
    regsort(parameter, flags);
    if (flags.t) {
        stime(parameter, parameter);
    }
    if (flags.r) {
        reverse(parameter);
    }
    if (flags.l && flags.R) {
        info(parameter, true);
        exit(0);
    }
    if (flags.R || !flags.l) {
        display(parameter);
        exit(0);
    }
}
int my_ls(std::vector<std::string> parameter, flag flags)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    std::vector<std::string> files;
    std::vector<std::string> directories;
    std::vector<std::string> content;
    std::vector<std::string> lflag;
    std::vector<std::string> tflags;

    f_or_d(parameter, files, directories);
    ls_files(files, directories, flags);
    for (size_t i = 0; i < directories.size(); i++) {
        r = opendir(directories[i].c_str());
        rep = readdir(r);
        while(rep != NULL){
            content.emplace_back(rep->d_name);
            rep = readdir(r);
        }
        closedir(r);
        sort_it(i, content, parameter, tflags, flags);
        if (flags.d){
            lsd_n_co(parameter, flags);
        }
        if (flags.l) {
            if (directories.size() > 1) cout << directories[i] << endl;
            lflag = get_file_path(content, directories[i]);
            info(lflag, false);
            if (directories.size() > 1) cout << directories[i] << endl;
            lflag.clear();
            content.clear();
        }
        if (flags.R) {
            display(content);
            recursive(content, directories, i, flags);
            content.clear();
        }
        if (!flags.l && !flags.R && !flags.d) {
            if (parameter.size() > 1 || !files.empty()) cout << directories[i] << endl;
            display(content);
        }
        tflags.clear();
    }
    return 0;
}