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

#define maxn 50
int T, a, b, A[maxn + 5], ta, B[maxn + 5], tb;
char s[maxn + 5];

vector<pair<int, int> > as;

void P_APA(int idx) {
    as.pb({ 1, idx });
}
void A_PAP(int idx) {
    as.pb({ 0, idx });
}
void AAA_0(int idx) {
    as.pb({ 2, idx });
}
void APA_P(int idx) {
    For(i, 2, a) P_APA(idx + i - 1);
    AAA_0(idx);
    AAA_0(idx + 1);
}
void AA_PP(int idx) {
    A_PAP(idx + 1);
    APA_P(idx);
}
void AP_PPPA(int idx) {
    P_APA(idx + 1);
    AA_PP(idx);
}
void PPP_0(int idx) {
    as.pb({ 3, idx });
}
void PAP_A(int idx) {
    For(i, 2, b) A_PAP(idx + i - 1);
    PPP_0(idx);
    PPP_0(idx + 1);
}
void APPPP_A(int idx) {
    AP_PPPA(idx);
    PAP_A(idx + 2);
    PAP_A(idx + 1);
    PAP_A(idx + 0);
}
void PA_APPP(int idx) {
    P_APA(idx);
    AA_PP(idx + 2);
}

// 0    1 2  3   4 5  6   7
// PPPP P PP PPP A AP APP APPP
int sol() {
    as.resize(0);
    int now = -1;
    int len = strlen(s + 1);
    Rof(i, len, 1) {
        if(now == -1) {
            if(s[i] == 'P') now = 1;
            else now = 4;
            continue;
        }
        else if(now == 0) {
            if(s[i] == 'P') {
                P_APA(i);
                APPPP_A(i + 2);
                APA_P(i);
                now = 1;
            }
            else {
                APPPP_A(i);
                now = 4;
            }
        }
        else if(now == 1) {
            if(s[i] == 'P') now = 2;
            else now = 5;
        }
        else if(now == 2) {
            if(s[i] == 'P') now = 3;
            else now = 6;
        }
        else if(now == 3) {
            if(s[i] == 'P') now = 0;
            else now = 7;
        }
        else if(now == 4) {
            if(s[i] == 'P') {
                PA_APPP(i);
                now = 7;
            }
            else {
                AA_PP(i);
                now = 2;
            }
        }
        else if(now == 5) {
            if(s[i] == 'P') {
                PAP_A(i);
                now = 4;
            }
            else {
                AA_PP(i);
                now = 3;
            }
        }
        else if(now == 6) {
            if(s[i] == 'P') {
                PA_APPP(i);
                APPPP_A(i);
                now = 5;
            }
            else {
                AA_PP(i);
                now = 0;
            }
        }
        else if(now == 7) {
            if(s[i] == 'P') {
                PA_APPP(i);
                APPPP_A(i);
                now = 6;
            }
            else {
                A_PAP(i + 1);
                APPPP_A(i + 2);
                APA_P(i);
                now = 1;
            }
        }
    }
    return now;
}

int ttt[10005], tot = 0;
void inv(pair<int, int> opt) {
    if(opt.fir == 0) {
        PAP_A(opt.sec);
        tot -= 2;
        For(i, opt.sec + 1, tot) ttt[i] = ttt[i + 2];
        ttt[opt.sec] = 1;
    }
    if(opt.fir == 1) {
        APA_P(opt.sec);
        tot -= 2;
        For(i, opt.sec + 1, tot) ttt[i] = ttt[i + 2];
        ttt[opt.sec] = 0;
    }
    if(opt.fir == 2) {
        if(ttt[opt.sec - 1]) {
            A_PAP(opt.sec - 1);
            For(i, 1, a) P_APA(opt.sec + i);
            AAA_0(opt.sec);
            PAP_A(opt.sec - 1);
        }
        else {
            For(i, 1, a) P_APA(opt.sec + i - 2);
            AAA_0(opt.sec - 1);
        }
        tot += a;
        Rof(i, tot, opt.sec + a) ttt[i] = ttt[i - a];
        For(i, opt.sec, opt.sec + a - 1) ttt[i] = 1;
    }
    if(opt.fir == 3) {
        if(!ttt[opt.sec - 1]) {
            P_APA(opt.sec - 1);
            For(i, 1, b) A_PAP(opt.sec + i);
            PPP_0(opt.sec);
            APA_P(opt.sec - 1);
        }
        else {
            For(i, 1, b) A_PAP(opt.sec + i - 2);
            PPP_0(opt.sec - 1);
        }
        tot += b;
        Rof(i, tot, opt.sec + b) ttt[i] = ttt[i - b];
        For(i, opt.sec, opt.sec + b - 1) ttt[i] = 0;
    }
}

int aa[10005], len = 0;
void opt1(int idx) {
    assert(aa[idx] == 1);
    len += 2;
    Rof(i, len, idx + 3) aa[i] = aa[i - 2];
    aa[idx] = aa[idx + 2] = 0;
    aa[idx + 1] = 1;
}
void opt2(int idx) {
    assert(aa[idx] == 0);
    len += 2;
    Rof(i, len, idx + 3) aa[i] = aa[i - 2];
    aa[idx] = aa[idx + 2] = 1;
    aa[idx + 1] = 0;
}
void opt3(int idx) {
    For(i, 1, a) assert(aa[idx + i - 1] == 1);
    len -= a;
    For(i, idx, len) aa[i] = aa[i + a];
}
void opt4(int idx) {
    For(i, 1, b) assert(aa[idx + i - 1] == 0);
    len -= b;
    For(i, idx, len) aa[i] = aa[i + b];
}

vector<pair<int, int> > As;
void mian() {
    read(a); read(b);
    scanf("%s", s + 1); ta = sol(); As = as;
    len = strlen(s + 1);
    For(i, 1, len) aa[i] = s[i] == 'A';

    // tot = len;
    // For(i, 1, len) ttt[i] = aa[i];
    // As.resize(0);
    // inv({ 3, 2 });
    // As = as;
    // for(auto i : As) {
    //     if(i.fir == 0) {
    //         opt1(i.sec);
    //         // cout << "+P " << i.sec << endl;
    //     }
    //     if(i.fir == 1) {
    //         opt2(i.sec);
    //         // cout << "+A " << i.sec << endl;
    //     }
    //     if(i.fir == 2) {
    //         opt3(i.sec);
    //         // cout << "-A " << i.sec << endl;
    //     }
    //     if(i.fir == 3) {
    //         opt4(i.sec);
    //         // cout << "-P " << i.sec << endl;
    //     }
    // }

    // cout << len << endl;
    // For(i, 1, len) {
    //     if(aa[i] == 0) cout << "P";
    //     else cout << "A";
    // }
    // cout << endl;

    if(ta == 0) {
        tot = 4;
        For(i, 1, 4) ttt[i] = 0;
    }
    if(ta == 1) {
        tot = 1;
        For(i, 1, 1) ttt[i] = 0;
    }
    if(ta == 2) {
        tot = 2;
        For(i, 1, 2) ttt[i] = 0;
    }
    if(ta == 3) {
        tot = 3;
        For(i, 1, 3) ttt[i] = 0;
    }
    if(ta == 4) {
        tot = 1; ttt[1] = 1;
        For(i, 2, 1) ttt[i] = 0;
    }
    if(ta == 5) {
        tot = 2; ttt[1] = 1;
        For(i, 2, 2) ttt[i] = 0;
    }
    if(ta == 6) {
        tot = 3; ttt[1] = 1;
        For(i, 2, 3) ttt[i] = 0;
    }
    if(ta == 7) {
        tot = 4; ttt[1] = 1;
        For(i, 2, 4) ttt[i] = 0;
    }

    scanf("%s", s + 1); tb = sol();
    // if(ta != tb) {
    //     puts("-1");
    //     return;
    // }
    auto tas = as;
    reverse(tas.begin(), tas.end());
    as.resize(0);
    for(auto i : tas) inv(i);
    // As.insert(As.end(), as.begin(), as.end());
    // cout << As.size() << endl;
    for(auto i : As) {
        if(i.fir == 0) {
            opt1(i.sec);
            // cout << "+P " << i.sec << endl;
        }
        if(i.fir == 1) {
            opt2(i.sec);
            // cout << "+A " << i.sec << endl;
        }
        if(i.fir == 2) {
            opt3(i.sec);
            // cout << "-A " << i.sec << endl;
        }
        if(i.fir == 3) {
            opt4(i.sec);
            // cout << "-P " << i.sec << endl;
        }
    }

    cout << len << endl;
    For(i, 1, len) {
        if(aa[i] == 0) cout << "P";
        else cout << "A";
    }
    cout << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
