/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** lsreg.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

void my_ls(std::vector<std::string> parameter)
{
    struct dirent *rep = NULL;
    DIR *r = NULL;
    struct stat type;
    std::vector<std::string> content;
    std::vector<std::string> lflag;

    for (size_t i = 0; i < parameter.size(); i++)
    {
        if(lstat(parameter[i].c_str(), &type) != -1 && !S_ISDIR(type.st_mode)) {
            cout << endl << parameter[i] << endl;
        } else {
            r = opendir(parameter[i].c_str());
            if(r == NULL){
                cout << parameter[i] << endl;
                fprintf(stderr, "my_ls : Cannot access: No such file or directory\n");}
            rep = readdir(r);
            while(rep != NULL){
                content.emplace_back(rep->d_name);
                rep = readdir(r);
            }
            closedir(r);
            regsort(content);
            //lflag = get_file_path(content, parameter[i]);
            //lflag = info(lflag);
 //           reverse(lflag);
            display(content);
            recursive(content, parameter, i);
            content.clear();
        }
    }
    //lflag = info(content);
    //stime(content);
    //reverse(content);
    // for (size_t i = 0; i < content.size(); i++) {
    //     cout << content[i] << endl;
    // }
    //regsort(content);
    //reverse(content);
    //display(content);
}
