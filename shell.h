#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <string.h>

#define BUFFER_SIZE 1024

ssize_t custom_getline(char **input, size_t *size, FILE *stream);
void run_command(char **parsed_command,
		char **environment, char *input_line);
char *find_executable_path(char *command, char **environment);
void exit_shell_program(char **command_tokens, char *input_line);
void read_input_line(char **input_line, size_t size);
int main(int argc, char **argv, char **environment);
void print_custom_error_message(char *program_name, char *command);
void free_allocated_memory(int count, char *allocation1, ...);
void handle_user_command(char **tokens, char **environment,
		char *cmd_exec, char *line);
char **split_input_string(char *str, char *delim);
char *duplicate_string(char *destination, char *source);
char *duplicate_n_string(char *destination, char *source, int n);
int compare_input_strings(char *string1, char *string2);
int calculate_string_length(char *string);
ssize_t combine_strings(int count, char **result, ...);
int count_input_delimiters(char *str, char *delim);
void process_user_command(char **command_tokens, char **environment,
		char *executable_path, char *input_line);
/* Other functions */
int get_number_of_delimiters(char *str, char *delim);
void display_error_message(char *argv, char *cmd);
void release_allocated_memory(int n, char *alloc1, ...);
void handle_command_execution(char **tokens, char **envp, char *cmd_exec, char *line);
char *get_environment_variable(char **envp, char *var, unsigned int length);
#endif

