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

int t, n, cnt[27], ok[27];
char s[maxn + 5];
struct Node{
    int pos, num;
} a[30];
bool operator < (Node &x, Node &y){
    return x.num > y.num;
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
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        memset(ok, 0, sizeof ok);
        memset(cnt, 0, sizeof cnt);
        read(n);
        For(i, 0, 25) a[i] = (Node){i, 0};
        scanf("%s", s + 1);
        For(i, 1, n) a[s[i] - 'a'].num++, cnt[s[i] - 'a']++;
        sort(a, a + 26);
        int mn = inf, mn_i;
        For(i, 1, 26){
            if(n % i != 0) continue;
            int sum = 0;
            For(j, 0, i - 1) sum += max(n / i - a[j].num, 0);
            if(sum < mn) mn = sum, mn_i = i;
        }
        printf("%d\n", mn);
        For(i, 0, mn_i - 1) ok[a[i].pos] = 1;
        int now = mn_i - 1;
        // cout << mn_i << endl;
        For(i, 1, n){
            int tem = s[i] - 'a';
            if(ok[tem] && cnt[tem] <= n / mn_i) printf("%c", s[i]);
            else{
                cnt[tem]--;
                printf("%c", 'a' + a[now].pos);
                cnt[a[now].pos]++;
                if(cnt[a[now].pos] == n / mn_i) now--;
            }
        }
        puts("");
    }
    return 0;
}
