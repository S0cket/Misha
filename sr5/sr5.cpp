#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	getline(cin, str);
	int k, count = 0;
	cin >> k;

	bool space = true;
	for (int i = 0; i < str.size(); i ++) {
		if (space && str[i] != ' ') {
			count ++;
			space = false;
		}
		else if (!space && str[i] == ' ')
			space = true;
		if (i == k) {
			cout << count <<endl;
			return 0;
		}
	}
	cout << "error" <<endl;
	return 1;
}
