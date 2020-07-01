/*
** EPITECH PROJECT, 2018
** ftp / server
** File description:
** commands / dele.c
*/

#include "server.h"

void dele(client_t client, svr_t *svr, char **av, int ac)
{
    int del = -1;

    (void)svr;
    if (ac != 1 || (ac == 1 && strcmp(av[1], "\n") == 0)) {
        send_to_client(501, "Syntax error in parameters or arguments.", client);
        return;
    }
    if (strstr(av[1], ".c") || strstr(av[1], ".h")) {
        send_to_client(550, "Permission denied.", client);
        return;
    }
    del = remove(pathcon(svr->path, client.cwd, av[1]));
    if (!del)
        send_to_client(250, "The file is Deleted successfully.", client);
    else
        send_to_client(550, "Permission denied.", client);

}