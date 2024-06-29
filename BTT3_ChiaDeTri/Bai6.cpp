#include<bits/stdc++.h>
using namespace std;

int find_min_even(int Arr[], int l, int r) {
	if(l == r) {
		if(Arr[l] % 2 == 0) return Arr[l];
		return INT_MAX;
	}
	
	int m = l + (r - l) / 2;
	int minleft = find_min_even(Arr, l, m);
	int minright = find_min_even(Arr, m + 1, r);
	
	return min(minleft, minright);
}

int main() {
	int Arr[20] = {10, 9, 2, 7, 100, 50, 3, 4, 25, 43, 55, 86, 14, 15, 76, 54, 37, 99, 32, 50};
	cout << "So chan nho nhat trong day la: " << find_min_even(Arr, 0, 19);
	return 0;
}
