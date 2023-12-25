#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
using namespace std;

#define maxn 20
int T, n;
int st[maxn + 5][maxn + 5], top[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int tot = 0;
int w[10] = { 0, 1, 2, 3, 5, 4, 6, 7, 8, 9 };
int que(cst vector<int> &vec) {
    tot++;
    printf("? ");
    for(auto i : vec) printf("%d ", i);
    puts("");
    fflush(stdout);
    int res = 0; read(res);
    // for(auto i : vec) if(w[i] > w[res]) res = i;
    // cout << res << endl;
    return res;
}

void upd(int x) {
    vector<int> vec;
    For(i, 1, n) vec.pb(st[x][i]);
    int tem = que(vec);
    For(i, 1, n) if(st[x][i] == tem) swap(st[x][i], st[x][1]);
}
// int tot = 0;
int to[405];
vector<int> res;
int st1[25], top1 = 0, st2[25], top2 = 0;
void sol(int ty) {
    vector<int> vec;
    For(i, 1, n) vec.pb(st[i][1]);
    int tem = que(vec);
    res.pb(tem);
    swap(st[to[tem]][1], st[to[tem]][top[to[tem]]]);
    top[to[tem]]--;
    if(ty) {
        while(top[to[tem]] < n) {
            For(i, 1, n) if(i != to[tem]) {
                while(top[to[tem]] < n && top[i] > 1) {
                    // tot++;
                    // assert(tot <= )
                    int tem1 = st[i][top[i]--];
                    to[st[to[tem]][++top[to[tem]]] = tem1] = to[tem];
                }
            }
        }
        upd(to[tem]);
    }
    else {
        For(i, 1, n) {
            if(i != to[tem]) {
                st1[++top1] = st[i][1];
                For(j, 2, top[i]) st2[++top2] = st[i][j];
            }
            else {
                For(j, 1, top[i]) st2[++top2] = st[i][j];
            }
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    // T = 1;
    For(_, 1, T) {
        top1 = top2 = tot = 0;
        res.resize(0);
        read(n);
        // n = 3;
        For(i, 1, n) top[i] = 0;
        For(i, 1, n) For(j, 1, n) to[st[i][++top[i]] = (i - 1) * n + j] = i;
        For(i, 1, n) upd(i);
        For(i, 1, n * n - 2 * n + 1) sol(1);
        sol(0);
        // For(i, 1, top1) cout << st1[i] << " "; cout << endl;
        Rof(i, n, 3) {
            st1[i] = st2[top2--];
            vector<int> vec;
            For(i, 1, n) vec.pb(st1[i]);
            int tem = que(vec);
            For(j, 1, i - 1) if(st1[j] == tem) swap(st1[j], st1[i - 1]);
            res.pb(tem);
        }
        res.pb(st1[1]);
        printf("! ");
        for(auto i : res) printf("%d ", i);
        puts("");
        fflush(stdout);
        // printf("%d %d\n", _, tot);
    }
    // cout << (DD)clock() / 1000 << endl;
}