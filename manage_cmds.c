/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** manage_cmds
*/

#include "include/server.h"
#include "include/cmds.h"

void parse_cmd(char *input, client_t client, svr_t *svr, cmds_t *cmds)
{
    int ac = 0;
    char **av = str_to_tab(input, &ac, ' ');
    int boule = 0;

    for (int i = 0 ; i < ac + 1 ; i++)
        printf("server av[%d] = %s\n", i, av[i]);
    for (int i = 0 ; cmds[i].name != NULL ; i++) {
            printf("looking for <%s> we have <%s>\n", av[0], cmds[i].name);
        if (strcmp(av[0], cmds[i].name) == 0) {
            cmds[i].func(client, svr, av, ac);
            boule  = 1;
            printf("found it\n");
            break;
        }
    }
    if (boule == 0)
        send_to_client(500, "Syntax error, command unrecognized.", client);
    for (int i = 0 ; i < ac ; i++)
        free(av[i]);
    free(av);
}

void rm_client(client_t client, svr_t *svr)
{
    send_to_client(221, "Goodbye.", client);
    svr->clts = rm_with(client.socket, svr->clts);
    FD_CLR(client.socket, &svr->list_sockets);
    close(client.socket);
}

void is_a_command(char *in, client_t client, svr_t *svr, cmds_t *cmds)
{
    int t = 0;
    char **av = str_to_tab(in, &t, ' ');

    in = no_more_br(in);
    if (strncmp(in, "USER", 4) == 0)
        user(client, svr, av, t);
    else if (strncmp(in, "PASS", 4) == 0)
        pass(client, svr, av, t);
    else {
        if (in != NULL && client.logged == 1)
            parse_cmd(in, client, svr, cmds);
        else
            send_to_client(530, "Not logged in.", client);
    }
}

void check_cmd(svr_t *svr, client_t client, cmds_t *cmds)
{
    char *in = NULL;
    FILE *fd = fdopen(client.socket, "r");
    size_t s = 0;

    if (fd != NULL) {
        getline(&in, &s, fd);
        in = no_more_br(in);
        printf("input[%d]: <%s>\n", client.socket, in);
        if (in == NULL || strlen(in) < 2 || strncmp(in, "QUIT", 4) == 0)
            return (rm_client(client, svr));
        is_a_command(in, client, svr, cmds);
    }
}

void handle_co(client_t client, cmds_t *cmds, svr_t *svr)
{
    printf("handle connection of client %d\n", client.socket);
    check_cmd(svr, client, cmds);
}