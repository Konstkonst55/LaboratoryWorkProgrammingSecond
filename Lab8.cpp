#include "Lab8.h"

bool compareSchools(School& a, School& b) {
    double perA = (double)(a.enrolled) / a.graduates * 100;
    double perB = (double)(b.enrolled) / b.graduates * 100;
    return perA > perB;
}

string* getUniqueFaculties(Room rooms[], int len, int& uniqFacCount) {
    string* uniqueFaculties = new string[1];
    uniqFacCount = 0;

    for (int i = 0; i < len; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (rooms[i].faculty == rooms[j].faculty) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            uniqFacCount++;
            string* newUniqueFaculties = new string[uniqFacCount];
            copy(uniqueFaculties, uniqueFaculties + uniqFacCount - 1, newUniqueFaculties);
            newUniqueFaculties[uniqFacCount - 1] = rooms[i].faculty;
            delete[] uniqueFaculties;
            uniqueFaculties = newUniqueFaculties;
        }
    }

    return uniqueFaculties;
}

void printSchoolData(School schools[], int n) {
    const string space = "  ";
    int* indices = new int[n];
    
    for (int i = 0; i < n; i++) indices[i] = i;

    sort(indices, indices + n, [&](int i, int j) { return compareSchools(schools[i], schools[j]); });

    for (int i = 0; i < n; ++i) {
        int index = indices[i];
        double percentage = static_cast<double>(schools[index].enrolled) / schools[index].graduates * 100;

        cout << "Школа #" << schools[index].number << endl
            << space <<"Выпуск: " << schools[index].graduates << endl
            << space <<"Поступление: " << schools[index].enrolled << endl
            << space <<"Процент: " << percentage << "%" << endl << endl;
    }
}

void printRoomData(Room rooms[], int n) {
    const string space = "  ";
    int uniqFacCount = 0;
    string *faculties = getUniqueFaculties(rooms, n, uniqFacCount);

    for (int i = 0; i < uniqFacCount; i++) {
        int roomsCount = 0;
        int residentsCount = 0;
        double totalArea = 0.0;

        for (int j = 0; j < n; j++) {
            if (rooms[j].faculty == faculties[i]) {
                roomsCount++;
                residentsCount += rooms[j].residents;
                totalArea += rooms[j].area;
            }
        }

        cout << "Факультет: " << faculties[i] << endl
            << space << "Кол-во комнат: " << roomsCount << endl
            << space << "Кол-во проживающих: " << residentsCount << endl
            << space << "Средняя площадь на проживающего: " << totalArea / residentsCount << endl << endl;
    }
}