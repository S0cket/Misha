#include <iostream>
#include <string>

using namespace std;

class Shape {
private:
	string type;
public:
	virtual void info() = 0;
	virtual void move(double, double) = 0;
	friend class Square;
	friend class Circle;
	friend class Ellipse;
};

class Square : public Shape {
private:
	double x, y, a;
public:
	Square() {
		this->type = "Square";
		this->x = 0;
		this->y = 0;
		this->a = 1;
	}
	Square(double x, double y, double a) {
		this->type = "Square";
		this->x = x;
		this->y = y;
		this->a = a;
	}

	void info() override {
		cout << type <<":\n"
			<< "\ttopleft: x: " << x << ", y: " << y << "\n"
			<< "\tside: " << a << "\n";
	}
	void move(double x, double y) override {
		this->x += x;
		this->y += y;
	}

	~Square() {}
};

class Circle : public Shape {
private:
	double x, y, r;
public:
	Circle() {
		this->type = "Circle";
		this->x = 0;
		this->y = 0;
		this->r = 1;
	}
	Circle(double x, double y, double r) {
		this->type = "Circle";
		this->x = x;
		this->y = y;
		this->r = r;
	}

	void info() override {
		cout << type <<":\n"
			<< "\tcenter: x: " << x << ", y: " << y << "\n"
			<< "\tradius: " << r << "\n";
	}
	void move(double x, double y) override {
		this->x += x;
		this->y += y;
	}

	~Circle() {}
};

class Ellipse : public Shape {
private:
	double x1, y1, x2, y2;
public:
	Ellipse() {
		this->type = "Ellipse";
		this->x1 = 0;
		this->y1 = 0;
		this->x2 = 1;
		this->y2 = 1;
	}
	Ellipse(double x1, double y1, double x2, double y2) {
		this->type = "Ellipse";
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	void info() override {
		cout << type <<":\n"
			<< "\ttopleft: x: " << x1 << ", y: " << y1 << "\n"
			<< "\tbotright: x: " << x2 << ", y: " << y2 << "\n";
	}
	void move(double x, double y) override {
		this->x1 += x;
		this->y1 += y;
		this->x2 += x;
		this->y2 += y;
	}

	~Ellipse() {}
};

int main(void) {
	Square a;
	Circle b;
	Ellipse c;
	a.info();
	b.info();
	c.info();
	return 0;
}