#include <stdio.h>
#include <iostream>
#include <locale.h>

using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");
	int age;
	cin >> age;
	if (age < 1 || age > 99) {
		cout << "Error\n";
		return 1;
	}
	int a = age % 10;
	int b = age / 10;
	cout << "Мне " << age << " ";
	switch (b) {
		case 1:
			cout << "лет";
			break;
		default:
			switch (a) {
				case 1:
					cout << "год";
					break;
				case 2:
					cout << "года";
					break;
				case 3:
					cout << "года";
					break;
				case 4:
					cout << "года";
					break;
				default:
					cout << "лет";
					break;
			}
			break;
	}
	cout << endl;
	return 0;
}