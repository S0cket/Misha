#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int s = abs(x2 - x1) * abs(y2 - y1);
	cout << s << endl;
	return 0;
}