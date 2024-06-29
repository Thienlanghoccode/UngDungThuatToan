#include<bits/stdc++.h>
using namespace std;

struct Class {
	string maLop;
	int soHocSinh;
	int soHSNu;
};

void show_Data(Class x){
	cout << setw(12) << x.maLop;
	cout << setw(10) << x.soHocSinh;
	cout << setw(10) << x.soHSNu;
	cout << endl;
}

int getClass(Class lop[], int n, int m){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(lop[i].soHocSinh <= m || m > 0){
			count++;
			m -= lop[i].soHocSinh;
		}
		else {
			break;
		}
	}
	return count;
}

void Algo(Class lop[], int n, int s, int dp[8][115]){
	for(int j = 0; j <= s; j++) dp[0][j] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= s; j++){
			dp[i][j] = dp[i - 1][j];
			if(j >= lop[i - 1].soHocSinh){
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - lop[i - 1].soHocSinh] 
				+ lop[i - 1].soHSNu);
			}
		}
	}
}

int Result(Class lop[], int n, int s, int dp[8][115], vector<Class> &res){
	int i = n; int j = s;
	while(i != 0){
		if(dp[i][j] != dp[i - 1][j]){
			res.push_back(lop[i - 1]);
			j -= lop[i - 1].soHocSinh;
		}
		i--;
	}
	return res.size();
}

int z[100];
bool z_Algo(string p, string t, int z[]){
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


int main(){
	
	Class lop[7] = {
		{"IT 6041", 60, 7 },
		{"IT 6082", 50, 8},
		{"KT 6055", 45, 10},
		{"TDH 6151", 43, 7},
		{"DL 4421", 41, 20},
		{"TM 1234", 30, 4},
		{"IT 6789", 20, 1}
	};
	
	
	int m = 114;
	int s = 114;
	int dp[8][115];
	cout << "So lop it nhat can lay de lon hon " << m << " la: " << getClass(lop, 7, m);
	cout << endl;
	Algo(lop, 7, s, dp);
	vector<Class> res;
	int solop = Result(lop, 7, s, dp, res);
	if(solop > 0){
		cout << "Cac lop duoc chon la: " << endl;
		for(auto x : res){
			show_Data(x);
		}
	}
	else
	{
		cout << "Khong co lop nao chon duoc !";
	}
	cout << endl;
	cout << "Cac lop co ma IT la: " << endl;
	for(auto x : lop){
		if(z_Algo("IT", x.maLop, z) == true){
			show_Data(x);
		}
	}
	return 0;
}
