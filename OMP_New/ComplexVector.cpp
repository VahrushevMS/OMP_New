#include "Header.h"
ComplexVector::ComplexVector(vector<Complex> elems) {
	this->elems = elems;
}
void ComplexVector::GetArr() {
    for (int i = 0;i < ChildLen;i++) {
        Complex num;
        num.GetComplex();
        elems.push_back(num);
    }
}
ostream& operator<<(ostream& os, const ComplexVector& vector) {
	for (const Complex& element : vector.elems) {
		os << element << " ; ";
	}
	return os;
}

bool ComplexVector:: operator==(ComplexVector& other) {
        for (size_t i = 0; i < elems.size(); i++) {
		if (elems[i] != other.elems[i]) {
			return false;
		}
	}

	return true;
}

int ComplexVector::Input(ifstream& filename, vector<ComplexVector*>& res, vector<CFabric*>& fabric, vector<string*> &name) {
    for (int i = 0; i < N; i++) {
        int a;
        string b;
        filename >> b;
        filename >> a;
        name.push_back(new string(b));
        if (a == 1) {
            vector<int> elems;
            vector<Complex> arr;
            for (int j = 0; j < 2 * len; j += 2) {
                int a, b;
                filename >> a >> b;
                elems.push_back(a);
                elems.push_back(b);
                Complex num(elems[j], elems[j + 1]);
                arr.push_back(num);
            }
            ComplexVector* num = fabric[0]->Create(arr);
            res.push_back(num);
        }
        else {
            vector<int> elems;
            vector<Complex> arr;
            for (int j = 0; j < 2 * len; j += 2) {
                int a, b;
                filename >> a >> b;
                elems.push_back(a);
                elems.push_back(b);
                Complex num(elems[j], elems[j + 1]);
                arr.push_back(num);
            }
            ComplexVector* num = fabric[1]->Create(arr);
            res.push_back(num);
        }
    }
    return 0;
}




ComplexVector:: ~ComplexVector() {
	//cout << "virtual dectructor";
}
