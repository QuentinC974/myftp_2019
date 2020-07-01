/*
** EPITECH PROJECT, 2018
** myftp / server
** File description:
** commands / user.c
*/

#include "server.h"

void user(client_t client, svr_t *svr, char **av, int ac)
{
    client_t *c = get_with_socket(client.socket, svr->clts);

    if (ac != 1) {
        send_to_client(501, "Syntax error in parameters or arguments.", client);
        return;
    } else if (ac == 1 && strcmp(av[1], "\n") == 0) {
        send_to_client(501, "Syntax error in parameters or arguments.", client);
        return;
    }
    send_to_client(230, "User logged in, proceed.", client);
    send_to_client(331, "User name okay, need password.", client);
    c->name = strdup(av[1]);
}