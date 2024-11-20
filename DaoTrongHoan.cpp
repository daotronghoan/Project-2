#include <bits/stdc++.h>
using namespace std;

class Nguoi
{
	protected:
		char ten[30];
		char DoB[10];
		char queQuan[100];
	public:
		void nhap();
		void xuat();
};
class Lop;
class SinhVien: public Nguoi
{
	private:
		int id;
		char nganh[30];
		int khoaHoc;
	public:
		void nhap();
		void xuat();
	friend class Lop;
	friend int tim(Lop x,int k);
	friend void sap_xep(Lop x);
};

class Lop
{
	private:
		char maLH[10];
		char tenLH[10];
		char ngayTL[10];
		SinhVien *x;
		int n;
		Nguoi gv;
	public:
		void nhap();
		void xuat();
	friend int tim(Lop x,int k);
	friend void sap_xep(Lop x);
};


void Nguoi::nhap()
{
	cout << "Ho ten: ";
	cin.getline(ten,200);
	cout << "Nhap lan luot ngay thang nam sinh: ";
//	cin.ignore();
	cin >> DoB;
	cout << "Que quan: ";
	cin.ignore();
	cin.getline(queQuan,200);
}

void SinhVien::nhap()
{
	Nguoi::nhap();
	cout << "Ma SV: ";
	cin >> id;
	cout << "Khoa: ";
	cin >> khoaHoc;
	cin.ignore();
	cout << "Nganh: ";
	cin.getline(nganh,200);
}

void Lop::nhap()
{
	cout << "Ma lop: ";
	cin >> maLH;
	cout << "Ten lop: ";
	cin.ignore();
	cin.getline(tenLH,200);
	cout << "Ngay mo: ";
	cin >> ngayTL;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cin.ignore();
	x = new SinhVien[n];
	for (int i=0;i<n;i++)
	{
		cout << "Sinh vien " << i+1 << "\n";
		x[i].nhap();
	}
	cout << "GVCN\n";
	gv.nhap();
}

void Nguoi::xuat()
{
	cout << "Ho ten: ";
	cout <<  ten<<'\n';
	cout << "ngay sinh: ";
	cout << left << setw(20) << DoB;
	cout << '\n';
	cout << "que: ";
	cout << queQuan <<'\n';
}

void SinhVien::xuat()
{
	cout << left << setw(10) << id;
	cout << left<<setw(30) <<  ten;
	cout << left << setw(20) << DoB;
	cout << left << setw(20) << queQuan;
	cout << left << setw(5) << khoaHoc;
	cout << nganh << '\n';
}

void Lop::xuat()
{
	cout << "Ma lop: " << maLH << '\n';
	cout << "Ten lop: " << tenLH << "\n";
	cout << "Ngay thanh lap: " << ngayTL;
	cout << '\n';
	gv.xuat();
	cout << left << setw(10) << "Ma SV";
	cout << left<<setw(30) <<  "Ho ten";
	cout << left << setw(20) << "Ngay sinh";
	cout << left << setw(20) << "Que quan";
	cout << left << setw(5) << "Khoa";
	cout << "Nganh" << '\n';
	for (int i=0;i<n;i++)
		x[i].xuat();
}

int tim(Lop m,int k)
{
	int res=0;
	for (int i=0;i<m.n;i++)
	{
		if (m.x[i].khoaHoc==k)
			res++;
	}
	return res;
}

void sap_xep(Lop m)
{
	int n = m.n;
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (m.x[i].khoaHoc>m.x[j].khoaHoc)
				swap(m.x[i],m.x[j]);
		}
	}
}

int main()
{
	Lop k;
	k.nhap();
	cout << "=======================================\n";
	k.xuat();
	cout << "=======================================\n";
	cout << "Co "<<tim(k,11) << " sv thuoc khoa 11"  << "\n";
	sap_xep(k);
	cout << "==================Thong tin lop sau khi sap xep=============\n";
	k.xuat();
	
}
