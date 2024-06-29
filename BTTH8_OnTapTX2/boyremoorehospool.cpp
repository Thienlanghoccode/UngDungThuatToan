#include<bits/stdc++.h>
using namespace std;

int char_in_string (char c, string Q) {
    for (int i = Q.size()-1; i>=0; i--) {
        if (c == Q[i]) return i;
    }
    return -1;
}  
int boyer(string p, string t) {
    int i = t.size()-1;
    while (i < p.size()) {
        int x = t.size() - 1;
        while (x >= 0 && p[i] == t[x]) {
            i--;
            x--;
        }
        if (x < 0) return i+1;
        else {
            int k = char_in_string(p[i], t);
            if (k < 0) i += t.size();
            else i += t.size() - k - 1;
        }
    }
    return -1;
}

int z[50];

int z_algo(string p, string t, int z[]){
	string s = p + "$" + t;
	int n = s.length(), l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i > r){
			l = r = i;
			while(r < n && s[r - l] == s[r])
				r++;
			z[i] = r - l; r--;
		}
		else if(z[r - l] < r - i + 1){
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

int main(){
	cout << boyer("abc dec def", "def") << endl;
	z_algo("def", "abc dac def", z);
	for(auto x : z){
		cout << x << endl;
	}
	return 0;
}
