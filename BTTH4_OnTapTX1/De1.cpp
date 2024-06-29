#include<bits/stdc++.h>
using namespace std;

struct Maytinh {
	string tenHang;
	float kichThuoc;
	long long giaBan;
};

//khoi tao
Maytinh maytinh[7] = {
	{"MT001", 15.5, 20000000},
	{"MT002", 12.9, 15000000},
	{"MT003", 20.0, 22000000},
	{"MT004", 14.7, 17000000},
	{"MT005", 18.3, 21000000},
	{"MT006", 30, 40000000},
	{"MT007", 37.3, 47000000},

};

void show(Maytinh mt){
	cout << setw(8) << mt.tenHang;
	cout << setw(12) << fixed << setprecision(1) << mt.kichThuoc;
	cout << setw(12) << mt.giaBan;
	cout << endl;
}

void show_title(int n){
	for(int i = 1; i <= n; i++){
		cout << setw(8) << i;
	}
	cout << endl;
}

int A2(Maytinh mt[], int l, int r){
	if(l >= r){
		if(mt[l].kichThuoc >= 15.6)
			return 1;
		return 0;
	}
	
	int m = l + (r - l)/2;
	int cnt_left = A2(mt, l, m);
	int cnt_right = A2(mt, m + 1, r);
	return cnt_left + cnt_right;
}

long long A1(Maytinh mt[], int n){
	if(n <= 0) return 0;
	return mt[n - 1].giaBan + A1(mt, n - 1);
}

//dat n man len n ban -> sinh hoan vi
int x[100];int dd[100]; int n;

void show_config(){
	for(int i = 1; i <= n; i++)
		cout << setw(8) << maytinh[x[i] - 1].tenHang;
	cout << endl;
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(dd[j] == 0){
			x[i] = j;
			if(i == n)
				show_config();
			else {
				dd[j] = 1;
				Try(i + 1);
				dd[j] = 0;
			}
		}
	}
}


int main(){
	n = 4;
	cout << "Tong gia ban may tinh la: " << A1(maytinh, 7);
	cout << endl;
	cout << "So may tinh co kich thuoc >= 15.6 la: " << A2(maytinh, 0, 6);
	cout << endl;
	cout << "Cac cach xep vao n vi tri la: " << endl;
	show_title(n);
	Try(1);
	return 0;
}
