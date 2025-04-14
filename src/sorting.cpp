/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** sorting.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

// 1. Function to convert a string to lowercase
std::string toLower(const std::string& str)
{
    std::string lowerStr = str;

    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// 2. Function to perform a case-insensitive sort that preserves the original case
void regsort(std::vector<std::string>& files, flag flags)
{
    std::vector<std::string> lowerFiles;
    std::vector<int> indices;
    std::string sorted;

    if (!flags.a) {
        for (size_t i = 0; i < files.size(); ) {
            if ((files[i].back() == '.') || files[i].front() == '.') {
                files.erase(files.begin() + i);
                continue;
            }
            i++;
        }
    }
    lowerFiles = files;
    indices.resize(files.size());
    for (size_t i = 0; i < files.size(); ) {
            lowerFiles[i] = toLower(files[i]);
            indices[i] = i;
            i++;
    }
    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
        return lowerFiles[a] < lowerFiles[b];
    });
    std::vector<std::string> sortedFiles(files.size());
    for (size_t i = 0; i < files.size(); i++) {
        sortedFiles[i] = files[indices[i]];
    }
    files = sortedFiles;
}

void regsort1(std::vector<std::string>& files, flag flags)
{
    std::vector<std::string> lowerFiles = files;
    std::vector<int> indices(files.size());

    if (!flags.a) {
        for (size_t i = 0; i < files.size(); ) {
            if ((files[i].back() == '.') || files[i].front() == '.') {
                files.erase(files.begin() + i);
                continue;
            }
            i++;
        }
    }
    lowerFiles = files;
    indices.resize(files.size());
    for (size_t i = 0; i < files.size(); ) {
            lowerFiles[i] = toLower(files[i]);
            indices[i] = i;
            i++;
    }
    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
        return lowerFiles[a] < lowerFiles[b];
    });
    std::vector<std::string> sortedFiles(files.size());
    for (size_t i = 0; i < files.size(); i++) {
        sortedFiles[i] = files[indices[i]];
    }
    files = sortedFiles;
}
