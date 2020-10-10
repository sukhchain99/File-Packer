#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "loader.h"

void tokenizer(FILE *file)
{
    // file attributes
    FILE *fp = fopen("tokens.txt", "w");
    if (fp == NULL) perror ("Error opening file");
    char buffer[500];
    char* token;

    while(fgets(buffer, 499, file)) 
    {
        token = strtok(buffer, " \n\t");
        
        while (token != NULL)
        {
            
            fprintf(fp, "%s\n", token);

            token = strtok(NULL, " \n\t");
        }

    }

    if (!feof(file))
        printf("\n\n Something went wrong while reading the file.\n\n");

    fclose(fp);
    //return tokens;
}
