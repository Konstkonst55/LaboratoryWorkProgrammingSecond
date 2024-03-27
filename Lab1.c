#include "Lab1.h"

/// <summary>
/// ѕечатает дату пасхи в указанном году
/// </summary>
/// <param name="year"></param>
void calculateEaster(int year) {
    int year19 = year % 19, year4 = year % 4, year7 = year % 7;
    int d = (19 * year19 + 15) % 30;
    int day = d + ((2 * year4 + 4 * year7 + 6 * d + 6) % 7);

    if (day <= 26) printf("%d April %d", day + 4, year);
    else printf("%d May %d", day - 26, year);
}

/// <summary>
/// ¬озвращает значение указанного числа в указанной степени
/// </summary>
/// <param name="num"></param>
/// <param name="exp"></param>
/// <returns></returns>
double calculatePow(double num, int exp) {
    double result = 1.0;

    if (exp >= 0) for (int i = 0; i < exp; i++) result *= num;
    else for (int i = 0; i > exp; i--) result /= num;

    return result;
}

/// <summary>
/// ¬озвращает значение косинуса с указанной точностью
/// </summary>
/// <param name="x"></param>
/// <param name="eps"></param>
/// <returns></returns>
double calculateCos(double x, const double eps) {
    x = fmod(x, 2 * M_PI); // период от -п до п
    double result = 1.0, term = 1.0;

    for (int i = 2; fabs(term) > eps; i += 2) {
        term *= -x * x / (i * (i - 1)); // новый элемент р€да
        result += term; 
    }

    return result;
}