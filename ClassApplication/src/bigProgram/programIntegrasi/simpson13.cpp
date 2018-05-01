#include <stdio.h>
#include <stdlib.h>
#include "gotoxy-custom.h"
#include "getxy-custom.h"

float absolute(float);
float f(float);

int main() {

	float a, as, b, h, ai, e, ei, asi, A;
	int n, p, cursorY;

	do {
		system("CLS");

		printf("  Program Simpson 1/3\n");
		printf("  Mencari luas suatu area yang dibatasi oleh suatu fungsi f(x), sumbu x,\n");
		printf("  garis x = a dan garis x = b dengan menggunakan metode Simpson 1/3.\n");
		printf("\n");
		printf("  Wafi Azmi Hartono / 1310171041\n");
		printf("  Dosen: Suhariningsih, S.ST., M.T.\n");
		printf("  ----------------------------------------------------------------------\n");
		printf("\n");
		printf("  Fungsi f(x) = -2X^2 - 6X + 8.\n");
		printf("\n");

		printf("  Masukkan batasan:\n");
		printf("  1. Garis x = a = ");
		scanf("%f", &a);
		printf("  2. Garis y = b = ");
		scanf("%f", &b);
		printf("\n");

		printf("  Masukkan jumlah pias (n)! (Harus genap)\n");
		printf("  n = ");
		scanf("%d", &n);
		printf("\n");
		h = (b - a) / n;

		printf("  Masukkan nilai luas yang dihitung menggunakan integral murni (as)!\n");
		printf("  as = ");
		scanf("%f", &as);
		printf("\n");

		printf("   _____________________________________________________________________________\n");
		printf("  | Iterasi |        Luas tiap 2 pias         |   Luas sampai  |  Error setiap  |\n");
		printf("  |         | Integral Murni | M. Simpson 1/3 |   iterasi ke-  |      pias      |\n");
		printf("  |---------|----------------|----------------|----------------|----------------|\n");
		e = 0; A = 0;
		for (int i = 1; i <= n / 2; i++) {
			cursorY = gety();
			printf("  | %7d | ", i);
			scanf("%f", &asi);

			ai = (h * (f(a + (i - 1) * h * 2) + 4 * f(a + (2 * i - 1) * h) + f(a + 2 * i * h))) / 3;
			ai = absolute(ai);
			A += ai;
			ei = absolute(asi - ai);
			e += ei;

			gotoxy(1, cursorY);
			printf("  | %7d | %14.5f | %14.5f | %14.5f | %14.5	f |\n", i, asi, ai, A, ei);
		}
		printf("  |_________|________________|________________|________________|________________|\n");
		printf("\n");

		printf("  Luas yang dihitung menggunakan metode simpson 1/3 adalah %f\n", A);
		printf("  Error luas adalah %f\n", e);
		printf("\n");
		
		printf("  Apakah Anda ingin mengulang program lagi? (1/2)\n  ");
		scanf("%d", &p);
	} while (p == 1);

	return 0;
}

float f(float x) {
	return ((-2 * (x * x)) - (6 * x) + 8);
}

float absolute(float v) {
	if (v <= 0) {
		return -v;
	} else {
		return v;
	}
}