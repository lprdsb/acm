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

#define maxn 100000
int num[3][maxn + 5], len[3], id[maxn + 5];
char s[maxn + 5];

vector<pair<int, int> > as;
vector<int> st[3][3], st1[3];

int main() {
    // freopen("in.txt", "r", stdin);
    int tot = 25;
    For(i, 1, tot) id[i] = i;
    For(o, 0, 2) {
        scanf("%s", s + 1); len[o] = strlen(s + 1);
        For(i, 1, len[o]) num[o][s[i] - 'A']++;
    }
    For(o, 0, 25) {
        while((num[0][o] != 0) + (num[1][o] != 0) + (num[2][o] != 0) >= 2 && num[0][o] + num[1][o] + num[2][o] >= 3) {
            int idx[3] = { 0, 1, 2 };
            sort(idx, idx + 3, [&](int x, int y) {return num[x][o] < num[y][o];});
            id[++tot] = o;
            num[idx[1]][o]--; num[idx[2]][o]--;
            if(idx[1] > idx[2]) swap(idx[1], idx[2]);
            st[idx[1]][idx[2]].pb(tot);
        }
        int idx[3] = { 0, 1, 2 };
        sort(idx, idx + 3, [&](int x, int y) {return num[x][o] < num[y][o];});
        if(num[idx[1]][o]) {
            if(idx[1] > idx[2]) swap(idx[1], idx[2]);
            // if(o == 0) cout << idx[1] << " " << idx[2] << endl;
            st[idx[1]][idx[2]].pb(o);
        }
        else if(num[idx[2]][o]) st1[idx[2]].pb(o);
    }
    // cout << st[1][2].size() << endl;
    // cout << st1[2].size() << endl;
    For(o, 0, 25) For(i, 0, 2) while(num[i][o] >= 2) {
        id[++tot] = o;
        num[i][o]--;
        st1[i].pb(tot);
    }
    // For(i, 0, 2) cout << st1[i].size() << " "; cout << endl;
    // cout << "asd" << endl;
    For(i1, 0, 2) For(i2, i1 + 1, 2) while(st[i1][i2].size() && st1[3 - i1 - i2].size()) {
        as.pb({ st[i1][i2].back(), st1[3 - i1 - i2].back() });
        st[i1][i2].pop_back(); st1[3 - i1 - i2].pop_back();
    }
    while((st[0][1].size() != 0) + (st[0][2].size() != 0) + (st[1][2].size() != 0) == 3) {
        as.pb({ st[0][1].back() , st[0][2].back() });
        as.pb({ st[0][2].back(), st[1][2].back() });
        st[0][1].pop_back(); st[0][2].pop_back(); st[1][2].pop_back();
    }

    For(i1, 0, 2) For(i2, i1 + 1, 2) while(st[i1][i2].size()) {
        as.pb({ st[i1][i2].back(), st[i1][i2].back() });
        st[i1][i2].pop_back();
    }

    while((st1[0].size() != 0) + (st1[1].size() != 0) + (st1[2].size() != 0) >= 2) {
        int idx[3] = { 0, 1, 2 };
        sort(idx, idx + 3, [&](int x, int y) {return st1[x].size() < st1[y].size();});
        as.pb({ st1[idx[1]].back(), st1[idx[2]].back() });
        st1[idx[1]].pop_back(); st1[idx[2]].pop_back();
    }

    int idx[3] = { 0, 1, 2 };
    sort(idx, idx + 3, [&](int x, int y) {return st1[x].size() < st1[y].size();});
    while(st1[idx[2]].size()) {
        as.pb({ st1[idx[2]].back(), st1[idx[2]].back() });
        st1[idx[2]].pop_back();
    }

    printf("%d\n", as.size());
    // for(auto [i, j] : as) printf("%d %d\n", i, j);
    for(auto [i, j] : as) printf("%c%c\n", 'A' + id[i], 'A' + id[j]);
    return 0;
}
