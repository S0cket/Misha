#include <iostream>
#include <fstream>

using namespace std;

void bs(int *arr, int len) {
	for (int i = 0; i < len; ++ i) {
		for (int j = i; j > 0; -- j) {
			if (arr[j] < arr[j - 1]) {
				arr[j] += arr[j - 1];
				arr[j - 1] = arr[j] - arr[j - 1];
				arr[j] -= arr[j - 1];
			}
		}
	}
}

int main(void) {
	int n = 0, elem;
	int *arr = new int[n], *old = nullptr;
	ifstream f("f.txt");
	fstream g;
	while (f >> elem) {
		old = arr;
		arr = new int[n + 1];
		for (int i = 0; i < n; ++ i)
			arr[i] = old[i];
		arr[n ++] = elem;
		delete [] old;
	}
	f.close();

	bs(arr, n);
	int m = n / 2;

	g.open("g1.txt", ios::out);
	for (int i = 0; i < m; ++ i)
		g << arr[i] << " " << arr[n - i - 1] << " ";
	g.close();

	g.open("g2.txt", ios::out);
	for (int i = n - 1; i >= 0; -- i) {
		g << arr[i] << " ";
	}
	g.close();

	g.open("g3.txt", ios::out);
	for (int i = 0; i < m - 1; i += 2) {
		g << arr[n - i - 1] << " "
		<< arr[n - i - 2] << " "
		<< arr[i] << " "
		<< arr[i + 1] << " ";
	}
	if (m % 2 != 0) {
		g << arr[m] << " " << arr[m - 1];
	}
	g.close();
	delete [] arr;
	return 0;
}