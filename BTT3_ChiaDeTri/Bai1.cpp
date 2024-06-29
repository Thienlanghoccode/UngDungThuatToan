#include<bits/stdc++.h>
using namespace std;

struct Student {
	char ten[10];
	char hoDem[20];
	int namSinh;
	string diaChi;
};

//so sanh 2 chuoi khong phan biet hoa thuong
int my_strcmpi(char *s, char *t){
    int len1 = strlen(s), len2 = strlen(t);
    int min_len = len1 < len2 ? len1 : len2;
    for(int i = 0; i < min_len; i++){
        if(tolower(s[i]) != tolower(t[i])){
            return tolower(s[i]) - tolower(t[i]);
        }
    }
    if(len1 < len2)
        return '\0' - t[min_len];
    else if(len1 > len2)
        return s[min_len] - '\0';
    else
        return 0;
}

// Khoi tao

Student list_Student[6] = {
	{"Than", "Yen Van", 2004, "Thanh Hoa"},
	{"Minh Anh", "Tran Nguyen", 2004, "Tay Ninh"},
	{"A", "Tran Thi", 1999, "Ha Noi"},
	{"E", "Nguyen Van", 2005, "Bac Ninh"},
	{"D", "Le Thi", 2002, "Nghe An"},
	{"B", "Ly Van", 2000, "TP HCM"},
};

void display() {
	cout << setw(10) << "TEN";
	cout << setw(20) << "HO DEM";
	cout << setw(15) << "NAM SINH";
	cout << setw(20) << "DIA CHI";
	cout << endl;
		
	for(auto x : list_Student){
		cout << setw(10) << x.ten;
		cout << setw(20) << x.hoDem;
		cout << setw(15) << x.namSinh;
		cout << setw(20) << x.diaChi;
		cout << endl;
	}
}

//sort By Name
void merge(Student Arr[], int l, int m, int r){
	int len1 = m - l + 1;
	int len2 = r - m;
	
	//copy 2 mang student
	Student x[len1]; Student y[len2];
	for(int i = 0; i < len1; i++){
		x[i] = Arr[i + l];
	}
	for(int j = 0; j < len2; j++){
		y[j] = Arr[m + 1 + j];
	}
	
	int i = 0; int j = 0;
	while(i < len1 && j < len2){
		if(strcmp(x[i].ten, y[j].ten) <= 0) {
			Arr[l] = x[i]; i++; l++;
		}
		else {
			Arr[l] = y[j]; j++; l++;
		}
	}
	
	while(i < len1) {
		Arr[l] = x[i]; i++; l++;
	}
	while(j < len2){
		Arr[l] = y[j];j++; l++;
	}
}

void merge_Sort(Student Arr[], int l, int r){
	if(l >= r) return ;
	int m = l + (r - l) / 2;
	
	merge_Sort(Arr, l, m );
	merge_Sort(Arr, m + 1, r);
	
	merge(Arr, l, m, r);
}

//search by name
bool search_Name(Student Arr[], int l, int r, char name[10], Student &student){
	if(r >= l) {
		int m = l + (r - l) / 2;
		if(my_strcmpi(Arr[m].ten, name) == 0) {
			student = Arr[m];
			return true;
		}
		else if (my_strcmpi(Arr[m].ten, name) > 0) {
			return search_Name(Arr, l, m - 1, name, student);
		}
		else {
			return search_Name(Arr, m + 1, r, name, student);
		}
	}
	return false;
}


int main() {
	Student Student;
	cout << "Danh Sach Ban Dau: " << endl;
	display();
	cout << endl;
	cout << "Danh sach sau khi sap xep theo ten: " << endl ;
	merge_Sort(list_Student, 0, 5);
	display();
	cout << endl;
	
	char name[10];
	cout << "Hay Nhap Ten Sinh Vien Can Tim: ";
	cin.getline(name, 10);
	bool x = search_Name(list_Student, 0, 5, name, Student);
	if(x == 1) {
		cout << "Thong Tin Sinh Vien Tim Duoc La: " << endl << endl;
		
		cout << setw(10) << "TEN";
		cout << setw(20) << "HO DEM";
		cout << setw(15) << "NAM SINH";
		cout << setw(20) << "DIA CHI";
		cout << endl;
		cout << setw(10) << Student.ten;
		cout << setw(20) << Student.hoDem;
		cout << setw(15) << Student.namSinh;
		cout << setw(20) << Student.diaChi;
	}
	else {
		cout << "Khong tim duoc sinh vien co ten : " << name;
	}
	return 0;
}
