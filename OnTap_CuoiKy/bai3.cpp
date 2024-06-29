#include<bits/stdc++.h>
using namespace std;

struct product{
	string maSP;
	string tenSP;
	int khoiLuong;
	double giaTri;
};

void show_Data(product x){
	cout << setw(10) << x.maSP;
	cout << setw(12) << x.tenSP;
	cout << setw(8) << x.khoiLuong;
	cout << setw(12) << fixed << setprecision(0) << x.giaTri;
	cout << endl;
}

int lower_bound(product sp[], int l, int r, string tenSp){
	if(l > r)
		return l;
	int m = l + (r - l) / 2;
	if(sp[m].tenSP <= tenSp)
		return lower_bound(sp, m + 1, r, tenSp);
	lower_bound(sp, l, m - 1, tenSp);
}

int z[100];
bool z_algo(string p, string t, int z[]){
	string s = p + "$" + t;
	int n = s.length(), l = 0, r = 0;
	for(int i = 1; i <= n; i++){
		if(i > r){
			l = r = i;
			while(r < n && s[r - l] == s[r])
				r++;
			z[i] = r - l; r--;
		}
		else if(z[i - l] < r - i + 1){
			z[i] = z[i - 1];
		}
		else {
			l = i;
			while(r < n && s[r - l] == s[r])
				r++;
			z[i] = r - l; r--;
		}
		if(z[i] == p.length()) return true;
	}
	return false;
}

int getProductByName(product sp[], int n, vector<product> &res, int z[]){
	for(int i = 0; i < n; i++){
		if(z_algo("Tivi", sp[i].tenSP, z) == true){
			res.push_back(sp[i]);
		}
	}
	return res.size();
}

int main(){
	product Sanpham[7] = {
		{"SP0082", "Ao jeans", 10, 150000},
		{"SP0083", "Ban La", 20, 1500000},
		{"SP0084", "Con ga", 30, 110000},
		{"SP0085", "Ghe tua", 35, 250000},
		{"SP0086", "Keo ngot", 50, 10000},
		{"SP0087", "Mat ong", 10, 400000},
		{"SP0088", "Tivi", 10, 500000}
	};
//	for(auto x : Sanpham){
//		show_Data(x);
//	}

	string newTensp = "Dia CD Alibaba va con 10 UDTT";
	cout << "vi tri co the chen vao sau la: " << lower_bound(Sanpham, 0, 6, newTensp) + 1 ;
	cout << endl;
	
	vector<product> resTivi;
	if(getProductByName(Sanpham, 7, resTivi, z)){
		cout << "San pham co ten la Tivi la: " << endl;
		for(auto x : resTivi){
			show_Data(x);
		}
	}
	else {
		cout << "Khong co san pham nao !" << endl;
	}
	return 0;
}
