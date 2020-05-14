#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int sum(int *arr, int n) {
	int ret = 0;
	for (int i = 0; i < n; ++ i)
		ret += arr[i];
	return ret;
}

int main(void) {
	srand(time(NULL));
	int m, n, x;
	cin >> m >> n;
	x = m * n;
	int *arr = new int[x];
	for (int i = 0; i < x; ++ i) {
		arr[i] = rand() % 50;
		cout << arr[i] << " ";
	}
	cout << "\n";
	int ans = 1;
	for (int i = 0; i < x; i += m)
		ans *= sum(arr + i, m);
	cout << ans << "\n";
	delete [] arr;
	return 0;
}