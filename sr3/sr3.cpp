#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (; n != 0; n /= 2)
		cout << n % 2;
	cout << endl;
	return 0;
}