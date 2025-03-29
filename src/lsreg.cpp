/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** lsreg.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

int my_ls_a(std::vector<std::string> parameter, flag flags)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    struct stat type;
    std::vector<std::string> content;
    std::vector<std::string> lflag;
    std::vector<std::string> tflags;

    for (size_t i = 0; i < parameter.size(); i++)
    {
        if(lstat(parameter[i].c_str(), &type) != -1 && !S_ISDIR(type.st_mode)) {
            cout << endl << parameter[i] << endl;
        } else {
            r = opendir(parameter[i].c_str());
            if(r == NULL){
                cout << parameter[i] << endl;
                perror("my_ls");
            } else {
                rep = readdir(r);
                while(rep != NULL){
                    content.emplace_back(rep->d_name);
                    rep = readdir(r);
                }
                closedir(r);
                regsort(content);
                if (flags.t) {
                    tflags = get_file_path(content, parameter[i]);
                    stime(tflags);
                    display(tflags, flags);
                }
                if (flags.R) {
                    display(tflags, flags);
                    recursive(content, parameter, i, flags);
                    content.clear();
                }
            }
        }
    }
    return 0;
}

int my_ls(std::vector<std::string> parameter, flag flags)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    struct stat type;
    std::vector<std::string> content;
    std::vector<std::string> lflag;
    std::vector<std::string> tflags;

    if (flags.a) {
        my_ls_a(parameter, flags);
        return 0;
    }
    for (size_t i = 0; i < parameter.size(); i++)
    {
        if(lstat(parameter[i].c_str(), &type) != -1 && !S_ISDIR(type.st_mode)) {
            cout << endl << parameter[i] << endl;
        } else {
            r = opendir(parameter[i].c_str());
            if(r == NULL){
                cout << parameter[i] << endl;
                perror("my_ls");
            } else {
                rep = readdir(r);
                while(rep != NULL){
                    content.emplace_back(rep->d_name);
                    rep = readdir(r);
                }
            }
            closedir(r);
            regsort(content);
            if (flags.t) {
                tflags = get_file_path(content, parameter[i]);
                stime(tflags);
                display(tflags, flags);
            }
            if (flags.l) {
                lflag = get_file_path(content, parameter[i]);
                info(lflag);
                printf("\n");
                lflag.clear();
                content.clear();
            }
            if (flags.R) {
                display(content, flags);
                recursive(content, parameter, i, flags);
                content.clear();
            }
        }
    }
    return 0;
}
