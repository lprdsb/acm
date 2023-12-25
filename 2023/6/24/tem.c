#include<stdio.h>

int a, b, c, d;

struct Node{
    int a:3, b:5, c:6, d:9;
} node;

int st[2000], top;

int main(){
    scanf("%d %d %d %d", &a, &b, &c, &d);
    node.a = a;
    node.b = b;
    node.c = c;
    node.d = d;

    printf("%d %x ", node.a, node.a);
    while(node.a) st[++top] = node.a & 1, node.a >>= 1;
    while(top) printf("%d", st[top--]);
    puts("");

    
    printf("%d %x ", node.b, node.b);
    while(node.b) st[++top] = node.b & 1, node.b >>= 1;
    while(top) printf("%d", st[top--]);
    puts("");

    
    printf("%d %x ", node.c, node.c);
    while(node.c) st[++top] = node.c & 1, node.c >>= 1;
    while(top) printf("%d", st[top--]);
    puts("");

    
    printf("%d %x ", node.d, node.d);
    while(node.d) st[++top] = node.d & 1, node.d >>= 1;
    while(top) printf("%d", st[top--]);
    puts("");
}