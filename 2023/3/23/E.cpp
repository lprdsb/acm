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

int t, n;
char s[maxn + 5];
struct Node{
    int a, b;
};
void chkmn(Node &x, Node y){
    if(x.a + x.b > y.a + y.b) x = y;
    else if(x.a + x.b == y.a + y.b && x.a < y.a) x = y;
}

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
        scanf("%s", s + 1); n = strlen(s + 1);
        int cnt = 0;
        For(i, 1, n) cnt += s[i] == '0';
        int now[2] = {0, 0};
        Node as = {0, cnt};
        For(i, 1, n){
            now[s[i] - '0']++;
            if(s[i] == '0'){
                chkmn(as, {0, now[1] + cnt - now[0]});
                if(i > 1 && s[i - 1] == '1'){
                    chkmn(as, {1, now[1] - 1 + cnt - now[0]});
                    // cout << now[1] - 1 + cnt - now[0] << endl;
                }
            }
        }
        printf("%lld\n", 1000000000000ll * (as.a + as.b) + as.b);
    }
    return 0;
}
