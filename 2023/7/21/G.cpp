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
#define maxn 1000000
using namespace std;

int t, n, a[2 * maxn + 5], to[2 * maxn + 5];//bq dp nu o s x z
char s[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(int x, int y){
    if(x <= 5) return x == (y ^ 1);
    return x == y;
}

int main(){
	// freopen("in.txt", "r", stdin);
    to[0] = 1;
    read(t);
    while(t--){
        scanf("%s", s + 1); n = strlen(s + 1);
        int cnt = 0, fl = 1;
        For(i, 1, n){
            if(s[i] == 'b') a[++cnt] = 0;
            else if(s[i] == 'q') a[++cnt] = 1;
            else if(s[i] == 'd') a[++cnt] = 2;
            else if(s[i] == 'p') a[++cnt] = 3;
            else if(s[i] == 'n') a[++cnt] = 4;
            else if(s[i] == 'u') a[++cnt] = 5;
            else if(s[i] == 'o') a[++cnt] = 6;
            else if(s[i] == 's') a[++cnt] = 7;
            else if(s[i] == 'x') a[++cnt] = 8;
            else if(s[i] == 'z') a[++cnt] = 9;
            else{
                // cout << "asd" << endl;
                fl = 0;
            }
            a[++cnt] = 10; 
        }
        // cout << (s + 1) << endl;
        if(!fl){
            puts("No");
            continue;
        }
        int now = 0;
        For(i, 1, cnt){
            to[i] = max(0, min(now + to[now] - 1, i + to[2 * now - i] - 1) - i + 1);
            while(i - to[i] >= 1 && i + to[i] <= cnt && chk(a[i - to[i]], a[i + to[i]])){
                to[i]++;
                now = i;
            }
        }
        // For(i, 1, cnt) cout << to[i] << " "; cout << endl;
        now = 1;
        For(i, 1, cnt){
            if(i < now) continue;
            if(i - to[i] + 1 <= now) now = 2 * i - now + 1;
        }
        // cout << now << " " << cnt << endl;
        if(now != cnt && now != cnt + 1) puts("No");
        else puts("Yes");
        // For(i, 1, cnt) f[i] = -1;
    }
    return 0;
}
