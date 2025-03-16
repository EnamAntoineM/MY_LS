/*
** EPITECH PROJECT, 2024
** MY_LS
** File description:
** lsreg.cpp
*/

#include "../include/my.h"

void printspace(std::vector<std::string> indir, int see)
{
    if(indir.size() < 10){
        see = 2;
    }
    for(int j = 0; j < see; j++){
        cout << " ";
    }
}

void display(std::vector<std::string> indir)
{
    int limit = step(indir);
    int control = longstring(indir);
    size_t see = 0;
    int format = 0;

    for(size_t i = 0; i < indir.size(); i++){
        if(indir[i][0] != '.'){
            if(format != limit){
                see = control - indir[i].size() + 2;
                cout << indir[i];
                printspace(indir, see);
                format++;
            }
            else {
                format = 0;
                cout << endl;
            }
        }
    }
}

void my_ls(void)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    const char *here = ".";
    std::vector<std::string> content;

    r = opendir(here);
    if(r == NULL){fprintf(stderr, "my_ls : Cannot access: No such file or directory\n");}
    rep = readdir(r);
    while(rep != NULL){
        content.emplace_back(rep->d_name);
        rep = readdir(r);
    }
    closedir(r);
    regsort(content);
    reverse(content);
    display(content);
}
