#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

//show 
void show_Config(int Arr[], int n){
	for(int i = 1; i <= n; i++){
		cout << Arr[i];
	}
	cout << endl;
}

//sinh to hop
int Arr[100];
void Generation(int n, int k){
	bool check = true;
	//Khoi tao
	for(int i = 0; i <= n; i++){
		Arr[i] = i;
	}
	
	do 
	{
		show_Config(Arr, k);
		int i = k;
		while(i >= 1 && Arr[i] == n - k + i){
			i--;
		}
		
		if(i == 0) check = false;
		else {
			Arr[i]++;
			for(int j = i + 1; j <= k; j++){
				Arr[j] = Arr[j - 1] + 1;
			}
		}
	} while(check);
	
}

int main() {
	Generation(5,3);
	return 0;
}
