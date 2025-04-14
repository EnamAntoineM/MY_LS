/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** main.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/

#include "../include/my.h"

int main(int argc, char **argv) {
    std::vector<std::string> parameters;
    flag flags = {false, false, false, false, false, false};

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg[0] == '-') {
            for (size_t j = 1; j < arg.size(); ++j) {
                char c = arg[j];
                switch (c) {
                    case 'l': flags.l = true; break;
                    case 'a': flags.a = true; break;
                    case 'R': flags.R = true; break;
                    case 'r': flags.r = true; break;
                    case 'd': flags.d = true; break;
                    case 't': flags.t = true; break;
                    default:
                        std::cerr << "my_ls: invalid option -- '" << c << "'\n";
                        exit(84);
                }
            }
        } else {
            parameters.push_back(arg);
        }
    }

    if (parameters.empty()) {
        parameters.push_back(".");
    }
    my_ls(parameters, flags);
    return 0;
}
