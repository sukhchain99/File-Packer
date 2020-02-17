#include <stdio.h>
#include <unistd.h>
#include "pack.h"
#include "unpack.h"

int main(int argc, char *argv[]) {

    // Checks if arguments are provided or not.
    if (argc > 1) {
        // Checks if file exists or not.
        if ( access( argv[1], F_OK ) != -1 ) {
            printf("%s will be used to load files and directories \
for Packing and Unpacking.\n", argv[1]);
        } else { 
            printf("%s is not a file.\n", argv[1]);
        }

        // Prints the options provided to the program.
        for (char i = 2; i < argc; i++)
        {
            printf("%s\t", argv[i]);
        }
        printf("\n");
    }
    // Print this if arguments weren't provided.
    else
    {
        printf("You didn't provide any arguments.\n");
    }
    
    return 0;
}