#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

//	Phuong pháp sinh có the mô ta nhu sau:
//	Generation() {
//	Xây dung cau hình dau tiên;
//	do {
//		• Ðua ra cau hình dang có;
//		• Tu cau hình dang có sinh ra cau hình ke tiep neu còn;
//	} while (chua het cau hình);
//}

//	cau 1 : sinh day nhi phan

//cach trong slide
//void next_config(int x[], int n, int i){
//	x[i] = 1;
//	i ++;
//	while (i <= n){
//	//Dat x[i+1], …, x[n] = 0
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
//	int x[n + 1] = {0}; //Cau hinh dau tien {00…0}
//	do {
//		view_config(x, n); //In m?t c?u hình
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
//	Xây dung cau hình dau tiên;
	bool check = true;
	for(int i = 0; i <= n; i++){
		Arr[i] = 0;
	}
	
	do {
//		• Ðua ra cau hình dang có;
		show_Config(Arr, n);
		
//		• Tu cau hình dang có sinh ra cau hình ke tiep neu còn;
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
