#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
typedef long long ll;
using namespace std;

const int N = 1e5 + 7, P = 10;

int len, n, m;
char ss[N];
struct NUM {
    int a[6];
    // NUM() {}
    NUM() {
        fs(i, 1, len)a[i] = 0;
    }
    NUM(int x) {
        fn(i, len, 1)a[i] = x % P, x /= P;
    }
    NUM(char *s) {
        fs(i, 1, len)a[i] = s[i] - '0';
    }
    void clr() {
        fs(i, 1, len)a[i] = 0;
    }
    NUM operator + (const NUM &rhs) {
        NUM tp;
        fs(i, 1, len)tp.a[i] = (a[i] + rhs.a[i]) % P;
        return tp;
    }
    int val() {
        int tp = 0;
        fs(i, 1, len)tp = tp * 10 + a[i];
        return tp;
    }
    void print() {
        fs(i, 1, len)printf("%d", a[i]);
    }
}dta[N];
int tot;

vector<int>w[55];
vector<NUM>wt[55];
bool vis[N];
int cnt[N];
vector<int>suc[N];

//多测清空
void pre() {
    tot = 0;
    fs(i, 1, len) {
        fs(j, i, len) {
            ++tot;dta[tot].clr();
            fs(k, i, j)dta[tot].a[k] = 1;
            ++tot;dta[tot].clr();
            fs(k, i, j)dta[tot].a[k] = 9;
        }
    }
    fs(num, 0, n - 1) {
        NUM tp = NUM(num);
        suc[num].clear();
        fs(stp, 1, tot) {
            suc[num].emplace_back((tp + dta[stp]).val());
        }
    }
    w[0].clear();
    w[0].emplace_back(0);
    fs(stp, 1, 50) {
        fs(i, 0, n - 1)vis[i] = false;
        w[stp].clear();
        for(int v : w[stp - 1]) {
            for(int u : suc[v])vis[u] = true;
        }
        // fs(i, 0, 100)cout << vis[i] << ' ';
        // cout << endl;
        fs(i, 0, n - 1)if(vis[i])w[stp].emplace_back(i);
    }
    // fs(stp, 1, 10) {
    //     for(int v : w[stp])cout << v << ' ';
    //     cout << endl;
    // }
    fs(stp, 0, 50) {
        wt[stp].clear();
        for(int v : w[stp])wt[stp].emplace_back(NUM(v));
    }
}

void solve() {
    scanf("%d%d", &len, &m);
    n = 1;
    fs(i, 1, len)n *= P;
    pre();
    fs(i, 0, n - 1)cnt[i] = 0;
    fs(abcde, 1, m) {
        scanf("%s", ss + 1);
        NUM number = NUM(ss);
        int y;scanf("%d", &y);
        // number.print();printf("\n");
        for(auto chg : wt[y]) {
            // cout << (number + chg).val() << ' ';
            cnt[(number + chg).val()]++;
        }
    }
    // cout << endl;
    int cntt = 0, ans = 0;
    fs(i, 0, n - 1)if(cnt[i] == m)++cntt, ans = i;
    // fs(i, 0, n - 1) {
    //     if(vis[i]) {
    //         cout << i << ' ';
    //     }
    // }
    // cout << endl;
    if(cntt == 1) {
        NUM(ans).print();printf("\n");
    }
    else if(cntt == 0) {
        printf("IMPOSSIBLE\n");
    }
    else {
        printf("MANY\n");
    }
}

signed main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}