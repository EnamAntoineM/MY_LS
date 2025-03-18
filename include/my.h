/*
 * * MY_PROJECT (IDEA FROM EPITECH)
 * * File: my.h
 * * MY_LS
 * * Author: Enam KODJOH-KPAKPASSOU
 * * Email: eakodjoh-kpakpassou.st.ug.edu.gh
 * * Description: 
 */

#ifndef MY_H
    #define MY_H
    #include "cpp.h"
    #include "alias.h"
    #include "flag.h"
    void my_ls(std::vector<std::string> parameter, flag flags);
    int tcharwidth(void);
    int longstring(std::vector<std::string> content);
    int step(std::vector<std::string> astring);
    void regsort(std::vector<std::string>& files);
    void reverse(std::vector<std::string>& array);
    std::vector<std::string> info(std::vector<std::string> indir);
    std::vector<std::string> stime(std::vector<std::string>& files);
    void display(std::vector<std::string> indir);
    void recursive(std::vector<std::string> filelist, std::vector<std::string> path, int i);
    std::vector<std::string> get_file_path(std::vector<std::string> file, std::string path);
    void simple_print(std::vector<std::string> to_print);
    std::vector<std::string> get_dir1(std::vector<std::string> file, std::vector<std::string> path, int i);
    std::vector<std::string> get_dir2(std::vector<std::string> file, std::string path);
#endif
