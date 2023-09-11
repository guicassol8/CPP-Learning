#include <iostream>
#include <cmath>

int main(){
	float log;
	unsigned int input;
	while (1){
		std::cin >> input;
		if (input == -1){
			break;
		}
		log = log2(input);
		std::cout << log << std::endl;
		log = 0;
	}
	return 0;
}