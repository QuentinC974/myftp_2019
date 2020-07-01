/*
** EPITECH PROJECT, 2018
** ftp / server
** File description:
** commands / noop.c
*/

#include "server.h"

void noop(client_t client, svr_t *svr, char **av, int ac)
{
    (void)svr;
    (void)av;
    (void)ac;
    send_to_client(200, "Command okay.", client);
}