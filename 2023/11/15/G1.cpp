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
#define maxn 100000
using namespace std;

int T, n, k, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

multiset<int> se;

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); read(k);
        int fl = 1;
        For(i, 1, n) read(a[i]), fl &= a[i] == 1;
        if(!fl){
            For(i, 1, n - 1){
                if(a[i] != 1 && a[i - 1] != 1 && a[i + 1] != 1 && gcd(a[i], a[i - 1]) == 1 && gcd(a[i], a[i + 1]) == 1){
                    k--;
                    a[i] = 0;
                    if(!k) break;
                }
            }
            int res = 0;
            For(i, 2, n) res += gcd(a[i], a[i - 1]) == 1;
            int pre = -1;
            For(i, 1, n + 1){
                if(a[i] == 1){
                    if(pre == -1) pre = i;
                }
                else{
                    if(pre != -1){
                        if(pre != 1 && i != n + 1) se.insert(i - pre); 
                    }
                    pre = -1;
                }
            }
            while(k && se.size()){
                auto it = se.begin();
                if(k >= *it){
                    res -= *it + 1;
                    k -= *it;
                }
                else{
                    res -= k;
                    k = 0;
                }
                se.erase(it);
            }
            if(k) res -= min(res, k);
            printf("%d\n", res);
            se.clear();
        }
        else{
            printf("%d\n", n - k);
        }
    }
    return 0;
}
