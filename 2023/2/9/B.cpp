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
    #define maxn 10000
    using namespace std;

    int n, m, vis[2][maxn + 5], a[maxn + 5];

    template <class T>
    void read(T &x){
        char ch;
        bool ok;
        for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
        for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        if(ok) x = -x;
    }

    int main(){
        //freopen("in", "r", stdin);
        read(n); read(m);
        For(i, 1, m){
            int k, fl = 0; read(k);        
            For(j, 1, k){
                int x; read(x);
                a[j] = x;
                if(a[j] < 0) a[j] *= -1;
                if(x < 0){
                    vis[0][-x] = 1;
                    if(vis[1][-x]){
                        fl = 1;
                    }
                }
                else{
                    vis[1][x] = 1;
                    if(vis[0][x]){
                        fl = 1;
                    }
                }
            }
            For(j, 1, k) For(o, 0, 1) vis[o][a[j]] = 0;
            if(!fl){
                puts("YES");
                return 0;
            }
        }
        puts("NO");
        return 0;   
    }
