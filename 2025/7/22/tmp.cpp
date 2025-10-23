#include<bits/stdc++.h>
using namespace std;

void f(int x) {
    cout << __builtin_clz(x) << endl;
}

int main() {
    f(0);
    cout << __builtin_clz(0) << endl;
}