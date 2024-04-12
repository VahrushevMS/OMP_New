#include "Header.h"


void getFile() {
	ofstream file("input.txt");
	srand(time(0));
	for (int i = 0;i < N;i++) {
		int indexClass = 1 + rand() % 2;
		int numFile = 1 + rand() % quantityFiles;
		file << "out" << numFile << ".txt " << indexClass << " ";

		for (int i = 0;i < 2 * len;i++) {
			file << (1 + rand() % 100) << " ";

		}
		file << endl;
	}
}
