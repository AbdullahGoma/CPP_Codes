#include <cstdio>
#include <utility>

using std::pair;

void cleanBuffer() {
	int c; while ((c = getchar()) != '\n' && c != EOF) {}
}

pair<int*, int*> getOperands();
void reduce(int [2]);
void operate(int);

int main() {
	char done = 'n';
	int choice = 0;
	
	do {
		printf("Supported operations:\n");
		printf("1. Add\n2. Sub\n3. Mul\n4. Div\n");
		printf("\nEnter choice:\n");
		
		if (scanf_s("%d", &choice) == 0) {
			cleanBuffer();
			printf("\nIllegal choice!\n\n");
			continue;
		}

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
			printf("\nIllegal choice!\n\n");
			continue;
		}

		operate(choice);
		
		printf("Are you done? (y or N): ");
		scanf_s("%c", &done, 1);
		printf("\n");

	} while (done != 'y' && done != 'Y');

	return 0;
}

pair<int*, int*> getOperands() {
	int* a = new int[2];
	int* b = new int[2];
	
	int val;
	printf("\n");

	for (int i = 0; i < 4; i++) {
		printf("Enter %c's %s: ", (i > 1) ? 'B' : 'A', (i % 2 == 0) ? "numerator" : "denominator");
		
		if (scanf_s("%d", &val) == 0) {
			cleanBuffer();
			printf("\nIllegal input!\n\n");
			i--;
			continue;
		}

		if (val == 0 && (i == 1 || i == 3)) {
			printf("\nIllegal input!\nDenominator can't be zero.\n\n");
			i--;
		}
		else if (i > 1) {
			b[i % 2] = val;
		}
		else {
			a[i] = val;
		}

		cleanBuffer();
	}

	return { a, b };
}

void reduce(int x[2]) {
	int gcd = 1;

	for (int i = 2; i <= x[0]; i++) {
		if (x[0] % i == 0 && x[1] % i == 0) gcd = i;
	}
	
	x[1] /= gcd;
	x[0] /= gcd;
}

void operate(int choice) {
	auto p = getOperands();
	auto a = p.first, b = p.second;
	
	char operation;
	int* c = new int[2];

	switch (choice) {
	case 1:
		c[0] = a[0] * b[1] + a[1] * b[0];
		c[1] = a[1] * b[1];
		operation = '+';
		break;

	case 2:
		c[0] = a[0] * b[1] - a[1] * b[0];
		c[1] = a[1] * b[1];
		operation = '-';
		break;

	case 3:
		c[0] = a[0] * b[0];
		c[1] = a[1] * b[1];
		operation = '*';
		break;

	default:
		c[0] = a[0] * b[1];
		c[1] = a[1] * b[0];
		operation = '/';

		if (c[1] == 0) {
			printf("Error: can't divide by 0\n");
			return;
		}
	}

	reduce(c);

	printf("\nResult:\n(%d/%d) %c (%d/%d) = %d/%d\n\n", a[0], a[1], operation, b[0], b[1], c[0], c[1]);

	delete[] a; delete[] b; delete[] c;
}