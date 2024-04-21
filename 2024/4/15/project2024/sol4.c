#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define cst const
#define DD double

#define P 998244353
#define Hash_P 9982457
#define bas 13331
#define maxn 9982457
#define maxm 2048

typedef struct Edge {
    int key, val, id;
    struct Edge *net;
} Edge;
Edge _edge[maxm];
int Edge_tot = 1;
typedef struct Hash {
    Edge *hd[maxn];
    int hsh_key[maxn], key_tot;
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
int get_hash_key(int *s, int len) {
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

int is_txt(int c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

void init() {
    For(i, 0, 164) Hash_add(&hsh, hash_key[i]);
}

unsigned int *get_malloc(int len) { return (unsigned int*)malloc(4 * len); }

int code_tot = 0;
typedef struct Code {
    unsigned int fun_tot, fun_key[maxm], fun_len[maxm], main_ind, id, len, *s, *s_fun[maxm];
} Code;
Code code[maxm];

unsigned int vis[maxm], st[maxm], tp = 0;
void Code_init(Code *self, unsigned int *s, unsigned int len) {
    Hash_init(&code_hsh);
    self->fun_tot = 0;
    self->s = get_malloc(len + 5);
    unsigned int sum = 0, now = 0;
    For(i, 1, len) {
        if(!sum) {
            if(self->fun_tot) {
                unsigned int *ss = get_malloc(now + 5);
                self->s_fun[self->fun_tot] = ss;
                self->fun_len[self->fun_tot] = now;
                memcpy(ss + 1, self->s + 1, 4 * now);
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
    For(i, 1, self->fun_tot) vis[i] = 0;
    tp = 0;
    vis[self->main_ind] = 1;
    st[++tp] = self->main_ind;
    For(i, 1, self->fun_tot) {
        int key = 0, now = 0, pre = 0;
        unsigned int *ss = self->s_fun[i], *ts = self->s;
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
        memcpy(ss + 1, ts + 1, 4 * now);
    }
    int len1 = 0;
    For(i, 1, tp) {
        memcpy(self->s + len1 + 1, self->s_fun[st[i]] + 1, 4 * self->fun_len[st[i]]);
        len1 += self->fun_len[st[i]];
    }
    self->len = len1;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))
void swap(unsigned int **s1, unsigned int **s2) {
    unsigned int *t = *s1;
    *s1 = *s2;
    *s2 = t;
}
void swap1(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

unsigned int _ty = 0, _vis[2][maxm][maxm], q[maxn], _f[maxm][maxm];
int chk(unsigned int *_s1, int _len1, unsigned int *_s2, int _len2) {
    int res = 0, now = 1;
    if(_len1 > _len2) swap(&_s1, &_s2), swap1(&_len1, &_len2);
    register unsigned int _lim = 0.05 * _len2;
    For(i, 1, _len1) {
        while(now <= _len2 && _s2[now] != _s1[i]) {
            now++; res++;
            if(res > _lim) break;
        }
        if(res > _lim) break;
        if(now > _len2) {
            res += _len1 - i + 1;
            break;
        }
    }
    if(res <= _lim) return 1;
    else if(res > _lim + 1) return 0;
    else {

    }
    _ty++;
    register unsigned int l = 500000, r = l - 1;
    if(_len2 - _len1 <= _lim) {
        q[++r] = _len1; q[++r] = _len2;
        _f[_len1][_len2] = 0;
        _vis[1][_len1][_len2] = _ty;
    }
    while(l <= r) {
        register int i = q[l++], j = q[l++], ii = (i & 1) ? i ^ 1 : i - 1, jj = (j & 1) ? j ^ 1 : j - 1;
        if(i - j == _len1 - _len2) {
            if(_f[i][j] > _lim) return 0;
        }
        if(_vis[0][i][j] == _ty) continue;
        _vis[0][i][j] = _ty;
        int fl = _f[i][j] + abs(i - j) < _lim;
        if(i == 1) {
            if(_s1[1] == _s2[j] || j + _f[i][j] <= _lim) return 1;
        }
        else if(_vis[1][ii][j] != _ty && (fl || _f[i][j] + abs(ii - j) + 1 <= _lim)) {
            if(_f[i][j] + 1 + max(ii, j) <= _lim) return 1;
            _f[ii][j] = _f[i][j] + 1;
            _vis[1][ii][j] = _ty;
            q[++r] = ii; q[++r] = j;
        }
        if(j == 1) {
            if(_s1[i] == _s2[1] || i + _f[i][j] <= _lim) return 1;
        }
        else if(_vis[1][i][jj] != _ty && (fl || _f[i][j] + abs(i - jj) + 1 <= _lim)) {
            if(_f[i][j] + 1 + max(i, jj) <= _lim) return 1;
            _f[i][jj] = _f[i][j] + 1;
            _vis[1][i][jj] = _ty;
            q[++r] = i; q[++r] = jj;
        }
        if(i != 1 && j != 1) {
            if(_s1[i] == _s2[j]) {
                if((fl || _f[ii][jj] > _f[i][j] || _vis[1][ii][jj] != _ty)) {
                    if(_f[i][j] + max(ii, jj) <= _lim) return 1;
                    _f[ii][jj] = _f[i][j];
                    _vis[1][ii][jj] = _ty;
                    q[--l] = jj; q[--l] = ii;
                }
            }
            else if(_vis[1][ii][jj] != _ty && fl) {
                if(_f[i][j] + 1 + max(ii, jj) <= _lim) return 1;
                _f[ii][jj] = _f[i][j] + 1;
                _vis[1][ii][jj] = _ty;
                q[++r] = ii; q[++r] = jj;
            }
        }
    }
    return 0;
}

unsigned int _s[maxn], _c;
FILE *file;
unsigned int fuck_new_line() {
    while(666) {
        _c = fgetc(file);
        if(_c == -1) return 0;
        if(_c != '\n' && _c != '\r') break;
    }
    return _c;
}

unsigned int read_num() {
    unsigned int res = 0;
    while(_c < '0' || _c > '9') if(!fuck_new_line()) return -1;
    while(_c >= '0' && _c <= '9') {
        res = res * 10 + _c - '0';
        if(!fuck_new_line()) return -1;
    }
    return res;
}

unsigned int as[maxm][maxm];
int main() {

    srand(time(0));
    init();
    file = fopen("codes.txt", "r");
    // freopen("out.txt", "w", stdout);
    fuck_new_line();
    int now = 0;
    code_tot = 1;
    code[1].id = read_num();
    int tot = 0;
    while(666) {
        tot++;
        _s[++now] = _c; fuck_new_line();
        if(_s[now] == '\f') {
            int len = 0, fl = 0;
            For(i, 1, now) {
                if(_s[i] != ' ' && _s[i] != '\t') _s[++len] = _s[i], fl = 1;
                else if(fl) _s[++len] = ' ', fl = 0;
            }
            _s[len + 1] = '\0';
            Code_init(&code[code_tot++], _s, len);
            if((code[code_tot].id = read_num()) == -1) break;
            now = 0;
        }
    }
    code_tot--;
    // return 0;
    For(i, 1, code_tot) vis[i] = 0;
    For(i, 1, code_tot) if(!vis[i]) {
        For(j, i + 1, code_tot) {
            if(chk(code[i].s, code[i].len, code[j].s, code[j].len)) {
                as[i][++as[i][0]] = j;
                vis[j] = 1;
            }
        }
        if(as[i][0]) {
            printf("%u ", code[i].id);
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