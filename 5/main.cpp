#include <iostream>
#include <math.h>

using namespace std;

class tre {
protected:
	double A, B, C;
	double a, b, c;
public:
	tre() {
		this->A = 1;
		this->B = 1;
		this->C = 1;

		a = acos((B * B + C * C - A * A) / (2 * B * C));
		b = acos((A * A + C * C - B * B) / (2 * A * C));
		c = acos((A * A + B * B - C * C) / (2 * A * B));
	}
	tre(double A, double B, double C) {
		this->A = A;
		this->B = B;
		this->C = C;

		a = acos((B * B + C * C - A * A) / (2 * B * C));
		b = acos((A * A + C * C - B * B) / (2 * A * C));
		c = acos((A * A + B * B - C * C) / (2 * A * B));
	}

	bool is() {
		return (A + B > C && A + C > B && B + C > A);
	}

	double P() {
		return A + B + C;
	}

	double S() {
		return 0.5 * A * B * sin(c);
	}

	void print() {
		cout << "tre:\n"
			<< "\tA: " << A << "\n"
			<< "\tB: " << B << "\n"
			<< "\tC: " << C << "\n"
			<< "\ta: " << a << "\n"
			<< "\tb: " << b << "\n"
			<< "\tc: " << c << "\n"
			<< "\tP: " << P() << "\n"
			<< "\tS: " << S() << "\n";
	}

	~tre() {}
};

class rtre : public tre {
public:
	rtre() {
		this->A = 1;
		this->B = 1;
		this->C = 1;

		a = acos((B * B + C * C - A * A) / (2 * B * C));
		b = acos((A * A + C * C - B * B) / (2 * A * C));
		c = acos((A * A + B * B - C * C) / (2 * A * B));
	}
	rtre(double A, double B, double C) {
		this->A = A;
		this->B = B;
		this->C = C;

		a = acos((B * B + C * C - A * A) / (2 * B * C));
		b = acos((A * A + C * C - B * B) / (2 * A * C));
		c = acos((A * A + B * B - C * C) / (2 * A * B));
	}

	bool is() {
		return (A + B > C && A + C > B && B + C > A && (A == C || A == B || B == C));
	}

	~rtre() {}
};

int main(void) {
	int n, m;
	cin >> n >> m;

	double s = 0;
	for (int i = 0; i < n; ++ i) {
		cout << "tre " << (i + 1) << ":\n";
		int a, b, c;
		cin >> a >> b >> c;
		tre t(a, b, c);
		if (!t.is()) {
			cout << "error\n";
			-- i;
		}
		else {
			t.print();
			s += t.S();
		}
	}
	s /= n;

	rtre mnt;
	bool flag = true;
	for (int i = 0; i < m; ++ i) {
		cout << "rtre " << (i + 1) << ":\n";
		int a, b, c;
		cin >> a >> b >> c;
		rtre t(a, b, c);
		if (!t.is()) {
			cout << "error\n";
			-- i;
		}
		else {
			t.print();
			if (flag) {
				mnt = t;
				flag = false;
			}
			else {
				if (t.S() < mnt.S())
					mnt = t;
			}
		}
	}
	cout << "\n\nAnswer:\n1: " << s << "\n2:\n";
	mnt.print();
	return 0;
}