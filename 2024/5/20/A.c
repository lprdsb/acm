#include<stdio.h>
#include<string.h>

int tot = 0, cnt = 0, L[3000], R[3000];
char s[3505][25], ts[25];

int cmp(char *s1, char *s2) {
    // cnt++;
    while(*s1 == *s2 && *s1) s1++, s2++;
    if(*s1 < *s2) return -1;
    if(*s1 == *s2) return 0;
    return 1;
}

#define NHASH  3001

#define MULT  37
int st[3005][3005], tp[3005];
unsigned int hash(char *str)

{

    unsigned int h = 0;

    char *p;



    for(p = str; *p != '\0'; p++)

        h = MULT * h + *p;

    return h % NHASH;

}

int main() {
    FILE *fin = fopen("dictionary3000.txt", "r");
    while(fgets(ts, 24, fin)) {
        int len = strlen(ts);
        while(ts[len - 1] == '\n' || ts[len - 1] == '\r') ts[--len] = 0;
        strcpy(s[tot++], ts);
    }
    for(int i = 0; i < tot; ++i) {
        int hsh = hash(s[i]);
        st[hsh][tp[hsh]++] = i;
    }
    for(int i = 0; i < 1000; ++i) L[i] = 0, R[i] = -1;
    for(int i = 0; i < tot; ++i) R[s[i][0]] = i;
    for(int i = tot - 1; i >= 0; --i) L[s[i][0]] = i;
    int ty;
    while(~scanf("%s %d", ts, &ty)) {
        cnt = 0;
        if(ty == 1) {
            int now = 0;
            while(now < tot && cmp(s[now], ts) < 0) now++;
            if(now == tot) now--;
            printf("%d %d\n", now > 0 && !cmp(s[now], ts), now + 1);
        }
        else if(ty == 2) {
            int l = 0, r = tot - 1;
            while(l <= r) {
                cnt++;
                int md = l + r >> 1;
                if(cmp(s[md], ts) > 0) r = md - 1;
                else {
                    if(cmp(s[md], ts) < 0) l = md + 1;
                    else break;
                }
            }
            printf("%d %d\n", l <= r, cnt);
        }
        else if(ty == 3) {
            int l = L[ts[0]], r = R[ts[0]];
            // printf("%d %d\n", l, r);
            while(l <= r) {
                cnt++;
                int md = l + r >> 1;
                if(cmp(s[md], ts) > 0) r = md - 1;
                else {
                    if(cmp(s[md], ts) < 0) l = md + 1;
                    else break;
                }
            }
            // if(cnt == 1 && l > r) printf("%s$$\n", ts);
            printf("%d %d\n", l <= r, cnt);
        }
        else {
            int hsh = hash(ts);
            int now = 0;
            while(now < tp[hsh] && cmp(s[st[hsh][now]], ts) < 0) now++;
            if(now == tp[hsh]) now--;
            // if(now + 1 == 1 && cmp(s[st[hsh][now]], ts)) printf("%s", ts, s[st[hsh][now]]);
            printf("%d %d\n", now >= 0 && !cmp(s[st[hsh][now]], ts), now + 1);
        }
    }
}