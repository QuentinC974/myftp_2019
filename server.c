/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** serveur
*/

#include "include/server.h"
#include "include/cmds.h"
#include <ctype.h>

void accept_new_connection(svr_t *svr)
{
    int clientfd = 0;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    struct sockaddr_in clt_addr;

    clientfd = accept(svr->socket, (struct sockaddr *) &clt_addr, &addr_size);
    if (clientfd == -1)
        handle_error("accept");
    svr->clts = add_end(NULL, clientfd, svr->clts, "/");
}

int setup_server(char *port, struct sockaddr_in *svr_addr)
{
    int svr_socket = socket(AF_INET, SOCK_STREAM, 0);
    int option = 1;

    if (svr_socket == -1)
        handle_error("socket");
    if (setsockopt(svr_socket, SOL_SOCKET, SO_REUSEADDR,
        (char *)&option, sizeof(option)) < 0)
        handle_error("setopt");
    svr_addr->sin_family = AF_INET;
    svr_addr->sin_addr.s_addr = INADDR_ANY;
    svr_addr->sin_port = ntohs(atoi(port));
    if (bind(svr_socket, (struct sockaddr *)svr_addr, sizeof(*svr_addr)) == -1)
        handle_error("bind");
    if (listen(svr_socket, 5) == -1)
        handle_error("listen");
    return (svr_socket);
}

int loop(svr_t *svr)
{
    fd_set read_sockets;
    cmds_t *cmds = setupcmds();
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    FD_ZERO(&svr->list_sockets);
    FD_SET(svr->socket, &svr->list_sockets);
    while (42) {
        read_sockets = svr->list_sockets;
        if (select(FD_SETSIZE, &read_sockets, NULL, NULL, &tv) < 0)
            handle_error("select");
        for (int i = 0 ; i < FD_SETSIZE ; i++) {
            if (FD_ISSET(i, &read_sockets)) {
                if (i == svr->socket) {
                    accept_new_connection(svr);
                    send_to_client(220, "Service ready for new user.",
                    *get_last(svr->clts));
                    FD_SET(get_last(svr->clts)->socket, &svr->list_sockets);
                } else {
                    handle_co(*(get_with_socket(i, svr->clts)), cmds, svr);
                }
            }
        }
    }
}

void bridge(char **av)
{
    struct sockaddr_in svr_addr;
    svr_t server;
    server.socket = setup_server(av[1], &svr_addr);

    server.path = strdup(av[2]);
    printf(SERVER_UP);
    loop(&server);
    printf(SERVER_DOWN);
    close(server.socket);
}

int main(int ac, char **av)
{
    if (ac == 2 && (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0)) {
        usage();
        return (0);
    } else if (ac != 3) {
        printf("bad argument:\n");
        usage();
        return (84);
    }
    if (is_a_number(av[1]) != 0 ||  is_a_path(av[2]) != 0) {
        usage();
        return 84;
    }
    bridge(av);
    return 0;
}