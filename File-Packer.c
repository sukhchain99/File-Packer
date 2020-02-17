#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "pack.h"
#include "unpack.h"

// Options available globally
char option[10];

int main(int argc, char *argv[]) {

    // Checks if arguments are provided or not.
    if (argc > 1) {
        // Checks if file exists or not.
        if ( access( argv[1], F_OK ) != -1 ) {
            printf("%s will be used to load files and directories \
for Packing and Unpacking.\n", argv[1]);
        } else { 
            printf("%s is not a file.\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        // Enables the options provided to the program.
        enum Options enable[argc-2];
        char buffer[10];

        for (char i = 2; i < argc; i++)
        {
            strcpy(buffer, argv[i]);
            enable[i-2] = buffer[1];
        }

        for (char i = 2; i < argc; i++)
        {
            switch (enable[i-2])
            {
            case 'P':
                option[P] = 1;
                break;
            case 'o':
                option[o] = 1;
                break;
            case 'r':
                option[r] = 1;
                break;
            case 't':
                option[t] = 1;
                break;
            case 'U':
                option[U] = 1;
                break;
            case 'g':
                option[g] = 1;
                break;
            case 'u':
                option[u] = 1;
                break;
            case 'E':
                option[E] = 1;
                break;
            case 's':
                option[s] = 1;
                break;
            case 'e':
                option[e] = 1;
                break;
            
            default:
                printf("Wrong Option %s", argv[i]);
                break;
            }
        }
        printf("\n");
    }
    // Print this if arguments weren't provided.
    else
    {
        printf("You didn't provide any arguments.\n");
    }
    
    for (char i = 0; i < 10; i++)
    {
        printf("%d ", option[i]);
    } printf("\n");
    
    return 0;
}