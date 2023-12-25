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

int t, k, bas;
pair<int, int> pre[maxn + 5], seg[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int as[10], fl = 0;
void sol(){
    if(fl) return;
    if(as[1] > as[3]){
        swap(as[1], as[3]);
        swap(as[2], as[4]);
    }
    fl = 1;
    if(as[2] < as[3]) printf("%d %d %d %d\n", as[1], as[2], as[3], as[4]);
    else if(as[2] >= as[3] && as[2] <= as[4]) printf("%d %d %d %d\n", as[1], as[3] - 1, as[2] + 1, as[4]);
    else printf("%d %d %d %d\n", as[1], as[3] - 1, as[4] + 1, as[2]);
}

vector<int> vec;

int main(){
	// freopen("in.txt", "r", stdin);
    For(i, 0, maxn) pre[i] = seg[i] = {-1, 0};
    read(t);
    while(t--){
        fl = 0;
        read(k);
        bas = (1 << k) - 1;
        LL sum = 0;
        For(i, 0, 1 << (k + 1)){
            LL x = 0;
            if(i) read(x);
            sum ^= x;
            if(fl) continue;
            if(pre[sum & bas].fir != -1){
                int tem = (sum >> k) ^ pre[sum & bas].sec;
                // cout << tem << endl;
                if(seg[tem].fir != -1){
                    as[1] = seg[tem].fir + 1;
                    as[2] = seg[tem].sec;
                    as[3] = pre[sum & bas].fir + 1;
                    as[4] = i;
                    sol();
                }
                else{
                    seg[tem] = {pre[sum & bas].fir, i};
                    vec.pb(tem);
                }
                pre[sum & bas] = {i, sum >> k};
            }
            else{
                pre[sum & bas] = {i, sum >> k};
                vec.pb(sum & bas);
            }
        }
        for(auto i : vec) pre[i] = seg[i] = {-1, 0};
        vec.resize(0);
    }
    return 0;
}
