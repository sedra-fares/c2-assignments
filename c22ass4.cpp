#include<iostream>
#include<math.h>
#include<ostream>
using namespace std;
class cylinder {
private:
	float hieght;
	float radius;
public:
	cylinder(){}
	cylinder(float h) {
		 setHieght(h);
	}
	cylinder(float h, float r) {
		 setHieght(h);
	     setRadios(r);
	}
	~cylinder() {}

	void setHieght(float h) {
		this->hieght = h;
	}
	void setRadios(float r) {
		this->radius = r;
	}
	float getHieght()const {
		return hieght;
	}
	float getRadios() const {
		return radius;
	}
	friend ostream& operator <<(ostream& out, cylinder& c) {
		out << "the cylinder radios:" << c.radius;
		out << endl << "the cylinder " << c.hieght;
		out << endl << "the base area" << c.getBaseArea();
		out << endl << "the cylinder volume" << c.getVolume();
		return out;
	}

	float getBaseArea()const {
		return 3.14 * (radius * radius);
	}
	float getVolume()const {
		return getBaseArea() * hieght;
	}
	 
	friend istream& operator >>(istream& in, cylinder & l) {
		float a, b;
		int valid = 0;
		while (!valid) {
			cout << "enter the cylinder radios,hieght";
			in >> a >> b;
			if (a > 0 && b > 0) {
				valid = 1;
				l.setRadios(a);
				l.setHieght(b);
			}
			else cout << endl << "invalid input, try again";
		}
		return in;
	}
	cylinder(const cylinder& copy) {
		setHieght(copy.getHieght());
		setRadios(copy.getRadios());
	}
	cylinder& operator=(const cylinder& other) {
		if (this != &other) { // Check for self-assignment
			this->hieght = other.hieght;
			this->radius = other.radius;
		}
		return *this;
	}
};
int main() {
	const int s = 3;
	cylinder C[s];
	for (int i = 0; i < s; i++) {//reading cylinder
		cout << endl << "cylinder number " << i + 1;
		cin >> C[i];
	}
	cout << endl << "cylinders details";
	for (int i = 0; i < s; i++) {
		cout << endl << C[i];
	}

	cout << endl << "sorting the array based on the cylinder's volume:";
	for (int i = 0; i < s - 1; i++) {
		for (int j = 0; j < s - i - 1; j++) {
			if (C[j].getVolume() < C[j + 1].getVolume()) {
				swap(C[j], C[j + 1]);
			}
		}
	}
	
	cout << endl << "cylinders details"<<endl;
	for (int i = 0; i < s; i++) {
		cout << endl << C[i];
	}
	//ÈãÇ Çäí ÚãáÊ ááÇÑÑÇí ÊÑÊíÈ ÍÓÈ ÇáÍÌã ÇÐÇ Çæá ÎáíÉ åí ÇßÈÑ ÍÌã æÇÎÑ ÎáíÉ åí ÇáÇÕÛÑ
	cout << endl << "the cylinder with the largest volume:" << C[0];
	cout << endl << "the cylinder with the smallest volume:" << C[s-1];

}