/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** fileinfo.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

std::vector<std::string> ftype(std::vector<std::string>& f_info, struct stat file, int i)
{
    if (S_ISREG(file.st_mode)) f_info[i] = '-';
    else if (S_ISDIR(file.st_mode)) f_info[i] = 'd';
    else if (S_ISBLK(file.st_mode)) f_info[i] = 'b';
    else if (S_ISCHR(file.st_mode)) f_info[i] = 'c';
    else if (S_ISSOCK(file.st_mode)) f_info[i] = 's';
    else if (S_ISLNK(file.st_mode)) f_info[i] = 'l';
    else if (S_ISFIFO(file.st_mode)) f_info[i] = 'p';
    return f_info;
}

std::vector<std::string> fpermissions(std::vector<std::string>& f_info, struct stat file, int i)
{
    //USER'S PERMISSIONS
    if ((file.st_mode & S_IRUSR)) f_info[i].append("r");
    else f_info[i].append("-");
    if ((file.st_mode & S_IWUSR)) f_info[i].append("w");
    else f_info[i].append("-");
    if ((file.st_mode & S_IXUSR)) f_info[i].append("x");
    else f_info[i].append("-");
    //GROUP'S PERMISSIONS
    if ((file.st_mode & S_IRGRP)) f_info[i].append("r");
    else f_info[i].append("-");
    if ((file.st_mode & S_IWGRP)) f_info[i].append("w");
    else f_info[i].append("-");
    if ((file.st_mode & S_IXGRP)) f_info[i].append("x");
    else f_info[i].append("-");
    //OTHERS'S PERMISSIONS
    if ((file.st_mode & S_IROTH)) f_info[i].append("r");
    else f_info[i].append("-");
    if ((file.st_mode & S_IWOTH)) f_info[i].append("w");
    else f_info[i].append("-");
    if ((file.st_mode & S_IXOTH)) f_info[i].append("x");
    else f_info[i].append("-");
    f_info[i].append(".");
    return f_info;
}

std::vector<std::string> others(std::vector<std::string>& f_info, struct stat file, int i)
{
    struct passwd *pw = getpwuid(file.st_uid);
    struct group *grp = getgrgid(file.st_gid);
    char time[20];
    struct tm* timeinfo = localtime(&file.st_mtime);

    strftime(time, sizeof(time), "%b %d %H:%M", timeinfo);
    f_info[i].append(" ").append(std::to_string(file.st_nlink));
    f_info[i].append(" ").append(pw->pw_name);
    f_info[i].append(" ").append(grp->gr_name);
    f_info[i].append(" ").append(std::to_string(file.st_size));
    f_info[i].append(" ").append(time);
    return f_info;
}

void name(std::vector<std::string>& f_info, int i, std::vector<std::string> indir)
{
    size_t j = 0;

    for(j = indir[i].size(); indir[i][j] != '/'; j--);
    f_info[i].append(" ").append(indir[i].substr(j + 1));
    cout << f_info[i] << endl;
}

void info(std::vector<std::string> indir)
{
    struct stat file;
    std::vector<std::string> copy = indir;
    std::vector<std::string> informations;

    for(size_t i = 0; i < indir.size(); i++) {
        lstat(indir[i].c_str(), &file);
        if(lstat(indir[i].c_str(), &file) == -1){
            fprintf(stderr, "my_ls : Cannot access: No such file or directory\n");
            cout << indir[i] << endl;
        } else {
            informations = ftype(indir, file, i);
            informations = fpermissions(indir, file, i);
            informations = others(indir, file, i);
            name(indir, i, copy);
        }
    }
}
