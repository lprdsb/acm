#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long

#define maxn 100
int T, n, m, a[maxn + 5][4], cnt[512], num[maxn + 5][4];
int mask[10] = { 0b1111011,0b0010010,0b0111101,0b0110111,0b1010110,0b1100111,0b1101111,0b0110010,0b1111111,0b1110111 };

vector<pair<int, int> > vec;
bitset<128> ok[15][15];

void mian() {
    scanf("%d%d", &n, &m);
    For(i, 1, n) {
        For(j, 1, m) {
            char c; cin >> c;
            a[i][j] = mask[num[i][j] = c - '0'];
        }
    }
    int res = 21;
    if(m == 1) {
        res = 7;
        For(sta, 0, 127) {
            int fl = 1;
            For(i, 1, n) For(j, i + 1, n) if(a[i][1] != a[j][1] && (a[i][1] & sta) == (a[j][1] & sta)) {
                fl = 0;
                break;
            }
            if(fl) res = min(res, cnt[sta]);
        }
    }
    else if(m == 2) {
        res = 14;
        For(sta, 0, 127) For(sta1, 0, 127) {
            int fl = 1;
            For(i, 1, n) For(j, i + 1, n) if(((a[i][1] & sta) == (a[j][1] & sta)) && ((a[i][2] & sta1) == (a[j][2] & sta1))) {
                fl = 0;
                break;
            }
            if(fl) res = min(res, cnt[sta] + cnt[sta1]);
        }
    }
    else {
        res = 21;
        For(sta, 0, 127) For(sta1, 0, 127) {
            bitset<128> tmp;
            For(i, 0, 127) tmp[i] = 1;
            For(i, 1, n) For(j, i + 1, n) if(((a[i][1] & sta) == (a[j][1] & sta)) && ((a[i][2] & sta1) == (a[j][2] & sta1))) tmp &= ok[num[i][3]][num[j][3]];
            For(i, 0, 127) if(tmp[i]) res = min(res, cnt[sta] + cnt[sta1] + cnt[i]);
        }
    }
    printf("%d\n", res);
    // For(i, 0,)
}


int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 0, 9) For(j, 0, 9) For(sta, 0, 127) if((mask[i] & sta) != (mask[j] & sta)) ok[i][j][sta] = 1;
    cnt[0] = 0;
    For(i, 1, 127) cnt[i] = cnt[i >> 1] + (i & 1);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}