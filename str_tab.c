/*
** EPITECH PROJECT, 2019
** str to
** File description:
** tab 2.0
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *my_strcon(char *a, char *b)
{
    int len = 0;
    int cpt = 0;
    int cpt2 = 0;
    char *dest = NULL;

    if (a && strlen(a) > 0)
        len = strlen(a);
    if (b && strlen(b) > 0)
        len += strlen(b);
    dest = calloc(sizeof(char), (len + 1));
    while (a && a[cpt] != '\0') {
        dest[cpt] = a[cpt];
        cpt++;
    }
    for (; b && b[cpt2] != '\0' ; cpt++, cpt2++)
        dest[cpt] = b[cpt2];
    dest[cpt] = '\0';
    return (dest);
}

int count_charac(char *str, int i, char sep)
{
    int count = 0;

    if (str && str[i] == sep)
        i++;
    while (str && str[i] != '\0' && str[i] != sep)
    {
        i++;
        count++;
    }
    return count;
}

char **nb_sep(int *nb, char *str, char sep)
{
    char **ret = NULL;
    int i = 0;

    while (str && str[i] != 0) {
        if (str[i] == sep)
            *nb += 1;
        i++;
    }
    ret = calloc(sizeof(char *), (*nb + 1));
    for (int lol = 0; lol != *nb + 1; lol++)
        ret[lol] = NULL;
    return (ret);
}

char **str_to_tab(char *str, int *row, char sep)
{
    int nb = (strlen(str) > 0) ? 1 : 0;
    char **ret = nb_sep(&nb, str, sep);
    int j = 0;
    int i = 0;
    int len = 0;

    len = (count_charac(str, i, sep) + 1);
    ret[0] = calloc(sizeof(char), len);
    for (i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == sep) {
            j = 0 + (0 * (i += 1)) + (0 * (*row += 1));
            len = (count_charac(str, i, sep) + 1);
            ret[*row] = calloc(sizeof(char), len);
            ret[*row][j] = 0;
        }
        ret[*row][j] = str[i];
        j++;
        ret[*row][j] = '\0';
    }
    ret[*row + 1] = NULL;
    return (ret);
}
