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

int t, n, k, a[55], b[55], as[55];

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
    read(t);
    while(t--){
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        read(n); read(k);
        For(i, 1, n + 1) b[i] = 1;
        For(i, 1, n){
            if(k >= i) a[i] = i, k -= i;
            else a[i] = k, k = 0;
        }
        Rof(i, n, 0){
            int sum = 0;
            For(j, 1, n + 1){
                sum += b[j];
                if(sum == a[i] + 1){
                    as[i] = j;
                    b[j] = 0;
                    break;
                }
            }
        }
        // For(i, 0, n) cout << as[i] << " "; cout << endl;
        For(i, 1, n) printf("%d ", as[i] - as[i - 1]);
        puts("");
    }
    return 0;
}
