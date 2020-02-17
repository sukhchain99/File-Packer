#include <stdio.h>
#include <unistd.h>
#include "pack.h"
#include "unpack.h"

int main(int argc, char *argv[]) {

    if (argc > 1) {
        if ( access( argv[1], F_OK ) != -1 ) {
            printf("%s will be used to load files and directories \
for Packing and Unpacking.\n", argv[1]);
        } else { 
            printf("%s is not a file.\n", argv[1]);
        }

        for (char i = 2; i < argc; i++)
        {
            printf("%s\t", argv[i]);
        }
        printf("\n");
    }
    else
    {
        printf("You didn't provide any arguments.\n");
    }
    

    return 0;
}