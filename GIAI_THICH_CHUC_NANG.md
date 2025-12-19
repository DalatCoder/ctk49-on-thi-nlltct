# 📖 Giải Thích Chi Tiết Các Chức Năng
## Chương trình: Quản Lý Vật Tư

> **Hướng dẫn đọc**: Tài liệu này giải thích từng chức năng trong chương trình một cách đơn giản, dễ hiểu. Mỗi chức năng được trình bày theo thứ tự: **Mục đích → Code → Giải thích từng dòng**.

---

## 📋 Mục Lục

1. [Tổng quan chương trình](#1-tổng-quan-chương-trình)
2. [Chức năng 1: Nhập danh sách vật tư](#2-chức-năng-1-nhập-danh-sách-vật-tư)
3. [Chức năng 2: Xuất danh sách vật tư](#3-chức-năng-2-xuất-danh-sách-vật-tư)
4. [Chức năng 3: Tính tổng giá](#4-chức-năng-3-tính-tổng-giá)
5. [Chức năng 4: Tìm vị trí vật tư](#5-chức-năng-4-tìm-vị-trí-vật-tư)
6. [Chức năng 5: Sắp xếp danh sách](#6-chức-năng-5-sắp-xếp-danh-sách)
7. [Chức năng 6: Xóa vật tư](#7-chức-năng-6-xóa-vật-tư)
8. [Chức năng 7: Chèn vật tư](#8-chức-năng-7-chèn-vật-tư)
9. [Chức năng 8: In bảng thống kê](#9-chức-năng-8-in-bảng-thống-kê)
10. [Hệ thống Menu](#10-hệ-thống-menu)

---

## 1. Tổng quan chương trình

### 🏗️ Cấu trúc dữ liệu

```cpp
struct VatTu
{
    string maVT;      // Mã vật tư (ví dụ: "VT001")
    string tenVT;     // Tên vật tư (ví dụ: "Xi măng")
    int soLuong;      // Số lượng (ví dụ: 100)
    string donVi;     // Đơn vị tính (ví dụ: "kg", "bao")
    double donGia;    // Đơn giá (ví dụ: 50000)
};

typedef VatTu DanhSachVatTu[MAX];  // Mảng chứa tối đa 100 vật tư
```

**Giải thích đơn giản:**
- `VatTu` giống như một **tấm thẻ thông tin** chứa 5 thông tin về một loại vật tư
- `DanhSachVatTu` là **tập hợp nhiều tấm thẻ** - có thể chứa đến 100 vật tư

### 🚀 Điểm bắt đầu (Hàm main)

```cpp
int main()
{
    // Tạo danh sách với 5 vật tư mẫu
    DanhSachVatTu ds = {
        {"VT001", "Vat tu 1", 10, "kg", 10000},
        {"VT002", "Vat tu 2", 20, "kg", 20000},
        {"VT003", "Vat tu 3", 30, "kg", 30000},
        {"VT004", "Vat tu 4", 40, "kg", 40000},
        {"VT005", "Vat tu 5", 50, "kg", 50000}
    };

    int n = 5;  // Số lượng vật tư ban đầu
    ChayChuongTrinh(ds, n);  // Bắt đầu chương trình

    return 1;
}
```

**Giải thích:**
- Chương trình bắt đầu bằng việc tạo sẵn **5 vật tư mẫu** để test
- Biến `n = 5` cho biết hiện tại có **5 vật tư** trong danh sách
- `ChayChuongTrinh()` là hàm điều khiển **toàn bộ chương trình**

---

## 2. Chức năng 1: Nhập danh sách vật tư

### 🎯 Mục đích
Cho phép người dùng **nhập thông tin** nhiều vật tư vào danh sách.

### 📝 Code và giải thích

#### Hàm nhập MỘT vật tư:

```cpp
void NhapMotVatTu(VatTu& vt)
{
    cout << "Nhap ma vat tu: ";      // Hiện dòng "Nhap ma vat tu: "
    cin >> vt.maVT;                   // Đọc và lưu mã vào vt.maVT

    cout << "Nhap ten vat tu: ";     // Hiện dòng "Nhap ten vat tu: "
    cin >> vt.tenVT;                  // Đọc và lưu tên vào vt.tenVT

    cout << "Nhap so luong: ";       // Hiện dòng "Nhap so luong: "
    cin >> vt.soLuong;                // Đọc và lưu số lượng

    cout << "Nhap don vi: ";         // Hiện dòng "Nhap don vi: "
    cin >> vt.donVi;                  // Đọc và lưu đơn vị

    cout << "Nhap don gia: ";        // Hiện dòng "Nhap don gia: "
    cin >> vt.donGia;                 // Đọc và lưu đơn giá
}
```

**Tại sao có dấu `&` trong `VatTu& vt`?**
- Dấu `&` nghĩa là **tham chiếu** (reference)
- Khi nhập dữ liệu, ta cần **lưu vào biến gốc** bên ngoài hàm
- Nếu không có `&`, dữ liệu chỉ lưu vào bản sao và sẽ **mất** khi hàm kết thúc

#### Hàm nhập DANH SÁCH vật tư:

```cpp
void NhapDanhSachVatTu(DanhSachVatTu ds, int& n)
{
    for (int i = 0; i < n; i++)           // Lặp n lần (mỗi lần nhập 1 vật tư)
    {
        cout << "Nhap vat tu thu " << i + 1 << ": ";  // In số thứ tự
        NhapMotVatTu(ds[i]);                           // Gọi hàm nhập 1 vật tư
    }

    cout << endl << "Da nhap xong danh sach vat tu" << endl;
}
```

**Giải thích từng dòng:**
| Dòng | Ý nghĩa |
|------|---------|
| `for (int i = 0; i < n; i++)` | Lặp từ 0 đến n-1 (tổng cộng n lần) |
| `i + 1` | Hiển thị số thứ tự thân thiện (1, 2, 3...) thay vì (0, 1, 2...) |
| `NhapMotVatTu(ds[i])` | Nhập thông tin cho vật tư thứ i trong mảng |

---

## 3. Chức năng 2: Xuất danh sách vật tư

### 🎯 Mục đích
**Hiển thị** toàn bộ danh sách vật tư ra màn hình dưới dạng **bảng đẹp**.

### 📝 Code và giải thích

#### Hàm xuất tiêu đề:

```cpp
void XuatDongTieuDe()
{
    cout << endl
        << setiosflags(ios::left)        // Căn lề trái
        << setw(15) << "Ma vat tu"       // Cột "Ma vat tu" rộng 15 ký tự
        << setw(15) << "Ten vat tu"      // Cột "Ten vat tu" rộng 15 ký tự
        << setw(15) << "So luong"        // Cột "So luong" rộng 15 ký tự
        << setw(15) << "Don vi"          // Cột "Don vi" rộng 15 ký tự
        << setw(15) << "Don gia"         // Cột "Don gia" rộng 15 ký tự
        << endl;
}
```

**Giải thích các lệnh định dạng:**
| Lệnh | Ý nghĩa |
|------|---------|
| `setiosflags(ios::left)` | Căn chữ về bên **trái** cột |
| `setw(15)` | Đặt độ rộng cột là **15 ký tự** |

**Kết quả hiển thị:**
```
Ma vat tu      Ten vat tu     So luong       Don vi         Don gia
```

#### Hàm xuất đường kẻ ngang:

```cpp
void XuatDongKeNgang()
{
    cout << setfill(' ')                           // Điền khoảng trống nếu thiếu
        << setw(15) << "==============="           // In 15 dấu = cho mỗi cột
        << setw(15) << "==============="
        << setw(15) << "==============="
        << setw(15) << "==============="
        << setw(15) << "==============="
        << endl;
}
```

#### Hàm xuất MỘT vật tư:

```cpp
void XuatMotVatTu(VatTu vt)
{
    cout << setiosflags(ios::left)       // Căn trái
        << setw(15) << vt.maVT           // In mã vật tư
        << setw(15) << vt.tenVT          // In tên vật tư
        << setw(15) << vt.soLuong        // In số lượng
        << setw(15) << vt.donVi          // In đơn vị
        << setw(15) << vt.donGia         // In đơn giá
        << endl;
}
```

#### Hàm xuất DANH SÁCH:

```cpp
void XuatDanhSachVatTu(DanhSachVatTu ds, int n)
{
    XuatDongTieuDe();      // 1. In tiêu đề
    XuatDongKeNgang();     // 2. In đường kẻ

    for (int i = 0; i < n; i++)     // 3. Duyệt từng vật tư
    {
        XuatMotVatTu(ds[i]);        //    In thông tin vật tư thứ i
    }

    XuatDongKeNgang();     // 4. In đường kẻ cuối
    cout << endl;
}
```

**Kết quả hiển thị:**
```
Ma vat tu      Ten vat tu     So luong       Don vi         Don gia
===============================================================
VT001          Vat tu 1       10             kg             10000
VT002          Vat tu 2       20             kg             20000
VT003          Vat tu 3       30             kg             30000
===============================================================
```

---

## 4. Chức năng 3: Tính tổng giá

### 🎯 Mục đích
Tính **tổng giá trị** của tất cả vật tư có số lượng nằm trong khoảng **[x, y]**.

### 📝 Code và giải thích

```cpp
double TinhTongGia(DanhSachVatTu ds, int n, int x, int y)
{
    double tong = 0;                          // Bước 1: Khởi tạo tổng = 0

    for (int i = 0; i < n; i++)               // Bước 2: Duyệt từng vật tư
    {
        if (ds[i].soLuong >= x && ds[i].soLuong <= y)    // Bước 3: Kiểm tra điều kiện
        {
            double gia = ds[i].donGia * ds[i].soLuong;   // Tính giá = đơn giá × số lượng
            tong += gia;                                  // Cộng dồn vào tổng
        }
    }

    return tong;                              // Bước 4: Trả về kết quả
}
```

### 💡 Minh họa bằng ví dụ

**Giả sử:** x = 15, y = 35 (tìm vật tư có số lượng từ 15 đến 35)

| Vật tư | Số lượng | Trong [15, 35]? | Giá trị |
|--------|----------|-----------------|---------|
| VT001 | 10 | ❌ Không (10 < 15) | - |
| VT002 | 20 | ✅ Có | 20 × 20000 = 400,000 |
| VT003 | 30 | ✅ Có | 30 × 30000 = 900,000 |
| VT004 | 40 | ❌ Không (40 > 35) | - |
| VT005 | 50 | ❌ Không (50 > 35) | - |

**Kết quả:** Tổng = 400,000 + 900,000 = **1,300,000**

---

## 5. Chức năng 4: Tìm vị trí vật tư

### 🎯 Mục đích
Tìm **vị trí** (index) của vật tư trong mảng dựa trên **mã vật tư**.

### 📝 Code và giải thích

```cpp
int TimViTriVatTu(DanhSachVatTu ds, int n, string maVT)
{
    int viTri = -1;                    // Giả sử chưa tìm thấy (đặt = -1)

    for (int i = 0; i < n; i++)        // Duyệt từng vật tư
    {
        if (ds[i].maVT == maVT)        // Nếu mã trùng khớp
        {
            viTri = i;                 // Lưu vị trí tìm thấy
            break;                     // Thoát vòng lặp ngay (không cần tìm tiếp)
        }
    }

    return viTri;                      // Trả về vị trí (hoặc -1 nếu không tìm thấy)
}
```

### 💡 Giải thích chi tiết

**Tại sao khởi tạo `viTri = -1`?**
- Vị trí trong mảng luôn >= 0 (0, 1, 2, ...)
- Nếu trả về **-1** nghĩa là **không tìm thấy**
- Đây là quy ước phổ biến trong lập trình

**Tại sao cần `break`?**
- Sau khi tìm thấy, không cần tiếp tục duyệt
- Giúp chương trình **chạy nhanh hơn**

### 💡 Minh họa bằng ví dụ

**Tìm** `maVT = "VT003"`:

```
i = 0: ds[0].maVT = "VT001" ≠ "VT003" → tiếp tục
i = 1: ds[1].maVT = "VT002" ≠ "VT003" → tiếp tục
i = 2: ds[2].maVT = "VT003" = "VT003" → TÌM THẤY! viTri = 2, break
```

**Kết quả:** Trả về **2** (vị trí thứ 3 trong mảng, đếm từ 0)

---

## 6. Chức năng 5: Sắp xếp danh sách

### 🎯 Mục đích
Sắp xếp danh sách theo 2 tiêu chí:
1. **Giảm dần** theo đơn vị tính (theo alphabet ngược: z → a)
2. Nếu **cùng đơn vị**: **tăng dần** theo số lượng

### 📝 Code và giải thích

#### Hàm hoán vị (đổi chỗ 2 phần tử):

```cpp
void HoanVi(VatTu& a, VatTu& b)
{
    VatTu temp = a;     // Bước 1: Lưu a vào biến tạm
    a = b;              // Bước 2: Gán giá trị b cho a
    b = temp;           // Bước 3: Gán giá trị tạm (a cũ) cho b
}
```

**Minh họa hoán vị:**
```
Trước:  a = "Táo",  b = "Cam"
        temp = "Táo"
        a = "Cam"
        b = "Táo"
Sau:    a = "Cam",  b = "Táo"
```

#### Hàm sắp xếp (Interchange Sort):

```cpp
void SapXepDanhSachVatTu(DanhSachVatTu ds, int n)
{
    for (int i = 0; i < n - 1; i++)              // Vòng lặp ngoài
    {
        for (int j = i + 1; j < n; j++)          // Vòng lặp trong
        {
            // Điều kiện 1: Đơn vị của ds[i] < ds[j] (cần đổi chỗ để giảm dần)
            bool dieuKien1 = ds[i].donVi < ds[j].donVi;

            // Điều kiện 2: Cùng đơn vị nhưng số lượng của ds[i] > ds[j]
            bool dieuKien2 = ds[i].donVi == ds[j].donVi 
                             && ds[i].soLuong > ds[j].soLuong;

            if (dieuKien1 || dieuKien2)          // Nếu 1 trong 2 điều kiện đúng
            {
                HoanVi(ds[i], ds[j]);            // Đổi chỗ 2 phần tử
            }
        }
    }
}
```

### 💡 Giải thích thuật toán Interchange Sort

**Ý tưởng:**
- So sánh từng cặp phần tử
- Nếu sai thứ tự → đổi chỗ
- Lặp lại cho đến khi mảng được sắp xếp

**Minh họa:**
```
Ban đầu: [kg, bao, kg, lit]
         
Vòng i=0: So sánh ds[0] với ds[1], ds[2], ds[3]
          kg < bao → đổi: [bao, kg, kg, lit]
          bao < lit → đổi: [lit, kg, kg, bao]
          
Vòng i=1: So sánh ds[1] với ds[2], ds[3]
          kg = kg → không đổi (cùng đơn vị, xét số lượng)
          kg < bao → đổi: [lit, bao, kg, kg]
          
Kết quả: [lit, kg, kg, bao] (giảm dần theo alphabet)
```

---

## 7. Chức năng 6: Xóa vật tư

### 🎯 Mục đích
Xóa tất cả vật tư có **đơn giá nhỏ hơn x**.

### 📝 Code và giải thích

#### Hàm xóa 1 vật tư tại vị trí cho trước:

```cpp
void Xoa1VatTu(DanhSachVatTu ds, int& n, int viTri)
{
    // Dịch chuyển các phần tử từ viTri+1 trở đi lên 1 vị trí
    for (int i = viTri; i < n - 1; i++)
    {
        ds[i] = ds[i + 1];    // Ghi đè phần tử hiện tại bằng phần tử kế tiếp
    }

    n--;    // Giảm số lượng phần tử đi 1
}
```

**Minh họa xóa phần tử tại vị trí 1:**
```
Trước:   [A] [B] [C] [D]     n = 4
              ↑ xóa

Dịch:    [A] [C] [C] [D]     (C ghi đè lên B)
         [A] [C] [D] [D]     (D ghi đè lên C cũ)

Sau:     [A] [C] [D]         n = 3
         (Phần tử D cuối cùng bị "bỏ quên", không truy cập nữa)
```

#### Hàm xóa nhiều vật tư theo điều kiện:

```cpp
void XoaVatTu(DanhSachVatTu ds, int& n, double x)
{
    for (int i = 0; i < n; i++)         // Duyệt từng vật tư
    {
        if (ds[i].donGia < x)           // Nếu đơn giá < x
        {
            Xoa1VatTu(ds, n, i);        // Xóa vật tư tại vị trí i
            i--;                         // QUAN TRỌNG: Lùi i lại 1 bước
        }
    }
}
```

**Tại sao cần `i--`?**

Sau khi xóa, các phần tử phía sau **dịch lên** 1 vị trí:
```
Trước xóa:  [A] [B] [C] [D]     i đang ở B
Sau xóa:    [A] [C] [D]         C dịch lên vị trí cũ của B

Nếu không i--: i tăng lên, bỏ qua C!
Có i--: i giữ nguyên, kiểm tra được C
```

---

## 8. Chức năng 7: Chèn vật tư

### 🎯 Mục đích
Chèn một vật tư mới **vào trước** vật tư có mã cho trước.

### 📝 Code và giải thích

```cpp
void ChenVatTu(DanhSachVatTu ds, int& n, string maVT)
{
    // Bước 1: Tìm vị trí vật tư cần chèn vào trước
    int viTri = TimViTriVatTu(ds, n, maVT);

    if (viTri == -1)    // Nếu không tìm thấy
    {
        cout << "Khong tim thay vat tu co ma " << maVT << endl;
        return;         // Kết thúc hàm, không làm gì thêm
    }

    // Bước 2: Nhập thông tin vật tư mới
    VatTu vt;
    NhapMotVatTu(vt);

    // Bước 3: Dịch các phần tử từ cuối về sau 1 vị trí
    for (int i = n; i > viTri; i--)
    {
        ds[i] = ds[i - 1];    // Gán phần tử trước cho vị trí sau
    }

    // Bước 4: Chèn vật tư mới vào vị trí trống
    ds[viTri] = vt;

    // Bước 5: Tăng số lượng
    n++;
}
```

**Minh họa chèn X vào vị trí 1:**
```
Trước:   [A] [B] [C]         n = 3
              ↑ chèn X vào đây

Dịch:    [A] [B] [B] [C]     (C dịch sang vị trí 3)
         [A] [B] [B] [C]     (B dịch sang vị trí 2)

Chèn:    [A] [X] [B] [C]     (X vào vị trí 1)
                             n = 4
```

**Lưu ý quan trọng:**
- Dịch **từ cuối lên** (i giảm dần) để không ghi đè dữ liệu
- Tăng `n` sau khi chèn xong

---

## 9. Chức năng 8: In bảng thống kê

### 🎯 Mục đích
Thống kê **số lượng vật tư** theo từng **đơn vị tính**.

### 📝 Code và giải thích - Các hàm phụ trợ

#### Tìm vị trí đơn vị trong mảng:

```cpp
int TimViTriDonVi(string cacDonVi[], int soDonVi, string donViCanTim)
{
    for (int i = 0; i < soDonVi; i++)
    {
        if (cacDonVi[i] == donViCanTim)
        {
            return i;    // Tìm thấy → trả về vị trí
        }
    }
    return -1;           // Không tìm thấy
}
```

#### Thêm đơn vị mới:

```cpp
void ThemDonViMoi(string cacDonVi[], int soLuongTheoDonVi[], 
                  int& soDonVi, string donViMoi)
{
    cacDonVi[soDonVi] = donViMoi;          // Lưu đơn vị mới
    soLuongTheoDonVi[soDonVi] = 1;         // Khởi tạo số lượng = 1
    soDonVi++;                              // Tăng số loại đơn vị
}
```

#### Tăng số lượng:

```cpp
void TangSoLuong(int soLuongTheoDonVi[], int viTri)
{
    soLuongTheoDonVi[viTri]++;    // Tăng đếm lên 1
}
```

### 📝 Hàm chính - In bảng thống kê:

```cpp
void InBangThongKe(DanhSachVatTu ds, int n)
{
    // Bước 1: Khai báo mảng lưu kết quả
    string cacDonVi[MAX];           // Mảng lưu tên các đơn vị
    int soLuongTheoDonVi[MAX];      // Mảng đếm số vật tư theo đơn vị
    int soDonVi = 0;                // Số loại đơn vị (ban đầu = 0)

    // Bước 2: Duyệt từng vật tư để thống kê
    for (int i = 0; i < n; i++)
    {
        string donVi = ds[i].donVi;

        // Tìm xem đơn vị này đã có trong mảng chưa
        int viTri = TimViTriDonVi(cacDonVi, soDonVi, donVi);

        if (viTri == -1)    // Chưa có → thêm mới
        {
            ThemDonViMoi(cacDonVi, soLuongTheoDonVi, soDonVi, donVi);
        }
        else                // Đã có → tăng đếm
        {
            TangSoLuong(soLuongTheoDonVi, viTri);
        }
    }

    // Bước 3: Xuất bảng thống kê
    XuatTieuDeThongKe();

    for (int i = 0; i < soDonVi; i++)
    {
        XuatMotDongThongKe(cacDonVi[i], soLuongTheoDonVi[i]);
    }

    XuatChanThongKe(soDonVi, n);
}
```

### 💡 Minh họa thống kê

**Dữ liệu đầu vào:**
```
VT001 - kg
VT002 - kg
VT003 - bao
VT004 - kg
VT005 - lit
```

**Quá trình duyệt:**
| Lần | Đơn vị | Tìm thấy? | Hành động |
|-----|--------|-----------|-----------|
| 1 | kg | Không (-1) | Thêm "kg", đếm = 1 |
| 2 | kg | Có (vị trí 0) | Tăng đếm tại 0 → đếm = 2 |
| 3 | bao | Không (-1) | Thêm "bao", đếm = 1 |
| 4 | kg | Có (vị trí 0) | Tăng đếm tại 0 → đếm = 3 |
| 5 | lit | Không (-1) | Thêm "lit", đếm = 1 |

**Kết quả:**
```
========== THONG KE VAT TU THEO DON VI TINH ==========
----------------------------------------
Don vi tinh         So luong vat tu
----------------------------------------
kg                  3
bao                 1
lit                 1
----------------------------------------
Tong cong: 3 loai don vi, 5 vat tu.
```

---

## 10. Hệ thống Menu

### 🎯 Mục đích
Điều khiển **luồng chạy** của chương trình, cho phép người dùng **chọn chức năng**.

### 📝 Hàm hiển thị menu:

```cpp
void XuatMenu()
{
    cout << "\n\n";
    cout << "=========================== CHON CHUC NANG ===========================" << endl;
    cout << "1. Nhap danh sach vat tu" << endl;
    cout << "2. Xuat danh sach vat tu" << endl;
    cout << "3. Tinh tong gia cua tat ca vat tu co so luong in [x, y]" << endl;
    cout << "4. Tim vi tri vat tu theo ma vat tu" << endl;
    cout << "5. Sap xep danh sach vat tu giam theo don vi tinh..." << endl;
    cout << "6. Xoa tat ca vat tu co don gia < x" << endl;
    cout << "7. Chen vat tu sau vat tu co ma vat tu y cho truoc" << endl;
    cout << "8. In bang thong ke so vat tu theo don vi tinh" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "======================================================================" << endl;
}
```

### 📝 Hàm chọn menu (có kiểm tra hợp lệ):

```cpp
int ChonMenu(int soMenu)
{
    int menu;
    do
    {
        system("cls");        // Xóa màn hình
        XuatMenu();           // Hiển thị menu
        cout << "Nhap chuc nang: ";
        cin >> menu;          // Đọc lựa chọn
    } while (menu < 0 || menu > soMenu);  // Lặp nếu nhập sai

    return menu;
}
```

**Giải thích:**
- `system("cls")`: Xóa màn hình console (Windows)
- `do-while`: Lặp cho đến khi người dùng nhập **đúng** (0 đến 8)

### 📝 Hàm xử lý menu:

```cpp
void XuLyMenu(int menu, DanhSachVatTu ds, int& n)
{
    switch (menu)
    {
        case 1:  NhapDanhSachVatTu(ds, n);           break;
        case 2:  XuatDanhSachVatTu(ds, n);           break;
        case 3:  /* Tính tổng giá */                 break;
        case 4:  /* Tìm vị trí */                    break;
        case 5:  SapXepDanhSachVatTu(ds, n);         break;
        case 6:  /* Xóa vật tư */                    break;
        case 7:  /* Chèn vật tư */                   break;
        case 8:  InBangThongKe(ds, n);               break;
        case 0:  cout << "Thoat chuong trinh";       break;
    }

    if (menu > 0)
    {
        cout << "\nNhan phim bat ky de tiep tuc...";
        _getch();    // Chờ người dùng nhấn phím
    }
}
```

### 📝 Hàm chạy chương trình chính:

```cpp
void ChayChuongTrinh(DanhSachVatTu ds, int& n)
{
    int menu;
    int soMenu = 8;    // Tổng số chức năng

    do
    {
        menu = ChonMenu(soMenu);     // Hiển thị menu và lấy lựa chọn
        XuLyMenu(menu, ds, n);       // Thực hiện chức năng được chọn
    } while (menu > 0);              // Tiếp tục cho đến khi chọn 0 (Thoát)
}
```

**Sơ đồ luồng chương trình:**
```
       ┌──────────────────────────────────┐
       │      ChayChuongTrinh()           │
       └──────────────┬───────────────────┘
                      │
       ┌──────────────▼───────────────────┐
       │         ChonMenu()               │
       │    - Xóa màn hình                │
       │    - Hiển thị menu               │
       │    - Đọc lựa chọn                │
       └──────────────┬───────────────────┘
                      │
       ┌──────────────▼───────────────────┐
       │         XuLyMenu()               │
       │    - switch theo lựa chọn        │
       │    - Gọi hàm xử lý tương ứng     │
       └──────────────┬───────────────────┘
                      │
           ┌──────────▼──────────┐
           │   menu > 0?         │
           └──────────┬──────────┘
              Có │          │ Không
                 │          │
        ┌────────▼────┐     │
        │ Quay lại    │     │
        │ ChonMenu()  │     │
        └─────────────┘     │
                            ▼
                     ┌──────────────┐
                     │   KẾT THÚC   │
                     └──────────────┘
```

---

## 📚 Tổng kết

| Chức năng | Thuật toán chính | Điểm cần nhớ |
|-----------|------------------|--------------|
| Nhập | Vòng lặp + tham chiếu | Dùng `&` để lưu dữ liệu |
| Xuất | Vòng lặp + định dạng | `setw()`, `setiosflags()` |
| Tính tổng | Tích lũy có điều kiện | Khởi tạo `tong = 0` |
| Tìm kiếm | Tìm tuyến tính | Trả về -1 nếu không thấy |
| Sắp xếp | Interchange Sort | 2 vòng lặp lồng nhau |
| Xóa | Dịch chuyển + giảm n | Nhớ `i--` khi xóa liên tiếp |
| Chèn | Dịch ngược + tăng n | Dịch từ cuối lên |
| Thống kê | Đếm + phân loại | 2 mảng song song |

---

**Chúc bạn học tốt và thi đạt điểm cao! 🎓**
