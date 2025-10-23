#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long

int T;

LL sx[2], sy[2], tx[2], ty[2];
void mian() {
    // cout << "asd" << endl;
    For(o, 0, 1) scanf("%lld%lld", &sx[o], &sy[o]);
    For(o, 0, 1) scanf("%lld%lld", &tx[o], &ty[o]);
    // if(sx[0] > sx[1]) {
    //     swap(sx[0], sx[1]);
    //     swap(sy[0], sy[1]);
    // }
    // if(tx[0] > tx[1]) {
    //     swap(tx[0], tx[1]);
    //     swap(ty[0], ty[1]);
    // }
    // if(sx[0] == sx[1]) {
    //     if(sy[0] > sy[1]) {
    //         swap(sx[0], sx[1]);
    //         swap(sy[0], sy[1]);
    //     }
    //     if(ty[0] > ty[1]) {
    //         swap(tx[0], tx[1]);
    //         swap(ty[0], ty[1]);
    //     }
    //     // if(tx[0] == tx[1]) printf("%lld\n", 2 * (abs(tx[0] - sx[0]) + abs(ty[0] - sy[0])));
    //     // else {

    //     // }
    // }
    LL mn = -1;
    For(o1, 0, 1) For(o2, 0, 1) {
        LL tmp = 2 * (abs(sx[o1] - tx[o2]) + abs(sy[o1] - ty[o2])) - min(abs(sx[o1] - tx[o2]), abs(sy[o1] - ty[o2]));
        if(mn == -1 || tmp < mn) mn = tmp;
    }
    // cout << mn << endl;
    if((sx[0] == sx[1]) ^ (tx[0] == tx[1])) mn++;
    else {
        if(sx[0] == sx[1]) {
            if(sy[0] > sy[1]) swap(sy[0], sy[1]);
            if(ty[0] > ty[1]) swap(ty[0], ty[1]);
            if(sy[0] != ty[0]) mn += 2;
        }
        else {
            if(sx[0] > sx[1]) swap(sx[0], sx[1]);
            if(tx[0] > tx[1]) swap(tx[0], tx[1]);
            if(sx[0] != tx[0]) mn += 2;
        }
    }
    printf("%lld\n", mn);
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}