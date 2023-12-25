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
#define maxn 90000
using namespace std;

int n, a[305], f[maxn + 5], col[305];
set<int> se[2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void gout(int x){
    printf("%d\n", x);
    fflush(stdout);
}
int gin(){
    int tem; read(tem);
    return tem;
}
int s[2];
void sol(int x, int y){
    int tem = min(a[x], a[y]);
    s[col[x]] -= tem;
    a[x] -= tem;
    if(a[x] == 0) se[col[x]].erase(x);
    s[col[y]] -= tem;
    a[y] -= tem;
    if(a[y] == 0) se[col[y]].erase(y);
}

int main(){
	//freopen("in", "r", stdin);
    memset(f, -1, sizeof f);
    read(n);
    int sum = 0;
    f[0] = 0;
    For(i, 1, n){
        read(a[i]);
        Rof(j, sum, 0) if(f[j] != -1 && f[j + a[i]] == -1) f[j + a[i]] = i;
        sum += a[i];
    }
    // if(n == 99){
    //     cout << f[sum >> 1] << endl;
    //     return 0;
    // }
    if(sum & 1 || f[sum >> 1] == -1){
        puts("First");
        fflush(stdout);
        For(i, 1, n) se[0].insert(i);
        while(666){
            int tem = *se[0].begin();
            gout(tem);
            int tem1 = gin();
            if(!tem1 || tem1 == -1) break;
            sol(tem, tem1);
        }
    }
    else{
        puts("Second");
        fflush(stdout);
        int now = sum >> 1;
        s[0] = s[1] = sum >> 1;
        while(now){
            col[f[now]] = 1;
            now -= a[f[now]];
        }
        // if(n == 99){
        //     return 0;
        // }
        For(i, 1, n) se[col[i]].insert(i);
        while(666){
            int tem = gin();
            if(!tem || tem == -1) break;
            // if(se[!col[tem]].size() == 0){
            //     cout << (s[0] != 0 || s[1] != 0);
            //     return 0;
            // }
            int tem1 = *se[!col[tem]].begin();
            // if(!a[tem1]){
            //     cout << "asd" << endl;
            //     return 0;
            // }
            gout(tem1);
            sol(tem, tem1);
        }
    }
}
