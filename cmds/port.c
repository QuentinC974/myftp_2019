/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** port
*/

#include "server.h"

void port(client_t client, svr_t *svr, char **av, int ac)
{
    (void)svr;
    (void)av;
    (void)ac;
    send_to_client(502, "Not implemented yet.", client);
}