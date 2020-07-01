/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** list
*/

#include "include/server.h"

int size_client(client_t *client)
{
    int i = 1;
    client_t *tmp = client;

    if (client == NULL)
        return 0;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

client_t *add_end(char *name, int socket, client_t *client, char *dir)
{
    client_t *tmp = client;
    client_t *new = calloc(sizeof(client_t), 1);

    new->next = NULL;
    new->name = name == NULL ? NULL : strdup(name);
    new->socket = socket;
    new->cwd = strdup(dir);
    if (tmp == NULL)
        client = new;
    else if (tmp->next == NULL)
        tmp->next = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
    printf("\tclient added with socket: %d, \
    the nb of client is now: %d\n",
    socket, size_client(client));
    return (client);
}

client_t *rm_with(int socket, client_t *client)
{
    client_t *tmp = client;
    client_t *tmp2 = NULL;

    while (tmp->next != NULL) {
        tmp = tmp->next;
        if (tmp->socket == socket) {
            tmp2 = tmp->next;
            free(tmp);
            tmp = tmp2;
            break;
        }
    }
    client = tmp;
    return (client);
}

client_t *change_mode(int socket, client_t *client)
{
    client_t *tmp = client;

    while (tmp->next != NULL) {
        tmp = tmp->next;
        if (tmp->next->socket == socket) {
            tmp->next->socket = tmp->next->socket == 0 ? 1 : 0;
            return (client);
        }
    }
    return (client);
}