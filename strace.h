/*
** strace.h for strace in /home/charla_n/projects/strace/strace
**
** Made by nicolas charlas
** Login   <charla_n@epitech.net>
**
** Started on  Sun May  5 22:36:47 2013 nicolas charlas
** Last update Fri May 17 17:06:28 2013 nicolas charlas
*/

#ifndef STRACE_H_
# define STRACE_H_

# include <sys/user.h>

# define	FILE_SYSCALL	"syscall.sys"
# define	SUCCESS		0
# define	FAIL		-1
# define	LINE_PARSE_ERR	-2
# define	MAX_ARG		6
/* # define	MAX_SYSCALLS	310 */
# define	TOO_BIG		1690000

# define	DISPLAY_STRCHAR	32

typedef unsigned long long int	ulli;

typedef enum			e_type
  {
    PID = 1,
    PROG
  }				t_type;

enum				e_type_arg
  {
    INT,
    STR,
    PTR
  };

struct				s_syscalls_generated
{
  char				*name;
  int				nb_args;
  void				(*specs)(ulli param_reg[MAX_ARG], int pid);
  int				args[MAX_ARG];
};

typedef struct			s_syscall
{
  int				id;
  char				*syscall;
  struct s_syscall		*next;
}				t_syscall;

typedef struct			s_signinfo
{
  int				pid;
  t_type			type;
}				t_signinfo;

extern t_signinfo		g_signinfo;

int			write_error(char *error);
void			detach_handler(__attribute__((unused))int sig);
int			strace(char **av);
int			parse_args(char **av, char ***args);
int			parse_syscall(t_syscall **sys);
char			*find_syscall(int id, t_syscall *sys);
void			display_syscall(int pid, char *name,
					struct user_regs_struct *regs);
void			spec_open(ulli param_reg[MAX_ARG], int pid);
void			spec_mmap(ulli param_reg[MAX_ARG], int pid);
void			spec_mprotect(ulli param_reg[MAX_ARG], int pid);
void			spec_access(ulli param_reg[MAX_ARG], int pid);
void			print_str(int pid, ulli reg);
void			print_int(int reg);
void			print_ptr(ulli reg);
void			print_ret(struct user_regs_struct *regs);
void			detach_handler(int sig);
void			spec_read_write(ulli param_reg[MAX_ARG], int pid);
void			spec_stat(ulli param_reg[MAX_ARG], int pid);
int			do_child(char **args);
int			do_father(int pid, t_syscall *sys,
				  t_type type);

#endif /* !STRACE_H_ */
