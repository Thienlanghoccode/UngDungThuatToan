#include<bits/stdc++.h>
using namespace std;

char ghe[4] = {'A', 'B', 'C', 'D'};
string name[4] = {"Tung", "Cuc", "Truc", "Mai"};


void show_Title() {
	for(int i = 0; i < 4; i++){
		cout << setw(8) << ghe[i];
	}
	cout << endl;
}

//sap xep 4 nguoi vao 4 vi tri -> hoan vi

void show_config(int arr[], int n){
	for(int i = 1; i <= n; i++)
		cout << setw(8) << name[arr[i] - 1];
	cout << endl;
}

void next_config(int arr[], int n, int i){
	int k = n;
	while(arr[k] < arr[i])
		k--;
	swap(arr[i], arr[k]);
	
	int j = n; i++;
	while(i < j) {
		swap(arr[i], arr[j]); j--; i++;
	}
}

void list_config(int n, int &count){
	int i, arr[n + 1] = {0};
	for(i = 1; i <= n; i++){
		arr[i] = i;
	}
		
	do
	{
		show_config(arr, n);
		count++;
		i = n - 1;
		while(i > 0 && arr[i] > arr[i + 1])
			i--;
		if(i > 0)
			next_config(arr, n, i);
	} while(i > 0);
}


// quay lui hoan vi

int dd[100]; int x[100]; int N = 4;
void show() {
	for(int i = 1; i <= N; i++)
		cout << setw(8) << name[x[i] - 1];
	cout << endl;
}
void Try(int k, int &count) {
	for(int i = 1; i <= N; i++){
		if(dd[i] == 0){
			x[k] = i;
			if(k == N){
				show();
				count++;
			}
			else {
				dd[i] = 1;
				Try(k + 1,count);
				dd[i] = 0;
			}
		}
	}
}

int main(){
	show_Title() ;
	// sinh
	int cnt = 0;
	list_config(4,cnt);
	cout << endl;
	cout << "So cach sap xep la: " << cnt;
	
	cout << endl << endl;
	//quay lui
	
	show_Title();
	int count = 0;
	Try(1, count);
	cout << endl;
	cout << "So cach sap xep la: " << count ;
	return 0;
}
