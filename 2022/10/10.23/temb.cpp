#include<iostream>
using namespace std;

int san[50][50];

int main(){
	//freopen("in", "r", stdin);
	san[1][1] = 1;
	for(int i = 2; i <= 7; ++i){
		for(int j = 1; j <= i; ++j)
			san[i][j] = san[i - 1][j - 1] + san[i - 1][j];
	}	
	for(int i = 1; i <= 7; ++i){
		for(int j = 1; j <= 7 - i; ++j) cout << "  ";
		for(int j = 1; j <= i; ++j){
			if(san[i][j] < 10) cout << " ";
			cout << san[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}


