#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

//	Phuong ph�p sinh c� the m� ta nhu sau:
//	Generation() {
//	X�y dung cau h�nh dau ti�n;
//	do {
//		� �ua ra cau h�nh dang c�;
//		� Tu cau h�nh dang c� sinh ra cau h�nh ke tiep neu c�n;
//	} while (chua het cau h�nh);
//}

//	cau 1 : sinh day nhi phan

//cach trong slide
//void next_config(int x[], int n, int i){
//	x[i] = 1;
//	i ++;
//	while (i <= n){
//	//Dat x[i+1], �, x[n] = 0
//	x[i] = 0;
//	i ++;
//	}
//}
//
////Hien thi mot cau hinh
//void view_config(int x[], int n){
//for (int i = 1; i <= n; i++)
//		cout<<x[i];
//	cout<<endl;
//}
//
//void listing_configs(int n){
//	int i;
//	int x[n + 1] = {0}; //Cau hinh dau tien {00�0}
//	do {
//		view_config(x, n); //In m?t c?u h�nh
//		i = n;
//		while (i > 0 && x[i] == 1) {
//			i --;
//		}
//		if (i > 0) { //Chua phai cau hinh cuoi
//			next_config(x, n, i);
//		}
//	} while (i > 0);
//}

// tu code

int n;
int Arr[100];

//In Cau Hinh Dang Co:
void show_Config(int Arr[], int n){
	for(int i = 1; i <= n; i++) {
		cout << Arr[i];
	}
	cout << endl;
}

void Generation_Binary(int n) {
//	X�y dung cau h�nh dau ti�n;
	bool check = true;
	for(int i = 0; i <= n; i++){
		Arr[i] = 0;
	}
	
	do {
//		� �ua ra cau h�nh dang c�;
		show_Config(Arr, n);
		
//		� Tu cau h�nh dang c� sinh ra cau h�nh ke tiep neu c�n;
		int i = n;
		while(i >= 1 && Arr[i] == 1){
			Arr[i] = 0;
			i--;
		}
		if(i == 0){
			check = false;
		} else Arr[i] = 1;
	} while (check);
}

int main() {
	cout << "Nhap N: ";
	int n; cin >> n;
	Generation_Binary(n);
	return 0;
}
