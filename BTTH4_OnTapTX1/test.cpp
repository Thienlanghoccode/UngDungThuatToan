#include<bits/stdc++.h>
using namespace std;
int x[100], dd[100];
int n;

void show(){
	for(int i = 1; i <= n; i++)
		cout << x[i];
	cout << endl;
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(dd[j] == 0){
			x[i] = j;
			if(i == n)
				show();
			else{
				dd[j] = 1;
				Try(i + 1);
				dd[j] = 0;
			}
		}
	}
}




int main() {
	n = 5;
	Try(1);
	return 0;
}
