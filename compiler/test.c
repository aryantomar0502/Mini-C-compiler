#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "parser.h"
// Forward declaration from parser.c
void parse_statement(void);

int main(void) {
    struct {
        const char *code;
        const char *description;
    } tests[] = {
        { "1+2;",                       "Simple addition" },
        { "2*3+4;",                     "Multiplication and addition" },
        { "2*(3+4);",                   "Parentheses and multiplication" },
        { "12+34*(5-2);",              "Complex expression" },
        { "(1+2)*(3+4);",              "Nested expression" },
        { "10/2+7*3;",                 "Division and multiplication" },
        { "100-5*5;",                  "Subtraction and multiplication" },
        { "(8/2)/2;",                  "Nested division" },
        { "(2+3)*(4-1)/5;",            "Combination of operations" },
        { "if (3 < 5) { 2+3; }",       "Simple if block (true condition)" },
        { "if (5 < 3) { 1+2; }",       "Simple if block (false condition)" },
        { "if (5 < 3) { 1+2; } else { 7+8; }", "If-else with false if block" },
        { "for (1; 2 < 3; 1) { 4+5; }", "Simple for loop (1 iteration)" }
    };

    int ntests = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < ntests; i++) {
        printf("Test %2d: %-40s → ", i + 1, tests[i].description);
        init_tokenizer(tests[i].code);
        parse_statement();
    }

    return 0;
}



// command to run the code
// gcc -o mini_c_compiler lexer.c parser.c main.c
// gcc -o test_mini lexer.c parser.c test.c

// # Run your interpreter:
// ./mini_c_compiler "12 + 34*(5 - 2)"

// # Run the test suite:
// ./test_mini
