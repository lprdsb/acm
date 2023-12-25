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

int t, n;
LL a[maxn + 1];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[maxn + 5], top = 0;
int main(){
	//freopen("in", "r", stdin);
    For(i, 1, maxn) a[i] = a[i - 1] + i - 1;
    read(t);
    while(t--){
        read(n);
        int now = 2;
        while(a[now + 1] <= n) now++;
        top = 0;
        while(n){
            while(a[now] > n) now--;
            n -= a[now];
            st[++top] = now;
            // cout << n << endl;
        }
        int now1 = 1;
        Rof(i, st[1], 1){
            while(now1 <= top && st[now1] == i) printf("1"), now1++;
            printf("3");
        }
        printf("7\n");
    }
}
