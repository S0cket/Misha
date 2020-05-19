#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void) {
	srand(time(NULL));

	int n, s = 0;
	cin >> n;
	int *a = new int[n];
	cout << "old:\n";
	for (int i = 0; i < n; ++ i) {
		*(a + i) = rand() % 100 - 20;
		s += *(a + i);
		cout << *(a + i) << " ";
	}

	int mv = 0;

	int cnt = 0, ma = -1000, mi = 1000;
	for (int i = 0; i < n; ++ i) {
		if (*(a + i) > 0) {
			++ cnt;
			mv += *(a + i);
			if (*(a + i) > ma)
				ma = *(a + i);
			if (*(a + i) < mi)
				mi = *(a + i);
		}
		if (*(a + i) <= 0 || i == n - 1){
			if (cnt > 1) {
				mv /= cnt;
				for (int j = (*(a + i) > 0) ? i : (i - 1); j >= 0 && *(a + j) > 0; -- j) {
					if (*(a + j) == ma || *(a + j) == mi)
						*(a + j) = mv;
				}
			}
			mv = 0;
			cnt = 0;
			ma = -1000;
			mi = 1000;
		}
	}

	cout << "\nnew:\n";
	for (int i = 0; i < n; ++ i)
		cout << *(a + i) << " ";
	cout << "\n";
	delete [] a;
	return 0;
}