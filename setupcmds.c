/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** setupcmds
*/

#include "include/server.h"
#include "include/cmds.h"

cmds_t *setupcmds3(cmds_t *cmds)
{
    cmds[8].name = strdup("PASV");
    cmds[8].desc = strdup(DESC_PASV);
    cmds[8].usage = strdup(USAGE_PASV);
    cmds[8].func = &pasv;
    cmds[9].name = strdup("RETR");
    cmds[9].desc = strdup(DESC_RETR);
    cmds[9].usage = strdup(USAGE_RETR);
    cmds[9].func = &retr;
    cmds[10].name = strdup("STOR");
    cmds[10].desc = strdup(DESC_STOR);
    cmds[10].usage = strdup(USAGE_STOR);
    cmds[10].func = &stor;
    cmds[11].name = NULL;
    cmds[11].desc = NULL;
    cmds[11].usage = NULL;
    cmds[11].func = NULL;
    return (cmds);
}

cmds_t *setupcmds2(cmds_t *cmds)
{
    cmds[4].name = strdup("NOOP");
    cmds[4].desc = strdup(DESC_NOOP);
    cmds[4].usage = strdup(USAGE_NOOP);
    cmds[4].func = &noop;
    cmds[5].name = strdup("PWD");
    cmds[5].desc = strdup(DESC_PWD);
    cmds[5].usage = strdup(USAGE_PWD);
    cmds[5].func = &pwd;
    cmds[6].name = strdup("LIST");
    cmds[6].desc = strdup(DESC_LIST);
    cmds[6].usage = strdup(USAGE_LIST);
    cmds[6].func = &list;
    cmds[7].name = strdup("PORT");
    cmds[7].desc = strdup(DESC_PORT);
    cmds[7].usage = strdup(USAGE_PORT);
    cmds[7].func = &port;
    return (setupcmds3(cmds));
}

cmds_t *setupcmds(void)
{
    cmds_t *cmds = calloc(sizeof(cmds_t), 12);

    cmds[0].name = strdup("HELP");
    cmds[0].desc = strdup(DESC_HELP);
    cmds[0].usage = strdup(USAGE_HELP);
    cmds[0].func = &help;
    cmds[1].name = strdup("CDUP");
    cmds[1].desc = strdup(DESC_CDUP);
    cmds[1].usage = strdup(USAGE_CDUP);
    cmds[1].func = &cdup;
    cmds[2].name = strdup("CWD");
    cmds[2].desc = strdup(DESC_CWD);
    cmds[2].usage = strdup(USAGE_CWD);
    cmds[2].func = &cwd;
    cmds[3].name = strdup("DELE");
    cmds[3].desc = strdup(DESC_DELE);
    cmds[3].usage = strdup(USAGE_DELE);
    cmds[3].func = &dele;
    return (setupcmds2(cmds));
}
