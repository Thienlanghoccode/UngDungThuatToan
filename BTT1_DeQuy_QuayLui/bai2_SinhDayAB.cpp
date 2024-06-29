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

char Arr[100];

void show_Config(int n) {
	for(int i = 1; i <= n; i++){
		cout << Arr[i];
	}
	cout << endl;
}

void Generation(int n) {
	bool check = true;
//	Xây dung cau hình dau tiên;
	for(int i = 1; i <= n; i++){
		Arr[i] = 'a';
	}
	
	do {
//		• Ðua ra cau hình dang có;
		int cntA = 0, cntB = 0;
		for(int i = 1; i <= n; i++){
			if(Arr[i] == 'a') cntA++;
			else cntB++;
		}
		if(cntA > 0 && cntB > 0) show_Config(n);
		
//		• Tu cau hình dang có sinh ra cau hình ke tiep neu còn;
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
