#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    struct Node *l, *r;
    char *s;
    int score;
};
struct Node *get_new() {
    struct Node *res = malloc(sizeof(struct Node));
    return res;
}
void Node_Init(struct Node *_x, char *_s, int _score) {
    _x->l = _x->r = 0;
    int len = strlen(_s);
    _x->s = malloc((len + 5) * sizeof(char));
    strcpy(_x->s, _s);
    _x->score = _score;
}

struct Node head, tail;
void add(struct Node *x) {
    struct Node *now = head.r;
    while(now != &tail && now->score <= x->score) now = now->r;
    x->l = now->l;
    x->r = now;
    now->l->r = x;
    now->l = x;
}
struct Node *get_last(int x) {
    struct Node *now = &tail;
    for(int i = 1; i <= x; ++i) {
        now = now->l;
        if(now == &head) break;
    }
    return now;
}

int main() {
    Node_Init(&head, "", 0);
    Node_Init(&tail, "", 0);
    head.r = &tail;
    tail.l = &head;
    int n;
    printf("Enter the number of students:");
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        printf("Enter the name of %dth student:", i);
        char s[150];
        scanf("%s", s);
        int score;
        printf("Enter the score of %dth student:", i);
        scanf("%d", &score);
        struct Node *now = get_new();
        Node_Init(now, s, score);
        add(now);
    }
    struct Node *now = get_last(3);
    while(now != &tail) {
        printf("%s %d\n", now->s, now->score);
        now = now->r;
    }
}