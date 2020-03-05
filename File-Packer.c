#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "pack.h"
#include "unpack.h"

#define VERSION "0.0.0.1"

// Options available globally
char p_option[10], s_option[4];

int main(int argc, char *argv[]) {
    printf("file-pack version : %s\n", VERSION);

    // Checks if arguments are provided or not.
    if (argc > 1) {
        // Checks if file exists or not.
        if ( access( argv[1], F_OK ) != -1 ) {
            printf("\nusing %s\n", argv[1]);
        } else {
            printf("\n%s does not exist or not readable\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        // will contain the options provided through arguments
        // options start from 2nd argument
        enum Options enable[argc-2];
        char buffer[10];

        // Convert arguments to string buffer
        for (char i = 2; i < argc; i++)
        {
            strcpy(buffer, argv[i]);
            enable[i-2] = buffer[1];
        }

        // Enable the options provided to the program.
        for (char i = 2; i < argc; i++)
        {
            switch (enable[i-2])
            {
            case 'P':
                p_option[P] = 1;
                break;
            case 'o':
                p_option[o] = 1;
                break;
            case 'r':
                p_option[r] = 1;
                break;
            case 't':
                p_option[t] = 1;
                break;
            case 'U':
                p_option[U] = 1;
                break;
            case 'g':
                p_option[g] = 1;
                break;
            case 'u':
                p_option[u] = 1;
                break;
            case 'E':
                p_option[E] = 1;
                break;
            case 's':
                p_option[s] = 1;
                break;
            case 'e':
                p_option[e] = 1;
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

    // To be removed after the implementation of pack.c and unpack.c
    for (char i = 0; i < 10; i++)
    {
        printf("%d ", p_option[i]);
    } printf("\n");

    return 0;
}
