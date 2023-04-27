#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#define BUFSIZE 1024
#define TOKK_BUFSIZE 128
#define TOKK_DELIM " \t\r\n\a"

/* Pointing to arr ptrs = environment */
extern char **envir;

/**
 * struct Data - struct contains all relevant data runtime
 * @argv: argument vector
 * @inp: command line written by the user
 * @argss: tokens of the command line
 * @stat: the last state of the shell
 * @counter: lines counter
 * @_envir: environment variable
 * @PID: process ID of the shell
 */
typedef struct Data
{
	char **argv;
	char **_envir;
	char *inp;
	char *PID;
	char **argss;
	int stat;
	int counter;
} Data_shell;

/**
 * struct CLI_list_s - singly linked list
 * @line: command line
 * @next_node: the next node
 * Description: single list storing command line
 */
typedef struct CLI_list_s
{
	char *line;
	struct CLI_list_s *next_node;
} CLI_list;

/**
 * struct sl_list_s - singly linked list
 * @separrator: & ; |
 * @next_node: the next node
 * Description: single list  storing separrators
 */
typedef struct sl_list_s
{
	char separrator;
	struct sl_list_s *next_node;
} sl_list;

/**
 * struct Builtin_S - a built in struct for the command argss.
 * @name: The name of the command
 * @f: data type pointer function.
 */
typedef struct Builtin_S
{
	char *name;
	int (*f)(Data_shell *Datashell);
} Builtin_T;

/**
 * struct S_Var_list - single linked list
 * @len_var: Variable length
 * @val_var: Variable value
 * @len_val_var: Value length
 * @next_node: next node
 * Description: single list storing variables
 */
typedef struct S_Var_list
{
	int len_var;
	char *val_var;
	int len_val_var;
	struct S_Var_list *next_node;
} S_Var;

/* These are prototypes of  aux_str Functions */
int _strcmp(char *str1, char *str2);
char *_strchr(char *s, char c);
char *_strcpy(char *destination, char *source);
int _strspn(char *s, char *Accept);
char *_strcat(char *destination, const char *source);

/* These are prototypes of  aux_str2.c Functions */
int _strlen(const char *str);
char *_strdup(const char *str);
int _isdigit(const char *str);
int cmp_chars(char string[], const char *delimit);
char *_strtok(char string[], const char *delimit);

/* These are prototypes of  aux_str3.c Functions */
void mex_string(char *str);

/* These are prototypes of aux_lists.c Functions */
sl_list *Sl_node_end_Add(sl_list **head, char sep);
CLI_list *CLI_node_end_Add(CLI_list **head, char *line);
void CLI_list_Free(CLI_list **head);
void Sl_list_Free(sl_list **head);

/* These are prototypes of  aux_lists2.c Functions */
S_Var *SVar_node_Add(S_Var **head, int lvar, char *var, int lval);
void SVar_list_Free(S_Var **head);

/* These are prototypes of  aux_mem.c Functions */
void *_realloc(void *ptr1, unsigned int size1, unsigned int size2);
char **_reallocdp(char **ptr1, unsigned int size1, unsigned int size2);
void _memcpy(void *ptr2, const void *ptr1, unsigned int size);

/* These are prototypes of  shell_loop.c Functions */
char *No_comment(char *in);
void sh_loop(Data_shell *Datashell);

/* These are prototypes of  read_line.c Functions */
char *read_line(int *xyz);

/* These are prototypes of  get_line.c Functions */
void Bring_Line(char **linepointr, size_t *n, char *buffer, size_t j);
ssize_t Get_Line(char **linepointr, size_t *n, FILE *stream);

/* These are prototypes of exec_line Functions */
int execute_line(Data_shell *Datashell);

/* These are prototypes of  check_syntax_error.c Functions */
int repeated_character(char *inp, int i);
int err_separrator(char *inp, int i, char last);
int first_character(char *inp, int *i);
void print_synt_err(Data_shell *Datashell, char *inp, int i, int bool);
int check_synt_err(Data_shell *Datashell, char *inp);

/* These are prototypes of  split.c Functions */
char *Character_swap(char *inp, int bool);
void Add_node(sl_list **head_s, CLI_list **head_l, char *inp);
void to_next(sl_list **list_s, CLI_list **list_l, Data_shell *Datashell);
int split_all_commands(Data_shell *Datashell, char *inp);
char **Split_the_line(char *inp);

/* These are prototypes of  cmd_exec.c Functions */
int is_cdirect(char *path, int *i);
char *_whichone(char *cmd, char **_envir);
int is_exe(Data_shell *Datashell);
int check_err_cmd(char *dir, Data_shell *Datashell);
int cmd_exe(Data_shell *Datashell);

/* These are prototypes of rep_var.c Functions */
void check_envir(S_Var **h, char *in, Data_shell *Data);
int check_variables(S_Var **h, char *in, char *st, Data_shell *Data);
char *replaced_inp(S_Var **head, char *inp, char *new_inp, int nlen);
char *rep_var(char *inp, Data_shell *Datashell);

/* These are prototypes of  env2.c Functions */
char *Copy_information(char *name, char *value);
void set_envirr(char *name, char *value, Data_shell *Datashell);
int _setenvirr(Data_shell *Datashell);
int _unsetenvirr(Data_shell *Datashell);

/* These are prototypes of  env1.c  Functions */
char *_getenvirr(const char *name, char **_envir);
int _envirr(Data_shell *Datashell);

/* These are prototypes of  aux_stdlib.c Functions */
int get_lengthh(int n);
char *itoa(int n);
int _atoi(char *str);


/* These are prototypes of  get_builtin Functions */
int (*Get_built_in(char *cmd))(Data_shell *Datashell);

/* These are prototypes of  _exit.c Functions */
int ShellExit(Data_shell *Datashell);

/* These are prototypes of  cd.c Functions */
void cd_dot(Data_shell *Datashell);
void cd_forword(Data_shell *Datashell);
void cd_backword(Data_shell *Datashell);
void cd_home(Data_shell *Datashell);

/* These are prototypes of  cd_shell.c Functions */
int cdshell(Data_shell *Datashell);

/* These are prototypes of  aux_error1.c Functions  */
char *strcat_cd(Data_shell *, char *, char *, char *);
char *err_Getcd(Data_shell *Datashell);
char *err_NotFound(Data_shell *Datashell);
char *err_ShellExit(Data_shell *Datashell);

/* These are prototypes of  aux_error2.c Functions */
char *err_alias(char **argss);
char *err_environment(Data_shell *Datashell);
char *err_synt(char **argss);
char *err_permiss(char **argss);
char *err_path126(Data_shell *Datashell);

/* These are prototypes of  get_error.c Functions */
int Get_the_errors(Data_shell *Datashell, int eval);

/* These are prototypes of  get_sigint.c Functions */
void Get_sig(int sig);

/* These are prototypes of  aux_help.c Functions */
void help_envirr(void);
void help_setenvirr(void);
void help_unsetenvirr(void);
void help_general(void);
void help_exit(void);

/* These are prototypes of  aux_help2.c Functions */
void auhelp(void);
void help_alias(void);
void help_cd(void);

/* These are prototypes of  get_help.c Functions */
int Get_Help(Data_shell *Datashell);

#endif
