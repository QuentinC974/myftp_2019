/*
** EPITECH PROJECT, 2018
** ftp / server
** File description:
** commands / cdup.c
*/

#include "server.h"

char *to_string(char **av)
{
    printf("to string in your ass bro <%s>\n", av[0]);
    char *path = NULL;;
    // char *path = strdup("/");

    for (int i = 1 ; av[i] != NULL ; i++) {
        printf("av[%d] = <%s>\n", i, av[i]);
        path = my_strcon(path, "/");
        path = my_strcon(path, av[i]);
    }
    return path;
}

void cdup(client_t client, svr_t *svr, char **av, int ac)
{
    printf ("cdup\n");
    client_t *c = get_with_socket(client.socket, svr->clts);
    int t = 0;
    char **p = NULL;

    (void)av;
    if (ac != 0) {
        send_to_client(501, "Syntax error in parameters or arguments.", client);
        return;
    }
    p = str_to_tab(c->cwd, &t, '/');
    if (t == 0 || p[1][0] == ' ' || p[1][0] == '\n' || strlen(p[1]) < 1)
        send_to_client(450, "Can not open folder.", client);
    else {
        p[cnt_tab(p) - 1] = NULL;
        c->cwd = to_string(p);
        send_to_client(250, "Directory changed.", client);
    }
}