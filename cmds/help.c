/*
** EPITECH PROJECT, 2018
** ftp / server
** File description:
** commands / help.c
*/

#include "server.h"

void help(client_t c, svr_t *svr, char **av, int ac)
{
    (void)ac;
    (void)svr;
    (void)av;
    send_to_client(214, "The following commands are recognized", c);
    dprintf(c.socket, "CDUP,\tCWD,\tDELE,\tHELP,\tLIST,\tNOOP,\tPASS,\n");
    dprintf(c.socket, "PASV,\tPORT,\tPWD,\tQUIT,\tRETR,\tSTOR,\tUSER\n");
    send_to_client(214, "Help ok", c);
}