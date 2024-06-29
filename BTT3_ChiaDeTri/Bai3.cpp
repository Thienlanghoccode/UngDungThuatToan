#include<bits/stdc++.h>
using namespace std;

float find_Max(float arr[], int l, int r){
	if(l >= r) return arr[l];
	
	int m = l + (r - l) / 2;
	float max_left = find_Max(arr, l, m);
	float max_right = find_Max(arr, m + 1, r);
	
	return max(max_left, max_right);
}

int main() {
	float arr[15] = {1.1, 1.2, 2.2, 3.5, 4.7, 10.5, 6.1, 15.9, 100.35, 20.15, 29.07, 7.09,
	3.14, 30.4, 12.37};
	cout << "So Lon Nhat La: " << find_Max(arr, 0, 14);
	return 0;
}
