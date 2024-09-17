#include<stdio.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)

#define maxn 100000
int len[21], id[21];
char s[21][maxn + 5];

int main() {
    freopen("in.txt", "r", stdin);
    char c;
    int tp = 0;
    while(scanf("%c", &c) != EOF) {
        if(c == '\n') {
            id[0] = ++tp;
            For(i, 1, 20) {
                if(len[i] < len[0] || (len[i] == len[0] && id[i] > id[0])) {
                    int tem = len[i];
                    len[i] = len[0];
                    len[0] = tem;

                    tem = id[i];
                    id[i] = id[0];
                    id[0] = tem;

                    tem = len[i];
                    if(len[0] > tem) tem = len[0];
                    For(j, 1, tem) {
                        char ct = s[0][j];
                        s[0][j] = s[i][j];
                        s[i][j] = ct;
                    }
                }
                if(len[0] == 0) break;
            }
            len[0] = 0;
        }
        else s[0][++len[0]] = c;
    }
    if(len[0]) {
        id[0] = ++tp;
        For(i, 1, 20) {
            if(len[i] < len[0] || (len[i] == len[0] && id[i] > id[0])) {
                int tem = len[i];
                len[i] = len[0];
                len[0] = tem;

                tem = id[i];
                id[i] = id[0];
                id[0] = tem;

                tem = len[i];
                if(len[0] > tem) tem = len[0];
                For(j, 1, tem) {
                    char ct = s[0][j];
                    s[0][j] = s[i][j];
                    s[i][j] = ct;
                }
            }
            if(len[0] == 0) break;
        }
    }
    // For(i, 1, 20) printf("%d ", id[i]); puts("");
    For(i, 1, 20) {
        int now = -1;
        For(j, 1, 20) if(id[j] != -1 && (now == -1 || id[j] < id[now])) now = j;
        id[now] = -1;
        // printf("%d\n", now);
        For(j, 1, len[now]) printf("%c", s[now][j]);
        puts("");
    }
}