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

int st[10005], top = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}
// the king, queen, two rooks, two bishops, and two knights
bool chk(int mask){
    int flk = 0, flq = 0, cr = 0, preb = -1, ck = 0;
    For(i, 0, 7){
        if(mask % 5 == 0){
            if(flk || cr != 1) return 0;
            flk = 1;
        }
        if(mask % 5 == 1){
            if(flq) return 0;
            flq = 1;
        }
        if(mask % 5 == 2){
            cr++;
            if(cr > 2) return 0;
        }
        if(mask % 5 == 3){
            if(preb == -1) preb = i;
            else if((i & 1) == (preb & 1)) return 0;
        }
        if(mask % 5 == 4){
            ck++;
            if(ck > 2) return 0;
        }
        mask /= 10;
    }
    // if(mask == 123  ) cout << flk
    return flk && flq && ck == 2 && cr == 2;
}

void dfs(int now, int mask){
    if(now > 8){
        if(chk(mask)) st[++top] = mask;
        return;
    }
    For(o, 0, 4) dfs(now + 1, mask * 10 + o);
}

int T;
char s[100];
vector<int> ch[1001][10];

int get_num(int mask1, int mask2){
    int res = 0;
    For(i, 0, 7){
        res += mask1 % 10 == mask2 % 10;
        mask1 /= 10;
        mask2 /= 10;
    }
    return res;
}

void print(int mask){
    For(i, 0, 7){
        if(mask % 10 == 0) printf("K");
        if(mask % 10 == 1) printf("Q");
        if(mask % 10 == 2) printf("R");
        if(mask % 10 == 3) printf("B");
        if(mask % 10 == 4) printf("N");
        mask /= 10;
    }
    puts("");
    fflush(stdout);
}

int mxc[1001], vis[1001];
vector<int> ok;

int main(){
	//freopen("in", "r", stdin);
    dfs(1, 0);
    // cout << top << endl;
    For(i, 1, top) For(j, 1, top) if(i != j) ch[i][get_num(st[i], st[j])].pb(j);
    int mx = -1, mmx = -1;
    // For(i, 1, top){
    //     mxc[i] = 0;
    //     For(j, 0, 8) mxc[i] = max(mxc[i], (int)ch[i][j].size());
    //     if(mx == -1 || mxc[i] <= mxc[mx]){
    //         mmx = mx;
    //         mx = i;
    //     }
    // }
    int tt = 0;
    mx = 16;
    while(666){
        scanf("%s", s + 1);
        if(s[1] == 'E') break;
        scanf("%d", &T);
    // For(t, 1, top){
        // cout << st[t] << endl;
        For(i, 1, top) vis[i] = 1;
        ok.pb(mx);
        For(_, 1, 100){
            int mx1 = -1, mx2 = -1;
            for(auto i : ok){
                int res = 0;
                For(j, 0, 8){
                    int cnt = 0;
                    for(auto p : ch[i][j]) cnt += vis[p];
                    res = max(res, cnt);
                }
                if(mx1 == -1 || res < mx1) mx1 = res, mx2 = i;
            }
            if(_ > 6){
                while(666);
            }
            print(st[mx2]);
            int x;
            scanf("%d", &x);
            // x = get_num(st[t], st[mx2]);
            if(x == 8){
                // cout << st[mx2] << endl;
                // assert(t == mx2);
                // tt = max(tt, _);
                break;
            }
            ok.resize(0);
            for(auto i : ch[mx2][x]) if(vis[i]) ok.pb(i);
            For(i, 1, top) vis[i] = 0;
            for(auto i : ok) vis[i] = 1;
        }
        ok.resize(0);
    }
    // scanf("%s", s + 1);
}
