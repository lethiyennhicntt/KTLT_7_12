#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Hàm tạo ma trận vuông với các phần tử ngẫu nhiên từ a đến b
void taoMaTranVuong(int a[][MAX], int n, int a_val, int b_val) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = a_val + rand() % (b_val - a_val + 1);
		}
	}
}

// Hàm xuất ma trận
void xuatMaTran(int a[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm xuất các phần tử trên đường chéo chính
void xuatDuongCheoChinh(int a[][MAX], int n) {
	printf("Cac phan tu tren duong cheo chinh: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i][i]);
	}
	printf("\n");
}

// Hàm xuất các phần tử thuộc đường chéo song song với đường chéo chính
void xuatDuongCheoSongSong(int a[][MAX], int n) {
	printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
	// Các đường chéo trên đường chéo chính
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n - k; i++) {
			printf("%d ", a[i][i + k]);
		}
		printf("\n");
	}
	// Các đường chéo dưới đường chéo chính
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n - k; i++) {
			printf("%d ", a[i + k][i]);
		}
		printf("\n");
	}
}
// Hàm tìm phần tử max thuộc tam giác trên của đường chéo chính
void maxTamGiacTrenDuongCheoChinh(int a[][MAX], int n) {
	int max = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	printf("Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", max);
}

// Hàm sắp xếp đường chéo chính tăng dần từ trên xuống dưới
void sapXepDuongCheoChinh(int a[][MAX], int n) {
	// Sử dụng thuật toán sắp xếp nổi bọt (Bubble Sort)
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][i] > a[j][j]) {
				int temp = a[i][i];
				a[i][i] = a[j][j];
				a[j][j] = temp;
			}
		}
	}
}

int main() {
	int n;
	printf("Nhap cap cua ma tran vuong (n >= 5): ");
	scanf_s("%d", &n);
	if (n < 5) {
		printf("Cap cua ma tran phai >= 5\n");
		return 1;
	}

	int a[MAX][MAX];

	// Tạo ma trận vuông với các phần tử ngẫu nhiên từ 0 đến 100
	taoMaTranVuong(a, n, 0, 100);

	// Xuất ma trận
	printf("Ma tran vuong a:\n");
	xuatMaTran(a, n);

	// Xuất các phần tử trên đường chéo chính
	printf("\n");
	xuatDuongCheoChinh(a, n);

	// Xuất các phần tử thuộc đường chéo song song với đường chéo chính
	printf("\n");
	xuatDuongCheoSongSong(a, n);

	// Tìm phần tử max thuộc tam giác trên của đường chéo chính
	printf("\n");
	maxTamGiacTrenDuongCheoChinh(a, n);

	// Sắp xếp đường chéo chính tăng dần từ trên xuống dưới
	printf("\nSap xep duong cheo chinh tang dan:\n");
	sapXepDuongCheoChinh(a, n);
	xuatMaTran(a, n);

	return 0;
}
