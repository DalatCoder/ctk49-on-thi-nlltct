# 📚 Tài Liệu Ôn Tập Lập Trình C++
## Dựa trên dự án: Quản Lý Vật Tư

> **Mục đích**: Tài liệu này giải thích các khái niệm lập trình C++ cơ bản thông qua ví dụ thực tế từ dự án Quản Lý Vật Tư. Phù hợp cho sinh viên ôn thi cuối kỳ.

---

## Mục Lục

1. [Struct - Kiểu dữ liệu tự định nghĩa](#1-struct---kiểu-dữ-liệu-tự-định-nghĩa)
2. [Typedef - Đặt tên mới cho kiểu dữ liệu](#2-typedef---đặt-tên-mới-cho-kiểu-dữ-liệu)
3. [Mảng (Array)](#3-mảng-array)
4. [Hàm (Function)](#4-hàm-function)
5. [Tham trị vs Tham chiếu](#5-tham-trị-vs-tham-chiếu)
6. [Cấu trúc điều khiển](#6-cấu-trúc-điều-khiển)
7. [Thuật toán cơ bản](#7-thuật-toán-cơ-bản)
8. [Định dạng Input/Output](#8-định-dạng-inputoutput)
9. [Tổng kết các điểm cần nhớ](#9-tổng-kết-các-điểm-cần-nhớ)

---

## 1. Struct - Kiểu dữ liệu tự định nghĩa

### 📌 Khái niệm
**Struct** (cấu trúc) là cách để nhóm nhiều biến có liên quan lại với nhau thành một kiểu dữ liệu mới.

### 🎯 Ví dụ trong dự án

```cpp
struct VatTu
{
    string maVT;      // Mã vật tư
    string tenVT;     // Tên vật tư
    int soLuong;      // Số lượng
    string donVi;     // Đơn vị tính
    double donGia;    // Đơn giá
};
```

### 💡 Giải thích đơn giản

Hãy tưởng tượng bạn cần quản lý thông tin sinh viên. Thay vì tạo 5 biến riêng lẻ:
```cpp
string maSV;
string tenSV;
int tuoi;
// ... rất rối!
```

Bạn gói chúng lại thành 1 "hộp" gọi là struct:
```cpp
struct SinhVien {
    string maSV;
    string tenSV;
    int tuoi;
};
```

### ✅ Cách sử dụng

```cpp
// Khai báo 1 biến kiểu VatTu
VatTu vt1;

// Gán giá trị cho từng thành phần (dùng dấu chấm .)
vt1.maVT = "VT001";
vt1.tenVT = "Xi mang";
vt1.soLuong = 100;
vt1.donVi = "bao";
vt1.donGia = 85000;

// Hoặc khởi tạo ngắn gọn (dùng dấu ngoặc nhọn {})
VatTu vt2 = {"VT002", "Sat thep", 50, "kg", 25000};
```

### 🔑 Điểm cần nhớ
- Struct giúp **gom nhóm** các biến liên quan
- Truy cập thành phần bằng **dấu chấm (.)**: `vt.maVT`
- Mỗi thành phần có thể là bất kỳ kiểu dữ liệu nào

---

## 2. Typedef - Đặt tên mới cho kiểu dữ liệu

### 📌 Khái niệm
**Typedef** cho phép bạn đặt một **tên ngắn gọn** hơn cho một kiểu dữ liệu phức tạp.

### 🎯 Ví dụ trong dự án

```cpp
#define MAX 100

typedef VatTu DanhSachVatTu[MAX];
```

### 💡 Giải thích đơn giản

Thay vì viết dài dòng:
```cpp
VatTu mangVatTu[100];  // Mảng 100 phần tử kiểu VatTu
```

Bạn định nghĩa tên mới ngắn gọn hơn:
```cpp
typedef VatTu DanhSachVatTu[100];

// Bây giờ chỉ cần viết:
DanhSachVatTu ds;  // Tương đương VatTu ds[100]
```

### 🔑 Điểm cần nhớ
- Typedef không tạo kiểu mới, chỉ **đặt tên khác** cho kiểu có sẵn
- Giúp code **dễ đọc hơn**
- Thường dùng cho: mảng, con trỏ, struct phức tạp

---

## 3. Mảng (Array)

### 📌 Khái niệm
**Mảng** là tập hợp các phần tử **cùng kiểu dữ liệu**, được lưu trữ liên tiếp trong bộ nhớ. Mỗi phần tử có một **chỉ số** (index) để truy cập.

### 🎯 Ví dụ trong dự án

```cpp
#define MAX 100

typedef VatTu DanhSachVatTu[MAX];  // Mảng tối đa 100 vật tư

// Khởi tạo mảng với dữ liệu
DanhSachVatTu ds = {
    {"VT001", "Vat tu 1", 10, "kg", 10000},
    {"VT002", "Vat tu 2", 20, "kg", 20000},
    {"VT003", "Vat tu 3", 30, "kg", 30000}
};

int n = 3;  // Số phần tử thực tế trong mảng
```

### 💡 Hình dung mảng

```
Chỉ số:    0           1           2           3          ...
        ┌─────────┬─────────┬─────────┬─────────┬─────────┐
Mảng:   │  VT001  │  VT002  │  VT003  │  VT004  │   ...   │
        └─────────┴─────────┴─────────┴─────────┴─────────┘
```

> ⚠️ **Lưu ý quan trọng**: Chỉ số mảng bắt đầu từ **0**, không phải 1!

### ✅ Các thao tác với mảng

```cpp
// Truy cập phần tử (dùng dấu ngoặc vuông [])
VatTu vatTuDauTien = ds[0];      // Phần tử đầu tiên
VatTu vatTuThu3 = ds[2];         // Phần tử thứ 3

// Thay đổi giá trị
ds[0].soLuong = 999;

// Duyệt mảng bằng vòng lặp
for (int i = 0; i < n; i++) {
    cout << ds[i].tenVT << endl;
}
```

### 🔑 Điểm cần nhớ
- Chỉ số **bắt đầu từ 0**
- Cần biến `n` để lưu **số phần tử thực tế**
- Truy cập bằng **dấu ngoặc vuông []**: `ds[i]`

---

## 4. Hàm (Function)

### 📌 Khái niệm
**Hàm** là khối lệnh thực hiện một nhiệm vụ cụ thể. Giúp:
- Tái sử dụng code
- Chia nhỏ bài toán
- Dễ đọc và bảo trì

### 🎯 Cấu trúc hàm

```
KieuTraVe TenHam(ThamSo1, ThamSo2, ...)
{
    // Thân hàm - các lệnh thực thi
    return giaTriTraVe;  // (nếu có)
}
```

### 🎯 Các ví dụ trong dự án

#### Hàm không trả về giá trị (void)
```cpp
void XuatMotVatTu(VatTu vt)
{
    cout << vt.maVT << " - " << vt.tenVT << endl;
}
```

#### Hàm trả về giá trị
```cpp
double TinhTongGia(DanhSachVatTu ds, int n, int x, int y)
{
    double tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i].soLuong >= x && ds[i].soLuong <= y)
        {
            tong += ds[i].donGia * ds[i].soLuong;
        }
    }
    return tong;  // Trả về tổng giá
}
```

#### Hàm tìm kiếm (trả về int)
```cpp
int TimViTriVatTu(DanhSachVatTu ds, int n, string maVT)
{
    for (int i = 0; i < n; i++)
    {
        if (ds[i].maVT == maVT)
        {
            return i;  // Tìm thấy -> trả về vị trí
        }
    }
    return -1;  // Không tìm thấy -> trả về -1
}
```

### 🔑 Điểm cần nhớ
- `void`: hàm không trả về gì
- `return`: trả về kết quả và **kết thúc hàm ngay lập tức**
- Tên hàm nên **mô tả rõ** hàm làm gì

---

## 5. Tham trị vs Tham chiếu

### 📌 Đây là khái niệm QUAN TRỌNG nhất!

### 🎯 Tham trị (Pass by Value)

```cpp
void TangGia(double gia)  // Không có dấu &
{
    gia = gia + 1000;  // Chỉ thay đổi bản sao
}

// Sử dụng:
double donGia = 5000;
TangGia(donGia);
// donGia vẫn = 5000 (không đổi!)
```

**Giải thích**: Hàm nhận **bản sao** của biến. Thay đổi trong hàm **không ảnh hưởng** đến biến gốc.

### 🎯 Tham chiếu (Pass by Reference)

```cpp
void TangGia(double& gia)  // Có dấu &
{
    gia = gia + 1000;  // Thay đổi trực tiếp biến gốc
}

// Sử dụng:
double donGia = 5000;
TangGia(donGia);
// donGia = 6000 (đã thay đổi!)
```

**Giải thích**: Hàm nhận **tham chiếu** đến biến gốc. Thay đổi trong hàm **ảnh hưởng trực tiếp** đến biến gốc.

### 🎯 Ví dụ trong dự án

```cpp
// Dùng tham chiếu vì cần THAY ĐỔI n sau khi xóa
void Xoa1VatTu(DanhSachVatTu ds, int& n, int viTri)
{
    for (int i = viTri; i < n - 1; i++)
    {
        ds[i] = ds[i + 1];  // Dịch chuyển lên
    }
    n--;  // Giảm số lượng -> thay đổi n gốc
}

// Nhập vật tư - cần tham chiếu để lưu giá trị nhập vào
void NhapMotVatTu(VatTu& vt)
{
    cout << "Nhap ma vat tu: ";
    cin >> vt.maVT;  // Lưu vào vt gốc
    // ...
}
```

### 💡 Khi nào dùng tham chiếu?

| Tình huống | Dùng gì? |
|------------|----------|
| Chỉ **đọc** dữ liệu | Tham trị hoặc `const&` |
| Cần **thay đổi** biến gốc | Tham chiếu `&` |
| Muốn **tối ưu** (struct lớn) | Tham chiếu `const&` |

### 🔑 Điểm cần nhớ
- **Tham trị**: bản sao, không ảnh hưởng gốc
- **Tham chiếu** (`&`): trực tiếp, thay đổi gốc
- Xem dấu `&` trong tham số để biết loại nào

---

## 6. Cấu trúc điều khiển

### 🔀 Cấu trúc rẽ nhánh (if / else)

```cpp
int viTri = TimViTriVatTu(ds, n, maVT);

if (viTri == -1)
{
    cout << "Khong tim thay vat tu" << endl;
}
else
{
    cout << "Tim thay tai vi tri: " << viTri << endl;
    XuatMotVatTu(ds[viTri]);
}
```

### 🔀 Switch - Case

Dùng khi có **nhiều trường hợp** cần xét:

```cpp
switch (menu)
{
    case 1:
        NhapDanhSachVatTu(ds, n);
        break;  // QUAN TRỌNG: phải có break!

    case 2:
        XuatDanhSachVatTu(ds, n);
        break;

    case 0:
        cout << "Thoat chuong trinh" << endl;
        break;

    default:  // Trường hợp còn lại
        cout << "Lua chon khong hop le!" << endl;
        break;
}
```

> ⚠️ **Lưu ý**: Quên `break` sẽ chạy tiếp case bên dưới!

### 🔁 Vòng lặp for

```cpp
// Duyệt từ đầu đến cuối mảng
for (int i = 0; i < n; i++)
{
    XuatMotVatTu(ds[i]);
}
```

**Giải thích 3 phần của for:**
- `int i = 0`: Khởi tạo biến đếm
- `i < n`: Điều kiện lặp (còn đúng thì tiếp tục)
- `i++`: Tăng biến đếm sau mỗi vòng

### 🔁 Vòng lặp do-while

Khác với `while`, vòng `do-while` **chạy ít nhất 1 lần**:

```cpp
int menu;
do
{
    XuatMenu();
    cout << "Nhap lua chon: ";
    cin >> menu;
} while (menu < 0 || menu > 8);  // Lặp nếu nhập sai
```

### 🔑 Điểm cần nhớ
- `for`: biết trước số lần lặp
- `while`: lặp khi điều kiện đúng
- `do-while`: chạy ít nhất 1 lần
- `switch`: nhớ `break` sau mỗi case

---

## 7. Thuật toán cơ bản

### 🔍 7.1. Thuật toán Tìm kiếm tuyến tính

**Ý tưởng**: Duyệt từng phần tử từ đầu đến cuối, so sánh với giá trị cần tìm.

```cpp
int TimViTriVatTu(DanhSachVatTu ds, int n, string maVT)
{
    for (int i = 0; i < n; i++)           // Duyệt từng phần tử
    {
        if (ds[i].maVT == maVT)           // So sánh
        {
            return i;                      // Tìm thấy -> trả về vị trí
        }
    }
    return -1;                            // Không tìm thấy
}
```

**Độ phức tạp**: O(n) - tệ nhất phải duyệt hết mảng

---

### 📊 7.2. Thuật toán Sắp xếp (Interchange Sort)

**Ý tưởng**: So sánh từng cặp phần tử, hoán vị nếu sai thứ tự.

```cpp
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
            // Điều kiện: giảm theo đơn vị, tăng theo số lượng
            bool dieuKien1 = ds[i].donVi < ds[j].donVi;
            bool dieuKien2 = ds[i].donVi == ds[j].donVi 
                             && ds[i].soLuong > ds[j].soLuong;

            if (dieuKien1 || dieuKien2)
            {
                HoanVi(ds[i], ds[j]);
            }
        }
    }
}
```

**Minh họa hoán vị**:
```
Trước: a = 5, b = 3
       temp = 5
       a = 3
       b = 5
Sau:   a = 3, b = 5
```

---

### ❌ 7.3. Thuật toán Xóa phần tử

**Ý tưởng**: Dịch chuyển tất cả phần tử phía sau lên 1 vị trí, rồi giảm n.

```cpp
void Xoa1VatTu(DanhSachVatTu ds, int& n, int viTri)
{
    // Dịch các phần tử từ viTri+1 đến cuối lên 1 vị trí
    for (int i = viTri; i < n - 1; i++)
    {
        ds[i] = ds[i + 1];
    }
    n--;  // Giảm số lượng
}
```

**Minh họa xóa phần tử tại vị trí 1**:
```
Trước: [A] [B] [C] [D]     n = 4
             ↑ xóa

Dịch:  [A] [C] [D] [D]     (C,D dịch lên)

Sau:   [A] [C] [D]         n = 3
```

---

### ➕ 7.4. Thuật toán Chèn phần tử

**Ý tưởng**: Dịch các phần tử từ cuối về sau 1 vị trí, rồi chèn phần tử mới vào.

```cpp
void ChenVatTu(DanhSachVatTu ds, int& n, string maVT)
{
    int viTri = TimViTriVatTu(ds, n, maVT);
    if (viTri == -1)
    {
        cout << "Khong tim thay" << endl;
        return;
    }

    VatTu vt;
    NhapMotVatTu(vt);

    // Dịch các phần tử về sau (từ cuối lên)
    for (int i = n; i > viTri; i--)
    {
        ds[i] = ds[i - 1];
    }

    ds[viTri] = vt;  // Chèn vào vị trí
    n++;              // Tăng số lượng
}
```

**Minh họa chèn X vào vị trí 1**:
```
Trước: [A] [B] [C]         n = 3

Dịch:  [A] [B] [B] [C]     (B,C dịch xuống)

Chèn:  [A] [X] [B] [C]     n = 4
```

---

### 📈 7.5. Thuật toán Thống kê (Đếm)

**Ý tưởng**: Duyệt mảng, phân loại và đếm theo tiêu chí.

```cpp
void InBangThongKe(DanhSachVatTu ds, int n)
{
    string cacDonVi[MAX];       // Mảng lưu các đơn vị
    int soLuongTheoDonVi[MAX];  // Mảng đếm số lượng
    int soDonVi = 0;            // Số loại đơn vị

    for (int i = 0; i < n; i++)
    {
        string donVi = ds[i].donVi;
        int viTri = TimViTriDonVi(cacDonVi, soDonVi, donVi);

        if (viTri == -1)
        {
            // Chưa có -> Thêm mới
            cacDonVi[soDonVi] = donVi;
            soLuongTheoDonVi[soDonVi] = 1;
            soDonVi++;
        }
        else
        {
            // Đã có -> Tăng đếm
            soLuongTheoDonVi[viTri]++;
        }
    }

    // Xuất kết quả...
}
```

---

## 8. Định dạng Input/Output

### 📤 Các hàm định dạng output

```cpp
#include <iomanip>  // Thư viện định dạng
#include <ios>

// setw(n) - Đặt độ rộng cột (n ký tự)
cout << setw(15) << "Ten vat tu";

// setiosflags(ios::left) - Căn trái
cout << setiosflags(ios::left) << setw(15) << "Hello";

// setfill(c) - Điền ký tự c vào chỗ trống
cout << setfill('-') << setw(40) << "-";
// Kết quả: ----------------------------------------
```

### 🎯 Ví dụ xuất bảng đẹp

```cpp
void XuatDongTieuDe()
{
    cout << endl
        << setiosflags(ios::left)      // Căn trái
        << setw(15) << "Ma vat tu"     // Cột rộng 15
        << setw(15) << "Ten vat tu"
        << setw(15) << "So luong"
        << setw(15) << "Don vi"
        << setw(15) << "Don gia"
        << endl;
}
```

**Kết quả:**
```
Ma vat tu      Ten vat tu     So luong       Don vi         Don gia
===============================================================
VT001          Xi mang        100            bao            85000
VT002          Sat thep       50             kg             25000
```

---

## 9. Tổng kết các điểm cần nhớ

### 📝 Checklist ôn tập

| Khái niệm | Điểm quan trọng |
|-----------|-----------------|
| **Struct** | Gom nhóm biến, truy cập bằng `.` |
| **Typedef** | Đặt tên mới ngắn gọn cho kiểu dữ liệu |
| **Mảng** | Chỉ số từ 0, cần biến `n` lưu số phần tử |
| **Hàm void** | Không trả về, chỉ thực hiện công việc |
| **Hàm có return** | Trả về giá trị, kết thúc hàm ngay |
| **Tham trị** | Bản sao, không ảnh hưởng biến gốc |
| **Tham chiếu &** | Trực tiếp, thay đổi biến gốc |
| **for** | Dùng khi biết số lần lặp |
| **do-while** | Chạy ít nhất 1 lần |
| **switch** | Nhớ `break` sau mỗi case |

### 💡 Mẹo làm bài thi

1. **Đọc kỹ đề**: Xác định input, output, xử lý gì
2. **Vẽ mảng**: Minh họa trước khi code thuật toán
3. **Kiểm tra tham chiếu**: Hàm có cần thay đổi biến gốc không?
4. **Xem xét trường hợp đặc biệt**: Mảng rỗng, không tìm thấy,...
5. **Test với dữ liệu mẫu**: Chạy tay qua từng bước

### 🎯 Các lỗi thường gặp

1. Quên `&` khi cần tham chiếu
2. Truy cập mảng ngoài phạm vi
3. Quên `break` trong switch
4. Vòng lặp vô hạn (điều kiện sai)
5. Quên cập nhật `n` sau khi thêm/xóa

---

**Chúc bạn thi tốt! 🍀**
