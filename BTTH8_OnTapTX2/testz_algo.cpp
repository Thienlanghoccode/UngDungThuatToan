#include<bits/stdc++.h>
using namespace std;

int z[23];

void z_algo(string s, int z[]){
	int n = s.length(), l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i > r){
			l = r = i;
			while(r < n && s[r - l] == s[r])
				r++;
			z[i] = r - l; r--;
		}
		else if(z[i - l] < r - i + 1){
			z[i] = z[i - l];
		}
		else {
			l = i;
			while(r < n && s[r - l] == s[r])
				r++;
			z[i] = r - l; r--;
		}
	}
}

int main() {
	string P = "Viet"; string t = "Ban Viet o Viet Nam";
	string s = P + "$" + t;
	z_algo(s, z);
	for(auto x : z)
		cout << x << endl;
	return 0;
}
