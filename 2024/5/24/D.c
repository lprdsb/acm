#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define P 998244353
#define Hash_P 9982457
#define bas 13331
#define maxn 10000000
typedef struct Edge {
    int key, val, id;
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
Edge *Hash_add(Hash *self, int key, char *s) {
    int kk = key % Hash_P, len = strlen(s + 1);
    _edge[Edge_tot].key = key;
    _edge[Edge_tot].net = self->hd[kk];
    _edge[Edge_tot].s = malloc((len + 5) * sizeof(char));
    _edge[Edge_tot].id = Edge_tot;
    strcpy(_edge[Edge_tot].s + 1, s + 1);
    self->hd[kk] = &_edge[Edge_tot++];
    return self->hd[kk];
}
void add(int *x, int y) {
    *x += y;
    if(*x >= P) *x -= P;
}
int get_hash_key(char *s) {
    int len = strlen(s + 1), key = 0;
    For(i, 1, len) key = 1ll * key * bas % P, add(&key, (500 + s[i]) + 1);
    return key;
}

int n, st[maxn + 5], tp = 0;
char s[10005];
typedef struct Path {
    int len, id;
} Path;
Path ma[1005][1005];

#define abs(x) ((x) > 0 ? (x) : -(x))
int pre[maxn + 5], dis[maxn + 5], vis[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    FILE *fin = fopen("bgstations.txt", "r");
    fscanf(fin, "%d", &n);
    for(int i = 1; i <= n; ++i) {
        int id, m; fscanf(fin, "%d%d", &id, &m);
        tp = 0;
        for(int j = 1; j <= m; ++j) {
            int ty;
            fscanf(fin, "%s%d", s + 1, &ty);
            int key = get_hash_key(s);
            if(!Hash_find(&hsh, key)) Hash_add(&hsh, key, s);
            st[++tp] = Hash_find(&hsh, key)->id;
        }
        for(int j = 1; j <= tp; ++j) for(int p = 1; p <= tp; ++p) if(st[j] != st[p]) {
            int len = abs(j - p);
            if(st[1] == st[tp] && len > tp - 1 - len) len = tp - 1 - len;
            if(!ma[st[j]][st[p]].len || len < ma[st[j]][st[p]].len) {
                ma[st[j]][st[p]].id = id;
                ma[st[j]][st[p]].len = len;
            }
        }
    }

    scanf("%s", s + 1); int key = get_hash_key(s);
    int ss = Hash_find(&hsh, key)->id;
    scanf("%s", s + 1); key = get_hash_key(s);
    int tt = Hash_find(&hsh, key)->id;
    For(i, 0, Edge_tot - 1) dis[i] = -1;
    dis[ss] = 0;
    while(666) {
        int mn = -1;
        For(i, 0, Edge_tot - 1) if(!vis[i] && dis[i] != -1) {
            if(mn == -1 || dis[mn] > dis[i]) mn = i;
        }
        if(mn == -1) return 0;
        if(mn == tt) break;
        vis[mn] = 1;
        For(i, 0, Edge_tot - 1) if(!vis[i] && ma[mn][i].len) {
            int nw = dis[mn] + ma[mn][i].len;
            if(dis[i] == -1 || nw < dis[i]) {
                dis[i] = nw;
                pre[i] = mn;
            }
        }
    }
    int now = tt;
    st[tp = 1] = now;
    while(now != ss) {
        now = pre[now];
        st[++tp] = now;
    }
    printf("%s", _edge[st[tp]].s + 1);
    Rof(i, tp - 1, 1) printf("-%d(%d)-%s", ma[st[i + 1]][st[i]].id, ma[st[i + 1]][st[i]].len, _edge[st[i]].s + 1);
}