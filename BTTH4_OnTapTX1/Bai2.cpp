#include<bits/stdc++.h>
using namespace std;

char S[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

//lay 6 tu 7 ky tu -> sinh to hop

void show_config(int arr[], int n){
	for(int i = 1; i <= n; i++)
		cout << setw(4) << S[arr[i] - 1];
	cout << endl;
}

void next_config(int arr[], int k, int i){
	arr[i] += 1;
	i++;
	while(i <= k){
		arr[i] = arr[i - 1] + 1;
		i++;
	}
}

void list_config(int n, int k, int &count){
	int i, arr[n + 1] = {0};
	for(int i = 1; i <= k; i++)
		arr[i] = i;
		
	do 
	{
		show_config(arr,k);
		count++;
		i = k;
		while(i > 0 && arr[i] == n - k + i)
			i--;
		if(i > 0)
			next_config(arr, k, i);
	} while(i > 0);
}

//sinh to hop bang quay lui
int x[100];
int N,K;
void show() {
	for(int i = 1; i <= K; i++)
		cout << setw(4) << S[x[i] - 1];
	cout << endl;
}

void Try(int i, int &count){
	for(int j = x[i - 1] + 1; j <= N - K + i; j++){
		x[i] = j;
		if(i == K){
			show();
			count++;
		}
		else
			Try(i + 1, count);
	}
}

int main() {
	N = 7; K = 6;
	return 0;
}
