/*
** EPITECH PROJECT, 2020
** cmds
** File description:
** cmds
*/

#ifndef CMDS_H_
#define CMDS_H_

#include "./server.h"

void cdup(client_t client, svr_t *svr, char **av, int ac);
void cwd(client_t client, svr_t *svr, char **av, int ac);
void dele(client_t client, svr_t *svr, char **av, int ac);
void help(client_t client, svr_t *svr, char **av, int ac);
void noop(client_t client, svr_t *svr, char **av, int ac);
void pwd(client_t client, svr_t *svr, char **av, int ac);
void list(client_t client, svr_t *svr, char **av, int ac);
void stor(client_t client, svr_t *svr, char **av, int ac);
void retr(client_t client, svr_t *svr, char **av, int ac);
void pasv(client_t client, svr_t *svr, char **av, int ac);
void port(client_t client, svr_t *svr, char **av, int ac);
void quit(client_t client, client_t *clts);
void pass(client_t client, svr_t *svr, char **av, int ac);
void user(client_t client, svr_t *svr, char **av, int ac);

#endif /* !CMDS_H_ */