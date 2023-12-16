#include<bits/stdc++.h>
#include<vector>
#include<array>
//#include<stdlib.h>
using namespace std;

class hoc_sinh{
	
		
		char name[50];
		int tuoi;
		char lop[8];
	public:
// menthod and operator
		int SBD;
		hoc_sinh& operator<<(hoc_sinh a);
		hoc_sinh& operator>>(hoc_sinh a);
		void nhap();
		void xuat(hoc_sinh a);
		int layma();
		
};


hoc_sinh& hoc_sinh::operator>>(hoc_sinh a){
	cout << "nhap ten hoc sinh : ";
	getchar();
	cin.get(name,50);
	cout << "nhap tuoi : ";
	cin >> tuoi;
	cout <<"nhap so bao danh : ";
	cin >> SBD;
	cout <<"nhap lop : ";
	cin.ignore();
	cin.get(lop,8);
}

hoc_sinh& hoc_sinh::operator<<(hoc_sinh a){
	cout << "\n"<< a.name<<" "<< a.tuoi << " "<< SBD <<" "<<a.lop <<" ";
}

int  hoc_sinh::layma(){
	return SBD; 
}

class quan_li{
	private:
		vector<hoc_sinh> dssv;
		int size = 0;
		int Tim_kiem(int SBD);
	public:
		int Tim_kiem(vector<hoc_sinh> ds1,int left, int right, int Y);
		int getsize(){ return size;	}
		void Them(hoc_sinh sv);
		void Xoa(int SBD);
		void xuat();
		void Tim_kiem();
};

void quan_li :: Them(hoc_sinh sv){
	dssv.push_back(sv);
	size ++;
}

void quan_li :: Xoa(int SBD){
	for(int i = 0; i < dssv.size(); i++){
		if(dssv[i].layma() == SBD){
			dssv.erase(dssv.begin() + i);
			return;
		}
	}
}

void quan_li::xuat(){
	for(int i = 0; i< size;i++){
		dssv[i]<<dssv[i];
		cout << endl;
	}
}


int quan_li::Tim_kiem(int SBD){
	for(int i = 0; i< dssv.size();i++){
		if(dssv[i].layma() == SBD) return i;
	}
	return -1;
}




int quan_li:: Tim_kiem(vector<hoc_sinh> ds1,int left, int right, int Y){
	if(left == right){
		if(ds1[left].SBD == Y) return left;
		return -1;
	}
	int middle = (left + right)/2;
	if(ds1[middle].layma() == Y) return middle;
	if(ds1[middle].layma() < Y) return Tim_kiem(ds1,middle +1, right, Y);
	return Tim_kiem(ds1,left, middle-1,Y);
}

void quan_li::Tim_kiem(){
	int SBD;
	cout << "nhap ma sinh vien can tim  ";
	cout << dssv.size() << " ";
	cin >> SBD;
	int kq = Tim_kiem(dssv,0,dssv.size(),SBD);;
	cout << "index = "<< Tim_kiem(dssv,0,4,SBD);
	if(kq == -1){
		cout << "ko thay ket qua";
	}
	else dssv[kq]<<dssv[kq];
}

int main(){
	hoc_sinh hs1,hs2,hs3,hs4;
	hs1 >> hs1;
	hs2 >> hs2;
	hs3 >> hs3;
	hs4 >> hs4;
	hs1.layma();
	
	quan_li ds1;
	ds1.Them(hs1);
	ds1.Them(hs2);
	ds1.Them(hs3);
	ds1.Them(hs4);
//	ds1.sort();
	ds1.xuat();
//	cout << ds1.size();
	
	ds1.Tim_kiem();
	
	
}
