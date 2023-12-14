#include"Header.h"
int main()
{
	LIST list;
	list.pTruoc = NULL;
	int n = 0, m;
	int chon;
	SinhVien kQua;
	cout << "\n              Truong Dai Hoc Cong Nghe Sai Gon                ";
	cout << "\n                     Do An Tin Hoc                            ";
	cout << "\n            Ten Chuong Trinh: Quan Li Sinh Vien               ";
	cout << "\n";
	cout << "\n  Thay Huong Dan: Huynh Quang Duc";
	cout << "\n  Sinh Vien Thuc Hien: Lac Minh Phuong D20-Th04";
	cout << "\n  Menu Thuc Hien Cac Chuc Nang Quan Li Sinh Vien C/C++";
	cout << "\n";
	cout << "\n  *************************MENU****************************** ";
	cout << "\n  **        1. Them sinh vien                              ** ";
	cout << "\n  **        2. Xoa thong tin sinh vien                     ** ";
	cout << "\n  **        3. Hien thi danh sach tat sinh vien            ** ";
	cout << "\n  **        4. Sap Xep Ma Sinh Vien theo tu nho den lon    ** ";
	cout << "\n  **        5. Sap xep theo DTB tang dan                   ** ";
	cout << "\n  **        6. Tim kiem sinh vien                          ** ";
	cout << "\n  **               Tim kiem sinh vien theo ten             ** ";
	cout << "\n  **               Tim kiem sinh vien tuoi                 ** ";
	cout << "\n  **               Tim kiem sinh vien gioi tinh            ** ";
	cout << "\n  **               Tim kiem sinh vien theo diem trung binh ** ";
	cout << "\n  **        7. ghi File                                    ** ";
	cout << "\n  **        0. Thoat                                       ** ";
	cout << "\n  **                                                       ** ";
	cout << "\n  *********************************************************** ";
	cout << "\n";
	cout << "\n                   Nhap So Ban Muon Chon ";
	do
	{
		
		cin >> chon;
		string ten_str;
		SinhVien SV1;
		int n = 0;
		switch (chon) {
		case 1:
			nhapSinhVien(list, n);
			break;
		case 2:
			cout << "\n  Nhap ma sinh vien can xoa: ";
			cin >> SV1.maSinhVien;
			xoaNode(list, SV1);
			break;
		case 3:
			hienThiDanhSach(list);
			break;
		case 4 : 
				cout << "\n Danh Sach Sau khi Sap Xep Ma Sinh Vien";
				sapXepDanhSach(list);
				hienThiDanhSach(list);
				break;
		case 5:
				cout << "\n Danh Sach Sau khi sap xep diem trung binh theo thu tu tang dan";
				sapXepDanhSach(list);
				hienThiDanhSach(list);
				break;
		case 6:
			cout << "\n1) Tim kiem theo Ma Sinh Vien: ";
			cout << "\n2) Tim kiem theo ten: ";
			cout << "\n3) Tim kiem theo Tuoi: ";
			cout << "\n4) Tim kiem theo Gioi Tinh: ";
			cout << "\n5) Tim kiem theo Diem Trung Binh: ";
			cout << "\nBan muon tim kiem thong tin gi?" << endl;
			cin >> m;
			switch (m)
			{
			case 1:
				cout << "\nNhap Ma Sinh Vien Can Tim:" << endl;
				cin >> kQua.maSinhVien;
				if (timKiem(list,maSinhVien ,kQua) == NULL)
					cout << "\nKhong tim thay!" << endl;
				else
					cout << "\nTim thay Sinh Vien !" << endl;
				break;
			case 2:
				cout << "\nNhap Tuoi Sinh Vien Can Tim:" << endl;
				cin >> kQua.tuoi;
				if (timKiem(list, tuoi, kQua) == NULL)
					cout << "\nKhong tim thay!" << endl;
				else
					cout << "\nTim thay Sinh Vien !" << endl;
				break;
			case 3:
				cout << "\nNhap Gioi Tinh Sinh Vien Can Tim:" << endl;
				cin >> kQua.gioiTinh;
				if (timKiem(list, GioiTinh, kQua) == NULL)
					cout << "\nKhong tim thay!" << endl;
				else
					cout << "\nTim thay Sinh Vien !" << endl;
				break;
			}

		case 7:
			ghiFile(list);
			cout << "\nThong ke da duoc ghi lai";
			break;
		}
	} while (chon != 0);
     return 0;
	 system("pause");
}


