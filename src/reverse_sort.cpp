/*
 * * MY_PROJECT (IDEA FROM EPITECH)
 * * File: reverse_sort.cpp
 * * Author: Enam KODJOH-KPAKPASSOU
 * * Email: eakodjoh-kpakpassou.st.ug.edu.gh
 * * Description: 
 */

#include "../include/my.h"

void reverse(std::vector<std::string>& array)
{
    std::vector<std::string> decoy = array;
    size_t re = array.size() - 1;
    int i = 0;

    for(size_t j = re; j != 0; j--){
        printf("%zu ---- %d \n", j, i);
        cout << decoy[j] << endl;
        array[i] = decoy[j];
        i++;
    }
}
