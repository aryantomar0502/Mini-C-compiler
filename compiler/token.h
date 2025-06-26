#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOK_EOF,
    TOK_PLUS,    // +
    TOK_MINUS,   // -
    TOK_MUL,     // *
    TOK_DIV,     // /
    TOK_LPAREN,  // (
    TOK_RPAREN,  // )
    TOK_NUM,     // integer literal
    TOK_IF,
    TOK_ELSE,
    TOK_FOR,
    TOK_SEMI,    // ;
    TOK_LBRACE,  // {
    TOK_RBRACE,  // }
    TOK_LT,      // <
    TOK_GT,      // >
    TOK_ASSIGN,  // =
    TOK_ID,      // variable (only one character)
    TOK_INVALID
} TokenType;

typedef struct {
    TokenType type;
    int       value;  // for TOK_NUM
    char      name;   // for TOK_ID
} Token;

void init_tokenizer(const char *src);
void next_token(void);
Token current_token(void);

#endif // TOKEN_H
