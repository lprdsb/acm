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

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 1000
int n, k, a[maxn + 5], num[maxn + 5];
set<int> se;

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    if(k == 2) {
        int res = 0;
        For(i, 1, n) {
            res += a[i] == a[i + 1];
            i++;
        }
        printf("%d\n", res);
    }
    else {
        int res = 0;
        For(i, 1, k) num[a[i]]++;
        For(i, 1, k) if(num[i] >= 2) se.insert(i);
        For(i, k + 1, n) {
            if(se.size()) {
                // cout << "asd" << endl;
                int tem = *se.begin();
                res++;
                num[tem] -= 2;
                if(num[tem] <= 1) se.erase(tem);
                if(a[i] != a[i + 1]) {
                    if(num[a[i]] == 1) se.insert(a[i]); num[a[i]]++;
                    if(num[a[i + 1]] == 1) se.insert(a[i + 1]); num[a[i + 1]]++;
                }
                else {
                    num[a[i]] += 2;
                    se.insert(a[i]);
                }
            }
            else {
                For(j, i, n) num[a[j]]++;
                int fl = 0;
                For(j, 1, k) fl |= num[j];
                if(!(fl & 1)) res -= 2;
                break;
            }
            i++;
        }
        For(i, 1, k) res += num[i] / 2;
        printf("%d\n", res);
    }
}
