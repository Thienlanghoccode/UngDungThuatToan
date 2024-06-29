#include<bits/stdc++.h>
using namespace std;

float POW(float a, int n){
	if(n == 1) return a;
	if(n % 2 == 0)
		return POW(a, n / 2) * POW(a, n / 2);
	return POW(a, n / 2) * POW(a, n / 2) * a;
}


int main() {
	float a; int n;
	cout << "Nhap so thuc a: "; cin >> a;
	cout << "Nhap so nguyen n: "; cin >> n;
	float res = POW(a,n);
	cout << "Gia tri pow(a,n) la: ";
	cout << fixed << setprecision(1) << res;
	
	return 0;
}
