##
## Makefile for strace in /home/charla_n/projects/strace/strace
## 
## Made by nicolas charlas
## Login   <charla_n@epitech.net>
## 
## Started on  Mon Apr 29 16:18:12 2013 nicolas charlas
## Last update Fri May 10 10:40:10 2013 arthur jansen
##

NAME=	strace

SRC=	main.c \
	strace.c \
	write_error.c \
	parse_args.c \
	parse_syscall.c \
	find_syscall.c \
	display_syscall.c \
	specs_open.c \
	specs_mmap.c \
	specs_mprotect.c \
	specs_access.c \
	print_ret.c \
	print_str.c \
	print_int.c \
	print_ptr.c \
	specs_read_write.c \
	do_father.c \
	do_child.c

CFLAGS=	-W -Wall -Wextra

OBJ=	$(SRC:.c=.o)

TILDE=	*~

RM=	rm -f

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(TILDE)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rec: fclean all
	@$(RM) $(TILDE)
	@$(RM) $(OBJ)
