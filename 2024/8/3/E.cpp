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

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 100
int T, n, a[maxn + 5][maxn + 5];

int num[maxn + 5];
vector<int> vec[2];
void mian() {
    read(n);
    For(i, 1, n) For(j, 1, n) read(a[i][j]);
    vec[0].resize(0); vec[1].resize(0);
    For(i, 1, n) {
        int fl = 0;
        For(j, 1, n) {
            num[a[i][j]]++;
            if(num[a[i][j]] == 2) {
                fl = 1;
                break;
            }
        }
        if(!fl) vec[0].pb(i);
        For(j, 1, n) num[j] = 0;
    }


    For(j, 1, n) {
        int fl = 0;
        For(i, 1, n) {
            num[a[i][j]]++;
            if(num[a[i][j]] == 2) {
                fl = 1;
                break;
            }
        }
        if(!fl) vec[1].pb(j);
        For(i, 1, n) num[i] = 0;
    }

    printf("%d\n", max(vec[0].size(), vec[1].size()));
    For(i, 0, (int)min(vec[0].size(), vec[1].size()) - 1) {
        int x = vec[0][i], y = vec[1][i];
        printf("%d %d %d\n", vec[0][i], vec[1][i], a[x][y] % n + 1);
        a[x][y] = a[x][y] % n + 1;
    }
    if(vec[0].size() > vec[1].size()) {
        if(vec[0].size() - vec[1].size() >= 2) {
            int t1 = vec[0][vec[1].size()], t2 = vec[0][vec[1].size() + 1];
            For(i, 1, 3) if(a[t1][1] != i && a[t2][1] != i) {
                printf("%d 1 %d\n%d 1 %d\n", t1, i, t2, i);
                break;
            }
            // cout << "asd" << endl;
            For(i, vec[1].size() + 2, vec[0].size() - 1) printf("%d 1 %d\n", vec[0][i], a[vec[0][i]][1] % n + 1);
        }
        else {
            int t0 = vec[0][vec[1].size()], t1 = t0 % n + 1, t2 = (t0 - 2 + n) % n + 1;
            if(a[t1][1] == a[t2][1]) printf("%d 1 %d\n", t0, a[t0][1] % n + 1);
            else {
                if(a[t1][1] == a[t0][1]) swap(t1, t2);
                printf("%d 1 %d\n", t0, a[t1][1]);
            }
        }
    }
    else if(vec[0].size() < vec[1].size()) {
        if(vec[1].size() - vec[0].size() >= 2) {
            int t1 = vec[1][vec[0].size()], t2 = vec[1][vec[0].size() + 1];
            For(i, 1, 3) if(a[1][t1] != i && a[1][t2] != i) {
                printf("1 %d %d\n1 %d %d\n", t1, i, t2, i);
                break;
            }
            // cout << "asd" << endl;
            For(i, vec[0].size() + 2, vec[1].size() - 1) printf("1 %d %d\n", vec[1][i], a[1][vec[1][i]] % n + 1);
        }
        else {
            int t0 = vec[1][vec[0].size()], t1 = t0 % n + 1, t2 = (t0 - 2 + n) % n + 1;
            if(a[1][t1] == a[1][t2]) printf("1 %d %d\n", t0, a[1][t0] % n + 1);
            else {
                if(a[1][t1] == a[1][t0]) swap(t1, t2);
                printf("1 %d %d\n", t0, a[1][t1]);
            }
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
