#include<bits/stdc++.h>
using namespace std;

float Sum(float arr[], int l, int r){
	if(l == r){
		if(arr[l] > 0) return arr[l];
		return 0;
	}
	
	int m = l + (r - l) / 2;
	float sum_left = Sum(arr,l,m);
	float sum_right = Sum(arr, m + 1, r);
	
	return sum_left + sum_right;
}

int main() {
	float arr[20] = {-1.1, 1.2, -2.2, -3.5, 4.7, -10.5,
	-6.1, 15.9, 100.35, 20.15, 29.07, 7.09,
	3.14, 30.4, -12.37, 33.23, -55.55, 66.66, 77.77, -88.88};
	
	float res = Sum(arr, 0, 19);
	cout << "Tong Gia Tri Duong Co Trong Mang La: ";
	cout << fixed << setprecision(1) << res;
	return 0;
}
