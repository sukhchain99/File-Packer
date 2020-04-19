#include "lexer.h"

void tokenizer(FILE *file)
{
    char ch;

    while(ch != EOF)
    {
     ch = getc(file);
     printf("%c", ch);
    }

    if (feof(file))
        printf("\n End of file reached.\n");
    else
        printf("\n Something went wrong.\n");
    //return tokens;
}
