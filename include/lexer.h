#include <stdio.h>

void tokenizer(FILE *file);

enum tokens {
    KEYWORD,
    OPERATOR,
    LITERAL,
    CONSTANT,
    IDENTIFIER,
    FUNCTION,
};
