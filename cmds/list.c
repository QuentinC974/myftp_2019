/*
** EPITECH PROJECT, 2018
** myftp / server
** File description:
** commands / pass.c
*/

#include "server.h"
#include <dirent.h>

void list(client_t client, svr_t *svr, char **av, int ac)
{
    DIR *dir;
    struct dirent *entry;
    char *dirtoopen = NULL;

    (void)svr;
    if (ac == 1 && strlen(av[1]) > 0)
        dirtoopen = pathcon(svr->path, client.cwd, av[1]);
    else
        dirtoopen = my_strcon(svr->path, client.cwd);
    dir = opendir(dirtoopen);
    if (dir == NULL)
        send_to_client(425, "Can not open folder.", client);
    else {
        send_to_client(150, "File status okay; about to open data connection.",
                        client);
        while ((entry = readdir(dir)) != NULL)
            send_to_client(226, entry->d_name, client);
        closedir(dir);
    }
}