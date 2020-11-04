#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Time {
public:
	int h, m, s;
	Time() {
		this->h = 0;
		this->m = 0;
		this->s = 0;
	}
	Time(int h, int m, int s) {
		this->h = h;
		this->m = m;
		this->s = s;
	}
	Time(string s) {
		sscanf(s.c_str(), "%d:%d:%d", &this->h, &this->m, &this->s);
	}
	Time(int sec) {
		this->h = sec / 3600;
		sec %= 3600;
		this->m = sec / 60;
		this->s = sec % 60;
	}
	Time(const Time& T) {
		this->h = T.h;
		this->m = T.m;
		this->s = T.s;
	}

	int diff(Time T) {
		int a = (this->h * 3600) + (this->m * 60) + this->s;
		int b = (T.h * 3600) + (T.m * 60) + T.s;
		return abs(a - b);
	}
	void add(int sec) {
		int secpday = 24 * 60 * 60;
		while (sec < 0) sec += secpday;
		sec %= secpday;
		this->s += sec;
		this->m += this->s / 60;
		this->s %= 60;
		this->h += this->m / 60;
		this->m %= 60;
		this->h %= 24;
	}
	void sub(int sec) {
		int s = (this->h * 3600) + (this->m * 60) + this->s, t;
		int secpday = 24 * 60 * 60;
		s -= sec;
		while (s < 0) s += secpday;
		s %= secpday;
		this->h = s / 3600;
		s %= 3600;
		this->m = s / 60;
		this->s = s % 60;
	}
	Time min(Time T) {
		if (this->h < T.h)
			return Time(this->h, this->m, this->s);
		else if (this->h > T.h)
			return T;
		else {
			if (this->m < T.m)
				return Time(this->h, this->m, this->s);
			else if (this->m > T.m)
				return T;
			else {
				if (this->s < T.s)
					return Time(this->h, this->m, this->s);
				else
					return T;
			}
		}
	}
	Time max(Time T) {
		if (this->h > T.h)
			return Time(this->h, this->m, this->s);
		else if (this->h < T.h)
			return T;
		else {
			if (this->m > T.m)
				return Time(this->h, this->m, this->s);
			else if (this->m < T.m)
				return T;
			else {
				if (this->s > T.s)
					return Time(this->h, this->m, this->s);
				else
					return T;
			}
		}
	}
	int tosec() {
		return (this->h * 3600) + (this->m * 60) + this->s;
	}
	int tomin() {
		return (this->h * 60) + (this->m) + ((this->s >= 30) ? 1 : 0);
	}
	void print() {
		cout << this->h << ":" << this->m << ":" << this->s << endl;
	}
};

int main(void) {
	Time a(12, 40, 35), b(a);
	b.add(1);
	Time mn = a.min(b);
	Time mx = a.max(b);
	mn.print();
	mx.print();


	int s = a.tosec();
	s += 3 * 24 * 60 * 60;
	a.sub(s + 1);
	a.print();

	s = 24 * 60 * 60 - a.tosec();
	s -= 4 * 24 * 60 * 60;
	a.add(s + 1);
	a.print();
	return 0;
}