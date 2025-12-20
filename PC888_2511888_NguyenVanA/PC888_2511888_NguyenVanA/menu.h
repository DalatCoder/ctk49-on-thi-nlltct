#include <iostream>
#include <conio.h>

using namespace std;

// prototypes => Nguyen mau ham
void XuatMenu();
int ChonMenu(int soMenuToiDa); 
void XuLyMenu(int luaChonMenu, DanhSachVatTu ds, int &n);
void ChayChuongTrinh(DanhSachVatTu ds, int &n);



// function definition => Dinh nghia ham

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


int ChonMenu(int soMenuToiDa)
{
    int menuDaChon = 0;

    cout << endl << "Nhap chuc nang mong muon: ";
    cin >> menuDaChon;

    return menuDaChon;
}


void XuLyMenu(int luaChonMenu, DanhSachVatTu ds, int& n)
{
    // khai bao 3 bien phuc vu chuc nang 3
    double x = 0;
    double y = 0;
    double tongGiaTriVatTu = 0;

    // khai bao 1 bien phuc vu chuc nang 4
    string maVatTuCanTim = "";
    int viTriVatTu = 0;

    switch (luaChonMenu)
    {
    case 1:
        // Nhap danh sach vat tu
        cout << endl << "=== 1. Nhap danh sach vat tu ===\n\n";

        // Nhap vao so luong mong muon
        cout << endl << "Nhap vao so luon vat tu can them: ";
        cin >> n;

        // Goi ham
        NhapDanhSachVatTu(ds, n);

        // In ket qua
        cout << endl << endl << "Da nhap xong danh sach vat tu";

        cout << endl << "=== Danh sach vat tu hien co ===\n\n";
        XuatDanhSachVatTu(ds, n);

        break;

    case 2:
        // Xuat danh sach vat tu
        cout << endl << "=== 2. Danh sach vat tu hien co ===\n\n";
        XuatDanhSachVatTu(ds, n);
        break;

    case 3:
        // Tinh tong gia cua vat tu co so luong trong [x, y]
        cout << endl << "=== 3. Tinh tong gia cua vat tu co so luong trong [x, y] ===\n\n";

        cout << endl << "Hay nhap x: ";
        cin >> x;

        cout << endl << "Hay nhap y: ";
        cin >> y;

        // Goi ham
        tongGiaTriVatTu = TinhTongGiaTri(ds, n, x, y);

        // In ket qua
        cout << endl << "Tong gia tri vat tu trong khoang tu [x, y] la: " << tongGiaTriVatTu << endl;

        break;

    case 4:
        // Tim vi tri vat tu theo ma
        cout << endl << "=== 4. Tim vi tri vat tu theo ma ===\n\n";

        cout << endl << "Hay nhap vao ma vat tu can tim: ";
        cin >> maVatTuCanTim;

        // Goi ham
        viTriVatTu = TimVatTuTheoMa(ds, n, maVatTuCanTim);

        // In ket qua
        if (viTriVatTu == -1)
        {
            cout << endl << endl << "Khong tim thay vat tu co ma " << maVatTuCanTim << endl;
        }
        else 
        {
            cout << endl << endl << "Tim thay vat tu tai vi tri " << viTriVatTu << endl;

            XuatMotVatTu(ds[viTriVatTu]);
            cout << endl;
        }

        break;

    case 5:
        // Sap xep danh sach
        break;

    case 6:
        // Xoa vat tu co don gia < x
        break;

    case 7:
        // Chen vat tu sau vat tu co ma cho truoc
        break;

    case 8:
        // In bang thong ke
        break;

    case 0:
        cout << endl << "Thoat khoi chuong trinh" << endl;
        break;

    default:
        cout << endl << "Lua chon khong hop le!" << endl;
        break;
    }
}


void ChayChuongTrinh(DanhSachVatTu ds, int& n)
{
    int soLuongMenuToiDa = 8;
    int menuNguoiDungChon = 0;

    while (true)
    {
        system("cls");

        XuatMenu();
        menuNguoiDungChon = ChonMenu(soLuongMenuToiDa);

        XuLyMenu(menuNguoiDungChon, ds, n);

        if (menuNguoiDungChon == 0)
        {
            break;
        }

        // dung chuong trinh de xem ket qua
        cout << endl << "hay nhap phim bat ky de tiep tuc" << endl;

        _getch();
        // system("pause");
    }
}