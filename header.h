#ifndef HEADER_H
#define HEADER_H
/* prevents the header to be compiled multiple times */

/* main commands structure */
typedef struct {
    char *command;        // Command name
    char *args[256];      // Arguments (NULL-terminated)
    char *input_file;     // For < redirection (NULL if none)
    char *output_file;    // For > or >> redirection (NULL if none)
    bool append;          // true for >>, false for >
    bool background;      // true if & present
    char *original_string;    // for freeing the copy of the arguments
} Command;

/* maintains a structure of background jobs */
typedef struct
{
    int job_counter;            // Counter to keep track of the number of background jobs
    int job_pids[256];        // Array to store PIDs of background jobs
} Background;

/* constants */
#define MAX_ARGS 254

/* makes sure that the function in other files can be accessed in the mysh.c */
Command parse(char* input);
int interpret(Command* cmd);

#endif