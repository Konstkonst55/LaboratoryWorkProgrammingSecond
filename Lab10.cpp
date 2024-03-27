#include "Lab10.h"

void sortWordFile() {
    vector<string> words;
    string line;
    ifstream file;

    try {
        file.open("data\\10_data.txt");

        while (getline(file, line)) {
            istringstream stream(line);
            string word;

            while (stream >> word) words.push_back(word);
        }

        file.close();

        sort(words.begin(), words.end(), [&](string a, string b) { return a < b; });

        ofstream outputfile("data\\10_result.txt");

        for (const auto& word : words) outputfile << word << " ";

        outputfile.close();
    }
    catch (ifstream::failure& ifse) {
        cerr << "������ ��� ������ � ������: " << ifse.what() << endl;
    }
    catch (exception& e) {
        cerr << "������: " << e.what() << endl;
    }
}