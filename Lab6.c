#include "Lab6.h"
#include "MathUtils.h"
#include <math.h>

int calculateTriangleProperties(float a, float b, float c, float* perimeter, float* area) {
    if (a + b < c || a + c < b || b + c < a) return 0;

    float s = (a + b + c) / 2;

    *area = sqrt(s * (s - a) * (s - b) * (s - c));
    *perimeter = a + b + c;

    return 1;
}

int calculateProbability(int n, int m, double* probGirls, double* probBoys) {
    if (n < 0 || m < 0 || m > n) return 0;

    const double p = 0.45, q = 1 - p;
    unsigned long long cnm = factorial(n) / (factorial(m) * factorial(n - m));

    *probGirls = cnm * pow(p, m) * pow(q, n - m);
    *probBoys = cnm * pow(q, m) * pow(p, n - m);
}
