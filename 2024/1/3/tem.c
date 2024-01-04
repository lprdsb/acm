#include<stdio.h>
#include<stdlib.h>

int main(void) {
    char *s[] = { "abc", "defg" };
    char **p[] = { s, s + 1 }, ***p1;
    p1 = p;
    printf("%s", *(*p1 + 1));
}