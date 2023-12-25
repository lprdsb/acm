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

int n, cnt = 0;
LD pi = acos(-1.0), b[2 * maxn + 5], as = inf;
struct Opt{
    LD the, d, l, r, ty;
} opt[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(LD x, LD y){return x > y || fabs(x - y) <= eps;}

int find(LD x){
    int l = 1, r = cnt;
    while(l < r){
        int mid = l + r >> 1;
        if(chk(b[mid], x)) r = mid;
        else l = mid + 1;
    }
    return l;
}

LD sum[2 * maxn + 5][2];
void add(int l, int r, LD the, LD d){
    // cout << l << " " << r << " " << the / pi << " " << d << endl;
    LD c = d * cos(the), s = d * sin(the);
    sum[l][0] += c; sum[r][0] -= c;
    sum[l][1] += s; sum[r][1] -= s;
}

LD sol(LD l, LD r, LD c, LD s){
    LD asi = min(c * cos(l) + s * sin(l), c * cos(r) + s * sin(r)), tem;
    // cout << l / pi << "  " << r / pi << " " << c << " " << s << endl;
    if(fabs(c) <= eps) tem = 0.5 * pi;
    else tem = atan(s / c);
    if(tem < 0) tem += pi;
    if(chk(tem, l) && chk(r, tem)) asi = min(asi, c * cos(tem) + s * sin(tem));
    tem += pi;
    if(chk(tem, l) && chk(r, tem)) asi = min(asi, c * cos(tem) + s * sin(tem));
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
	read(n);
    b[++cnt] = 0;
    b[++cnt] = 2 * pi;
    int pre_x, pre_y, s_x, s_y;
    For(i, 0, n){
        int x, y;
        if(i < n) read(x), read(y);
        else x = s_x, y = s_y;
        if(!i) s_x = x, s_y = y;
        if(i >= 1){
            opt[i].the = atan2(y - pre_y, x - pre_x);
            if(opt[i].the < 0) opt[i].the += 2 * pi;
            opt[i].d = sqrt((x - pre_x) * (x - pre_x) + (y - pre_y) * (y - pre_y));
            if(0.5 * pi - opt[i].the >= eps){
                opt[i].l = b[++cnt] = 1.5 * pi - opt[i].the;
                opt[i].r = b[++cnt] = 0.5 * pi - opt[i].the;
                opt[i].ty = 0;
            }
            else if(pi - opt[i].the >= eps){
                opt[i].l = b[++cnt] = 1.5 * pi - opt[i].the;
                opt[i].r = b[++cnt] = 2.5 * pi - opt[i].the;
                opt[i].ty = 1;
            }
            else if(1.5 * pi - opt[i].the >= eps){
                opt[i].l = b[++cnt] = 1.5 * pi - opt[i].the;
                opt[i].r = b[++cnt] = 2.5 * pi - opt[i].the;
                opt[i].ty = 2;
            }
            else{
                opt[i].l = b[++cnt] = 3.5 * pi - opt[i].the;
                opt[i].r = b[++cnt] = 2.5 * pi - opt[i].the;
                opt[i].ty = 3;
            }
        }
        pre_x = x;
        pre_y = y;
    }
    sort(b + 1, b + cnt + 1);
    int tem = 1;
    For(i, 2, cnt) if(fabs(b[i] - b[tem]) >= eps) swap(b[++tem], b[i]);
    cnt = tem;
    For(i, 1, n){
        int l = find(opt[i].l), r = find(opt[i].r);
        if(opt[i].ty == 0){
            add(l, cnt, -opt[i].the, opt[i].d);
            add(1, r, -opt[i].the, opt[i].d);
        }
        else if(opt[i].ty == 1) add(l, r, -opt[i].the, opt[i].d);
        else if(opt[i].ty == 2) add(l, r, -opt[i].the, opt[i].d);
        else{
            add(l, cnt, -opt[i].the, opt[i].d);
            add(1, r, -opt[i].the, opt[i].d);
        }
    }
    For(i, 2, cnt){
        sum[i][0] += sum[i - 1][0];
        sum[i][1] += sum[i - 1][1];
    }
    For(i, 1, cnt - 1) as = min(as, sol(b[i], b[i + 1], sum[i][0], sum[i][1]));
    if(fabs(as) <= 0.0001) puts("0.00");
    else printf("%.2Lf\n", as);
    return 0;
}
