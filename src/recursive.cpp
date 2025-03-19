/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** recursive.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void remove_parent(std::vector<std::string>& dir, size_t& i) {
    dir.erase(std::remove_if(dir.begin(), dir.end(),
                             [&](const std::string& s) { return s.ends_with("."); }),
              dir.end());
    dir.erase(std::remove_if(dir.begin(), dir.end(),
                             [&](const std::string& s) { return s.ends_with(".."); }),
              dir.end());
}

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
        fprintf(stderr, "my_ls : Cannot access: No such file or directory,\n");
    } else if (S_ISDIR(type.st_mode)) {
        r = opendir(parameter.c_str());
        rep = readdir(r);
        while(rep != NULL){
            content.emplace_back(rep->d_name);
            rep = readdir(r);
        }
        closedir(r);
        regsort(content);
        if (flags.t) {
            stime(content);
        }
        if (flags.l) {
            info_indir(content);
        //     if (flags.r) {
        //         reverse(lflag);
        //     } else {
        //         simple_print(lflag);
        //     }
        // }
        // if (flags.r && flags.l) {
        //     reverse(content);
        // } else {
        //     //display(content);
        }
        std::cout << endl;
        lcontinue = get_dir2(content, parameter);
        if (!lcontinue.empty()) {
            for (size_t i = 0; i < lcontinue.size(); i++) {
                lstat(lcontinue[i].c_str(), &type);
                if (S_ISDIR(type.st_mode)) {
                    if (lcontinue[i].find(".") != std::string::npos || lcontinue[i].find("..") != std::string::npos) {
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
    struct stat utility;
    struct dirent *rep = NULL;
    DIR *r = NULL;
    std::vector<std::string> directories = get_dir1(filelist, path, i);

    regsort(directories);
    cout << endl;
    if (!directories.empty()) {
        for (size_t j = 0; j < directories.size(); j++) {
            if (directories[j].find(".") != std::string::npos || directories[j].find("..") != std::string::npos) {
                continue;
            } else {
                std::cout << endl << directories[j] << endl;
                get_dir_content(directories[j], flags); 
            }
        }
    }
}
