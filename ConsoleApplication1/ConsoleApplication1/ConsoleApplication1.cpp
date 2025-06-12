#include <stdio.h>

typedef struct {
	int numerator;
	int denominator;
}Fraction;

Fraction read() {
	Fraction f;
	scanf("%d %d", &f.numerator, &f.denominator);
	return f;
}

void print(Fraction a) {
	printf("%d/%d\n", a.numerator, a.denominator);
}

Fraction add(Fraction a, Fraction b) {
	Fraction f;
	f.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	f.denominator = a.denominator * b.denominator;
	return f;
}

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void reduce(Fraction* a) {
	int divisor = gcd(a->numerator, a->denominator);
	a->numerator /= divisor;
	a->denominator /= divisor;
}

void normalize(Fraction* a) {
	int x = a->numerator, y = a->denominator;
	while (y != 0) {
		int temp = y;
		y = x % y;
		temp = x;
	}
	int gcd = x;
	a->numerator /= gcd;
	a->denominator /= gcd;
}

Fraction subtract(Fraction a, Fraction b) {
	Fraction f;
	f.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	f.denominator = a.denominator * b.denominator;
	int divisor = gcd(f.numerator, f.denominator);
	f.numerator /= divisor;
	f.denominator /= divisor;

	if (f.denominator < 0) {
		f.numerator = -f.numerator;
		f.denominator = -f.denominator;
	}
	return f;
}

Fraction multiply(Fraction a, Fraction b) {
	Fraction f;
	f.numerator = a.numerator * b.numerator;
	f.denominator = a.denominator * b.denominator;
	int divisor = gcd(f.numerator, f.denominator);
	f.numerator /= divisor;
	f.denominator /= divisor;

	if (f.denominator < 0) {
		f.numerator = -f.numerator;
		f.denominator = -f.denominator;
	}
	return f;
}

Fraction divide(Fraction a, Fraction b) {
	Fraction f;
	f.numerator = a.numerator * b.denominator;
	f.denominator = a.denominator * b.numerator;
	int divisor = gcd(f.numerator, f.denominator);
	f.numerator /= divisor;
	f.denominator /= divisor;

	if (f.denominator < 0) {
		f.numerator = -f.numerator;
		f.denominator = -f.denominator;
	}
	return f;
}