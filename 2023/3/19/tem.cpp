#include<bits/stdc++.h>
using namespace std;

struct Node{int x;} a1 = {0}, a2 = {114514};
vector<Node> poi;
int sol(){
    poi.push_back(a1);
    return 2;
}
int build(){
    poi.push_back(a2);
    poi[0].x = sol();
    cout << poi[0].x << endl;
    return 1;
}

int main(){
    build();
    return 0;
}
