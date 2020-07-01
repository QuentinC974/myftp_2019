/*
** EPITECH PROJECT, 2018
** myftp / server
** File description:
** commands / pwd.c
*/

#include "server.h"

void pwd(client_t client, svr_t *svr, char **av, int ac)
{
    (void)svr;
    if (ac != 0) {
        send_to_client(501, "Syntax error in parameters or arguments.", client);
        return;
    } else if (ac == 1 && strcmp(av[1], "\n") == 0) {
        send_to_client(501, "Syntax error in parameters or arguments.", client);
        return;
    }
    send_to_client(257, client.cwd, client);
}