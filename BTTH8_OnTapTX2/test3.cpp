#include<bits/stdc++.h>
using namespace std;

struct Laptop {
	string manufacturer;
    string configuration;
    int price;
};

void show_Data(Laptop x){
	cout  << left << setw(8) << x.manufacturer;
	cout << left <<  setw(55) << x.configuration;
	cout <<  setw(10) << x.price;
	cout << endl;
}

int z[23];

bool z_algo(string p, string t, int z[]){
	string s = p + "$" + t;
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
		if(z[i] == p.length()) return true;
	}
	return false;
}

int main() {
	
	Laptop laptops[5] = {
        {"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 100},
        {"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB", 200},
        {"Dell", "CPU 2.5GHz upto 3.5GHz-RAM 12GB-SSD 128GB", 300},
        {"Lenovo", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 1TB", 400},
        {"Asus", "CPU 2.5GHz upto 3.5GHz-RAM 32GB-SSD 256GB", 500}
	};
	
	for(auto x : laptops){
		show_Data(x);
	}
	cout << endl;
	
	int count16GB = 0;
    cout << "\nDanh sach laptop co RAM 16GB:\n";
    
//	for (int i = 0; i < 5; i++)
//    {
//        if (laptops[i].configuration.find("RAM 16GB") != string::npos)
//        {
//            count16GB++;
//            show_Data(laptops[i]);
//        }
//    }

	for(auto x : laptops){
		if(z_algo("RAM 16GB", x.configuration, z) == true){
			count16GB++;
			show_Data(x);
		}
	}
    cout << "Tong so laptop co RAM 16GB: " << count16GB << endl;
	
	return 0;
}
