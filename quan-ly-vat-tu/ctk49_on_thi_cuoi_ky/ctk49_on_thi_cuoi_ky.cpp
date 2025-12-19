#include <iostream>

#include "thuvien.h"
#include "menu.h"

int main()
{
    DanhSachVatTu ds = {
        {
            "VT001", "Vat tu 1", 10, "kg", 10000
        },
        {
            "VT002", "Vat tu 2", 20, "kg", 20000
        },
        {
            "VT003", "Vat tu 3", 30, "kg", 30000
        },
        {
            "VT004", "Vat tu 4", 40, "kg", 40000
        },
        {
            "VT005", "Vat tu 5", 50, "kg", 50000
        }
    };

    int n = 5;
    ChayChuongTrinh(ds, n);

    return 1;
}