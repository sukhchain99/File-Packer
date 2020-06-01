#include <stdbool.h>
#include "lexer.h"

void tokenizer(FILE *file)
{
    FILE *fp = fopen("tokens.txt", "w");
    char ch, str[250] = "token: ";
    bool flag;
    int count = 7;

    // breaking strings into tokens
    while(ch != EOF)
    {
        ch = getc(file);
        printf("%c", ch);

        // check if it's a character or just a whitespace
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == EOF)
            flag = 0;
        else
            flag = 1;

        if (flag == true)
        {
            str[count] = ch;
            count++;
        } else {
            str[count] = '\n';
            str[count+1] = '\0';
            fputs(str, fp);
            count = 7;
        }
    }

    if (feof(file))
        printf("\n End of file reached.\n");
    else
        printf("\n Something went wrong.\n");

    fclose(fp);
    //return tokens;
}
