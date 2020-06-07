#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, m;

template<class T>
void bsort(T* arr, int n, int (*comp)(T, T)) {
	for (int i = 0; i < n; ++ i) {
		for (int j = i; j > 0; -- j) {
			if (comp(arr[j], arr[j - 1]) == -1) {
				T tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

int compare(int* a, int* b) {
	int x = 0, y = 0;
	for (int i = 0; i < m; ++ i) {
		if (a[i] < 0)
			x += a[i];
		if (b[i] < 0)
			y += b[i];
	}
	if (x > y)
		return -1;
	else if (y > x)
		return 1;
	else
		return 0;
}

int main(void) {
	srand(time(NULL));

	scanf("%d%d", &n, &m);

	//Создание и вывод матрицы
	int **arr = new int*[n];
	printf("old:\n");
	for (int i = 0; i < n; ++ i) {
		arr[i] = new int[m];
		for (int j = 0; j < m; ++ j) {
			arr[i][j] = rand() % 100 - 50;
			printf("%4d ", arr[i][j]);
		}
		printf("\n");
	}
	//

	//Поиск первого столбца с нулевым элементом
	int i = 0;
	bool flag = false;
	for (; i < m; ++ i) {
		for (int j = 0; j < n; ++ j) {
			if (arr[j][i] == 0) {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	printf("\n\n");
	if (flag)
		printf("Ans> %d\n", i + 1);
	else
		printf("NoAns\n");
	//

	//Сортировка и вывод матрицы
	bsort(arr, n, compare);
	printf("new:\n");
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j)
			printf("%4d ", arr[i][j]);
		printf("\n");
	}
	//

	for (int i = 0; i < n; ++ i)
		delete [] arr[i];
	delete [] arr;
	return 0;
}