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

int sta[10] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};
int mn[200], mx[2][200];

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int mask = 0;
void dfs(vector<pair<int, int> > &vec){
    if(vec.size() == 1){
        int tem = sta[vec[0].fir] & mask;
        if(vec[0].sec < vec[0].fir) mx[0][tem] = max(mx[0][tem], 10 - vec[0].fir);
        else mx[0][tem] = max(mx[0][tem], vec[0].sec - vec[0].fir);
        mx[1][tem] = max(mx[1][tem], (10 + vec[0].sec - vec[0].fir) % 10);
        // if(tem == 107) cout << 10 + vec[0].fir - vec[0].sec << endl;
        return;
    }
    vector<pair<int, int> > vv[200];
    for(auto [i, j] : vec) vv[sta[(j + 1) % 10] & mask].pb({i, (j + 1) % 10});
    For(i, 0, 127) if(vv[i].size()) dfs(vv[i]);
    return;
}
int T, pw[15];

int main(){
    // freopen("in.txt", "r", stdin);
    For(i, 0, 127) mn[i] = mx[0][i] = mx[1][i] = -1;
    For(i, 0, 9) For(j, 0, 127){
        int to = sta[i] & j;
        if(mn[to] == -1 || mn[to] > i) mn[to] = i;
    }
    For(i, 1, 127){
        mask = i;
        vector<pair<int, int> > vec[200];
        For(j, 0, 9) vec[sta[j] & i].pb({j, j});
        For(j, 1, 127) if(vec[j].size()) dfs(vec[j]);
    }
    // int tem = 0;
    // For(i, 1, 127) tem = max(tem, mx[i]);
    // cout << mx[2][127] << endl;
    // For(i, 1, 127) if(mmx[i] != -1 && mn[i] != -1 && mmx[i] > 10 - mn[i]) cout << i << " " << mmx[i] << " " << mn[i] << endl;
    pw[0] = 1;
    For(i, 1, 8) pw[i] = 10 * pw[i - 1];
    read(T);
    while(T--){
        int n; read(n);
        int fl = 0, res = 0, fl1 = 0, fl2 = 0;
        Rof(i, n - 1, 0){
            int now = 0;
            For(j, 0, 6){
                char c; cin >> c;
                now |= (c - '0') << j;
            }
            if(!now && i == n - 1) fl = -1;
            if(fl == -1) continue;
            // cout << mx[1][now] << endl;
            if(i == n - 1){
                if(mx[1][now]){
                    res += mx[1][now] * pw[i];
                    fl1 = 1;
                }
            }
            else{
                if(fl1) res -= mn[now] * pw[i];
                else{
                    if(!now){
                        res += 9 * pw[i];
                        fl2 = 1;
                    }
                    else{
                        if(fl2){
                            res -= mn[now] * pw[i];
                            fl1 = 1;
                        }
                        else if(mx[0][now]){
                            res += mx[0][now] * pw[i];
                            fl1 = 1;
                        }
                    }
                }
            }
        }
        if(fl == -1) puts("-1");
        else printf("%d\n", res);
    }
    return 0;
}
