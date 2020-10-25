#include <iostream>
#include <set>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

void print(set<double> s) {
	for (auto iter = s.begin(); iter != s.end(); ++ iter)
		cout << *iter << " ";
	cout << endl;
}

int main(void) {
	srand(time(NULL));

	int n;
	cout << "Input length: ";
	cin >> n;

	set<double> s, s_;
	for (int i = 0; i < n; ++ i)
		s.insert(rand() % 100);

	print(s);
	cout << "MAX: " << *(--s.end()) << endl;

	int a, b;
	cout << "Diapazon: ";
	cin >> a >> b;
	if (a > b) swap(a, b);
	s.erase(s.lower_bound(a), s.upper_bound(b));
	print(s);

	double sum = 0;
	for (auto iter = s.begin(); iter != s.end(); ++ iter)
		sum += *iter;
	sum /= s.size();
	cout << "Srznach: " << sum << endl;
	s_ = s;
	s.clear();
	for (auto iter = s_.begin(); iter != s_.end(); ++ iter)
		s.insert(*iter + sum);
	print(s);
	return 0;
}