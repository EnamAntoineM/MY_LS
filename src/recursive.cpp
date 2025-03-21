/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** recursive.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void get_dir_content(std::string parameter, flag flags)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    struct stat type;
    std::vector<std::string> content;
    std::vector<std::string> lcontinue;
    std::vector<std::string> lflag;

    lstat(parameter.c_str(), &type);
    if(lstat(parameter.c_str(), &type) == -1){
        perror("my_ls");
    } else if (S_ISDIR(type.st_mode)) {
        r = opendir(parameter.c_str());
        if (r == NULL) {
            perror("my_ls");
        } else {
            rep = readdir(r);
            while(rep != NULL){
                if (!flags.a) {
                    if (rep->d_name[0] == '.') {
                        rep = readdir(r);
                    } else {
                        if (rep->d_name[sizeof(rep->d_name)] == '.') {
                            rep = readdir(r);
                        } else {
                            content.emplace_back(rep->d_name);
                            rep = readdir(r);
                        }
                    }
                } else {
                    if (rep->d_name[sizeof(rep->d_name)] == '.') {
                            rep = readdir(r);
                    } else {
                        content.emplace_back(rep->d_name);
                        rep = readdir(r);
                    }
                }
            }
        }
        closedir(r);
        regsort(content);
        display(content, flags);
        std::cout << endl;
        lcontinue = get_dir2(content, parameter);
        if (!lcontinue.empty()) {
            for (size_t i = 0; i < lcontinue.size(); i++) {
                if (lstat(lcontinue[i].c_str(), &type) == -1) {
                    fprintf(stderr, "my_ls : Cannot access: No such file or directory,\n");
                } else if (S_ISDIR(type.st_mode)) {
                        if (lcontinue[i][lcontinue[i].size() - 1] == '.') {
                        continue;
                    } else {
                        std::cout << endl << lcontinue[i] << endl;
                        get_dir_content(lcontinue[i], flags); 
                    }
                }
            }
        }
    }
}

void recursive(std::vector<std::string> filelist, std::vector<std::string> path, int i, flag flags)
{
    std::vector<std::string> directories = get_dir1(filelist, path, i);
    struct stat type;

    regsort(directories);
    display(directories, flags);
    cout << endl;
    if (!directories.empty()) {
        for (size_t j = 0; j < directories.size(); j++) {
            lstat(directories[j].c_str(), &type);
            if (S_ISDIR(type.st_mode)) {
                if (directories[j][directories[j].length() - 1] == '.') {
                    continue;
                } else {
                    std::cout << endl << directories[j] << endl;
                    get_dir_content(directories[j], flags); 
                }
            }
        }
    }
}
