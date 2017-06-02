#include <iostream>
using namespace std;

class arr {
public:
	arr(int a, float b) : i(a), f(b) {}
	arr() : i(0), f(0) {}

	friend ostream& operator << (ostream& out, const arr & a) {
		out << a.i << ' ' << a.f << endl;
		return out;
	}

	const arr& operator += (const arr& a) {
		i += a.i; f += a.f;
		return *this;
	}
	arr operator + (const arr& a) {
		int ii = i+a.i;
		float ff = f+a.f;
		return arr(ii, ff);
	}

	int i;
	float f;
};

int main() {
	arr a(1, 1.1), b(2, 2.2), c(3, 3.3), d;
	int i1 = 1, i2 = 2, i3 = 3, i4 = 0;
	d += a;
	d += b;
	d += c;
	cout << d << endl;
	cout << a+b+c << endl;
	return 0;
}
