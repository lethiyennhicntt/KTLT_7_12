#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Hàm tạo ma trận với các phần tử ngẫu nhiên từ a đến b
void taoMaTran(int a[][MAX], int m, int n, int a_val, int b_val) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = a_val + rand() % (b_val - a_val + 1);
		}
	}
}

// Hàm xuất ma trận
void xuatMaTran(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm tính và xuất tổng giá trị từng dòng
void tongGiaTriTungDong(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
		printf("Tong gia tri dong %d: %d\n", i, sum);
	}
}

// Hàm xuất phần tử lớn nhất trên từng cột
void phanTuLonNhatTungCot(int a[][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		int max = a[0][j];
		for (int i = 1; i < m; i++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		printf("Phan tu lon nhat cot %d: %d\n", j, max);
	}
}

// Hàm xuất các phần tử thuộc các đường biên
void xuatDuongBien(int a[][MAX], int m, int n) {
	printf("Phan tu duong bien: ");
	for (int i = 0; i < n; i++) printf("%d ", a[0][i]); // Bien tren
	for (int i = 1; i < m; i++) printf("%d ", a[i][n - 1]); // Bien phai
	for (int i = n - 2; i >= 0; i--) printf("%d ", a[m - 1][i]); // Bien duoi
	for (int i = m - 2; i > 0; i--) printf("%d ", a[i][0]); // Bien trai
	printf("\n");
}

// Hàm kiểm tra phần tử có phải cực đại hay không
int laCucDai(int a[][MAX], int m, int n, int i, int j) {
	int di[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dj[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (int k = 0; k < 8; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] >= a[i][j]) {
			return 0;
		}
	}
	return 1;
}

// Hàm xuất các phần tử cực đại
void xuatCacPhanTuCucDai(int a[][MAX], int m, int n) {
	printf("Cac phan tu cuc dai: ");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laCucDai(a, m, n, i, j)) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm kiểm tra phần tử có phải hoàng hậu hay không
int laHoangHau(int a[][MAX], int m, int n, int i, int j) {
	// Kiểm tra các phần tử trong dòng và cột
	for (int k = 0; k < n; k++) {
		if (a[i][k] > a[i][j]) return 0;
	}
	for (int k = 0; k < m; k++) {
		if (a[k][j] > a[i][j]) return 0;
	}
	return 1;
}

// Hàm xuất các phần tử hoàng hậu
void xuatCacPhanTuHoangHau(int a[][MAX], int m, int n) {
	printf("Cac phan tu hoang hau: ");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laHoangHau(a, m, n, i, j)) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm kiểm tra phần tử có phải điểm yên ngựa hay không
int laDiemYenNgua(int a[][MAX], int m, int n, int i, int j) {
	int minRow = a[i][0];
	for (int k = 1; k < n; k++) {
		if (a[i][k] < minRow) minRow = a[i][k];
	}
	int maxCol = a[0][j];
	for (int k = 1; k < m; k++) {
		if (a[k][j] > maxCol) maxCol = a[k][j];
	}
	return (a[i][j] == minRow && a[i][j] == maxCol);
}

// Hàm xuất các phần tử là điểm yên ngựa
void xuatCacDiemYenNgua(int a[][MAX], int m, int n) {
	printf("Cac diem yen ngua: ");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laDiemYenNgua(a, m, n, i, j)) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

// Hàm xuất các dòng chỉ chứa số chẵn
void xuatDongChiChuaSoChan(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int soChan = 1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				soChan = 0;
				break;
			}
		}
		if (soChan) {
			printf("Dong %d chi chua so chan: ", i);
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

// Hàm sắp xếp mảng tăng dần theo từng dòng
void sapXepTangTheoDong(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i][j] > a[i][k]) {
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
}

int main()
{
	int m, n;
	printf("Nhap so dong m: ");
	scanf_s("%d", &m);
	printf("Nhap so cot n: ");
	scanf_s("%d", &n);

	int a[MAX][MAX];

	// Tạo ma trận với các phần tử ngẫu nhiên từ 0 đến 100
	taoMaTran(a, m, n, 0, 100);

	// Xuất ma trận
	printf("Ma tran a:\n");
	xuatMaTran(a, m, n);

	// Tính và xuất tổng giá trị từng dòng
	printf("\nTong gia tri tung dong:\n");
	tongGiaTriTungDong(a, m, n);

	// Xuất phần tử lớn nhất trên từng cột
	printf("\nPhan tu lon nhat tung cot:\n");
	phanTuLonNhatTungCot(a, m, n);

	// Xuất các phần tử thuộc các đường biên
	printf("\nPhan tu thuoc duong bien:\n");
	xuatDuongBien(a, m, n);

	// Xuất các phần tử cực đại
	printf("\nPhan tu cuc dai:\n");
	xuatCacPhanTuCucDai(a, m, n);

	// Xuất các phần tử hoàng hậu
	printf("\nPhan tu hoang hau:\n");
	xuatCacPhanTuHoangHau(a, m, n);

	// Xuất các phần tử là điểm yên ngựa
	printf("\nPhan tu diem yen ngua:\n");
	xuatCacDiemYenNgua(a, m, n);

	// Xuất các dòng chỉ chứa số chẵn
	printf("\nDong chi chua so chan:\n");
	xuatDongChiChuaSoChan(a, m, n);

	// Sắp xếp mảng tăng theo từng dòng
	printf("\nMang sau khi sap xep tang theo tung dong:\n");
	sapXepTangTheoDong(a, m, n);
	xuatMaTran(a, m, n);

	return 0;
}
