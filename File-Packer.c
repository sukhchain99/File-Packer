#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dependencies/tiny-regex-c/re.h"

#include "include/pack.h"
#include "include/unpack.h"
#include "include/lexer.h"

#define VERSION "0.0.0.2"

enum Options {P, o, r, t, U, g, u, E, s, e};
enum Features {test, verbose, help, quite};

// Options available globally
char OPTIONS[10], FEATURES[4];
FILE *file;
bool is_file_open = false;

int main(int argc, char *argv[]) {
    printf("file-pack version : %s\n", VERSION);

    // Do this if arguments were provided.
    if (argc > 1) {
        // Checks if file exists or not.
        if ( access( argv[1], F_OK ) != -1 ) {
            printf("\nusing %s\n", argv[1]);
            file = fopen(argv[1], "r");
            if (file == NULL) {
                printf("Error opening the file : %s\n", argv[1]);
                exit(EXIT_FAILURE);
            } else {
                is_file_open = true;
            }
        } else {
            printf("\n%s does not exist or not readable\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        // OPTIONS count block
        char options_count = 0;
        {
            char temp[11];
            for (int i = 2; i < argc; ++i)
            {
                strcpy(temp, argv[i]);
                if (temp[0] == '-' && temp[1] != '-') {
                    options_count++;
                } else if (temp[0] == '-' && temp[1] == '-') {
                    break;
                } else {
                    printf("Invalid option : %s\n", argv[i]);
                    exit(EXIT_FAILURE);
                }
            }
        }

        // FEATURES count block
        char features_count = 0;
        {
            char temp[11];
            for (int i = options_count+2; i < argc; ++i)
            {
                strcpy(temp, argv[i]);
                if (temp[0] == '-' && temp[1] == '-') {
                    features_count++;
                } else {
                    printf("Invalid feature : %s\n", argv[i]);
                    exit(EXIT_FAILURE);
                }
            }
        }


        // will contain the options provided through arguments
        // options start from 2nd argument
        char buffer[12];

        // Convert arguments to string buffer
        for (char i = 2; i < options_count+2; ++i)
        {
            int len = strlen(argv[i]);

            if (len > 11) {
                printf("%s exceeds the option's allowed length!\n", argv[i]);
                exit(EXIT_FAILURE);
            } else {
                // Enable OPTIONS
                strcpy(buffer, argv[i]);
                for (int i = 1; i < len; ++i)
                {
                    switch (buffer[i])
                    {
                    case 'P':
                        OPTIONS[P] = 1;
                        break;
                    case 'o':
                        OPTIONS[o] = 1;
                        break;
                    case 'r':
                        OPTIONS[r] = 1;
                        break;
                    case 't':
                        OPTIONS[t] = 1;
                        break;
                    case 'U':
                        OPTIONS[U] = 1;
                        break;
                    case 'g':
                        OPTIONS[g] = 1;
                        break;
                    case 'u':
                        OPTIONS[u] = 1;
                        break;
                    case 'E':
                        OPTIONS[E] = 1;
                        break;
                    case 's':
                        OPTIONS[s] = 1;
                        break;
                    case 'e':
                        OPTIONS[e] = 1;
                        break;

                    default:
                        printf("Not an Option %c, ", buffer[i]);
                    }
                } printf("\n");
            }
        }


        // Enable the features provided to the program.
        for (char i = options_count+2; i < argc; i++)
        {
            if (!strcmp(argv[i], "--test")) {
                FEATURES[test] = 1;
            } else if (!strcmp(argv[i], "--verbose")) {
                FEATURES[verbose] = 1;
            } else if (!strcmp(argv[i], "--help")) {
                FEATURES[help] = 1;
            } else if (!strcmp(argv[i], "--quite")) {
                FEATURES[quite] = 1;
            } else
                printf("%s not a feature! \n", argv[i]);
        } printf("\n");
    }

    // Do this if arguments weren't provided.
    else {
        printf("You didn't provide any arguments.\n");
        printf("Finding \"packer.fp\" file\n");

        if ( access( "packer.fp", F_OK ) != -1 ) {
            printf("\nusing \"packer.fp\"\n");
            file = fopen("packer.fp", "r");
            if (file == NULL) {
                printf("Error opening the file : %s\n", argv[1]);
                exit(EXIT_FAILURE);
            } else {
                is_file_open = true;
            }
        } else {
            printf("\npacker.fp does not exist or not readable\n");
            exit(EXIT_FAILURE);
        }

    }


    /**
     * From here the application logic starts
     *
    */
    tokenizer(file);


    // closing the file
    fclose(file);

    // To be removed after the implementation of pack.c and unpack.c
    printf("\n");
    for (char i = 0; i < 10; i++)
    {
        printf("%d ", OPTIONS[i]);
    } printf(" ");
    for (char i = 0; i < 4; i++)
    {
        printf("%d ", FEATURES[i]);
    } printf("\n");

    return 0;
}
