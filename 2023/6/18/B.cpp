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

int t, n, m, a[105], b[105];
char s1[105], s2[105];

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
    read(t);
    while(t--){
        scanf("%s", s2 + 1); m = strlen(s2 + 1);
        scanf("%s", s1 + 1); n = strlen(s1 + 1);
        if(n > m){
            For(i, 1, m) s2[n - i + 1] = s2[m - i + 1];
            For(i, 1, n - m) s2[i] = '0';
        }
        int as = 0, now = 1;
        while(now <= n && s1[now] == s2[now]) now++;
        // cout << now << endl;
        if(now <= n){
            // int fl = 0;
            // For(i, now + 1, n) if(s1[i] != '9') fl = 1;
            // if(fl){
            //     s1[now]--;
            //     For(i, now + 1, n) s1[i] = '9';
            // }
            // fl = 0;
            // For(i, now + 1, n) if(s2[i] != '0') fl = 1;
            // if(fl){
            //     s2[now]++;
            //     For(i, now + 1, n) s2[i] = '0';
            // }
            For(i, now + 1, n) s1[i] = '0', s2[i] = '9';
        }
        // For(i, 1, n) cout << s1[i]; cout << endl;
        For(i, 1, n) as += abs(s1[i] - s2[i]);
        printf("%d\n", as);
    }
    return 0;
}
