#include "Header.h"
ostream& operator<<(ostream& os, const ComplexVector1& vector) {
	for (const Complex& element : vector.elems) {
		os << element << ";";
	}
	os << endl;
	return os;
}
ComplexVector* ComplexVector1:: operator+(ComplexVector& other) {
	vector<Complex> result;
        for (size_t i = 0;i < elems.size();i++) {
		result.push_back(elems[i] + other.elems[i]);
	}
	ComplexVector* num = new ComplexVector1(result);
	return num;
}
ComplexVector* ComplexVector1:: operator-(ComplexVector& other) {
	vector<Complex> result;
        for (size_t i = 0;i < elems.size();i++) {
		result.push_back(elems[i] - other.elems[i]);
	}
	ComplexVector* num = new ComplexVector1(result);
	return num;
}
ComplexVector1 ComplexVector1:: operator*(ComplexVector1& other) {
	vector<Complex> result;
        for (size_t i = 0;i < elems.size();i++) {
		result.push_back(elems[i] * other.elems[i]);
	}

	return ComplexVector1(result);
}
bool ComplexVector1:: operator==(ComplexVector& other) {
        for (size_t i = 0; i < elems.size(); i++) {
		if (elems[i] != other.elems[i]) {
			return false;
		}
	}

	return true;
}
bool ComplexVector1:: operator==(ComplexVector1& other) {
        for (size_t i = 0; i < elems.size(); i++) {
		if (elems[i] != other.elems[i]) {
			return false;
		}
	}

	return true;
}
void ComplexVector1::print(string a) {
	ofstream file(a, ios_base::app);
	if (file.is_open()) {
		file << "1 " << endl;
		for (int i = 0;i < len;i++) {
			
			file  << elems[i] << ";" << endl;
		}
		file << "--------" << endl;
	}
	else {
		cout << "File error" << endl;
	}
	file.close();
}
ComplexVector1& ComplexVector1::operator=(const ComplexVector& other) {
	
	this->elems = other.elems;

	return *this;
}
int ComplexVector1::getMagnitudeSum(Complex& other) {

               int sum3 = (other.real + other.image);
                return sum3;
}

void ComplexVector1::sort1(ComplexVector1& other) {
	//int timer = -clock();
	auto start = chrono::high_resolution_clock::now();
	ComplexVector1 a,b,c;
	a.GetArr();
	b.GetArr();
	c.GetArr();
	for (size_t i = 0;i < elems.size();i++) {
		a.elems[i] = (elems[i] + other.elems[i]);
	}
	for (size_t i = 0;i < elems.size();i++) {
		b.elems[i] = (elems[i] - other.elems[i]);
	}
	for (size_t i = 0;i < elems.size();i++) {
		c.elems[i] = (elems[i] * other.elems[i]);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
		//timer += clock();
        cout << "Required time for sorting " << elems.size() << " elements is " << duration.count() << " seconds" << endl;

		if (elems.size() > 11) {
			cout << "vector 1: ";
			for (int i = 0;i < 11;i++) {
				cout << elems[i] << " ";
			}
			cout << endl;
			cout << "vector 2: ";
			for (int i = 0;i < 11;i++) {
				cout << other.elems[i] << " ";
			}
			cout << endl;
			cout << "Sum: ";
			for (int i = 0;i < 11;i++) {
				cout << a.elems[i] << " ";
			}
			cout << endl;
		}
	else {
                for (size_t i = 0;i < elems.size();i++) {
			cout << elems[i] << " ";
		}
	}
	cout << endl;
}
ComplexVector1::~ComplexVector1() {}
ostream& operator<<(ostream& os, const ComplexVector2& vector) {
	for (const Complex& element : vector.elems) {
		os << element << ";";
	}
	os << endl;
	return os;
}
ComplexVector* ComplexVector2:: operator+(ComplexVector& other) {
	vector<Complex> result;
        for (size_t i = 0;i < elems.size();i++) {
		result.push_back(elems[i] + other.elems[i]);
	}
	ComplexVector* num = new ComplexVector2(result);
	return num;
}
ComplexVector* ComplexVector2:: operator-(ComplexVector& other) {
	vector<Complex> result;
        for (size_t i = 0;i < elems.size();i++) {
		result.push_back(elems[i] - other.elems[i]);
	}
	ComplexVector* num = new ComplexVector2(result);
	return num;
}
ComplexVector2 ComplexVector2:: operator*(ComplexVector2& other) {
	vector<Complex> result;
        for (size_t i = 0;i < elems.size();i++) {
		result.push_back(elems[i] * other.elems[i]);
	}

	return ComplexVector2(result);
}
bool ComplexVector2:: operator==(ComplexVector& other) {
        for (size_t i = 0; i < elems.size(); i++) {
		if (elems[i] != other.elems[i]) {
			return false;
		}
	}

	return true;
}
int ComplexVector2::getMagnitudeSum(Complex& other) {



       int sum2 = (other.real + other.image);


        return sum2;
}

void ComplexVector2::sort2(ComplexVector2 &other) {
	auto start = chrono::high_resolution_clock::now();
	Complex z;
	ComplexVector1 a,b,c;
	a.GetArr();
	b.GetArr();
	c.GetArr();
	#pragma omp parallel for
	for (size_t i = 0;i < elems.size();i++) {
		a.elems[i] = (elems[i] + other.elems[i]);	
	}
	#pragma omp parallel for
	for (size_t i = 0;i < elems.size();i++) {
		b.elems[i] = (elems[i] - other.elems[i]);
	}
	#pragma omp parallel for
	for (size_t i = 0;i < elems.size();i++) {
		c.elems[i] = (elems[i] * other.elems[i]);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end-start;
        cout << "Required time for sorting with OMP " << elems.size() << " elements is " << duration.count() << " seconds" << endl;
	if (elems.size() > 11) {
		cout << "vector 1: ";
		for (int i = 0;i < 11;i++) {
			cout << elems[i] << " ";
		}
		cout << endl;
		cout << "vector 2: ";
		for (int i = 0;i < 11;i++) {
			cout << other.elems[i] << " ";
		}
		cout << endl;
		cout << "Sum: ";
		for (int i = 0;i < 11;i++) {
			cout << a.elems[i] << " ";
		}
		cout << endl;
	}
	else {
                for (size_t i = 0;i < elems.size();i++) {
			cout << elems[i] << " ";
		}
	}
        cout << endl;
		cout << "!!!!!!!!!!";
}
void ComplexVector2::print(string a) {
	ofstream file(a, ios_base::app);
	if (file.is_open()) {
		file << "2 ";
		for (int i = 0;i < len;i++) {
			
			file << elems[i] << ";" << " ";
		}
		file << endl;
		file << "-------" << endl;
	}
	else {
		cout << "File error" << endl;
	}
	file.close();
}
ComplexVector2::~ComplexVector2() {}
