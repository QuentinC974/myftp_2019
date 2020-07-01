/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** list
*/

#include "include/server.h"

client_t *get_with_socket(int socket, client_t *client)
{
    client_t *tmp = client;

    printf("\tsearching for client with socket: %d...\n", socket);
    while (tmp != NULL) {
        printf("\t\tthis client have the socket: %d...\
        (searching %d)\n", tmp->socket, socket);
        if (tmp->socket == socket)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

client_t *get_with_name(char *name, client_t *client)
{
    client_t *tmp = client;

    while (tmp != NULL) {
        if (strcmp(tmp->name, name) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

client_t *get_last(client_t *client)
{
    client_t *tmp = client;

    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}