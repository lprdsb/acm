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
#define eps 1e-15
#define eeps 1e-9
using namespace std;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

DD get_val(DD x){
    
}

DD get_simp1(DD l, DD r){
    // return (get_val(l) * 989 + get_val((l * 7 + r) / 8.0) * 5888 -
    //         get_val((l * 3 + r) / 4.0) * 928 + get_val((l * 5 + r * 3) / 8.0) * 10496 -
    //         get_val((l + r) / 2.0) * 45440 + get_val(r) * 989 +
    //         get_val((r * 7 + l) / 8.0) * 5888 - get_val((r * 3 + l) / 4.0) * 928 +
    //         get_val((r * 5 + l * 3) / 8.0) * 10496) /
    //        28350.0;
    // return (get_val(l) * 751 + get_val((l * 6 + r) / 7.0) * 3577 +
    //         get_val((l * 5 + r * 2) / 7.0) * 1323 + get_val((l + 4 + r * 3) / 7.0) * 2989
    //         + get_val(r) * 751 + get_val((r * 6 + l) / 7.0) * 3577 + get_val((r * 5 + l * 2)
    //         / 7.0) * 1323 + get_val((r + 4 + l * 3) / 7.0) * 2989) /
    //        17280.0;
    // return (get_val(l) * 41 + get_val((5 * l + r) / 6.0) * 216 + get_val((2 * l + r) / 3.0) * 27 +
    //         get_val((l + r) / 2.0) * 272 + get_val((l + 2 * r) / 3.0) * 27 +
    //         get_val((l + r * 5) / 6.0) * 216 + get_val(r) * 41) *
    //        (r - l) / 840.0;
    // return (get_val(l) + get_val(r) + get_val((l*2 + r) / 3.0)*3.0+get_val((l+r*2)/3.0)*3.0) * (r -
    // l) / 8.0;
    // return (get_val(l) + get_val(r) + 4 * get_val((l + r) / 2.0)) * (r - l) / 6.0;
}

DD simp1(DD l, DD r, DD now){
    DD mid = (l + r) / 2, teml = get_simp1(l, mid), temr = get_simp1(mid, r);
    if(fabs(now - teml - temr) <= eeps) return teml + temr;
    return simp1(l, mid, teml) + simp1(mid, r, temr);
}

int main(){
	// freopen("in.txt", "r", stdin);
    // cout << (DD)clock() / 1000 << "s" << endl;
    return 0;
}
