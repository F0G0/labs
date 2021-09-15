#include <iostream>
#include "Table.h"

int main(int charc, char* chars[]) {
	if(charc != 3){
		std::cout << "Wrong number of parameters";
	}
	else {
		Table words;
		words.ReadFile(chars[1]);
		words.PrintFile(chars[2]);
	}
	return 0;
}