/*
** EPITECH PROJECT, 2018
** myftp / server
** File description:
** commands / quit.c
*/

#include "server.h"

void quit(client_t client, client_t *clts)
{
    send_to_client(221, "Goodbye.", client);
    client_t *tmp = get_with_socket(client.socket, clts);
    close(client.socket);

    tmp->logged = 0;
}