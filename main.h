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
 * struct Data - struct that contains all relevant data on runtime
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













#endif
