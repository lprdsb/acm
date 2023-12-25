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

int n, q, a[maxn + 5], sum = 0;
set<int> se[2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n){
        char c; cin >> c;
        a[i] = c == ')';
        sum += a[i] ? 1 : -1;
    }
    For(i, 1, n - 1){
        if(!a[i] && !a[i + 1]) se[0].insert(i);
        if(a[i] && a[i + 1]) se[1].insert(i);
    }
    while(q--){
        int x; read(x);
        if(a[x]){
            if(x < n){
                if(a[x + 1]) se[1].erase(x);
                else se[0].insert(x); 
            }
            if(x > 1){
                if(a[x - 1]) se[1].erase(x - 1);
                else se[0].insert(x - 1);
            }
        }
        else{
            if(x < n){
                if(a[x + 1]) se[1].insert(x);
                else se[0].erase(x);
            }
            if(x > 1){
                if(a[x - 1]) se[1].insert(x - 1);
                else se[0].erase(x - 1);
            }
        }
        sum -= a[x] ? 1 : -1;
        a[x] ^= 1;
        sum += a[x] ? 1 : -1;
        // cout << *se[1].begin() << endl;
        if(!a[1] && a[n]){
            if(!se[0].size() && !se[1].size()) puts("Yes");
            else if(se[0].size() && se[1].size()){
                if(abs(sum) & 1) puts("No");
                else if(*se[0].begin() <= *se[1].begin() && *(--se[0].end()) <= *(--se[1].end())) puts("Yes");
                else puts("No");
            }
            else puts("No");
        }
        else puts("No");
    }
    return 0;
}
