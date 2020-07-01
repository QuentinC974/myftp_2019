/*
** EPITECH PROJECT, 2018
** ftp / server
** File description:
** commands / cwd.c
*/

#include "server.h"
void cdup(client_t client, svr_t *svr, char **av, int ac);

char *pathcon(char *svr, char *clt, char *asking)
{
    char *tmp = strdup(svr);

    if (tmp[strlen(tmp) - 1] != '/')
        tmp = my_strcon(tmp, "/");
    tmp = my_strcon(tmp, clt);
    if (tmp[strlen(tmp) - 1] != '/')
        tmp = my_strcon(tmp, "/");
    return (my_strcon(tmp, asking));
}

char *cwdcon(char *a, char *b)
{
    char *tmp = strdup(a);
    if (tmp[strlen(tmp) - 1] != '/')
        tmp = my_strcon(tmp, "/");
    return (my_strcon(tmp, b));
}

void classic(client_t client, svr_t *svr, char **av)
{
    client_t *c = get_with_socket(client.socket, svr->clts);
    char *np = NULL;
    struct stat sb;

    np = pathcon(svr->path, c->cwd, av[1]);
    if (stat(np, &sb) != 0) {
        send_to_client(550, "Failed to change directory. (stat)", client);
        return;
    }
    if (!S_ISDIR(sb.st_mode)){
        send_to_client(550, "Failed to change directory. (isdir)", client);
        return;
    }
    c->cwd = cwdcon(c->cwd, av[1]);
    send_to_client(250, "Directory changed.", client);
}

void cwd(client_t client, svr_t *svr, char **av, int ac)
{
    printf("searching wich cwd\n");
    char *tmp = NULL;

    if (ac != 1 || (ac == 1 && strcmp(av[1], "\n") == 0)) {
        send_to_client(501, "Syntax error in parameters or arguments.", client);
        return;
    }
    tmp = no_more_br(av[1]);
    printf("tmp = <%s>\n", tmp);
    if (strcmp(tmp, "..") == 0)
        cdup(client, svr, av, 0);
    else
        classic(client, svr, av);
}