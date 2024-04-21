#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define P 998244353
#define Hash_P 9982457
#define bas 13331
#define maxn 10000000
typedef struct Edge {
    int key, val;
    char *s;
    struct Edge *net;
} Edge;
Edge _edge[2 * maxn + 5];
int Edge_tot = 0;
typedef struct Hash {
    Edge *hd[maxn + 5];
} Hash;

Hash hsh;
Edge *Hash_find(Hash *self, int key) {
    for(Edge *i = self->hd[key % Hash_P]; i; i = i->net) {
        if(i->key == key) return i;
    }
    return 0;
}
Edge *Hash_add(Hash *self, int key) {
    int kk = key % Hash_P;
    _edge[Edge_tot].key = key;
    _edge[Edge_tot].net = self->hd[kk];
    self->hd[kk] = &_edge[Edge_tot++];
}
void add(int *x, int y) {
    *x += y;
    if(*x >= P) *x -= P;
}
int get_hash_key(char *s, int len) {
    int key = 0;
    For(i, 1, len) {
        key = 1ll * key * bas % P, add(&key, s[i] + 1);
        printf("%d\n", key);
    }
    return key;
}

char s[maxn + 5];
int main() {
    printf("%d\n", get_hash_key(" DrawSubwayMap", 13));
    // freopen("keepwords.txt", "r", stdin);
    // // freopen("tem.txt", "w", stdout);
    // // printf("int hash_key[maxm + 5] = {");
    // int cnt = 0;
    // while(~scanf("%s", s + 1)) {
    //     // printf("%s\n", s + 1);
    //     int key = get_hash_key(s, strlen(s + 1));
    //     Edge *edge = Hash_add(&hsh, key);
    //     printf("%d, ", key);
    //     cnt++;
    //     // if(cnt % 10 == 0) printf("\n\t\t\t\t\t\t   ");
    // }
    // printf("%d\n", cnt);
    // printf("};");
}