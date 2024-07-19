#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define _CRT_SECURE_NO_WARNINGS

void taoMangNgauNhien(int a[], int n, int k);
void taoMangChan(int a[], int n);
int timKiemTuLin(int a[], int n, int x);
void sapXepInterchange(int a[], int n, int tangDan);
void sapXepSelection(int a[], int n);
void sapXepQuick(int a[], int low, int high);
int timKiemNhiPhan(int a[], int n, int x);

int main() {
	srand((unsigned int)time(NULL));
	int a[MAX_SIZE];
	int n = rand() % (MAX_SIZE - 15) + 15; // So phan tu >= 15
	taoMangNgauNhien(a, n, 100); // Tao mang ngau nhien tu 0 den 100

	int luaChon, x, pos;

	do {
		printf("\nMenu:\n");
		printf("1. Tao mang mot chieu ngau nhien\n");
		printf("2. Tao mang chua toan so chan\n");
		printf("3. Tim kiem x trong a (Linear Search)\n");
		printf("4. Sap xep a (Interchange Sort)\n");
		printf("5. Tim kiem x trong a (Binary Search)\n");
		printf("6. Sap xep a (Selection Sort)\n");
		printf("7. Sap xep a (Quick Sort)\n");
		printf("0. Thoat\n");
		printf("Chon mot tuy chon: ");
		scanf_s("%d", &luaChon);

		switch (luaChon) {
		case 1:
			taoMangNgauNhien(a, n, 100);
			printf("Mang ngau nhien da duoc tao.\n");
			break;
		case 2:
			taoMangChan(a, n);
			printf("Mang chua toan so chan da duoc tao.\n");
			break;
		case 3:
			printf("Nhap so x: ");
			scanf_s("%d", &x);
			pos = timKiemTuLin(a, n, x);
			if (pos != -1) {
				printf("Tim thay %d tai vi tri %d.\n", x, pos);
			}
			else {
				printf("%d khong co trong mang.\n", x);
			}
			break;
		case 4:
			sapXepInterchange(a, n, 1);
			printf("Mang da duoc sap xep tang dan.\n");
			break;
		case 5:
			printf("Nhap so x: ");
			scanf_s("%d", &x);
			sapXepInterchange(a, n, 1); // Dam bao mang da duoc sap xep
			pos = timKiemNhiPhan(a, n, x);
			if (pos != -1) {
				printf("Tim thay %d tai vi tri %d.\n", x, pos);
			}
			else {
				printf("%d khong co trong mang.\n", x);
			}
			break;
		case 6:
			sapXepSelection(a, n);
			printf("Mang da duoc sap xep theo thu tu tang dan.\n");
			break;
		case 7:
			sapXepQuick(a, 0, n - 1);
			printf("Mang da duoc sap xep theo thu tu tang dan.\n");
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long thu lai.\n");
		}

	} while (luaChon != 0);

	return 0;
}

void taoMangNgauNhien(int a[], int n, int k) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (k + 1);
	}
}
void taoMangChan(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = (rand() % 50) * 2; // So chan tu 0 den 100
	}
}
int timKiemTuLin(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i; // Tra ve vi tri
		}
	}
	return -1; // Khong tim thay
}
void sapXepInterchange(int a[], int n, int tangDan) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((tangDan && a[i] > a[j]) || (!tangDan && a[i] < a[j])) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void sapXepSelection(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minIdx]) {
				minIdx = j;
			}
		}
		int temp = a[i];
		a[i] = a[minIdx];
		a[minIdx] = temp;
	}
}
int timKiemNhiPhan(int a[], int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (a[mid] == x) {
			return mid;
		}
		if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1; // Khong tim thay
}
void sapXepQuick(int a[], int low, int high) {
	if (low < high) {
		int pivot = a[high];
		int i = low - 1;
		for (int j = low; j < high; j++) {
			if (a[j] < pivot) {
				i++;
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		int temp = a[i + 1];
		a[i + 1] = a[high];
		a[high] = temp;
		sapXepQuick(a, low, i);
		sapXepQuick(a, i + 2, high);
	}
}