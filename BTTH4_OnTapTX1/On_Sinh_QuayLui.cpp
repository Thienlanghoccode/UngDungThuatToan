#include<bits/stdc++.h>
using namespace std;

//sinh to hop
void show_config(int Arr[], int n) {
	for(int i = 1; i <= n; i++)
		cout << Arr[i];
	cout << endl;
}

void next_config(int arr[], int k, int i){
	arr[i] += 1;
	i++;
	while(i <= k) {
		arr[i] = arr[i - 1] + 1;
		i++;
	}
}

void list_config(int k, int n){
	int i, arr[k + 1] = {0};
	
	//cau hinh dau [1,k]
	for(i = 1; i <= k; i++)
		arr[i] = i;
	
	do 
	{
		show_config(arr, k);
		
		i = k;
		while(i > 0 && arr[i] == n - k + i)
			i--;
		if(i > 0)
			next_config(arr, k, i);
	} while(i > 0);
}

//sinh hoan vi

void next_config_1(int arr[], int n, int i) {
	int k = n;
	while(arr[k] < arr[i]){
		k--;
	} 
	
	swap(arr[i], arr[k]);
	int j = n; i++;
	while(i < j){
		swap(arr[i], arr[j]); i++; j--;
	}
}

void listing_config(int n){
	int i, arr[n + 1] = {0};
	
	for(i = 1; i <= n; i++){
		arr[i] = i;
	}
	
	do
	{
		show_config(arr, n);
		i = n - 1;
		while(i > 0 && arr[i] > arr[i + 1])
			i--;
		if(i > 0)
			next_config_1(arr, n, i);
	} while(i > 0);
}

//liet ke hoan vi

int dd[100];
int x[100];

int n = 4;
void show(){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << endl;
}

void Try(int k){
	for(int i = 1; i <= n; i++){
		if(dd[i] == 0) {
			x[k] = i;
			if(k == n)
				show();
			else {
				dd[i] = 1;
				Try(k + 1);
				dd[i] = 0;
			}
		}
	}
}

//liet ke to hop

int N;int K;
int arr[100];

void show_1(){
	for(int i = 1; i <= K; i++)
		cout << arr[i];
	cout << endl;
}
void Try2(int i){
	for(int j = arr[i - 1] + 1; j <= N - K + i; j++){
		arr[i] = j;
		if(i == K)
			show_1();
		else {
			Try2(i + 1);
		}
	}
}

int main() {
	Try(4);
	return 0;
}
