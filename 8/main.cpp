#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Set {
public:
	vector<int> vect;
	Set() {}
	Set(int *arr, int n) {
		for (int i = 0; i < n; ++ i)
			vect.push_back(arr[i]);
	}
	Set(vector<int> v) {
		vect = v;
	}

	int operator[](unsigned index) {
		if (index >= vect.size()) throw 1;
		return vect[index];
	}
	void operator()(int size) {
		if (size < 0) throw 2;
		vect.resize(size);
	}
	Set operator*(Set S) {
		vector<int> a = vect, b = S.vect, x;
		for (int i = 0; i < a.size(); ++ i) {
			auto iter = find(b.begin(), b.end(), a[i]);
			if (iter != b.end()) {
				x.push_back(a[i]);
				a.erase(a.begin() + i);
				b.erase(iter);
				-- i;
			}
		}
		return Set(x);
	}
	void operator+(int a) {
		vect.push_back(a);
	}
	int operator--() {
		if (vect.size() == 0) throw 3;
		int x = vect.front();
		vect.erase(vect.begin());
		return x;
	}
	int operator--(int) {
		if (vect.size() == 0) throw 3;
		int x = vect.back();
		vect.pop_back();
		return x;
	}
	void print() {
		for (int i = 0; i < vect.size(); ++ i)
			cout << vect[i] << " ";
		cout << endl;
	}



	~Set() {}
};

int main(void) {
	int a[5] {1, 2, 2, 5, 0}, b[5] = {2, 2, 3, 5, 2};
	Set A(a, 5), B(b, 5), C = A * B;
	A.print();
	B.print();
	C.print();
	C + 3;
	C.print();
	try {
		C(-1);
	}
	catch (int) {
		cout << "Error!!!\n";
	}
	return 0;
}