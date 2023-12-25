#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
using namespace std;

int n = 10000, m = 1;

int main(){
    freopen("in.txt", "w", stdout);
    cout << n << endl;
    For(i, 1, n) cout << rand() % 4 + 1 << " "; cout << endl;
    cout << m << endl;
    For(i, 1, m){
        int c = 1;
        cout << c << " ";
        For(j, 1, c)
            if(1) cout << 2 << " ";
            else cout << 3 << " ";
        cout << endl;
    }
}