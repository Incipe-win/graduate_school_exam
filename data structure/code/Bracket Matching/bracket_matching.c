#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct SqStack {
    char data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack *S) {
    for (int i = 0; i < MAXSIZE; ++i) {
        S->data[i] = 0;
    }
    S->top = -1;
}

bool StackEmpty(const SqStack *S) { return S->top == -1; }

bool Push(SqStack *S, char x) {
    if (S->top == MAXSIZE - 1) {
        return false;
    }
    S->data[++S->top] = x;
    return true;
}

bool Pop(SqStack *S, char *x) {
    if (StackEmpty(S)) {
        return false;
    }
    *x = S->data[S->top--];
    return true;
}

bool bracket_check(const char str[], int length) {
    SqStack S;
    InitStack(&S);
    for (int i = 0; i < length; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(&S, str[i]);
        } else {
            if (StackEmpty(&S)) {
                return false;
            }
            char top_elem;
            Pop(&S, &top_elem);
            if (str[i] == ')' && top_elem != '(') {
                return false;
            }
            if (str[i] == ']' && top_elem != '[') {
                return false;
            }
            if (str[i] == '}' && top_elem != '{') {
                return false;
            }
        }
    }
    return StackEmpty(&S);
}

int main() {
    const char *str = "(())[]{}{}";
    if (bracket_check(str, strlen(str))) {
        printf("The bracket is vaild!\n");
    } else {
        printf("The bracket is invaile!\n");
    }
    return 0;
}