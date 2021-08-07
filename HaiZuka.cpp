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
        Sleep(350);
    }
    cout << "\nStart..........!!!";
    Sleep(1000);

    system("cls");
    cout << std::endl;
    system("color F");
}

void question() {
    fstream f;
    string question[100], correct[100], answer;

    f.open("question.txt", std::ios::in);
    int N = 0;
    while (!f.eof()) {
        getline(f, question[N]);
        getline(f, correct[N++]);
    }
    f.close();
    
    cout << "Correctly answer " << N << " questions to continue." << endl;
    cout << "Contact https://github.com/zukahai/DrawImage-CPP if difficult" << endl << endl;
	for (int i = 0; i < N; i++) {
		cout << "Question " << (i + 1) << ": " << endl;
		do {
	        cout << question[i] << endl;
	        cout << "Your answer: ";
	        getline(cin, answer);
	        if (answer != correct[i]) {
	            cout << "The answer is not right to try again." << endl;
	        }
	    } while (answer != correct[i]);
	    cout << endl;
	}
}

void drawImage() {
	fstream f;
    f.open("input.txt", std::ios::in);
    if (f.is_open()) {
        std::string tp;
        while (getline(f, tp)) {
            cout << tp << std::endl;
            Sleep(100);
        }
        f.close();
    }
    string a;
    getline(cin, a);
}

int main() {
    question();
    loading();
	drawImage();
}
