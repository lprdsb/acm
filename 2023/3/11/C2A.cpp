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

int n, m, p, a[maxn + 5][105], lim, sum[maxn + 5], popcount[maxn + 5], as[105];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[105], top = -1, b[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    srand(time(0));
    read(n); read(m); read(p); lim = (n + 1) / 2;
    For(i, 1, n){
        For(j, 0, m - 1){
            char c; cin >> c;
            a[i][j] = c - '0';
        }
        b[i] = i;
    }
    random_shuffle(b + 1, b + n + 1);
    For(i, 0, (1 << 15) - 1) popcount[i] = popcount[i >> 1] + (i & 1);
    For(oo, 1, 60){
        int tem = b[oo];
        top = -1;
        For(i, 0, m - 1) if(a[tem][i]) st[++top] = i;
        For(i, 1, n){
            int tem = 0;
            For(j, 0, top) tem |= a[i][st[j]] << j;
            sum[tem]++;
        }
        For(o, 0, top) For(i, 0, (1 << (top + 1)) - 1) if(!((i >> o) & 1)) sum[i] += sum[i | (1 << o)];
        int asi = 0;
        For(i, 0, (1 << (top + 1)) - 1) if(sum[i] >= lim && popcount[i] > popcount[asi]) asi = i;
        For(i, 0, (1 << (top + 1)) - 1) sum[i] = 0;
        if(popcount[asi] > as[0]){
            as[0] = popcount[asi];
            top = 0;
            For(i, 0, m - 1){
                if(i == st[top]) as[i + 1] = (asi >> top++) & 1;
                else as[i + 1] = 0;
            }
        }
    }
    For(i, 1, m) printf("%d", as[i]);
    return 0;
}
