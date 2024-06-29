#include<bits/stdc++.h>
using namespace std;

long long sumOfArray(int arr[], int n){
	if(n <= 0)
		return 0;
	else {
		if(arr[n - 1] % 2 == 0)
			return arr[n - 1] + sumOfArray(arr, n - 1);
		return sumOfArray(arr, n - 1);
	}
}



int main() {
	cout << "Nhap n: ";
	int n; cin >> n;
	int arr[n];
	cout << "Nhap mang arr: ";
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << "Tong so chan trong mang la: " << sumOfArray(arr, n);
	
	return 0;
}
