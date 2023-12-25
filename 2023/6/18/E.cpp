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
#define maxn 300000
using namespace std;

int t, n, a[maxn + 5];
set<int> se, se1;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL gcd(LL x, LL y){return y ? gcd(y, x % y) : x;}
LL lcm(LL x, LL y){
    return x * y / gcd(x, y);
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n){
            LL x; read(x);
            set<int> sei;
            sei.insert(x);
            se.insert(x);
            for(auto j : se1){
                LL tem = lcm(x, j);
                if(tem <= inf){
                    sei.insert(tem);
                    se.insert(tem);
                }
            }
            se1 = sei;
        }
        // cout << se.size() << endl;
        se.insert(inf);
        int now = 0;
        for(auto i : se){
            // cout << i << endl;
            if(i != now + 1){
                printf("%lld\n", now + 1);
                break;
            }
            now++;
        }
        se.clear();
        se1.clear();
    }
}
