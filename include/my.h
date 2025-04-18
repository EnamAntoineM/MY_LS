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
    int my_ls(std::vector<std::string> parameter, flag &flags);
    int tcharwidth(void);
    int longstring(std::vector<std::string> content);
    int step(int lstring);
    void regsort(std::vector<std::string>& files, flag flags);
    void reverse(std::vector<std::string>& array);
    void info(std::vector<std::string> indir, bool total);
    void stime(std::vector<std::string>& files, std::vector<std::string> copy);
    void display(std::vector<std::string> indir);
    void regsort1(std::vector<std::string>& files, flag flags);
    void recursive(std::vector<std::string> filelist, std::vector<std::string> path, int i, flag &flags);
    std::vector<std::string> get_file_path(std::vector<std::string>& file, std::string path);
    std::vector<std::string> get_dir1(std::vector<std::string>& file, std::vector<std::string> path, int i);
    std::vector<std::string> get_dir2(std::vector<std::string> file, std::string path);
    void simple_print(std::vector<std::string> to_print);
    void maxi(std::vector<int>& list, int size, bool& swap);
    void get_dir_content(std::string parameter, flag &flags);
    std::string toLower(const std::string& str);
    std::vector<std::string> ftype(std::vector<std::string>& f_info, struct stat file, int i);
    std::vector<std::string> fpermissions(std::vector<std::string>& f_info, struct stat file, int i);
    std::vector<std::string> others(std::vector<std::string>& f_info, struct stat file, int i);
    void name(std::vector<std::string>& f_info, int i, std::vector<std::string> indir, bool& total);
#endif
