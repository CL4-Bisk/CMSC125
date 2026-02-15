/*
 * file: mysh.c
 * A simple C program to verify your UNIX development environment.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

/* retrieves the header file*/
#include "header.h"

int main()
{
    int checker = 1;
    while (checker)
    {
        char *arguments = readline("mysh> ");
        if (!arguments)
        {
            break; // Handle EOF (Ctrl+D)
        }
            
        if (arguments[0] != '\0')
        {
            add_history(arguments);

            /* accesses the parse function through the header */
            Command cmd = parse(arguments);

            /* accesses the interpret function through the header */
            checker = interpret(&cmd);

        }
        // User pressed enter without typing anything
        free(arguments);

    }
    return 0;
}