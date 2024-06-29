#include<bits/stdc++.h>
using namespace std;

struct DienThoai {
	string nhanHieu;
	int kichThuoc;
	double giaBan;
};

void show_Data(DienThoai x){
	cout << setw(8) << x.nhanHieu;
	cout << setw(7) << x.kichThuoc;
	cout << setw(12) << fixed << setprecision(0) << x.giaBan;
	cout << endl;
}

double F[7][26];
void QHD(DienThoai dt[], int n, int s, double F[7][26]){
	for(int j = 0; j <= s; j++) F[0][j] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= s; j++){
			F[i][j] = F[i - 1][j];
			if(j >= dt[i - 1].kichThuoc){
				F[i][j] = max(F[i - 1][j], F[i - 1][j - dt[i - 1].kichThuoc] + dt[i - 1].giaBan);
			}
		}
	}
}

int Result(DienThoai dt[], int n, int s, double F[7][26], vector<DienThoai> &res){
	int i = n; int j = s;
	while(i != 0){
		if(F[i][j] != F[i - 1][j]){
			res.push_back(dt[i - 1]);
			j -= dt[i - 1].kichThuoc;
		}
		i--;
	}
	return res.size();
}

int main() {
	int n = 6; int s = 25;
	
	DienThoai dt[n] = {
		{"Dienthoai001", 5, 5000000},
		{"Dienthoai002", 10, 10000000},
		{"Dienthoai003", 7, 7500000},
		{"Dienthoai004", 6, 6000000},
		{"Dienthoai005", 4, 4500000},
		{"Dienthoai006", 11, 9000000}
	};
	vector<DienThoai> res;
	QHD(dt, n, s, F);
	int cnt = Result(dt, n, s, F, res);
	if(cnt == 0){
		cout << "Khong co dt nao duoc lay !" << endl;
	}
	else {
		cout << "So luong dt la: " << cnt << endl;
		cout << "Danh sach dt la: " << endl;
		for(auto x : res)
			show_Data(x);
	}
	return 0;
}
