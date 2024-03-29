#include "Lab11.h"

string getFirstWord(const string& s) {
    string::const_iterator it1 = find_if(s.begin(), s.end(), isalpha);
    string::const_iterator it2 = find_if(it1, s.end(), not_fn(isalpha));

    return string(it1, it2);
}

void showMenu(int& choice) {
    cout << "1. Создать файл из N записей" << endl
        << "2. Просмотреть файл" << endl
        << "3. Добавить новую запись" << endl
        << "4. Удалить записи с общим весом < 10 кг" << endl
        << "5. Изменить вес вещей пассажира" << endl
        << "0. Выход" << endl << endl
        << "Выберите действие: ";
    cin >> choice;
    cin.ignore();
}

void addRecord(const string filename) {
    ofstream file(filename, ios::binary);

    if (!file) {
        cerr << endl << "Не удалось открыть файл для записи" << endl << endl;
        return;
    }

    Passenger passenger;

    cout << "Введите ФИО пассажира: ";
    cin.ignore();
    cin.getline(passenger.fullName, sizeof(passenger.fullName)); // todo

    cout << "Введите количество занимаемых багажом мест: ";
    cin >> passenger.baggageCount;

    cout << "Введите общий вес вещей: ";
    cin >> passenger.weight;
    cout << endl;
    cin.ignore();

    file.write(reinterpret_cast<char*>(&passenger), sizeof(Passenger));

    file.close();
}

void createFile(const string filename, int recordNum) {
    ofstream file(filename, ios::binary);

    if (!file) {
        cerr << endl << "Не удалось открыть файл для записи" << endl << endl;
        return;
    }

    for (int i = 0; i < recordNum; i++) addRecord(filename);

    file.close();
}

void viewFile(const string filename) {
    ifstream file(filename, ios::binary);

    if (!file) {
        cerr << endl << "Не удалось открыть файл для чтения" << endl << endl;
        return;
    }

    Passenger passenger;
    while (file.read(reinterpret_cast<char*>(&passenger), sizeof(Passenger))) {
        cout << "ФИО: " << passenger.fullName << endl
            << "Количество занимаемых багажом мест: " << passenger.baggageCount << endl
            << "Общий вес вещей: " << passenger.weight << endl << endl;
    }

    file.close();
}

void deleteRecords(const string filename, function<bool (const Passenger&)> delCondition) {
    const string tempFilename = "data\\temp.dat";
    ifstream ifs(filename, ios::binary);
    ofstream ofs(tempFilename);

    if (!ifs && !ofs) {
        cerr << endl << "Не удалось открыть файл для изменения" << endl << endl;
        return;
    }

    Passenger passenger;
    while (ifs.read(reinterpret_cast<char*>(&passenger), sizeof(Passenger))) {
        if (delCondition(passenger)) {
            ofs.write(reinterpret_cast<char*>(&passenger), sizeof(Passenger));
        }
    }

    ifs.close();
    ofs.close();

    remove(filename.c_str());
    int renameStatus = rename(tempFilename.c_str(), filename.c_str());
}

void updateWeight(const string filename, const string surname, const float newWeight) {
    fstream fs(filename, ios::binary | ios::in | ios::out);
    Passenger passenger;
    streampos pos;
    bool found = false;

    while (!fs.eof()) {
        pos = fs.tellg();

        fs.read(reinterpret_cast<char*>(&passenger), sizeof(Passenger));

        if (fs && getFirstWord(passenger.fullName) == surname) {
            found = true;
            passenger.weight = newWeight;
            fs.seekp(pos);
            fs.write(reinterpret_cast<char*>(&passenger), sizeof(Passenger));
            break;
        }
    }

    fs.close();

    if (found) cout << "Вес вещей пассажира успешно изменен" << endl;
    else cout << "Пассажир с такой фамилией не найден" << endl;
}

void runPassengerFileManager(string& filename) {
    filename = "data\\" + filename;
	int choice = 0;

    do {
        showMenu(choice);

        switch (choice) {
            case 1: {
                int N;
                cout << endl << "Введите количество записей: ";
                cin >> N;
                cin.ignore();
                createFile(filename, N);
                break;
            }

            case 2: {
                viewFile(filename);
                break;
            }
                
            case 3: {
                addRecord(filename);
                break;
            }

            case 4: {
                deleteRecords(filename, [&](const auto p) { return p.weight >= 10.0; });
                break;
            }

            case 5: {

                break;
            }

            case 0: break;
            default: cerr << endl << "Неверный выбор. Попробуйте снова" << endl << endl;
        }
    } while (choice != 0);
}