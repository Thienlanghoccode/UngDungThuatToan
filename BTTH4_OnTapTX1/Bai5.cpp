#include<bits/stdc++.h>
using namespace std;

struct Congviec {
	string maCV;
	float thoiGianBatDau;
	float thoiGianCanThiet;
};

string nhanvien[6] = {"A", "B", "C", "D", "E", "F"};

void show_Title(){
	for(auto x : nhanvien){
		cout << setw(8) << x;
	}
	cout << endl;
}

void show_CV(Congviec cv){
	cout << setw(8) << cv.maCV;
	cout << setw(12) << fixed << setprecision(2)  << cv.thoiGianBatDau;
	cout << setw(12) << fixed << setprecision(2)  << cv.thoiGianCanThiet;
	cout << endl;
}

//khai bao
Congviec congviec[6] = {
	{"CV001", 12.00, 0.1},
	{"CV003", 9.30, 0.5},
	{"CV004", 7.30, 0.3},
	{"CV002", 14.00, 0.7},
	{"CV006", 8.45, 1.5},
	{"CV005", 15, 0.45},	
};

void A1(Congviec cv[], int n){
	if(n <= 0) return;
	show_CV(cv[n - 1]);
	A1(cv, n - 1);
}

int A2(Congviec cv[], int l, int r, vector<Congviec> &res){
	if(l == r){
		if(cv[l].thoiGianCanThiet <= 0.5){
			res.push_back(cv[l]);
			return 1;
		}
		return 0;
	}
	
	int m = l + (r - l)/2;
	int cnt_left = A2(cv, l , m , res);
	int cnt_right = A2(cv, m + 1, r, res);
	return cnt_left + cnt_right;
}

//sinh hoan vi bang quay lui
int dd[100], x[100];

void show(){
	for(int i = 1; i <= 6; i++){
		cout << setw(8) << congviec[x[i] - 1].maCV ;
	}
	cout << endl;
}

void Try(int i){
	for(int j = 1; j <= 6; j++){
		if(dd[j] == 0){
			x[j] = i;
			if(i == 6)
				show();
			else {
				dd[j] = 1;
				Try(i + 1);
				dd[j] = 0;
			}
		}
	}
}


int main(){
	show_Title();
	Try(1);
	
	return 0;
}
