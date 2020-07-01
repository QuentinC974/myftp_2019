/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** serveur
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/select.h>
#include <time.h>
#include <uuid/uuid.h>
#include <sys/stat.h>
#include <fcntl.h>



#define capitaluuid true
#define DEFAULT_NAME_LENGTH 32
#define EPI_EXIT_FAILURE 84
#define DEFAULT_NAME "Anonymous"
#define SERVER_UP "Server is now on.\n"
#define SERVER_DOWN "Server is going down.\n"

#define INFO_CONNECT "Youre now connected to a server with socket %d\n"
#define ERROR_NOTLOGGED "You're not logged in. Please use /login [“username”].\n"
#define ERROR_COMMAND_NOT_fOUND "Command not found\n"

#define USAGE_USER "USER <username>"
#define USAGE_PASS "PASS <password>"
#define USAGE_CWD  "CWD <pathname>"
#define USAGE_CDUP "CDUP"
#define USAGE_QUIT "QUIT"
#define USAGE_DELE "DELE <pathname>"
#define USAGE_PWD  "PWD"
#define USAGE_HELP "HELP [cmd]"
#define USAGE_NOOP "NOOP"
#define USAGE_LIST "LIST [path]"
#define USAGE_PORT "PORT <host-port>"
#define USAGE_STOR "STOR  <pathname>"
#define USAGE_PASV "PASV"
#define USAGE_RETR "RETR  <pathname>"

#define DESC_USER  "Specify user for authentication"
#define DESC_PASS  "Specify password for authentication"
#define DESC_CWD   "Change working directory"
#define DESC_CDUP  "Change working directory to parent directory"
#define DESC_QUIT  "Disconnection"
#define DESC_DELE  "Delete file on the server"
#define DESC_PWD   "Print working directory"
#define DESC_HELP  "List available commands"
#define DESC_NOOP  "Do nothing"
#define DESC_LIST  "List files in the current working directory"
#define DESC_PORT  "Enable active mode for data transfer"
#define DESC_STOR  "Upload file from client to server"
#define DESC_PASV  "Enable passive mode for data transfer"
#define DESC_RETR  "Do nothing"


#define handle_error(msg) \
    do { printf("%s\n", msg); exit(EPI_EXIT_FAILURE); } while (0)

//struc
    typedef struct client
    {
        char *cwd;
        char *name;
        int socket;
        int logged;
        struct client *next;
    } client_t;

    typedef struct server
    {
        int socket;
        fd_set list_sockets;
        char *path;
        client_t *clts;
    } svr_t;

    typedef struct cmds
    {
        char *name;
        void (*func)(client_t client, svr_t *svr, char **av, int ac);
        char *usage;
        char *desc;
    } cmds_t;



//functions
    cmds_t *setupcmds();
    int cnt_tab(char **av);
    void parse_cmd(char *input, client_t client, svr_t *svr, cmds_t *cmds);
    char *get_filename(client_t first, client_t second);;
    void accept_new_connection(svr_t *svr);
    void rm_client(client_t client, svr_t *svr);
    void check_cmd(svr_t *svr, client_t client, cmds_t *cmds);
    void handle_co(client_t client, cmds_t *cmds, svr_t *svr);
    int setup_server(char *port, struct sockaddr_in *svr_addr);
    int loop(svr_t *svr);
    void usage(void);
    void setupFolder(void);
    void bridge(char **);
    int cnt_tab(char **av);
    int main(int ac, char **av);
    void send_to_client(int code, char *msg, client_t client);
    char *no_more_br(char *str);
    void free_tab(char **av);
    char *pathcon(char *svr, char *clt, char *asking);
    int is_a_number(char *str);
    int is_a_path(char *str);


//list
    int size_client(client_t *client);
    client_t *add_end(char *name, int socket, client_t *client, char *dir);
    client_t *rm_with(int socket, client_t *client);
    client_t *get_with_socket(int socket, client_t *client);
    client_t *create_list(char *name, int socket);
    client_t *change_mode(int socket, client_t *client);
    client_t *get_last(client_t *client);
    client_t *get_with_name(char *name, client_t *client);

//utils
    char **str_to_tab(char *str, int *row, char sep);
    char *my_strcon(char *a, char *b);

#endif /* !SERVER_HPP_ */
