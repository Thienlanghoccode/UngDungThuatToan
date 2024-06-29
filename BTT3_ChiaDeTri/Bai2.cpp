#include<bits/stdc++.h>
using namespace std;

//tron hai day con : day 1 [l, m] day 2 : [m + 1, r]

void merge(float a[], int l, int m, int r){
	int len1 = m - l + 1;
	int len2 = r - m;
	
	//tao mang de copy : mang x copy mang a tu left -> mid, 
	//mang y copy tu mid + 1 -> right
	
	float x[len1]; float y[len2];
	
	for(int i = 0; i < len1; i++){
		x[i] = a[i + l];
	}
	
	for(int j = 0; j < len2; j++) {
		y[j] = a[m + 1 + j];
	}
	
	int i = 0; int j = 0;
	while(i < len1 && j < len2) {
		if(x[i] <= y[j]){
			a[l] = x[i]; l++; i++;
		}
		else {
			a[l] = y[j]; l++; j++;
		}
	}
	
	while(i < len1){
		a[l] = x[i]; l++; i++;
	}
	while(j < len2){
		a[l] = y[j]; l++; j++;
	}
}

void merge_Sort(float arr[], int l, int r){
	if(l >= r) return;
	int m = l + (r - l) / 2;
	
	merge_Sort(arr, l, m);
	merge_Sort(arr, m + 1, r);
	merge(arr, l, m, r);
}

int main() {
	float arr[20] = {-1.1, 1.2, -2.2, -3.5, 4.7, -10.5, -6.1, 15.9, 100.35, 20.15, 29.07, 7.09,
	3.14, 30.4, -12.37, 33.23, -55.55, 66.66, 77.77, -88.88};
	
	merge_Sort(arr, 0, 19);
	
	for (auto x : arr) {
		cout << x << endl;
	}
	return 0;
}
