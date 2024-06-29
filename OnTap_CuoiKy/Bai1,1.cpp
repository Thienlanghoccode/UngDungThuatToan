#include<bits/stdc++.h>
using namespace std;

int upper_bound(int arr[], int l, int r, int X){
	if(l > r)
		return l;
	int mid = l + (r - l)/2;
	if(arr[mid] <= X){
		return upper_bound(arr, mid + 1, r, X);
	}
	return upper_bound(arr, l, mid - 1, X);
}

int main(){
	int arr[6] = {1, 2, 3, 4, 5, 6};
	int index = upper_bound(arr, 0, 5, 6);
	if(index == 6){
		cout << "NO";
	}
	else {
		cout << arr[index];
	}
	
	return 0;
}
