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
#define maxn 4000
using namespace std;

int t, n, m, k, fa[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<pair<int, int> > vec[maxn + 5];

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main(){
	// freopen("in.txt", "r", stdin);
    For(i, 1, maxn) fa[i] = i;
    read(t);
    while(t--){
        read(n); read(m); read(k);
        For(i, 1, k){
            int x1, y1, x2, y2; read(x1); read(y1); read(x2); read(y2);
            if(y1 > y2) vec[x1].pb({y2, 0});
            else vec[x1].pb({y1, 1});
        }
        int fl = 1;
        For(i, 1, n){
            For(j, 1, vec[i].size() - 1){
                if(vec[i][j].sec == vec[i][0].sec){
                    if(find(vec[i][j].fir) == find(m + vec[i][0].fir)){
                        fl = 0;
                        break;
                    }
                    else{
                        fa[find(vec[i][j].fir)] = find(vec[i][0].fir);
                        fa[find(m + vec[i][j].fir)] = find(m + vec[i][0].fir);
                    }
                }
                else{
                    if(find(vec[i][j].fir) == find(vec[i][0].fir)){
                        fl = 0;
                        break;
                    }
                    else{
                        fa[find(vec[i][j].fir)] = find(m + vec[i][0].fir);
                        fa[find(m + vec[i][j].fir)] = find(vec[i][0].fir);
                    }
                }
            }
            if(!fl) break;
        }
        puts(fl ? "Yes" : "No");
        For(i, 1, 2 * m) fa[i] = i;
        For(i, 1, n) vec[i].resize(0);
    }
}
