#include "MathUtils.h"

int getRandomInt(int min, int max) {
	return min + rand() % (max - min + 1);
}

float getRandomFloat(float min, float max) {
	return min + (rand() / (float)RAND_MAX) * (max - min + 1);
}

unsigned long long factorial(unsigned short x)
{
	unsigned long long f = 1;

	for (short i = 1; i <= x; ++i) f *= i;

	return f;
}