#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <functional>
#include <string>
#include <fstream>
using namespace std;

struct SinhVien {
	char maSinhVien[30];
	char ten[30];
	char gioiTinh[5];
	int tuoi;
	float diemMon1;
	float diemMon2;
	float diemMon3;
	float diemTB;	
};


typedef SinhVien SV;
struct Node {
	SV data;
	Node* pNext;
};
typedef struct Node NODE;
struct list {
	NODE* pTruoc;
	NODE* pSau;
};
typedef struct list LIST;
void khoiTao(LIST& list);
int kiemTraRong(LIST list);
Node* taoNode(SinhVien tt);
void nhapSinhVien(LIST& list, int n);
void themCuoi(LIST& list, SinhVien tt);
void hienThiDanhSach(LIST list);
void sapXepDanhSach(LIST& list);
bool maSinhVien(SinhVien SV, SinhVien SV1);
bool ten(SinhVien SV, SinhVien SV1);
bool GioiTinh(SinhVien SV, SinhVien SV1);
bool tuoi(SinhVien SV, SinhVien SV1);
bool diemMon1(SinhVien SV, SinhVien SV1);
bool diemMon2(SinhVien SV, SinhVien SV1);
bool diemMon3(SinhVien SV, SinhVien SV1);
bool diemTB(SinhVien SV, SinhVien SV1);
Node* timKiem(LIST list, bool(*func)(SinhVien SV1, SinhVien SV2), SinhVien s);
void xoa_Dau(LIST& list);
void xoa_Cuoi(LIST& list);
void xoaNode(LIST& list, SinhVien maSV);
int ghiFile(LIST list);
void sapXepDanhSachDTB(LIST& list);
