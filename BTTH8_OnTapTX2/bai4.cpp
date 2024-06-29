#include <bits/stdc++.h>
using namespace std;

struct Dienthoai {
	string nhanHieu;
	int kichThuoc;
	double giaBan;
};

void show_Data(Dienthoai x){
	cout << setw(10) << x.nhanHieu;
	cout << setw(8) << x.kichThuoc;
	cout << setw(12) << fixed << setprecision(0) << x.giaBan;
	cout << endl;
}

double F[10][26];

void Algo(Dienthoai dt[], int n, int s, double F[7][26]){
	for(int j = 0; j <= s; j++) F[0][j] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= s; j++){
			F[i][j] = F[i - 1][j];
			//co the dua vao tui
			if(j >= dt[i - 1].kichThuoc){
				F[i][j] = max(F[i - 1][j], F[i - 1][j - dt[i - 1].kichThuoc] + dt[i - 1].giaBan);
			}
		}
	}
}

void Result(Dienthoai dt[], int n, int s, double F[7][26]){
	cout << "Max value: " << fixed << setprecision(2) <<  F[n][s];
	cout << endl;
	int i = n; int j = s;
	while(i != 0){
		if(F[i][j] != F[i - 1][j]){
			show_Data(dt[i - 1]);
			j = j - dt[i - 1].kichThuoc;
		}
		i--;
	}
}



int main(){
    Dienthoai dienthoai[6] = {
		{"Dienthoai001", 5, 5000000},
		{"Dienthoai002", 9, 10000000},
		{"Dienthoai003", 7, 7500000},
		{"Dienthoai004", 6, 6000000},
		{"Dienthoai005", 4, 4500000},
		{"Dienthoai006", 8, 9000000}
	};
	
	int s = 25; int n = 6;
	Algo(dienthoai,6,s,F);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= s; j++){
			cout << setw(8) <<  fixed << setprecision(0) << F[i][j];
		}
		cout << endl;
	}
	cout << endl;
	Result(dienthoai,6,s,F);
    return 0;
}
