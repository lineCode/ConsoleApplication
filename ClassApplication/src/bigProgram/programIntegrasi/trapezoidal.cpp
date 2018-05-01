#include <stdio.h>
#include <stdlib.h>

float absolute(float);
float f(float);
float g(float);

int main() {

	float a, as, b, h, ak, e, ek, ask[100], A;
	int n, p;

	do {
		system("CLS");

		printf("  Program Trapezoidal\n");
		printf("  Mencari luas suatu area yang dibatasi oleh suatu fungsi f(x), sumbu x,\n");
		printf("  garis x = a dan garis x = b.\n");
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

		printf("  Masukkan jumlah pias (n)!\n");
		printf("  n = ");
		scanf("%d", &n);
		printf("\n");
		h = (b - a) / n;

		printf("  Masukkan nilai luas yang dihitung menggunakan integral murni (as)!\n");
		printf("  as = ");
		scanf("%f", &as);
		printf("\n");

		printf("  Masukkan nilai luas untuk setiap pias,  dengan nilai didapatkan melalui cara integral murni!\n");
		for (int i = 1; i <= n; i++) {
			printf("  Luas pias ke-%d = ", i);
			ask[i - 1] = 0;
			scanf("%f", &ask[i - 1]);
		}

		printf("   _____________________________________________________________________________\n");
		printf("  | Iterasi |          Luas tiap pias         |   Luas sampai  |  Error setiap  |\n");
		printf("  |         | Integral Murni | I. Trapezoidal |   iterasi ke-  |      pias      |\n");
		printf("  |---------|----------------|----------------|----------------|----------------|\n");
		e = 0;
		A = 0;
		for (int i = 1; i <= n; i++) {

			ak = (h * (f(a + (i - 1) * h) + f(a + i * h))) / 2;
			A += ak;
			ek = absolute(ask[i - 1] - ak);
			e += ek;
			printf("  | %7d | %14.3f | %14.3f | %14.3f | %14.3f |\n", i, ask[i - 1], ak, A, ek);
		}
		printf("  |_________|________________|________________|________________|________________|\n");
		printf("\n");

		printf("  Luas dari area tersebut yang dihitung menggunakan integral metode trapezoidal adalah %f\n", A);
		printf("\n");
		printf("  Error dari perhitungan luas metode trapezoidal jika dibandingkan dengan integral murni adalah %.3f %%\n", e);
		printf("\n");
		
		printf("  Apakah Anda ingin mengulang program lagi? (1/2)\n  ");
		scanf("%d", &p);
	} while (p == 1);

	return 0;
}

float f(float x) {
	return ((x * x)) - (6 * x) + 5;
}

float absolute(float v) {
	if (v <= 0) {
		return -v;
	} else {
		return v;
	}
}