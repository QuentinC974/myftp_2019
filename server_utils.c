/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_utils
*/

#include "include/server.h"
#include "include/cmds.h"

int cnt_tab(char **av)
{
    int ac = 0;

    for (ac = 0; av[ac] != NULL; ac++);
    return (ac);
}

void free_tab(char **av)
{
    for (int i = 0; av[i] != NULL; i++) {
        av[i] = NULL;
        free(av[i]);
    }
    av = NULL;
    free(av);
}

char *no_more_br(char *str)
{
    for (int i = 0 ; str[i] != 0 ; i++) {
        if (str[i] == '\r')
            str[i] = 0;
        if (str[i] == '\n')
            str[i] = 0;
    }
    return str;
}

void usage(void)
{
    printf("USAGE\n");
    printf("\t./myftp port path\n");
    printf("DESCRIPTION\n");
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the Anonymous user\n");
}

void send_to_client(int code, char *msg, client_t client)
{
    dprintf(client.socket, "%d %s\r\n", code, msg);
}
