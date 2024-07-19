#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	int phanNguyen;
	int tuSo;
	int mauSo;
} HonSo;

void taoMangHonSo(HonSo b[], int n);
void xuatDanhSachHonSo(HonSo b[], int n);
HonSo soSanhHonSoVaTraVe(HonSo hs1, HonSo hs2);
HonSo chuyenHonSoSangPhanSo(HonSo hs);
HonSo chuyenPhanSoSangHonSo(int tuSo, int mauSo);
HonSo tongHonSo(HonSo hs1, HonSo hs2);
HonSo hieuHonSo(HonSo hs1, HonSo hs2);
HonSo tichHonSo(HonSo hs1, HonSo hs2);
HonSo thuongHonSo(HonSo hs1, HonSo hs2);
void sapXepInterchange(HonSo b[], int n, int tangDan);
void sapXepSelection(HonSo b[], int n);
void sapXepQuick(HonSo b[], int low, int high);
void sapXepHonSo(HonSo b[], int n, int tangDan);

int main() {
	srand((unsigned int)time(NULL));
	HonSo b[MAX_SIZE];
	int n, luaChon;

	printf("Nhap so phan tu (n <= %d): ", MAX_SIZE);
	scanf_s("%d", &n);

	do {
		printf("\nMenu:\n");
		printf("1. Tao mang hon so ngau nhien\n");
		printf("2. Xuat danh sach hon so\n");
		printf("3. So sanh hai hon so\n");
		printf("4. Chuyen hon so sang phan so\n");
		printf("5. Chuyen phan so sang hon so\n");
		printf("6. Tinh toan hai hon so\n");
		printf("7. Sap xep hon so\n");
		printf("0. Thoat\n");
		printf("Chon mot tuy chon: ");
		scanf_s("%d", &luaChon);

		switch (luaChon) {
		case 1:
			taoMangHonSo(b, n);
			printf("Mang hon so da duoc tao.\n");
			break;
		case 2:
			printf("Danh sach hon so:\n");
			xuatDanhSachHonSo(b, n);
			break;
		case 3: {
			int idx1, idx2;
			printf("Nhap chi so hon so 1: ");
			scanf_s("%d", &idx1);
			printf("Nhap chi so hon so 2: ");
			scanf_s("%d", &idx2);

			if (idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n) {
				HonSo ketQua = soSanhHonSoVaTraVe(b[idx1], b[idx2]);
				printf("Hon so lon hon la: %d %d/%d\n", ketQua.phanNguyen, ketQua.tuSo, ketQua.mauSo);
			}
			else {
				printf("Chi so khong hop le. Vui long nhap chi so tu 0 den %d.\n", n - 1);
			}
			break;
		}
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long thu lai.\n");
		}

	} while (luaChon != 0);

	return 0;
}

void taoMangHonSo(HonSo b[], int n) {
	for (int i = 0; i < n; i++) {
		b[i].phanNguyen = rand() % 10; // Phần nguyên từ 0 đến 9
		b[i].tuSo = rand() % 10 + 1;    // Tử số từ 1 đến 10
		b[i].mauSo = rand() % 9 + 2;     // Mẫu số khác 0 và từ 2 đến 10
	}
}

void xuatDanhSachHonSo(HonSo b[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d/%d ", b[i].phanNguyen, b[i].tuSo, b[i].mauSo);
	}
	printf("\n");
}

HonSo soSanhHonSoVaTraVe(HonSo hs1, HonSo hs2) {
	int phanSo1 = hs1.phanNguyen * hs1.mauSo + hs1.tuSo;
	int phanSo2 = hs2.phanNguyen * hs2.mauSo + hs2.tuSo;

	if (phanSo1 > phanSo2) {
		printf("Hon so 1 (%d %d/%d) > Hon so 2 (%d %d/%d)\n",
			hs1.phanNguyen, hs1.tuSo, hs1.mauSo,
			hs2.phanNguyen, hs2.tuSo, hs2.mauSo);
		return hs1;
	}
	else {
		printf("Hon so 2 (%d %d/%d) >= Hon so 1 (%d %d/%d)\n",
			hs2.phanNguyen, hs2.tuSo, hs2.mauSo,
			hs1.phanNguyen, hs1.tuSo, hs1.mauSo);
		return hs2;
	}
}