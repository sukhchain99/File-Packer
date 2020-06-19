#include <stdio.h>
#include "dependencies/tiny-regex-c/re.h"

int main()
{
    int match_length;

    const char* string = "This is ... Hello World   ! string";

    re_t pattern = re_compile("[hH]ello [wW]orld\\s*[!]?");

    int match_index = re_matchp(pattern, string, &match_length);

    printf("match found at %d! of length %d", match_index, match_length);

    return 0;
}