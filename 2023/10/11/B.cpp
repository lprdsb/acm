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

int dir[4][8] ={{0, 1, 2, 3, 0, 1, 6, 7}, {0, 1, 6, 7, 4, 5, 6, 7}, {0, 1, 2, 3, 6, 7, 4, 5}, {0, 3, 2, 1, 4, 7, 6, 5}};

struct Data : array<int, 8>{
    Data(){fill(-1);}
    void init(){fill(-1);}
};

struct Hash{
    size_t operator ()(cst Data &_x) cst{
        size_t res = 0;
        For(i, 0, 7) res = res * 5 + _x[i] + 1;
        return res;
    } 
};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int T, a, b, c, d, m;
Data s;
unordered_map<Data, int, Hash> f;
bool chk(Data now){
    For(o, 0, 7) if(now[o] != -1 && (o >> 1) != now[o]) return 0;
    return 1; 
}
int bfs(){
    queue<Data> q;
    q.push(s); f[s] = 0;
    // cout << (s == t) << endl;
    if(chk(s)) return 0;
    while(q.size()){
        Data now = q.front(); q.pop();
        For(o1, 0, 3){
            Data to;
            int fl = 0;
            For(o2, 0, 7) if(now[o2] != -1){
                int u = dir[o1][o2];
                if(to[u] == -1) to[u] = now[o2];
                else if(to[u] != now[o2]){
                    fl = 1;
                    break;
                }
            }
            if(fl) continue;
            if(!f.count(to)){
                f[to] = f[now] + 1;
                q.push(to);
                if(chk(to)) return f[to];
            }
        }
    }
    return -1;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        s.init();
        read(a); read(b); read(c); read(d); read(m);
        int fl = 0;
        For(o, 0, 29){
            int u = (((a >> o) & 1) << 2) | (((b >> o) & 1) << 1) | ((m >> o) & 1);
            int v = (((c >> o) & 1) << 1) | ((d >> o) & 1);
            if(s[u] == -1) s[u] = v;
            else if(s[u] != v){
                puts("-1");
                fl = 1;
                break;
            }
        }
        if(fl) continue;
        f.clear();
        printf("%d\n", bfs());
    }
    return 0;
}
