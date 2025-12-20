#include <iostream>

#define		MAX		100

using namespace std;

struct VatTu {
	string maVatTu;
	string tenVatTu;
	int soLuong;
	string donViTinh;
	double donGia;
};

typedef VatTu DanhSachVatTu[MAX];

// prototypes => Nguyen mau ham

// 2. xuat danh sach
void XuatMotVatTu(VatTu vatTuHienTai);
void XuatDanhSachVatTu(DanhSachVatTu ds, int soLuongVatTu);


// 1. nhap danh sach vat tu
VatTu NhapMotVatTu();
void NhapDanhSachVatTu(DanhSachVatTu ds, int& soLuongVatTu);

// 3. Tinh tong gia tri vat tu trong khoang [x, y]
double TinhTongGiaTri(DanhSachVatTu ds, int soLuongVatTu, double x, double y);

// 4. Tim vat tu theo ma
// khong tim ra: -1
// tim ra: vi tri
int TimVatTuTheoMa(DanhSachVatTu ds, int soLuongVatTu, string maVatTu);





// function defintion => Dinh nghia ham

void XuatMotVatTu(VatTu vatTuHienTai)
{
	cout << "Ma vat tu: " << vatTuHienTai.maVatTu << endl;
	cout << "Ten vat tu: " << vatTuHienTai.tenVatTu << endl;
	cout << "So luong: " << vatTuHienTai.soLuong << endl;
	cout << "Don vi tinh: " << vatTuHienTai.donViTinh << endl;
	cout << "Don gia: " << vatTuHienTai.donGia << endl;
}

void XuatDanhSachVatTu(DanhSachVatTu ds, int soLuongVatTu)
{
	for (int i = 0; i < soLuongVatTu; i++) 
	{
		// code
		VatTu vatTuHienTai = ds[i];
		XuatMotVatTu(vatTuHienTai);

		cout << endl;
	}

	/*
	int bienDem = 0;
	while (bienDem < soLuongVatTu) 
	{
		// code
		VatTu vatTuHienTai = ds[bienDem];

		cout << "Ma vat tu: " << vatTuHienTai.maVatTu << endl;
		cout << "Ten vat tu: " << vatTuHienTai.tenVatTu << endl;
		cout << "So luong: " << vatTuHienTai.soLuong << endl;
		cout << "Don vi tinh: " << vatTuHienTai.donViTinh << endl;
		cout << "Don gia: " << vatTuHienTai.donGia << endl;
		cout << endl;

		bienDem++;
	}
	*/
}

VatTu NhapMotVatTu()
{
	VatTu vatTuMoi;

	cout << "Nhap ma vat tu: ";
	cin >> vatTuMoi.maVatTu;

	cout << "Nhap ten vat tu: ";
	cin >> vatTuMoi.tenVatTu;

	cout << "Nhap so luong: ";
	cin >> vatTuMoi.soLuong;

	cout << "Nhap don vi tinh: ";
	cin >> vatTuMoi.donViTinh;

	cout << "Nhap don gia: ";
	cin >> vatTuMoi.donGia;

	return vatTuMoi;
}


void NhapDanhSachVatTu(DanhSachVatTu ds, int& soLuongVatTu)
{
	for (int i = 0; i < soLuongVatTu; i++) 
	{
		cout << "Hay nhap vat tu moi: " << endl;
		ds[i] = NhapMotVatTu();
		cout << "Nhap thanh cong vat tu co ma: " << ds[i].maVatTu << endl << endl;
	}
}

double TinhTongGiaTri(DanhSachVatTu ds, int soLuongVatTu, double x, double y)
{
	double tongGiaTri = 0;

	for (int i = 0; i < soLuongVatTu; i++)
	{
		VatTu vatTuHienTai = ds[i];

		/*
		if (vatTuHienTai.donGia < x)
		{
			continue;
		}

		if (vatTuHienTai.donGia > y)
		{
			continue;
		}

		double giaTien = vatTuHienTai.donGia * vatTuHienTai.soLuong;
		tongGiaTri = tongGiaTri + giaTien;
		*/

		// tongGiaTri += giaTien;

		if (x <= vatTuHienTai.donGia && vatTuHienTai.donGia <= y)
		{
			double giaTien = vatTuHienTai.donGia * vatTuHienTai.soLuong;
			tongGiaTri = tongGiaTri + giaTien;
		}
	}

	return tongGiaTri;
}

int TimVatTuTheoMa(DanhSachVatTu ds, int soLuongVatTu, string maVatTu)
{
	// 0 -> n-1
	for (int i = 0; i < soLuongVatTu; i++)
	{
		VatTu vatTuHienTai = ds[i];

		if (vatTuHienTai.maVatTu == maVatTu)
		{
			return i;
		}
	}

	return -1;
}