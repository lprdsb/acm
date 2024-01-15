#include<stdio.h>
#include<stdlib.h>

int a[10];

void fun(int b[3]) {
    printf("%d\n", sizeof(b) / sizeof(int));
}

int main(void) {
    fun(a);
}