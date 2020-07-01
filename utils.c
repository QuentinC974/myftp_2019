/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** utils
*/

#include "server.h"

int is_a_number(char *str)
{
    for (int i = 0 ; str[i] != 0 ; i++) {
        if (str[i] < '0' || str[i] > '9') {
            printf("This is not a valid port.\n");
            return -1;
        }
    }
    return 0;
}

int is_a_path(char *str)
{
    struct stat sb;

    if (stat(str, &sb) != 0) {
        printf("This is not a file.\n");
        return -1;
    }
    if (!S_ISDIR(sb.st_mode)){
        printf("This is not a directory.\n");
        return -1;
    }
    return 0;
}