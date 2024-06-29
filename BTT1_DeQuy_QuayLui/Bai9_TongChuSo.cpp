#include<bits/stdc++.h>
using namespace std;

int Sum_Of_Numbers(int n){
	if(n < 10) return n;
	return (n % 10) + Sum_Of_Numbers(n / 10);
}

int main() {
	int n;
	cout << "Nhap N: "; cin >> n;
	cout << "Tong cac chu so la: " << Sum_Of_Numbers(n);
	return 0;
}
