#include<bits/stdc++.h>

using std::vector;

int t;
char u[210], v[210];
int lu, lv;
vector<char> su, sv;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%s%s", u, v);
        lu = strlen(u);
        lv = strlen(v);
        su.clear();
        sv.clear();
        int ca = 0, cb = 0, cc = 0;
        for(int i = 0;i < lu;i++) {
            if(u[i] == 'A') {
                if(cc % 2) {
                    if(!su.empty() && su.back() == 'C') {
                        su.pop_back();
                    }
                    else {
                        su.push_back('C');
                    }
                }
                cc = 0;
                ca++;
            }
            if(u[i] == 'B') {
                cb++;
            }
            if(u[i] == 'C') {
                if(ca % 2) {
                    if(!su.empty() && su.back() == 'A') {
                        su.pop_back();
                    }
                    else {
                        su.push_back('A');
                    }
                }
                ca = 0;
                cc++;
            }
        }
        if(ca % 2) {
            if(!su.empty() && su.back() == 'A') {
                su.pop_back();
            }
            else {
                su.push_back('A');
            }
        }
        if(cc % 2) {
            if(!su.empty() && su.back() == 'C') {
                su.pop_back();
            }
            else {
                su.push_back('C');
            }
        }
        if(cb % 2)
            su.push_back('B');
        ca = 0, cb = 0, cc = 0;
        for(int i = 0;i < lv;i++) {
            if(v[i] == 'A') {
                if(cc % 2) {
                    if(!sv.empty() && sv.back() == 'C') {
                        sv.pop_back();
                    }
                    else {
                        sv.push_back('C');
                    }
                }
                cc = 0;
                ca++;
            }
            if(v[i] == 'B') {
                cb++;
            }
            if(v[i] == 'C') {
                if(ca % 2) {
                    if(!sv.empty() && sv.back() == 'A') {
                        sv.pop_back();
                    }
                    else {
                        sv.push_back('A');
                    }
                }
                ca = 0;
                cc++;
            }
        }
        if(ca % 2) {
            if(!sv.empty() && sv.back() == 'A') {
                sv.pop_back();
            }
            else {
                sv.push_back('A');
            }
        }
        if(cc % 2) {
            if(!sv.empty() && sv.back() == 'C') {
                sv.pop_back();
            }
            else {
                sv.push_back('C');
            }
        }
        if(cb % 2)
            sv.push_back('B');
        bool f = su.size() == sv.size();
        if(f) {
            for(int i = 0;i < su.size();i++) {
                if(su[i] != sv[i]) {
                    f = false;
                    break;
                }
            }
        }
        puts(f ? "YES" : "NO");
    }
    return 0;
}