/*
 * file: parser.c
 * A simple C program to parse the user input for the command.
 */
 
#define _POSIX_C_SOURCE 200809L  
#include <stdio.h>
#include <stdlib.h> // For free() and malloc()
#include <string.h>
#include <stdbool.h>

/* retrieves the header file */
#include "header.h"

/* main parser function */
Command parse(char *input){

    /* initiliazes the Command variable to avoid unknown default values*/
    Command cmd = {
        .command      = NULL,
        .input_file   = NULL,
        .output_file  = NULL,
        .append       = false,
        .background   = false,
        .args         = {NULL},
        .original_string  = strdup(input) 
    };

    /* tokenize the copy */
    char *tokens = strtok(cmd.original_string, " ");

    int counter = 0;
    while (tokens != NULL) {

        if (strcmp(tokens, "<") == 0) {
            tokens = strtok(NULL, " ");
            cmd.input_file = tokens;

        } else if (strcmp(tokens, ">") == 0) {
            tokens = strtok(NULL, " ");
            cmd.output_file = tokens;
            cmd.append = false;

        } else if (strcmp(tokens, ">>") == 0) {
            tokens = strtok(NULL, " ");
            cmd.output_file = tokens;
            cmd.append = true;

        } else if (strcmp(tokens, "&") == 0) {
            cmd.background = true;

        } else {
            if (cmd.command == NULL) {
                cmd.command = tokens;
            }
            cmd.args[counter++] = tokens;
            
        }
        tokens = strtok(NULL, " ");
    }
    
    cmd.args[counter] = NULL;
    return cmd;
}


