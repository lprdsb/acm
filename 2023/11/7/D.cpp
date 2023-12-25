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
#define maxn 200000
using namespace std;

int T, n, m, cnt[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int vis[maxn + 5], st[maxn + 5];
struct Data{
    int d;
    vector<vector<int> > vec;
    void out(){
        For(o, 0, vec.size() - 1){
            // for(auto i : vec[o]) cout << i << " "; cout << endl;
            // if(o == 1) cout << vis[2] << endl;
            for(auto i : vec[o]) if(vis[i]) st[vis[i]] = i;

            int now = 0;
            For(i, 1, vec[o].size()) if(!st[i]){
                while(vis[vec[o][now]]) now++;
                st[i] = vec[o][now++];
            } 
            if(o){
                for(auto i : vec[o - 1]) vis[i] = 0;
            }
            For(i, 1, vec[o].size()){
                printf("%d ", st[i]);
                vis[st[i]] = d - (vec[o].size() - i + 1) + 1;
                st[i] = 0;
            }
        }
        for(auto i : vec[vec.size() - 1]) vis[i] = 0;
        puts("");
    }
} dat[maxn + 5];

struct Opt{
    int len, id;
};
vector<Opt> opt;

int s[maxn + 5], d[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, n){
            int x; read(x);
            cnt[x]++;
        }
        set<pair<int, int> > se;
        For(i, 1, n) if(cnt[i]) se.insert({-cnt[i], i});
        For(i, 1, m) read(s[i]);
        For(i, 1, m) read(d[i]), dat[i].d = d[i];

        For(i, 1, m){
            For(j, 1, s[i] / d[i]) opt.pb({d[i], i});
            if(s[i] % d[i]) opt.pb({s[i] % d[i], i});
        }
        sort(opt.begin(), opt.end(), [](cst Opt &_x, cst Opt &_y){return _x.len < _y.len;});

        int fl = 0;
        for(auto [len, id] : opt){
            if(se.size() < len){
                fl = 1;
                break;
            }
            auto it = se.begin();
            vector<int> sel;
            For(i, 1, len) sel.pb(it->sec), it++;
            // cout << len << endl;
            // for(auto i : sel) cout << i << " "; cout << endl;

            dat[id].vec.pb(sel);
            for(auto i : sel){
                se.erase({-cnt[i], i});
                cnt[i]--;
                if(cnt[i]) se.insert({-cnt[i], i});
            }

        }

        if(fl) puts("-1");
        else{
            For(i, 1, m) dat[i].out();
            // dat[2].out();
        }
        opt.resize(0);
        For(i, 1, n){
            cnt[i] = 0;
        }
        For(i, 1, m){
            dat[i].vec.resize(0);
        }
    }
}
