#include <stdio.h>
#include "pack.h"
#include "unpack.h"

int main(int argc, char *argv[]) {

    if (argc > 1) {
        for (char i = 0; i < argc; i++)
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