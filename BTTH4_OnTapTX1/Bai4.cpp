#include<bits/stdc++.h>
using namespace std;

struct Chuyenbay {
	string soHieu;
	long long giaVe;
	int soGhe;
};

// khoi tao
Chuyenbay chuyen[6] = {
	{"VN001", 1000000, 70},
	{"VN002", 500000, 50},
	{"VN003", 700000, 60},
	{"VN004", 1200000, 90},
	{"VN005", 1500000, 120},
	{"VN006", 2000000, 150},
};

// hien thi thong tin
void show(Chuyenbay chuyen){
		cout << setw(8) << chuyen.soHieu;
		cout << setw(12) << chuyen.giaVe;
		cout << setw(15) << chuyen.soGhe;
		cout << endl;
}

void hienThiCBTren700(Chuyenbay chuyenbay[], int n){
	if(n < 0)
		return;
	else {
		if(chuyenbay[n - 1].giaVe > 700000){
			show(chuyenbay[n - 1]);
			hienThiCBTren700(chuyenbay, n - 1);
		}
		else {
			hienThiCBTren700(chuyenbay, n - 1);
		}
	}
}

Chuyenbay minByCost(Chuyenbay a, Chuyenbay b){
	if(a.giaVe < b.giaVe)
		return a;
	return b;
}

Chuyenbay findMinCost(Chuyenbay chuyenbay[], int l, int r){
	if(l == r) return chuyenbay[l];
	
	int m = l + (r - l) / 2;
	Chuyenbay min_left = findMinCost(chuyenbay, l, m);
	Chuyenbay min_right = findMinCost(chuyenbay, m + 1, r);
	
	return minByCost(min_left, min_right);
}

//chon 4 tu 6 -> sinh to hop
int arr[100];
void show_By_SoHieu(int k){
	for(int i = 1; i <= k; i++){
		cout << setw(15) << chuyen[arr[i] - 1].soHieu;
	}
	cout << endl;
}

void Try(int i, int n, int k, int &count){
	for(int j = arr[i - 1] + 1; j <= n - k + i; j++){
		arr[i] = j;
		if(i == k){
			show_By_SoHieu(i);
			count++;
		}
		else {
			Try(i + 1, n, k, count);
		}
	}
}

int main(){
	Chuyenbay cb = findMinCost(chuyen, 0, 5);
	show(cb);
	return 0;
}
