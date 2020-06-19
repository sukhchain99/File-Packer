#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lexer.h"

#include "../dependencies/tiny-regex-c/re.h"

char* token[] = {
    "keyword",
    "operator",
    "literal",
    "constant",
    "identifier",
    "function",
};

const char* pattern = "[auto,break,case,char,const,"\
				"continue,default,do,double,else,"\
				"enum,extern,float,for,goto,"\
				"if,int,long,register,return,short,signed,"\
				"sizeof,static,struct,switch,typedef,union,unsigned,"\
				"void,volatile,while]\\s";

void tokenizer(FILE *file)
{
    // file attributes
    FILE *fp = fopen("tokens.txt", "w");
    char ch, buff[250];
    bool flag;
    int buff_count = 0, line_no = 0, char_pos = 1;
    int str_len = 0;
    // Regex attributes
    int match_len=0, match_index=0;
    char* match_str;
    re_t match_pattern = re_compile(pattern);

    // breaking strings into tokens
    while(ch != EOF)
    {
        ch = getc(file);
        char_pos++;
        // printf("%c", ch);

        // count lines
        if (ch == '\n')
        {
            line_no++;
            char_pos = 0;
        }

        // check if it's a character or just a whitespace
        flag = (ch == ' ' || ch == '\t' || ch == '\n' || ch == EOF) ? 0 : 1;

        // if it's a character then put it in the token buffer 
        // else just put the buffer in the token file and clear the buffer
        if (flag == true)
        {
            buff[buff_count] = ch;
            buff_count++;
        } else {
            buff[buff_count] = '\0';

            match_index = re_matchp(match_pattern, buff, &match_len);
                                
            if(match_index != -1) {
                memcpy(match_str, (void*)buff[match_index], match_len);
                fprintf(fp, "%s: %s %d:%d\n", token[0], match_str, line_no, char_pos);
            } else {
                printf("no keyword found!\n");
            }
            
            fprintf(fp, "%s: %s %d:%d\n", token[2], buff, line_no, char_pos);

            buff_count = 0;
        }
    }

    if (feof(file))
        printf("\n\n End of file reached.\n\n");
    else
        printf("\n\n Something went wrong.\n\n");

    fclose(fp);
    //return tokens;
}
