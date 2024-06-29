#include<bits/stdc++.h>
using namespace std;

struct Quatban {
	string tenHang;
	string mauSac;
	double giaBan;
};

// lay ra so luong va danh sach quat lay duoc nhieu nhat

// -> gia thap thi lay -> sort by price

bool compare_by_price(Quatban a, Quatban b){
	if(a.giaBan < b.giaBan)
		return true;
	return false;
}

int get_List_Product(Quatban arr[], int n, int p, vector<Quatban> &res){
	int cnt = 0;
	std::sort(arr, arr + n, compare_by_price);
	for(int i = 0; i < n; i++){
		if(arr[i].giaBan <= p){
			res.push_back(arr[i]);
			p -= arr[i].giaBan;
			cnt++;
		}
	}
	return cnt;
}


int main() {
	
	// Khoi tao
	Quatban quat[6] = {
		{"QUAT001", "DO", 100000},
		{"QUAT002", "CAM", 150000},
		{"QUAT003", "VANG", 50000},
		{"QUAT004", "LUC", 200000},
		{"QUAT005", "TIM", 300000},
		{"QUAT006", "XANH", 350000},
	};
	
	int p = 750000;
	vector<Quatban> res;
	int c = get_List_Product(quat, 6, p, res);
	if(c > 0){
		cout << "SO LUONG TOI DA LAY DUOC: " << c << endl;
		cout << "DANH SACH QUAT LA: " << endl;
		for(auto x : res){
			cout <<
		}
	}
	
	
	return 0;
}
