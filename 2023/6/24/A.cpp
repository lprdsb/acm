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

int t, a, b, c, pw[10];
LL k;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int s1, s2, s3, s4;

LL get_val(int x, int y){
    if(x < y) return 0;
    if(y >= pw[a - 1]) return 1ll * (1 + x - y + 1) * (x - y + 1) / 2;
    return 1ll * (pw[a - 1] - y + 1 + x - y + 1) * (x - pw[a - 1] + 1) / 2;
}

LL get_s(int x){
    if(x < pw[a - 1]) return 0;
    return get_val(x, s1) - get_val(x, s2) - get_val(x, s3) + get_val(x, s4);
}

bool chk(int lim){
    return get_s(lim) >= k;
}

int main(){
	// freopen("in.txt", "r", stdin);
    pw[0] = 1;
    For(i, 1, 6) pw[i] = pw[i - 1] * 10;
    read(t);
    while(t--){
        read(a); read(b); read(c); read(k);
        s1 = pw[c - 1] - pw[b] + 1;//+1
        s2 = pw[c - 1] - pw[b - 1] + 1;//-1
        s3 = pw[c] - pw[b] + 1;//-1
        s4 = pw[c] - 1 - pw[b - 1] + 1 + 1; //+1
        int l = pw[a - 1], r = pw[a] - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(chk(mid)) r = mid;
            else l = mid + 1;
        }
        // cout << get_s(9) << endl;
        // cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
        if(chk(l)){
            int res = k - get_s(l - 1), tem = max(pw[c - 1] - l, pw[b - 1]) + res - 1;
            // cout << max(pw[c - 1] - a, pw[b - 1]) << endl;
            printf("%d + %d = %d\n", l, tem, l + tem);
        }
        else puts("-1");
    }
}
