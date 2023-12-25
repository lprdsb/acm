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
pair<int, int> mx[2][200];
int mn[200];

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int mask = 0;
void dfs(vector<pair<int, int> > &vec, int o){
    if(vec.size() == 1){
        int tem = sta[vec[0].fir] & mask, fl = 1;
        if(!o){
            For(j, vec[0].fir + 1, vec[0].sec) fl &= (sta[j % 10] & mask) == tem;
            pair<int, int> tt = {vec[0].sec - vec[0].fir, fl};
            if(tt > mx[0][tem]){
                mx[0][tem] = tt;
            }
        }
        else{
            if(vec[0].fir < vec[0].sec){
                For(j, vec[0].fir + 1, vec[0].sec) fl &= (sta[j] & mask) == tem;
            }
            else{
                For(j, vec[0].fir + 1, 9) fl &= (sta[j] & mask) == tem;
                For(j, 0, vec[0].sec) fl &= (sta[j] & mask) == tem;
            }
            mx[1][tem] = max(mx[1][tem], {(10 + vec[0].sec - vec[0].fir) % 10, fl});
        }
        return;
    }
    vector<pair<int, int> > vv[200];
    for(auto [i, j] : vec){
        if(o) vv[sta[(j + 1) % 10] & mask].pb({i, (j + 1) % 10});
        else{
            if(j == 9){
                int tem = sta[i] & mask, fl = 1;
                For(p, i + 1, 10) fl &= (sta[p % 10] & mask) == tem;
                // if(tem == 3 && i == 8 && fl) cout << mask << endl;
                mx[0][tem] = max(mx[0][tem], {9 - i, fl});
            }
            else{
                vv[sta[(j + 1) % 10] & mask].pb({i, (j + 1) % 10});
            }
        }
    }
    For(i, 0, 127) if(vv[i].size()) dfs(vv[i], o);
    return;
}
int T, pw[15], val[15];

int main(){
    freopen("in.txt", "r", stdin);
    For(i, 0, 127) mn[i] = mx[0][i].fir = mx[1][i].fir = -1;
    For(i, 0, 9) For(j, 0, 127){
        int to = sta[i] & j;
        if(mn[to] == -1 || mn[to] > i) mn[to] = i;
    }
    For(i, 1, 127){
        mask = i;
        vector<pair<int, int> > vec[200];
        For(j, 0, 9) vec[sta[j] & i].pb({j, j});
        For(j, 0, 127) if(vec[j].size()){
            dfs(vec[j], 0);
            dfs(vec[j], 1);
        }
    }
    pw[0] = 1;
    For(i, 1, 8) pw[i] = 10 * pw[i - 1];
    read(T);
    while(T--){
        int n; read(n);
        Rof(i, n - 1, 0){
            int now = 0;
            For(j, 0, 6){
                char c; cin >> c;
                now |= (c - '0') << j;
            }
            val[i] = now;
        }
        int res = 0;
        if(!val[n - 1]) res = -1;
        else if(n == 1) res = mx[1][val[0]].fir;
        else if(mx[1][val[n - 1]].fir){
            res = pw[n - 1] * mx[1][val[n - 1]].fir;
            For(i, 0, n - 2) res -= pw[i] * mn[val[i]];
            if(!val[n - 2] && mx[1][val[n - 1]].sec){
                Rof(i, n - 2, 0){
                    if(!val[i]) res += 9 * pw[i];
                    else break;
                }
            }
        }
        else{
            while(!mx[0][val[n - 1]].fir) n--;
            if(!n);
            else if(n == 1){
                if(val[n - 1]) res = mx[0][val[n - 1]].fir;
                else res = 9;
            }
            else if(val[n - 1]){
                res += mx[0][val[n - 1]].fir * pw[n - 1];
                Rof(i, n - 2, 0) res -= mn[val[i]] * pw[i];
                if(!val[n - 2] && mx[0][val[n - 1]].sec){
                    Rof(i, n - 2, 0){
                        if(!val[i]) res += 9 * pw[i];
                        else break;
                    }
                }
            }
            else{
                Rof(i, n - 1, 0){
                    if(!val[i]) res += 9 * pw[i];
                    else{
                        Rof(j, i, 0) res -= mn[val[j]] * pw[j];
                        break;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
