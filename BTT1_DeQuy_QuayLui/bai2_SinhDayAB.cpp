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

char Arr[100];

void show_Config(int n) {
	for(int i = 1; i <= n; i++){
		cout << Arr[i];
	}
	cout << endl;
}

void Generation(int n) {
	bool check = true;
//	X�y dung cau h�nh dau ti�n;
	for(int i = 1; i <= n; i++){
		Arr[i] = 'a';
	}
	
	do {
//		� �ua ra cau h�nh dang c�;
		int cntA = 0, cntB = 0;
		for(int i = 1; i <= n; i++){
			if(Arr[i] == 'a') cntA++;
			else cntB++;
		}
		if(cntA > 0 && cntB > 0) show_Config(n);
		
//		� Tu cau h�nh dang c� sinh ra cau h�nh ke tiep neu c�n;
		int i = n;
		while(i >= 1 && Arr[i] == 'b'){
			Arr[i] = 'a';
			i--;
		}
		
		if(i == 0) check = false;
		else Arr[i] = 'b';
	} while (check);
}


int main() {
	int n;
	cout << "Nhap N: "; cin >> n;
	Generation(n);
}
