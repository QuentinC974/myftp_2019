##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## CPD10ysk01
##

# SERVERSRC = ./src/server/
# SERVERSRCCMDS = ./src/server/cmds/

SERVERSRC = ./
SERVERSRCCMDS = ./cmds/

SRCSVR	=	$(SERVERSRC)server.c			\
			$(SERVERSRC)list.c				\
			$(SERVERSRC)list_get.c			\
			$(SERVERSRC)str_tab.c			\
			$(SERVERSRC)setupcmds.c			\
			$(SERVERSRC)manage_cmds.c		\
			$(SERVERSRC)server_utils.c		\
			$(SERVERSRC)utils.c		\
			$(SERVERSRCCMDS)cdup.c		\
			$(SERVERSRCCMDS)cwd.c		\
			$(SERVERSRCCMDS)del.c		\
			$(SERVERSRCCMDS)help.c		\
			$(SERVERSRCCMDS)noop.c		\
			$(SERVERSRCCMDS)pass.c		\
			$(SERVERSRCCMDS)pwd.c		\
			$(SERVERSRCCMDS)quit.c		\
			$(SERVERSRCCMDS)user.c		\
			$(SERVERSRCCMDS)list.c		\
			$(SERVERSRCCMDS)stor.c		\
			$(SERVERSRCCMDS)retr.c		\
			$(SERVERSRCCMDS)port.c		\
			$(SERVERSRCCMDS)pasv.c		\


TEST	=
OBJSVR	=	$(SRCSVR:.c=.o)

NAMESVR	=	 myftp

UNIT_TEST   =	unit_tests

CFLAGS	=	-Wall -Wextra -ggdb -g3 -Iinclude -luuid

FDFLAGS	=	$(CFLAGS) -lcriterion --coverage

LIB	=

all:	server

server:	$(OBJSVR)
		gcc -o $(NAMESVR) $(OBJSVR) $(CFLAGS)

tests_run:
		gcc -o $(UNIT_TEST) $(TEST) $(LIB) $(FDFLAGS)
clean:

		rm -rf $(OBJCLT)
		rm -rf $(OBJSVR)

fclean:	clean
		rm -rf $(NAMESVR)
		rm -rf $(NAMECLT)
		rm -rf $(UNIT_TEST)

re: fclean all


.PHONY:		all tests_run clean fclean re