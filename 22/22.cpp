#include <stdio.h>
#include <ctype.h>
#include <string>
#include <iostream>

using namespace std;

int count(string::iterator begin, string::iterator end, int cnt = 0) {
	if (begin >= end)
		return cnt;
	if (isdigit((int)*begin))
		return count(begin + 1, end, cnt + *begin - '0');
	else
		return count(begin + 1, end, cnt);
}

int main(void) {
	string s, t;
	getline(cin, s);
	getline(cin, t);
	int a = count(s.begin(), s.end()), b = count(t.begin(), t.end());
	//cout << "\n\n\n" << s << "\n" << t << "\n" << "a = " << a << " " << "b = " << b << "\n";
	if (a > b)
		cout << "1\n";
	else if (a < b)
		cout << "2\n";
	else
		cout << "eq\n";
	return 0;
}