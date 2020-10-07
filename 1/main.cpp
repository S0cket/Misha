#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <time.h>

using namespace std;

struct Mystr {
	double kof;
	int stepen;
};

list<Mystr>::iterator offset(list<Mystr>::iterator iter, int n) {
	for (int i = 0; i < n; ++ i)
		iter++;
	return iter;
}

void Diff(list<Mystr> p, list<Mystr> &q) {
	q = p;
	for (auto i = q.begin(); i != q.end(); ++ i) {
		i->kof *= i->stepen;
		i->stepen --;
	}
	int cnt = 0;
	for (auto i = q.begin(); i != q.end();) {
		if (i->stepen == -1) {
			q.erase(i);
			i = offset(q.begin(), cnt);
		}
		else
			++ i; ++ cnt;
	}
}

void Print(list<Mystr> p) {
	bool flag = true;
	for (auto i = p.begin(); i != p.end(); ++ i) {
		if (i->kof == 0)
			continue;
		if (!flag && i->kof >= 0)
			cout << "+";

		if (i->stepen == 0)
			cout << i->kof;
		else
			cout << i->kof << "*" << "x" << "^" << i->stepen;
		flag = false;
	}
}

int main()
{
	srand(time(NULL));
	list <Mystr> Mylist, Mylist_;
	list <Mystr>::iterator it;
	int n, k;
	double a;
	cin >> n;
	Mystr p;

	for (int i = 0; i < n; i++) {
		p.kof = rand() % 40 - 20;
		p.stepen = rand() % 10;
		Mylist.push_back(p);
	}

	Print(Mylist);
	cout << "\n";
	Diff(Mylist, Mylist_);
	Print(Mylist_);
	cout << "\n";

	return 0;

}