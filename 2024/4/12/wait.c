#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define maxn 100000

int del[maxn + 5], q[maxn + 5], T, n[maxn + 5], as[maxn + 5], ty[maxn + 5], tim[maxn + 5];
int tp[2] = { 0, 0 };

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    For(i, 1, T) scanf("%d", &n[i]);
    int t = 1;
    int l = 1, r = 0;
    int now = 0;
    del[1] = 5;
    while(l <= r || t <= T) {
        tp[1] += del[t];
        while(tp[1] && tp[0] <= 1 && (r - l + 1) / (5 - tp[0]) < 7) tp[0]++, tp[1]--;
        if(t <= T) {
            For(i, 1, n[t]) {
                q[++r] = ++now;
                tim[now] = t;
                scanf("%d", &ty[now]);
            }
            while(tp[0] && (r - l + 1) / (5 - tp[0]) >= 7) tp[1]++, tp[0]--;
        }
        // while(tp[1] && tp[0] <= 1 && (r - l + 1) / (5 - tp[0] - 1) < 7) tp[0]++, tp[1]--;
        // if(t == 5) printf("%d\n", (r - l + 1));
        while(tp[1] && l <= r) {
            int id = q[l++];
            as[id] = t - tim[id];
            del[t + ty[id]]++;
            tp[1]--;
        }
        t++;
    }
    For(i, 1, now) printf("%d : %d\n", i, as[i]);
}