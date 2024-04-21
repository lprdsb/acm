#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define cst const
#define DD double

#define P 998244353
#define Hash_P 9982457
#define bas 13331
#define maxn 10000000
#define maxm 5000

typedef struct Edge {
    int key, val, id;
    struct Edge *net;
} Edge;
Edge _edge[2 * maxn + 5];
int Edge_tot = 1;
typedef struct Hash {
    Edge *hd[maxn + 5];
    int hsh_key[maxn + 5], key_tot;
} Hash;
Hash hsh, code_hsh;

Edge *Hash_find(Hash *self, int key) {
    for(Edge *i = self->hd[key % Hash_P]; i; i = i->net) if(i->key == key) return i;
    return 0;
}
Edge *Hash_add(Hash *self, int key) {
    Edge *res;
    if(res = Hash_find(self, key)) return res;
    int kk = key % Hash_P;
    _edge[Edge_tot].key = key;
    _edge[Edge_tot].net = self->hd[kk];
    self->hd[kk] = &_edge[Edge_tot];
    self->hsh_key[++self->key_tot] = kk;
    return &_edge[Edge_tot++];
}
void Hash_init(Hash *self) { while(self->key_tot) self->hd[self->hsh_key[self->key_tot--]] = 0; }
void add(int *x, int y) {
    *x += y;
    if(*x >= P) *x -= P;
}
int get_hash_key(char *s, int len) {
    int key = 0;
    For(i, 1, len) key = 1ll * key * bas % P, add(&key, s[i] + 1);
    return key;
}
int hash_key[maxm + 5] = { 702836896, 298549549, 870930970, 671849434, 871236246, 272559594, 855209072, 133424585, 727833438, 628017386,
                           304010925, 597819279, 973358067, 278179280, 971043930, 481207152, 21443013, 593729119, 942470045, 229292553,
                           638073486, 337797616, 533959335, 783349575, 737832889, 392063309, 495261604, 443827364, 1346543, 1413189,
                           573442417, 516437233, 650135711, 828416824, 57441242, 714188363, 853478784, 654123679, 783134356, 783761678,
                           393416073, 505818095, 403918354, 192812948, 953914134, 381329319, 985906155, 295331812, 350089730, 350089746,
                           832963139, 832963155, 611396393, 542965820, 611396409, 96025449, 971465098, 96025465, 887400425, 570337625,
                           895423743, 862684978, 156827965, 713530283, 212722610, 210128323, 765875903, 319035719, 854107854, 20075654,
                           401462591, 756720398, 903610347, 550348555, 391754202, 552733697, 637307982, 406132506, 900785716, 421363440,
                           35027950, 46331160, 913205256, 467875703, 126846888, 467675733, 126646918, 467835701, 126806886, 467769048,
                           297671968, 112444570, 549158925, 533746019, 316644937, 70680394, 894560496, 494293836, 136072539, 921724070,
                           136032537, 135965884, 982886163, 651531213, 802895287, 829140126, 347259132, 498623206, 524868045, 321237769,
                           836729508, 221118236, 705543395, 160202032, 405846618, 595143173, 118464525, 262018626, 440318026, 593915751,
                           606244538, 20157433, 570644250, 149125430, 742515852, 525054671, 525054674, 525054677, 494293829, 494293837,
                           20286982, 120955347, 379094718, 581647321, 745859474, 980058645, 632715995, 542749676, 408524325, 903000483,
                           909453459, 43221411, 217745474, 315176182, 447290862, 363519964, 980530865, 896759967, 196499235, 2990478,
                           230043152, 940852069, 929191592, 667977125, 533906019, 400967377, 320307556, 130765843, 429631827, 800547419,
                           133613623, 594255317, 152273079, 774498664, 303579339, };//165

int is_txt(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

void init() {
    For(i, 0, 164) Hash_add(&hsh, hash_key[i]);
}

char *get_malloc(int len) { return malloc(len + 5); }

int code_tot = 0;
typedef struct Code {
    int fun_tot, fun_key[maxm + 5], fun_len[maxm + 5], main_ind, id, len;
    char *s, *s_fun[maxm + 5];
} Code;
Code code[maxm + 5];

int vis[maxm + 5], st[maxm + 5], tp = 0;
void Code_init(Code *self, char *s, int len) {
    Hash_init(&code_hsh);
    self->fun_tot = 0;
    self->s = get_malloc(len + 5);
    int sum = 0, now = 0;
    For(i, 1, len) {
        if(!sum) {
            if(self->fun_tot) {
                self->s[now + 1] = '\0';
                char *ss = get_malloc(now + 5);
                self->s_fun[self->fun_tot] = ss;
                self->fun_len[self->fun_tot] = now;
                strcpy(ss + 1, self->s + 1);
            }
            self->fun_tot++;
            now = 0;

            while(i <= len && !is_txt(s[i])) i++;
            if(i > len) break;
            int key = 0;
            while(is_txt(s[i])) {
                key = 1ll * bas * key % P;
                add(&key, s[i] + 1);
                i++;
            }
            if(key == 655907298) {
                self->main_ind = self->fun_tot;
            }

            self->fun_key[self->fun_tot] = key;
            Hash_add(&code_hsh, key)->id = self->fun_tot;
            while(s[i] != '{') i++;
        }
        if(s[i] == '{') sum++;
        if(s[i] == '}') sum--;
        self->s[++now] = s[i];
    }
    self->fun_tot--;
    // if(self->fun_tot > 4000) {
    //     int ok = 1;
    //     while(ok) ok++;
    // }
    For(i, 1, self->fun_tot) vis[i] = 0;
    tp = 0;
    vis[self->main_ind] = 1;
    st[++tp] = self->main_ind;
    For(i, 1, self->fun_tot) {
        int key = 0, now = 0, pre = 0;
        char *ss = self->s_fun[i], *ts = self->s;
        For(j, 1, self->fun_len[i]) {
            if(!is_txt(ss[j])) {
                Edge *edge;
                if(edge = Hash_find(&code_hsh, key)) {
                    ts[++pre] = 'F';
                    ts[++pre] = 'U';
                    ts[++pre] = 'N';
                    ts[++pre] = 'C';
                    now = pre;
                    if(i == self->main_ind) {
                        if(!vis[edge->id]) st[++tp] = edge->id;
                        vis[edge->id] = 1;
                    }
                }
                else if(Hash_find(&hsh, key) || (ts[pre + 1] >= '0' && ts[pre + 1] <= '9')) pre = now;
                else now = pre;
                if(ss[j] != ' ' && ss[j] != '\t') ts[pre = ++now] = ss[j];
                key = 0;
            }
            else {
                ts[++now] = ss[j];
                key = 1ll * key * bas % P, add(&key, ss[j] + 1);
            }
        }
        self->fun_len[i] = now;
        ts[++now] = '\0';
        strcpy(ss + 1, ts + 1);
    }
    int len1 = 0;
    For(i, 1, tp) {
        strcpy(self->s + len1 + 1, self->s_fun[st[i]] + 1);
        len1 += self->fun_len[st[i]];
    }
    self->len = len1;
    printf("%s\n", self->s + 1);
}

int str_to_num(char *s) {
    int res = 0;
    For(i, 1, maxn) {
        if(s[i] >= '0' && s[i] <= '9') res = 10 * res + s[i] - '0';
        else break;
    }
    return res;
}

void chkmn(int *x, int y) {
    if(*x > y) *x = y;
}

int f[maxm + 5][maxm + 5];
int get_f(char *s1, int len1, char *s2, int len2) {
    f[len1][len2] = 0;
    Rof(i, len1, 0) Rof(j, len2, 0) if(i != len1 || j != len2) {
        f[i][j] = len1 + len2;
        if(i != len1) {
            if(j != len2) {
                chkmn(&f[i][j], f[i + 1][j + 1] + !(s1[i + 1] == s2[j + 1]));
                chkmn(&f[i][j], f[i][j + 1] + 1);
            }
            chkmn(&f[i][j], f[i + 1][j] + 1);
        }
        else chkmn(&f[i][j], f[i][j + 1] + 1);
    }
    return f[0][0];
}


int max(cst int *x, cst int *y) { return *x < *y ? *y : *x; }

int as[maxm + 5][maxm + 5];

char _s[maxn + 5];
FILE *file;
int fuck_new_line(char *s) {
    while(666) {
        if(!fgets(s + 1, maxn, file)) return 0;
        if(s[1] != '\n' && s[1] != '\r') break;
    }
    return 1;
}
int main() {
    init();
    // freopen("codes.txt", "r", stdin);
    file = fopen("codes.txt", "r");
    freopen("out.txt", "w", stdout);
    char *pos = _s;
    int len = 0;
    code_tot = 1;
    if(!fuck_new_line(pos)) return 0;
    code[code_tot].id = str_to_num(pos);
    pos = _s;
    len = 0;
    int tot = 0;
    while(fuck_new_line(pos)) {
        tot++;
        len += strlen(pos + 1);
        if(_s[len] == '\n' || _s[len] == '\r') _s[len--] = '\0';
        if(*(pos + 1) == '\f') {
            Code_init(&code[code_tot++], _s, len);
            if(!fuck_new_line(_s)) break;
            code[code_tot].id = str_to_num(_s);
            pos = _s;
            len = 0;
        }
        else pos = _s + len;
    }
    code_tot--;
    For(i, 1, code_tot) vis[i] = 0;
    For(i, 1, code_tot) if(!vis[i]) {
        For(j, 1, code_tot) if(i != j) {
            int tem = get_f(code[i].s, code[i].len, code[j].s, code[j].len);
            if(1 - (DD)tem / max(&code[i].len, &code[j].len) >= 0.95) {
                as[i][++as[i][0]] = j;
                vis[j] = 1;
            }
        }
        if(as[i][0]) {
            printf("%d ", code[i].id);
            For(j, 1, as[i][0]) {
                printf("%d", code[as[i][j]].id);
                if(j != as[i][0]) putchar(' ');
            }
            puts("");
        }
    }
    return 0;
}
/*
312157659
*/