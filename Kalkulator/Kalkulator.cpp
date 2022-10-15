#include <iostream>
#include <thread>
#include <ctime>
#include <ctype.h>
#include <string>
 
using namespace std;
 
 
bool isNumber(string &str) {
    for (int i = 0; i < str.length(); i++) if (!isdigit(str[i])) return false;
    return true;
}
 
 
bool shouldEnd = true;
void main_main() {
    string sa, sb;// , sc;
    int a, b=0, c;
    int dzialanie = 1;
    int mylocal_timer = 3;
    char *pEnd = NULL;
 
    cout << "Podaj pierwsza liczbe: " << endl;
    cin >> sa;
    shouldEnd = false;
    if (!isNumber(sa)) {
        while (!isNumber(sa)) {
            cout << "To nie jest liczba! " << endl;
            mylocal_timer--;
            if (mylocal_timer == 0)return;
            cin >> sa;
        }
    }
    else {
        //std::string::size_type sz;  
        a = stoi(sa, nullptr);
        system("cls");
        cout << "Podaj druga liczbe: " << endl;
        cin >> sb;
        if(!isNumber(sb)){
            while (!isNumber(sb)) {
                cout << "To nie jest liczba! " << endl;
                mylocal_timer--;
                if (mylocal_timer == 0)return;
                cin >> sb;
            }
        }
        else {
            b = stoi(sb, nullptr);
            system("cls");
            cout << "Dzialanie prosze reprezentowac tymi liczbami: " << endl << "+ -> 1" << endl << "- -> 2" << endl << "* -> 3" << endl << "/ -> 4" << endl;
            cin >> dzialanie;
            system("cls");
            switch (dzialanie) {
 
            case 1:
                c = a + b;
                break;
 
            case 2:
                c = a - b;
                break;
 
            case 3:
                c = a*b;
                break;
 
            case 4:
                if (b == 0) {
                    cout << "Blad matematyczny!" << endl; return;
                }
                else {
                    c = a / b;
                }
                break;
            default:
                cout << "Bledna opcja!" << endl;
                mylocal_timer--;
                if (mylocal_timer == 0)return;
 
            }
            cout << "Wynik to: " << c << endl;
            for (;;);
        }
    }
}
 
int main() {
 
 
    time_t start, koniec;
    time(&start);
    time(&koniec);
 
 
    thread *mainThread = new thread(main_main);
    while (difftime(koniec, start) <= 5)time(&koniec);
 
    if (!shouldEnd)mainThread->join();
 
    return 0;
}
