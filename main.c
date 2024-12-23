#include <stdio.h>
#include <stdbool.h>

bool isValid(char *s) {
    char *q = s;

    for (char *p = s; *p; p++) {
        switch (*p) {
            case '(': *q++ = ')'; continue;
            case '{': *q++ = '}'; continue;
            case '[': *q++ = ']'; continue;
            default: if (q == s || *p != *--q) return false;
        }
    }

    return q == s;
}

int main() {
    char input1[] = "()";
    char input2[] = "()[]{}";
    char input3[] = "(]";
    char input4[] = "([])";

    printf("Example 1: %s\n", isValid(input1) ? "true" : "false");
    printf("Example 2: %s\n", isValid(input2) ? "true" : "false");
    printf("Example 3: %s\n", isValid(input3) ? "true" : "false");
    printf("Example 4: %s\n", isValid(input4) ? "true" : "false");

    return 0;
}