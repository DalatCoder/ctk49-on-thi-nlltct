#include <iostream>

#include "thuvien.h"
#include "menu.h"

using namespace std;

int main()
{
    // khoi tao du lieu mau

    DanhSachVatTu ds = {
        {
            "VT001", "Vat tu 1", 10, "kg", 1000
        },
        {
            "VT002", "Vat tu 2", 20, "kg", 2000
        },
        {
            "VH001", "Vat tu 3", 30, "hop", 3000
        },
        {
            "VT004", "Vat tu 4", 40, "kg", 4000
        },
        {
            "VH002", "Vat tu 5", 50, "hop", 5000
        }
    };
    int soLuongVatTu = 5;


    ChayChuongTrinh(ds, soLuongVatTu);

    return 1;
}