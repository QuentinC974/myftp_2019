/*
** EPITECH PROJECT, 2018
** myftp / server
** File description:
** commands / pass.c
*/

#include "server.h"

void pass(client_t client, svr_t *svr, char **av, int ac)
{
    client_t *c = get_with_socket(client.socket, svr->clts);

    if (c->name == NULL) {
        send_to_client(530, "No username set. Please use USER <USERNAME>", client);
        return;
    }
    if (strncmp(c->name, DEFAULT_NAME, 9) == 0) {
        if (ac == 1 && strlen(av[1]) > 0)
            if (strcmp(av[1], "\n") != 0 || strcmp(av[1], "\0") != 0) {
                send_to_client(332, "Bad password.", client);
                return;
            }
        c->logged = 1;
        send_to_client(230, "User logged in, proceed.", client);
        return;
    }
    send_to_client(530, "Not login.", client);
}