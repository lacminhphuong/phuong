#include"Header.h"


void khoiTao(LIST& list) {
	list.pTruoc = NULL;
	list.pSau = NULL;
}
int kiemTraRong(LIST list) {
	if (list.pTruoc == NULL) {
		return 1;
	}
	return 0;
}
//Tao node
Node* taoNode(SinhVien tt)
{
	Node* pNode = new Node;
	if (pNode != NULL)
	{
		pNode->data = tt;
		pNode->pNext = NULL;
	}
	else
	{
		cout << "\n  Cap phat bo nho that bai!";
	}
	return pNode;
}

void nhapSinhVien(LIST& list, int n)
{
	cout << "  Nhap so luong sinh vien muon them: ";
	cin >> n;
	cout << "\n  Nhap thong tin sinh vien";
	for (int i = 0; i < n; i++) {
		SV x;
		cin.ignore();
		cout << "\n  Nhap ma sinh vien: ";
		cin >> x.maSinhVien;
		cout << "  Nhap ten sinh vien: ";
		cin >> x.ten;
		cout << "  Nhap gioi tinh Nam hoac Nu: ";
		cin >> x.gioiTinh;
		cout << "  Nhap tuoi : ";
		cin >> x.tuoi;
		cout << "  Nhap diem Mon 1: ";
		cin >> x.diemMon1;
		cout << "  Nhap diem Mon 2: ";
		cin >> x.diemMon2;
		cout << "  Nhap diem Mon 3: ";
		cin >> x.diemMon3;
		cout << "  Diem Trung Binh la: " <<  (x.diemMon1 + x.diemMon2 + x.diemMon3)/3 << endl;
		NODE* p = new Node;
		p = taoNode(x);
		themCuoi(list, x);
		
	}
}
//Them node vao cuoi dslkd
void themCuoi(LIST& list, SinhVien tt)
{
	Node* pNode = taoNode(tt);
	if (list.pTruoc == NULL)
	{
		list.pTruoc = pNode;
	}
	else
	{
		Node* ptam = list.pTruoc;
		while (ptam->pNext != NULL)
		{
			ptam = ptam->pNext;
		}
		ptam->pNext = pNode; 
	}
}
//Hien thi dslkd
void hienThiDanhSach(LIST list)
{
	if (list.pTruoc == NULL)
	{
		cout << "Danh sach rong!";
		return;
	}
	Node* ptam = list.pTruoc;
	cout << "\n       Danh Sach Sinh Vien      ";
		while (ptam !=NULL)
	{
		cout << "\n  Ma Sinh Vien: " << ptam->data.maSinhVien;
		cout << "\n  Ten Sinh Vien: " << ptam->data.ten;
		cout << "\n  Gioi Tinh: " << ptam->data.gioiTinh;
		cout << "\n  Tuoi Sinh Vien: " << ptam->data.tuoi;
		cout << "\n  Diem Mon 1: " << ptam->data.diemMon1;
		cout << "\n  Diem Mon 2: " << ptam->data.diemMon2;
		cout << "\n  Diem Mon 3: " << ptam->data.diemMon3;
		cout << "\n  Diem Trung Binh: " <<   (ptam->data.diemMon1 + ptam->data.diemMon2 + ptam->data.diemMon3)/3 << endl;
		
		ptam = ptam->pNext;	
	}

}
//tim kiem sinh vien 
Node* timKiem(LIST list, bool(*func)(SinhVien SV1, SinhVien SV2), SinhVien s)
{
	Node* ptam = list.pTruoc;
	while (ptam != NULL)
	{
		if (func(ptam->data, s))
			break;
		ptam = ptam->pNext;
	}
	return ptam;
}

void xoa_Dau(LIST& list)
{
	Node* p;
	if (list.pTruoc != NULL) {
		p = list.pTruoc;
		list.pTruoc = p->pNext;
		delete p;
	}
}
void xoa_Cuoi(LIST& list)
{
	Node* p = list.pTruoc;
	Node* before = list.pTruoc;
	if (p->pNext == NULL) {
		delete p;
		list.pSau = NULL;
	}
	else {
		while (p->pNext != NULL) {
			before = p;
			p = p->pNext;
		}
		if (p->pNext == NULL) {
			delete p;
			before->pNext = NULL;
		}
	}
}

void xoaNode(LIST& list, SinhVien maSV)
{
	if (list.pTruoc == NULL)
	{
		cout << "\nDanh sach rong!";
	}
	else if (strcmp(list.pTruoc->data.maSinhVien, maSV.maSinhVien) == 0)
	{
		xoa_Dau(list);
		return;
	}
	else
	{
		NODE* c = new Node;
		for (Node* k = list.pTruoc; k != NULL; k = k->pNext)
		{
			if (strcmp(k->data.maSinhVien, maSV.maSinhVien) == 0)
			{
				if (k->pNext == NULL)
				{
					xoa_Cuoi(list);
					return;
				}
				c->pNext = k->pNext;
				delete k;
				return;
			}
			c = k;
		}

	}
}


// sapxepmsv
void sapXepDanhSach(LIST& list)
{
	Node* i = list.pTruoc;
	Node* j = i->pNext;
	while (i != NULL)
	{
		j = i->pNext;
		while (j != NULL)
		{
			if (strcmp(i->data.maSinhVien, j->data.maSinhVien) > 0)
			{
				swap(i->data, j->data);
			}
			j = j->pNext;
		}
		i = i->pNext;
	}
}
// sapxep diemtb
void sapXepDanhSachDTB(LIST& list) {
	Node* i = list.pTruoc;
	Node* j = i->pNext;
	while (i != NULL)
	{
		j = i->pNext;
		while (j != NULL)
		{
			if (((i->data.diemMon1 + i->data.diemMon2 + i->data.diemMon3) / 3) > ((j->data.diemMon1 + j->data.diemMon2 + j->data.diemMon3) / 3))
			{
				swap(i->data, j->data);
			}
			j = j->pNext;
		}
		i = i->pNext;
	}
}
bool maSinhVien(SinhVien SV, SinhVien SV1)
{
	if (strcmp(SV.maSinhVien, SV1.maSinhVien) == 0)
	{
		return true;
	}
	return false;
}
bool ten(SinhVien SV, SinhVien SV1)
{
	if (strcmp(SV.ten, SV1.ten) == 0)
	{
		return true;
	}
	return false;
}
bool GioiTinh(SinhVien SV, SinhVien SV1)
{
	if (strcmp(SV.gioiTinh, SV1.gioiTinh) == 0)
	{
		return true;
	}
	return false;
}
bool tuoi(SinhVien SV, SinhVien SV1)
{
	if (SV.tuoi == SV1.tuoi)
	{
		return true;
	}
	return false;
}
bool diemMon1(SinhVien SV, SinhVien SV1)
{
	if (SV.diemMon1 == SV1.diemMon1)
	{
		return true;
	}
	return false;
}
bool diemMon2(SinhVien SV, SinhVien SV1)
{
	if (SV.diemMon2 == SV1.diemMon2)
	{
		return true;
	}
	return false;
}
bool diemMon3(SinhVien SV, SinhVien SV1)
{
	if (SV.diemMon3 == SV1.diemMon3)
	{
		return true;
	}
	return false;
}
bool diemTB(SinhVien SV, SinhVien SV1)
{
	if (SV1.diemTB == SV1.diemTB)
	{
		return true;
	}
	return false;
}
int ghiFile(LIST list) {
	ofstream f;
	f.open("KetQua.txt", ios_base::out);
	if (f.fail())
		return 0;
	NODE* ptam = list.pTruoc;
	f << "\t\t\t BANG THONG KE " << endl;
	while (ptam != NULL)
	{
		f << "\n  Ma Sinh Vien: " << ptam->data.maSinhVien;
		f << "\n  Ten Sinh Vien: " << ptam->data.ten;
		f << "\n  Gioi Tinh: " << ptam->data.gioiTinh;
		f << "\n  Tuoi Sinh Vien: " << ptam->data.tuoi;
		f << "\n  Diem Mon 1: " << ptam->data.diemMon1;
		f << "\n  Diem Mon 2: " << ptam->data.diemMon2;
		f << "\n  Diem Mon 3: " << ptam->data.diemMon3;
		f << "\n  Diem Trung Binh: " << (ptam->data.diemMon1 + ptam->data.diemMon2 + ptam->data.diemMon3) / 3 << endl;
		ptam = ptam->pNext;
	}
	return 1;
	f.close();
}