#include<cstdio>
#include<iostream>
using namespace std;

int n;

int main(){
	cin >> n;
	for(int i = n; i >= 1; --i){
		for(int j = 1; j <= n - i; ++j) cout << " ";
		for(int j = 1; j <= i; ++j) cout << j;
		for(int j = i - 1; j >= 1; --j) cout << j;
		cout << endl;
	}
	for(int i = 2; i <= n; ++i){
		for(int j = 1; j <= n - i; ++j) cout << " ";
		for(int j = 1; j <= i; ++j) cout << j;
		for(int j = i - 1; j >= 1; --j) cout << j;
		cout << endl;
	}
	return 0;
}


