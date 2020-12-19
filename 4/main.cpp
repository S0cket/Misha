#include <iostream>
#include <vector>
 
using namespace std;
 
class Matrix {
public:
	int n;
	vector<vector<int>> m;
	Matrix() {
		n = 0;
	}
	Matrix(vector<vector<int>> m_) {
		bool flag = true;
		for (int i = 0; i < m_.size(); ++ i) {
			if (m_[i].size() != m_.size())
				flag = false;
		}
		if (flag) {
			n = m_.size();
			this->m = m_;
		}
		else
			n = 0;
	}
	~Matrix() {}

	void print() {
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j)
				cout << m[i][j] << " ";
			cout << endl;
		}
	}

	bool diag() {
		bool flag = true;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				if (i == j) {
					if (m[i][j] == 0)
						flag = false;
				}
				else {
					if (m[i][j] != 0)
						flag = false;
				}
			}
		}
		return flag;
	}

	bool null() {
		bool flag = true;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				if (m[i][j] != 0)
					flag = false;
			}
		}
		return flag;
	}

	bool ed() {
		bool flag = true;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				if (i == j) {
					if (m[i][j] != 1)
						flag = false;
				}
				else {
					if (m[i][j] != 0)
						flag = false;
				}
			}
		}
		return flag;
	}
 
	Matrix operator+(Matrix M) {
		if (n != M.n) {
			cout << "\nERROR\n";
			return Matrix();
		}
		vector<vector<int>> v = m;
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j)
				v[i][j] += M.m[i][j];
		return Matrix(v);
	}
 
	Matrix operator-(Matrix M) {
		if (n != M.n) {
			cout << "\nERROR\n";
			return Matrix();
		}
		vector<vector<int>> v = m;
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j)
				v[i][j] -= M.m[i][j];
		return Matrix(v);
	}
 
	Matrix operator*(Matrix M) {
		if (n != M.n) {
			cout << "ERROR\n";
			return Matrix();
		}
		vector<vector<int>> v = m;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				v[i][j] = 0;
				for (int k = 0; k < n; ++ k)
					v[i][j] += m[i][k] * M.m[k][j];
			}
		}
		return Matrix(v);
	}
 
	Matrix operator*=(int n) {
		vector<vector<int>> v = m;
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j)
				v[i][j] *= n;
		return Matrix(v); 
	}
};
 
int main(void) {
	int n = 3;
	vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 2;
 	a[1][0] = 0; a[1][1] = 3; a[1][2] = 1;
 	a[2][0] = 1; a[2][1] = 0; a[2][2] = 0;
 
	b[0][0] = 0; b[0][1] = 0; b[0][2] = 1;
 	b[1][0] = 0; b[1][1] = 0; b[1][2] = 1;
	b[2][0] = 0; b[2][1] = 0; b[2][2] = -1;
 
	Matrix A(a), B(b), D;
	D = (B*=3) * A + (B - A);
	D.print();
	cout << "diag: " << D.diag() << endl;
	cout << "null: " << D.null() << endl;
	cout << "ed: " << D.ed() << endl;	
	return 0;
}