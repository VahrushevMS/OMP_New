#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <math.h>
#include <typeinfo>
#include <omp.h>
#include <ctime>
#include<chrono>
using namespace std;
const int len = 3;
const int N = 10;
const int ChildLen = 100000000;
const int quantityFiles = 11;
#define eps 1e-20
void test();
class CFabric;
class Complex {
public:
	int real;
	int image;
	Complex(int real, int image);
	Complex(){}
	void GetComplex();
	friend ostream& operator <<(ostream& os, const Complex& other);
	Complex operator+(Complex& other);
	Complex operator-(Complex& other);
	Complex operator*(Complex& other);
	bool operator!=(Complex& other);
	~Complex();

};
class ComplexVector {
	friend class ComplexVector1;
	friend class ComplexVector2;
public:
	vector<Complex> elems;
	ComplexVector(){}
	ComplexVector(vector<Complex> elems);
	void GetArr();
	//Complex& operator[](int index);
	friend ostream& operator<<(ostream& os, const ComplexVector& vector);
	virtual ComplexVector* operator+(ComplexVector& other)=0;
	virtual ComplexVector* operator-(ComplexVector& other)=0;
	static int Input(ifstream& filename, vector<ComplexVector*>& res, vector<CFabric*>& fabric, vector<string*>& name);
	virtual ~ComplexVector();
	virtual void print(string a)=0;
	bool operator==(ComplexVector& other);
};
class ComplexVector1 : public ComplexVector{
public:
	ComplexVector1():ComplexVector(){}
	ComplexVector1(vector<Complex> elems) : ComplexVector(elems){}
	//ComplexVector1 operator=(ComplexVector& other);
	ComplexVector1& operator=(const ComplexVector& other);
	ComplexVector* operator-(ComplexVector& other);
	ComplexVector* operator+(ComplexVector& other);
	ComplexVector1 operator*(ComplexVector1& other);
	friend ostream& operator<<(ostream& os, const ComplexVector1& vector);
	void print(string a);
    static int getMagnitudeSum(Complex& other);
	bool operator==(ComplexVector& other);
	bool operator==(ComplexVector1& other);
	void sort1(ComplexVector1& other);
	~ComplexVector1();
};
class ComplexVector2 : public ComplexVector{
public:
	ComplexVector2():ComplexVector(){}
	ComplexVector2(vector<Complex> elems) : ComplexVector(elems) {}
	ComplexVector* operator-(ComplexVector& other);
	ComplexVector* operator+(ComplexVector& other);
	ComplexVector2 operator*(ComplexVector2& other);
	friend ostream& operator<<(ostream& os, const ComplexVector2& vector);
    static int getMagnitudeSum(Complex& other);
	void sort2(ComplexVector2& other);
	void print(string a);
	bool operator==(ComplexVector& other);
	~ComplexVector2();
};
class CFabric
{
public:
	virtual ComplexVector* Create(vector<Complex> arr) = 0;
	virtual ~CFabric() {};
};

class CFabric1 : public CFabric
{
public:
	virtual ComplexVector* Create(vector<Complex> arr) { return new ComplexVector1(arr); }
};

class CFabric2 : public CFabric
{
public:
	virtual ComplexVector* Create(vector<Complex> arr) { return new ComplexVector2(arr); }
};

void getFile();

