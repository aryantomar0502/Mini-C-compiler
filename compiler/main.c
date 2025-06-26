#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "parser.h"

void parse_statement(void);

int main(int argc, char *argv[]) {
    char buffer[1024];
    const char *input;

    if (argc >= 2) {
        input = argv[1];
    } else {
        printf("Enter code: ");
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            fprintf(stderr, "Error reading input\n");
            return EXIT_FAILURE;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        input = buffer;
    }

    init_tokenizer(input);
    while (current_token().type != TOK_EOF) {
        parse_statement();
    }

    return EXIT_SUCCESS;
}
