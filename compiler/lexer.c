#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "token.h"

static const char *src_ptr;
static size_t pos;
static Token cur;

static int match_keyword(const char *kw) {
    size_t len = strlen(kw);
    if (strncmp(&src_ptr[pos], kw, len) == 0 && !isalnum(src_ptr[pos + len])) {
        pos += len;
        return 1;
    }
    return 0;
}

void init_tokenizer(const char *src) {
    src_ptr = src;
    pos = 0;
    next_token();
}

Token current_token(void) {
    return cur;
}

void next_token(void) {
    while (isspace(src_ptr[pos])) pos++;
    char c = src_ptr[pos];

    if (c == '\0') {
        cur.type = TOK_EOF;
        return;
    }

    if (match_keyword("if"))    { cur.type = TOK_IF; return; }
    if (match_keyword("else"))  { cur.type = TOK_ELSE; return; }
    if (match_keyword("for"))   { cur.type = TOK_FOR; return; }

    switch (c) {
        case '+': cur.type = TOK_PLUS; pos++; return;
        case '-': cur.type = TOK_MINUS; pos++; return;
        case '*': cur.type = TOK_MUL; pos++; return;
        case '/': cur.type = TOK_DIV; pos++; return;
        case '<': cur.type = TOK_LT; pos++; return;
        case '>': cur.type = TOK_GT; pos++; return;
        case '=': cur.type = TOK_ASSIGN; pos++; return;
        case ';': cur.type = TOK_SEMI; pos++; return;
        case '(': cur.type = TOK_LPAREN; pos++; return;
        case ')': cur.type = TOK_RPAREN; pos++; return;
        case '{': cur.type = TOK_LBRACE; pos++; return;
        case '}': cur.type = TOK_RBRACE; pos++; return;
    }

    if (isdigit(c)) {
        int val = 0;
        while (isdigit(src_ptr[pos])) {
            val = val * 10 + (src_ptr[pos] - '0');
            pos++;
        }
        cur.type = TOK_NUM;
        cur.value = val;
        return;
    }

    if (isalpha(c)) {
        cur.type = TOK_ID;
        cur.name = c;
        pos++;
        return;
    }

    cur.type = TOK_INVALID;
    pos++;
}
