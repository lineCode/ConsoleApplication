#include <string>
#include "getxy-custom.h"
#include "gotoxy-custom.h"

const char* formatCurrencyValue(unsigned long int);

int maina() {
	int xx, yy;

	printf("123456789\n");
	printf("123456789\n");
	xx = getx();
	yy = gety();
	printf("HERE56789\n");
	printf("123456789\n");
	printf("123456789\n");
	printf("%d %d\n", xx, yy);
	gotoxy(xx, yy);
	printf("REPLACED");
	gotoxy(1, 4);
	printf("HELLO");
	return 0;
}

const char* formatCurrencyValue(unsigned long int in) {
	std::string inS = std::to_string(in);
	int l = static_cast<int>(inS.length());

	unsigned long int r = l / 3;
	if (r != 0) {
		if (l % 3 == 0) r--;
		for (unsigned long int i = 1; i <= r; i++) {
			inS.insert(l - 3 * i, ".");
		}
	}
	char* value = new char[inS.length() + 1];
	strcpy(value, inS.c_str());
	return (value);
}