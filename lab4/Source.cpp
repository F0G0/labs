#include <iostream>
#include "GameControl.h"

int main() {
	GameControl controller;
	while (controller.init()) {
		controller.gameLoop();
	}
	return 0;
}