#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "parser.h"

static long long parse_expression(void);
static void parse_block(void);
static void expect(TokenType type);
static int parse_condition(void);
static void parse_for_loop(void);
static void parse_if_statement(void);

// Parse numeric literals and parenthesis
static long long parse_factor(void) {
    Token t = current_token();
    if (t.type == TOK_NUM) {
        next_token();
        return t.value;
    } else if (t.type == TOK_LPAREN) {
        next_token();
        long long val = parse_expression();
        expect(TOK_RPAREN);
        return val;
    } else {
        fprintf(stderr, "Unexpected token in factor\n");
        exit(1);
    }
}

// Handle * and /
static long long parse_term(void) {
    long long val = parse_factor();
    while (current_token().type == TOK_MUL || current_token().type == TOK_DIV) {
        Token op = current_token();
        next_token();
        long long rhs = parse_factor();
        if (op.type == TOK_MUL) val *= rhs;
        else if (op.type == TOK_DIV) {
            if (rhs == 0) {
                fprintf(stderr, "Error: Division by zero\n");
                exit(1);
            }
            val /= rhs;
        }
    }
    return val;
}

// Handle + and -
static long long parse_expression(void) {
    long long val = parse_term();
    while (current_token().type == TOK_PLUS || current_token().type == TOK_MINUS) {
        Token op = current_token();
        next_token();
        long long rhs = parse_term();
        if (op.type == TOK_PLUS) val += rhs;
        else val -= rhs;
    }
    return val;
}

// Handle conditions like 3 < 5 or 5 > 2
static int parse_condition(void) {
    long long lhs = parse_expression();
    Token op = current_token();
    next_token();
    long long rhs = parse_expression();
    switch (op.type) {
        case TOK_LT: return lhs < rhs;
        case TOK_GT: return lhs > rhs;
        default:
            fprintf(stderr, "Invalid conditional operator\n");
            exit(1);
    }
}

// for (init; condition; increment) { statement; }
static void parse_for_loop(void) {
    expect(TOK_LPAREN);
    parse_expression();  // initialization
    expect(TOK_SEMI);
    int condition_result = parse_condition();
    expect(TOK_SEMI);
    parse_expression();  // increment
    expect(TOK_RPAREN);

    if (condition_result) {
        parse_statement();  // one iteration (simplified)
    } else {
        // Skip block if condition is false
        if (current_token().type == TOK_LBRACE) {
            int braces = 1;
            next_token();
            while (braces > 0) {
                if (current_token().type == TOK_LBRACE) braces++;
                else if (current_token().type == TOK_RBRACE) braces--;
                next_token();
            }
        } else {
            next_token();  // skip single statement
        }
    }
}

// if (condition) { statement } else { statement }
static void parse_if_statement(void) {
    expect(TOK_LPAREN);
    int result = parse_condition();
    expect(TOK_RPAREN);

    if (result) {
        parse_statement();  // true block
        if (current_token().type == TOK_ELSE) {
            // skip else block
            next_token();
            if (current_token().type == TOK_LBRACE) {
                int braces = 1;
                next_token();
                while (braces > 0) {
                    if (current_token().type == TOK_LBRACE) braces++;
                    else if (current_token().type == TOK_RBRACE) braces--;
                    next_token();
                }
            } else {
                next_token(); // skip simple else statement
            }
        }
    } else {
        // skip if block
        if (current_token().type == TOK_LBRACE) {
            int braces = 1;
            next_token();
            while (braces > 0) {
                if (current_token().type == TOK_LBRACE) braces++;
                else if (current_token().type == TOK_RBRACE) braces--;
                next_token();
            }
        } else {
            next_token(); // skip simple statement
        }

        // run else block if present
        if (current_token().type == TOK_ELSE) {
            next_token();
            parse_statement();
        }
    }
}

// block of statements like { stmt1; stmt2; }
static void parse_block(void) {
    expect(TOK_LBRACE);
    while (current_token().type != TOK_RBRACE) {
        parse_statement();
    }
    expect(TOK_RBRACE);
}

// Main public function to parse and evaluate a statement
void parse_statement(void) {
    Token t = current_token();
    if (t.type == TOK_IF) {
        next_token();
        parse_if_statement();
    } else if (t.type == TOK_FOR) {
        next_token();
        parse_for_loop();
    } else if (t.type == TOK_LBRACE) {
        parse_block();
    } else {
        long long val = parse_expression();
        printf("Result: %lld\n", val);
        expect(TOK_SEMI);
    }
}

// Check expected token type
static void expect(TokenType type) {
    if (current_token().type != type) {
        fprintf(stderr, "Expected token %d but got %d\n", type, current_token().type);
        exit(1);
    }
    next_token();
}
