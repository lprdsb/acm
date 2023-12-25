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

int n, cnt = 0, fa[2 * maxn + 5];
vector<pair<int, int> > vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) fa[i] = i, fa[n + i] = n + i;
    For(i, 1, n){
        int x; read(x);
        int tem = 0;
        For(o, 0, 30) tem |= (((x >> o) & 1) << (29 - o));
        vec[cnt].pb({i, tem});
    }
    LL res = 0;
    Rof(o, 30, 0){
        int fl = 1;
        For(i, 0, cnt){
            int tem = 0;
            for(auto [j, p] : vec[i]) if(p & 1) tem++;
            if(tem >= 3 || vec[i].size() - tem >= 3){
                fl = 0;
                break;
            }
            int pre[2] = {0, 0};
            for(auto [j, p] : vec[i]){
                tem = p & 1;
                if(pre[tem]){
                    if(find(pre[tem]) == find(j)){
                        fl = 0;
                        break;
                    }
                }
                pre[tem] = j;
                if(!fl) break;
            }
        }
        res |= fl << o;
        if(!fl){
            For(i, 0, cnt){
                vector<pair<int, int> > tem[2];
                For(j, 0, vec[i].size() - 1){
                    tem[(vec[i][j].sec & 1) != (vec[i][0].sec & 1)].pb({vec[i][j].fir, vec[i][j].sec >> 1});
                }
                // if(o == 6) cout << tem[1].size() << endl;
                vec[i] = tem[0];
                if(tem[1].size()) vec[++cnt] = tem[1];
            }
        }
        else{
            For(i, 0, cnt){
                int pre[2] = {0, 0};
                for(auto &[j, p] : vec[i]){
                    int tem = p & 1;
                    if(pre[tem]){
                        fa[find(pre[tem])] = find(n + j);
                        fa[find(j)] = find(n + pre[tem]);
                    }
                    pre[tem] = j;
                    p >>= 1;
                }
            }
        }
    }

    // printf("%d\n", res);
    For(i, 1, n){
        if(find(i) == find(1)) printf("0");
        else if(find(i) == find(n + 1)) printf("1");
        else{
            fa[find(i)] = find(1);
            fa[find(n + i)] = find(n + 1);
            printf("0");
        }
    }
    puts("");
    return 0;
}
