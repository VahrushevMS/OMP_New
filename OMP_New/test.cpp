#include "Header.h"
void test() {
	ofstream test("test.txt", ios_base::app);
	vector<int> arr;
	vector<Complex> sum;
	vector<Complex> diff;
	vector<Complex> mult;
	for (int i = 0;i < 4 * len;i++) {
		int a = rand() % 100 - 50;
		test << a << ";";
		arr.push_back(a);
	}
	for (size_t i = 0;i < arr.size() / 2;i+=2) {
		test << arr[i] + arr[i + 2 * len] << ";" << arr[i+1] + arr[(i+1) + 2 * len] <<";";
		Complex num(arr[i] + arr[i + 2 * len], arr[i + 1] + arr[(i + 1) + 2 * len]);
		sum.push_back(num);
	}
	for (size_t i = 0;i < arr.size() / 2;i+=2) {
		test << arr[i] - arr[i + 2 * len] << ";" << arr[i + 1] - arr[(i + 1) + 2 * len] << ";";
		Complex num(arr[i] - arr[i + 2 * len], arr[i + 1] - arr[(i + 1) + 2 * len]);
		diff.push_back(num);
	}
	for (size_t i = 0;i < arr.size() / 2;i+=2) {
		test << arr[i] * arr[i + 2 * len] << ";" << arr[i + 1] * arr[(i + 1) + 2 * len] << ";";
		Complex num(arr[i] * arr[i + 2 * len], arr[i + 1] * arr[(i + 1) + 2 * len]);
		mult.push_back(num);
	}
	vector<Complex> vec1;
	vector<Complex> vec2;
	for (size_t i = 0;i < arr.size()/2;i += 2) {
		Complex num(arr[i], arr[i + 1]);
		vec1.push_back(num);
	}
	for (size_t i = arr.size() / 2;i < arr.size();i += 2) {
		Complex num(arr[i], arr[i + 1]);
		vec2.push_back(num);
	}
	ComplexVector1 sum1(sum), diff1(diff), mult1(mult), vector1(vec1), vector2(vec2);
	ComplexVector* sum2 = vector1 + vector2;
	cout << "Vector 1: " << vector1 << "Vector 2: " << vector2;
	cout <<"Sum: " <<  * sum2 << endl;
	if (sum1 == *sum2) {
		cout << "Test sum completed" << endl;
	}
	else {
		cout << "Test sum not completed" << endl;
	}
	ComplexVector* diff2 = vector1 - vector2;
	cout << "Diff: " <<  * diff2 << endl;
	if (diff1 == *diff2) {
		cout << "Test diff completed" << endl;
	}
	else {
		cout << "Test diff not completed" << endl;
	}
	ComplexVector1 mult2 = vector1 * vector2;
	cout << "Mult: " << mult2;
	if (mult1 == mult2) {
		cout << "Test mult completed" << endl;
	}
	else {
		cout << "Test mult not completed" << endl;
	}
	delete diff2;
	delete sum2;
}