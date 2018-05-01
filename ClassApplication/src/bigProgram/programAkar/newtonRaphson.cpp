#include <stdio.h>
#include <stdlib.h>

float absolute(float);
float f(float);
float g(float);

int main() {

	float xold, xnew, toly, tolx;
	int k, p;

	do {
		system("CLS");

		printf("  Program Newton Raphson\n");
		printf("  Mencari akar dari suatu persamaan kuadrat menggunakan metode Newton Raphson.\n");
		printf("\n");
		printf("  Wafi Azmi Hartono / 1310171041\n");
		printf("  Dosen: Suhariningsih, S.ST., M.T.\n");
		printf("  ----------------------------------------------------------------------\n");
		printf("\n");
		printf("  Persamaan kuadrat: -2X^2 - 6X + 8.\n");
		printf("  Turunan persamaan: -4X - 6.\n");
		printf("\n");

		printf("  Masukkan perkiraan akar persamaan (xold)!\n");
		printf("  xold = ");
		scanf("%f", &xold);
		printf("\n");

		printf("  Masukkan toleransi y (toly)!\n");
		printf("  toly = ");
		scanf("%f", &toly);
		printf("\n");

		printf("  Masukkan toleransi x (tolx)!\n");
		printf("  tolx = ");
		scanf("%f", &tolx);
		printf("\n");

		printf("  Masukkan jumlah iterasi!\n");
		printf("  Iterasi = ");
		scanf("%d", &k);

		printf("   _______________________________________________________________________________________\n");
		printf("  | Iterasi |      xold      |      xnew      |       f(xold)       |       g(xold)       |\n");
		printf("  |---------|----------------|----------------|---------------------|---------------------|\n");
		for (int i = 1; i <= k; i++) {
			xnew = (xold - (f(xold) / g(xold)));

			printf("  | %7d | %14.8f | %14.8f | %19.8f | %19.8f |\n", i, xold, xnew, f(xold), g(xold));

			//if (f(xnew) == 0) {
			if ((absolute(xnew - xold) < tolx) && (absolute(f(xnew)) <= toly)) {
				i = k;
			} else {
				xold = xnew;
			}
		}
		printf("  |_________|________________|________________|_____________________|_____________________|\n");
		printf("\n");

		printf("  %.8f merupakan akar pendekatan dari persamaan kuadrat 3X^2 + 3X + 2.\n", xnew);
		printf("\n");

		printf("  Apakah Anda ingin mengulang program lagi? (1/2)\n  ");
		scanf("%d", &p);
	} while (p == 1);

	return 0;
}

float f(float x) {
	return (((-2) * (x * x)) - (6 * x) + 8);
}

float g(float x) {
	return ((-4) * x - 6);
}

float absolute(float v) {
	if (v <= 0) {
		return -v;
	} else {
		return v;
	}
}