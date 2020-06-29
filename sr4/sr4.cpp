#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

const int mod = 100;
int NUMS[mod];

int main(void) {
	srand(time(NULL));

	int ans1 = 0, ans2 = -1;
	int n, m;
	cin >> n >> m;

	int **matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
		for (int j = 0; j < m; j++) {
			matrix[i][j] = rand() % mod;
			cout << setw(4) << matrix[i][j] << " ";
			NUMS[matrix[i][j]] ++;
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		bool nol = false;
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0)
				nol = true;
		}
		if (!nol)
			ans1 ++;
	}
	cout << "1> " << ans1 <<endl;
	for (int i = 0; i < mod; i++) {
		if (NUMS[i] > 1)
			ans2 = i;
	}
	if (ans2 == -1)
		cout << "2> no answer" <<endl;
	else
		cout << "2> " << ans2 <<endl;


	for (int i = 0; i < n; ++ i)
		delete [] matrix[i];
	delete [] matrix;
	return 0;
}
