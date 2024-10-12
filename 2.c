// define extra functions here

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int random(int min_int, int max_int) {
	static bool initialized = false;
	if (!initialized) {
		initialized = true;
		srand(time(NULL));
	}
	return rand() % max_int + min_int;
}

int randomColor() {
	return random(0, 255);
}