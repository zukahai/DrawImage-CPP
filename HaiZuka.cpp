#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

void loading() {
    system("color 0A");

    char a = 177, b = 219;

    cout << "\n\t\t\t\t\t\tLoading...\n\n";
    cout << "\t\t\t\t\t";

    for (int i = 0; i < 26; i++)
        cout << a;

    cout << "\r";
    cout << "\t\t\t\t\t";

    for (int i = 0; i < 26; i++) {
        cout << b;
        Sleep(100);
    }
    cout << "\nStart..........!!!";
    Sleep(500);

    system("cls");
    cout << std::endl;
    system("color F");
}

void question() {
    fstream f;
    string question, correct, answer;

    f.open("question.txt", std::ios::in);
    if (f.is_open()) {
        getline(f, question);
        getline(f, correct);
        f.close();
    }

    do {
        cout << question << " ";
        getline(cin, answer);
        if (answer != correct) {
            cout << "Cau tra loi khong dung! Vui long thu lai...\n";
        }
    } while (answer != correct);
    cout << "Ban da tra loi chinh xac!!!";
}

void drawImage() {
	fstream f;
    f.open("input.txt", std::ios::in);
    if (f.is_open()) {
        std::string tp;
        while (getline(f, tp)) {
            cout << tp << std::endl;
            Sleep(20);
        }
        f.close();
    }
}

int main() {
    question();
    loading();
	drawImage();

    return 0;
}
