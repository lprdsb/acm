#include<iostream>
#include<iomanip>
using namespace std;

void mat_transpose(int a[][3], int b[][3]){
    int n = a[0][0], m = a[0][1], t = a[0][2];
    b[0][1] = n; b[0][0] = m; b[0][2] = t;
    if(t > 0){
        for(int i = 1; i <= t; ++i){
            b[i][0] = a[i][1];
            b[i][1] = a[i][0];
            b[i][2] = a[i][2];
        }
    }
}

void outmat(int a[][3]){
    int n = a[0][0], m = a[0][1], t = a[0][2];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int fl = 0;
            for(int p = 1; p <= t; ++p){
                if(a[p][0] == i && a[p][1] == j){
                    cout << setw(8) << a[p][2];
                    fl = 1;
                    break;
                }
            }
            if(!fl) cout << setw(8) << 0;
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int a[100][3] = {{5, 4, 7}, {0, 0, 12}, {0, 1, 15}, {2, 0, 36}, {2, 1, 46}, {2, 3, 52}, {4, 1, 72}, {4, 3, 68}}, b[100][3];
    cout << "============mat   a==============\n";
    outmat(a);
    mat_transpose(a, b);
    
    cout << "============mat   b==============\n";
    outmat(b);
}