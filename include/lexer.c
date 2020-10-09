#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "lexer.h"


char* token[] = {
    "keyword",
    "operator",
    "literal",
    "constant",
    "identifier",
    "function",
};

const char* pattern = "int|for";

// "auto|break|case|char|const|"\
// 				"continue|default|do|double|else|"\
// 				"enum|extern|float\\|for\\|goto|"\
// 				"if|int|long|register|return|short|signed|"\
// 				"sizeof|static|struct|switch|typedef|union|unsigned|"\
// 				"void|volatile|while";

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
