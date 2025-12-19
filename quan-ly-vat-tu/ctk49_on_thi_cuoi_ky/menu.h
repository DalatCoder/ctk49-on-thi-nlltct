#include <iostream>
#include <conio.h>  

using namespace std;

void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, DanhSachVatTu ds, int& n);
void ChayChuongTrinh(DanhSachVatTu ds, int& n);

void XuatMenu()
{
    cout << "\n\n";
    cout << "=========================== CHON CHUC NANG ===========================" << endl;
    cout << "1. Nhap danh sach vat tu" << endl;
    cout << "2. Xuat danh sach vat tu" << endl;
    cout << "3. Tinh tong gia cua tat ca vat tu co so luong in [x, y]" << endl;
    cout << "4. Tim vi tri vat tu theo ma vat tu" << endl;
    cout << "5. Sap xep danh sach vat tu giam theo don vi tinh, neu trung sap tang theo so luong" << endl;
    cout << "6. Xoa tat ca vat tu co don gia < x" << endl;
    cout << "7. Chen vat tu sau vat tu co ma vat tu y cho truoc" << endl;
    cout << "8. In bang thong ke so vat tu theo don vi tinh" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "======================================================================" << endl;
}

int ChonMenu(int soMenu)
{
    int menu;
    do
    {
        system("cls");

        XuatMenu();

        cout << "Nhap chuc nang: ";
        cin >> menu;
    } while (menu < 0 || menu > soMenu);

    return menu;
}

void XuLyMenu(int menu, DanhSachVatTu ds, int& n)
{
    int x, y;
    string maVT;
    double donGia;
    int viTri;
    double tongGia;

    switch (menu)
    {
    case 1:
        // Nhap danh sach vat tu
        cout << endl << "Nhap so luong vat tu: ";
        cin >> n;
        NhapDanhSachVatTu(ds, n);
        break;

    case 2:
        // Xuat danh sach vat tu
        XuatDanhSachVatTu(ds, n);
        break;

    case 3:
        // Tinh tong gia cua vat tu co so luong trong [x, y]
        cout << endl << "Nhap gia tri x: ";
        cin >> x;
        cout << "Nhap gia tri y: ";
        cin >> y;
        tongGia = TinhTongGia(ds, n, x, y);
        cout << endl << "Tong gia cua cac vat tu co so luong trong [" << x << ", " << y << "]: " << tongGia << endl;
        break;

    case 4:
        // Tim vi tri vat tu theo ma
        cout << endl << "Nhap ma vat tu can tim: ";
        cin >> maVT;
        viTri = TimViTriVatTu(ds, n, maVT);
        if (viTri == -1)
        {
            cout << endl << "Khong tim thay vat tu co ma: " << maVT << endl;
        }
        else
        {
            cout << endl << "Tim thay vat tu tai vi tri: " << viTri << endl;
            cout << "Thong tin vat tu:" << endl;
            XuatMotVatTu(ds[viTri]);
        }
        break;

    case 5:
        // Sap xep danh sach
        SapXepDanhSachVatTu(ds, n);
        cout << endl << "Da sap xep xong!" << endl;
        XuatDanhSachVatTu(ds, n);
        break;

    case 6:
        // Xoa vat tu co don gia < x
        cout << endl << "Nhap gia tri x (xoa vat tu co don gia < x): ";
        cin >> donGia;
        XoaVatTu(ds, n, donGia);
        cout << endl << "Da xoa xong! Danh sach con lai:" << endl;
        XuatDanhSachVatTu(ds, n);
        break;

    case 7:
        // Chen vat tu sau vat tu co ma cho truoc
        cout << endl << "Nhap ma vat tu can chen vao sau: ";
        cin >> maVT;
        ChenVatTu(ds, n, maVT);
        cout << endl << "Danh sach sau khi chen:" << endl;
        XuatDanhSachVatTu(ds, n);
        break;

    case 8:
        // In bang thong ke
        InBangThongKe(ds, n);
        break;

    case 0:
        cout << endl << "Thoat khoi chuong trinh" << endl;
        break;

    default:
        cout << endl << "Lua chon khong hop le!" << endl;
        break;
    }

    // Cho nhan phim truoc khi quay lai menu (tru truong hop thoat)
    if (menu > 0)
    {
        cout << endl << "Nhan phim bat ky de tiep tuc...";
        _getch();
    }
}

void ChayChuongTrinh(DanhSachVatTu ds, int& n)
{
    int menu;
    int soMenu = 8;

    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, ds, n);
    } while (menu > 0);
}