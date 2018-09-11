#include <iostream>


int main() {
	int vetA[3] = {1,2,3};
	int vetB[3];
	int vetC[3];
	int i = 1; 

	// while(true) {
		vetB[0] = vetA[0];
		vetC[0] = vetA[1];
		vetC[1] = vetB[0];

		vetB[0] = vetA[2];
		vetA[0] = vetC[1];
		vetB[1] = vetC[0];
		vetB[2] = vetA[0];
	// }
	for(int i = 0; i < 3; i++) {
		std::cout << vetB[i] << " ";
	}
	std::cout << "\n";
}