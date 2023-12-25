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

DD f, d, H = 1e-19, R = 2e-8, a_0 = 1.65e-10, E_t = 1e11, v_t = 0.3, v_s = 0.33;

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
    // printf("%f", E_t);
	while(666){
        cin >> d >> f;
        d *= 1e-9;
        f *= 1e-9;
        DD E_eff = 0.75 * (f + H * R / 6 / a_0 / a_0) / (sqrt(R) * pow(a_0 - d, 1.5));
        // cout << E_eff << endl;
        cout << (1 - v_s * v_s) * E_t * E_eff  / (E_t - E_eff * (1 - v_t * v_t))  << endl;
    }
    system("pause");
    return 0;
}
