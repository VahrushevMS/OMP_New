#include "Header.h"

Complex::Complex(int real, int image) {
		this->real = real;
		this->image = image;

	}
void Complex::GetComplex() {
	real = 1 + rand() % 120;
	image = 1 + rand() % 120;
}
	ostream& operator <<(ostream& os, const Complex& other) {
		if (other.image >= 0) {
			os << other.real << "+" << other.image << "i";
		}
		else {
			os << other.real << other.image << "i";
		}
		return os;
	}
	Complex Complex::operator+(Complex& other) {
		Complex temp;
		temp.real = real + other.real;
		temp.image = image + other.image;
		return temp;
	}
	Complex Complex:: operator-(Complex& other) {
		Complex temp;
		temp.real = real - other.real;
		temp.image = image - other.image;
		return temp;
	}
	Complex Complex:: operator*(Complex& other) {
		Complex temp;
		temp.real = real * other.real;
		temp.image = image * other.image;
		return temp;
	}
	bool Complex::operator!=(Complex& other) {
		return !(real == other.real && image == other.image);
	}
	Complex::~Complex() {
		//cout << "dectructor" << endl;
	}
int main() {
	srand(time(0));
	getFile();
	for (int i = 1;i <= quantityFiles;i++) {
		ofstream ofs;
		string a{ "out" };
		string b{ ".txt" };
		string tempString = a + to_string(i);
		tempString.append(b);
		ofs.open(tempString, std::ofstream::out | std::ofstream::trunc);
		ofs.close();
	}
	ifstream file("input.txt", ios_base::out);
	vector<ComplexVector*> res;
	vector<CFabric*> fabric;
	fabric.push_back(new CFabric1);
	fabric.push_back(new CFabric2);
	string b;
	vector<string*> name;
	ComplexVector::Input(file, res, fabric, name);
	for (size_t i=0; i < res.size(); i++) {
		
		res[i]->print(*name[i]);
	}
	for (size_t i = 0; i < name.size(); ++i) delete name[i];
	for (size_t i = 0; i < fabric.size(); ++i) delete fabric[i];
	test();
	vector<Complex> arr;
	vector<Complex> nums;
        for (int i = 0;i < ChildLen;i++) {
		int a = 1 + rand() % 100;
		int b = 1 + rand() % 100;
		Complex z(a, b);
		arr.push_back(z);
	}
	for (int i = 0;i < ChildLen;i++) {
			int a = 1 + rand() % 100;
			int b = 1 + rand() % 100;
			Complex z(a, b);
			nums.push_back(z);
	}
	ComplexVector1 num1(arr);
	ComplexVector2 num2(arr);
	ComplexVector1 num3(nums);
	ComplexVector2 num4(nums);
	num1.sort1(num3);
	num2.sort2(num4);
	for (size_t i = 0; i < res.size(); ++i) delete res[i];
	file.close();
	return 0;
}
