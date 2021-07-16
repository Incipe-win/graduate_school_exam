#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(const char *haystack, const char *needle) {
    int size1 = strlen(haystack), size2 = strlen(needle);
    if (size2 == 0) {
        return 0;
    }
    if (size1 == 0) {
        return -1;
    }
    if (size1 < size2) {
        return -1;
    }
    int i = 0, j = 0;
    bool flag = false;
    int temp = 0;
    while (i < size1) {
        if (haystack[i] == needle[j]) {
            if (!flag) {
                flag = true;
                temp = i;
            }
            ++i;
            ++j;
        } else {
            j = 0;
            flag = false;
            i = temp + 1;
            temp = i;
        }
        if (j == size2) {
            return temp;
        }
    }
    return -1;
}

int Index(const char *haystack, const char *needle) {
    int size1 = strlen(haystack), size2 = strlen(needle);
    if (size2 == 0) {
        return 0;
    }
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == size2) {
        return i - j;
    } else {
        return -1;
    }
}

int main() {
    const char *haystack = "abaabaabcabaabc";
    const char *needle = "abaabc";
    printf("The position is %d\n", strStr(haystack, needle));
    printf("The position is %d\n", Index(haystack, needle));
    return 0;
}