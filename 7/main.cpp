#include <iostream>
#include <vector>

using namespace std;

class List {
public:
	vector<int> elems;
	List() {}
	List(vector<int> v) {
		elems = v;
	}

	int operator[](unsigned index) {
		return elems[index];
	}
	List operator+(List L) {
		vector<int> a = elems;
		int x = a.size();
		int y = L.elems.size();
		for (int i = 0; i < min(x, y); ++ i)
			a[i] += L.elems[i];
		return List(a);
	}
	List operator+(int n) {
		vector<int> a = elems;
		for (int i = 0; i < a.size(); ++ i)
			a[i] += n;
		return List(a);
	}
	void print() {
		for (int i = 0; i < elems.size(); ++ i)
			cout << elems[i] << " ";
		cout << endl;
	}
	~List() {}
};

template<class T1, class T2>
class Pair {
public:
	T1 first;
	T2 second;
	Pair() {}
	Pair(T1 first, T2 second) {
		this->first = first;
		this->second = second;
	}
	~Pair() {}
};

int main(void) {
	vector<int> a(10, 3), b(3, 4);
	List A(a), B(b), C = A + B, D = C + 2;
	A.print();
	B.print();
	C.print();
	D.print();

	Pair<int, double> x(3, 2.5);
	cout << x.first << ":" << x.second << endl;

	return 0;
}