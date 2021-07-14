#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool bracket_check(const char str[], int length) {
    char stack[20];
    int top = -1;
    for (int i = 0; i < length; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack[++top] = str[i];
        } else {
            if (top == -1) {
                return false;
            }
            char top_elem = stack[top--];
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
    return top == -1;
}

int main() {
    const char *str = "(()){}[]{";
    if (bracket_check(str, strlen(str))) {
        printf("The bracket is vaild!\n");
    } else {
        printf("The bracket is invaild!\n");
    }
    return 0;
}