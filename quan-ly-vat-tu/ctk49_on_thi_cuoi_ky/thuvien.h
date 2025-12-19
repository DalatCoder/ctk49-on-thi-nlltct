#include <iomanip>
#include <ios>
#include <iostream>

#define MAX 100
#define TAB '\t'

using namespace std;

struct VatTu
{
    string maVT;
    string tenVT;
    int soLuong;
    string donVi;
    double donGia;
};

typedef VatTu DanhSachVatTu[MAX];


void XuatDongTieuDe();
void XuatDongKeNgang();
void XuatMotVatTu(VatTu vt);
void XuatDanhSachVatTu(DanhSachVatTu ds, int n);
void NhapMotVatTu(VatTu& vt);
void NhapDanhSachVatTu(DanhSachVatTu ds, int& n);

double TinhTongGia(DanhSachVatTu ds, int n, int x, int y);
int TimViTriVatTu(DanhSachVatTu ds, int n, string maVT);
void HoanVi(VatTu& a, VatTu& b);
void SapXepDanhSachVatTu(DanhSachVatTu ds, int n);
void Xoa1VatTu(DanhSachVatTu ds, int& n, int viTri);
void XoaVatTu(DanhSachVatTu ds, int& n, double x);
void ChenVatTu(DanhSachVatTu ds, int& n, string maVT);
void InBangThongKe(DanhSachVatTu ds, int n);

void XuatDongTieuDe()
{
    cout << endl
        << setiosflags(ios::left)
        << setw(15) << "Ma vat tu"
        << setw(15) << "Ten vat tu"
        << setw(15) << "So luong"
        << setw(15) << "Don vi"
        << setw(15) << "Don gia"
        << endl;
}

void XuatDongKeNgang()
{
    cout << setfill(' ')
        << setw(15) << "==============="
        << setw(15) << "==============="
        << setw(15) << "==============="
        << setw(15) << "==============="
        << setw(15) << "==============="
        << endl;
}

void XuatMotVatTu(VatTu vt)
{
    cout << setiosflags(ios::left)
        << setw(15) << vt.maVT
        << setw(15) << vt.tenVT
        << setw(15) << vt.soLuong
        << setw(15) << vt.donVi
        << setw(15) << vt.donGia
        << endl;
}

void XuatDanhSachVatTu(DanhSachVatTu ds, int n)
{
    XuatDongTieuDe();
    XuatDongKeNgang();

    for (int i = 0; i < n; i++)
    {
        XuatMotVatTu(ds[i]);
    }

    XuatDongKeNgang();
    cout << endl;
}

void NhapMotVatTu(VatTu& vt)
{
    cout << "Nhap ma vat tu: ";
    cin >> vt.maVT;
    cout << "Nhap ten vat tu: ";
    cin >> vt.tenVT;
    cout << "Nhap so luong: ";
    cin >> vt.soLuong;
    cout << "Nhap don vi: ";
    cin >> vt.donVi;
    cout << "Nhap don gia: ";
    cin >> vt.donGia;
}

void NhapDanhSachVatTu(DanhSachVatTu ds, int& n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vat tu thu " << i + 1 << ": ";
        NhapMotVatTu(ds[i]);
    }

    cout << endl << "Da nhap xong danh sach vat tu" << endl;
}

double TinhTongGia(DanhSachVatTu ds, int n, int x, int y)
{
    double tong = 0;

    for (int i = 0; i < n; i++)
    {
        if (ds[i].soLuong >= x && ds[i].soLuong <= y)
        {
            double gia = ds[i].donGia * ds[i].soLuong;
            tong += gia;
        }
    }

    return tong;
}

int TimViTriVatTu(DanhSachVatTu ds, int n, string maVT)
{
    int viTri = -1;

    for (int i = 0; i < n; i++)
    {
        if (ds[i].maVT == maVT)
        {
            viTri = i;
            break;
        }
    }

    return viTri;
}

void HoanVi(VatTu& a, VatTu& b)
{
    VatTu temp = a;
    a = b;
    b = temp;
}

void SapXepDanhSachVatTu(DanhSachVatTu ds, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool dieuKien1 = ds[i].donVi < ds[j].donVi;
            bool dieuKien2 = ds[i].donVi == ds[j].donVi && ds[i].soLuong > ds[j].soLuong;

            if (dieuKien1 || dieuKien2)
            {
                HoanVi(ds[i], ds[j]);
            }
        }
    }
}

void Xoa1VatTu(DanhSachVatTu ds, int& n, int viTri)
{
    for (int i = viTri; i < n - 1; i++)
    {
        ds[i] = ds[i + 1];
    }

    n--;
}

void XoaVatTu(DanhSachVatTu ds, int& n, double x)
{
    for (int i = 0; i < n; i++)
    {
        if (ds[i].donGia < x)
        {
            Xoa1VatTu(ds, n, i);
            i--;
        }
    }
}


void ChenVatTu(DanhSachVatTu ds, int& n, string maVT)
{
    int viTri = TimViTriVatTu(ds, n, maVT);
    if (viTri == -1)
    {
        cout << "Khong tim thay vat tu co ma " << maVT << endl;
        return;
    }

    VatTu vt;
    NhapMotVatTu(vt);

    for (int i = n; i > viTri; i--)
    {
        ds[i] = ds[i - 1];
    }

    ds[viTri] = vt;
    n++;
}

// ===== CAC HAM CON CHO THONG KE =====

// Tim vi tri don vi trong mang
// Tra ve vi tri neu tim thay, tra ve -1 neu khong tim thay
int TimViTriDonVi(string cacDonVi[], int soDonVi, string donViCanTim)
{
    for (int i = 0; i < soDonVi; i++)
    {
        if (cacDonVi[i] == donViCanTim)
        {
            return i;  // Tim thay, tra ve vi tri
        }
    }
    return -1;  // Khong tim thay
}

// Them don vi moi vao mang
void ThemDonViMoi(string cacDonVi[], int soLuongTheoDonVi[], int& soDonVi, string donViMoi)
{
    cacDonVi[soDonVi] = donViMoi;
    soLuongTheoDonVi[soDonVi] = 1;
    soDonVi++;
}

// Tang so luong tai vi tri cho truoc
void TangSoLuong(int soLuongTheoDonVi[], int viTri)
{
    soLuongTheoDonVi[viTri]++;
}

// Xuat dong tieu de bang thong ke
void XuatTieuDeThongKe()
{
    cout << endl;
    cout << "========== THONG KE VAT TU THEO DON VI TINH ==========" << endl;
    cout << setfill('-') << setw(40) << "-" << endl;
    cout << setfill(' ');
    cout << setiosflags(ios::left)
        << setw(20) << "Don vi tinh"
        << setw(20) << "So luong vat tu" << endl;
    cout << setfill('-') << setw(40) << "-" << endl;
    cout << setfill(' ');
}

// Xuat mot dong thong ke
void XuatMotDongThongKe(string donVi, int soLuong)
{
    cout << setiosflags(ios::left)
        << setw(20) << donVi
        << setw(20) << soLuong << endl;
}

// Xuat dong cuoi cung (tong ket)
void XuatChanThongKe(int soDonVi, int tongVatTu)
{
    cout << setfill('-') << setw(40) << "-" << endl;
    cout << "Tong cong: " << soDonVi << " loai don vi, " << tongVatTu << " vat tu." << endl;
}

// ===== HAM CHINH: IN BANG THONG KE =====
void InBangThongKe(DanhSachVatTu ds, int n)
{
    // Buoc 1: Khai bao mang luu ket qua thong ke
    string cacDonVi[MAX];
    int soLuongTheoDonVi[MAX];
    int soDonVi = 0;

    // Buoc 2: Duyet qua tung vat tu de thong ke
    for (int i = 0; i < n; i++)
    {
        string donVi = ds[i].donVi;

        // Tim xem don vi da ton tai chua
        int viTri = TimViTriDonVi(cacDonVi, soDonVi, donVi);

        if (viTri == -1)
        {
            // Chua co -> Them moi
            ThemDonViMoi(cacDonVi, soLuongTheoDonVi, soDonVi, donVi);
        }
        else
        {
            // Da co -> Tang so luong
            TangSoLuong(soLuongTheoDonVi, viTri);
        }
    }

    // Buoc 3: Xuat bang thong ke
    XuatTieuDeThongKe();

    for (int i = 0; i < soDonVi; i++)
    {
        XuatMotDongThongKe(cacDonVi[i], soLuongTheoDonVi[i]);
    }

    XuatChanThongKe(soDonVi, n);
}