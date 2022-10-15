#include <iostream>
#include <ctype.h>
#include <cstring>
#include "Calculator.hh"
#include "Calculator.cpp"


using namespace std;
/*
bool isNumber(string &str) {
    for (int i = 0; i < str.length(); i++) if (!isdigit(str[i])) return false;
    return true;
}
*/
void podaj_liczby (float &a, float &b, float &c)
{
	int timer=3;
	cout << "Podaj pierwsza liczbe: " << endl;
	cin >> a;
	while(!cin.good() && timer >0)
	{
	timer--;
	system("cls");
	cout << "To nie liczba. Zostalo prob: " << timer << endl;
	cin >> a;
	}
	
    cout << "Podaj druga liczbe: " << endl;
	cin >> b;
	while(!cin.good() && timer >0)
	{
	timer--;
	system("cls");
	cout << "To nie liczba. Zostalo prob: " << timer << endl;
	cin >> b;
	} 	
	
	/*cin >> c;
	while(!cin.good() && timer >0)
	{
	timer--;
	cout << "To nie liczba. Zostalo prob: " << timer << endl;
	cin >> c;
	}
	
	if(timer==0)
	{
	cout << "Program konczy dzialanie.";
	}
*/
}


 
int main() 
{
	float a, b, c;
	int dzialanie, timer = 3;
	podaj_liczby(a, b, c);
	
    cout << "Dzialanie prosze reprezentowac tymi liczbami: " << endl << "+ -> 1" << endl << "- -> 2" << endl << "* -> 3" << endl << "/ -> 4" << endl;
	cin >> dzialanie;
	
	Calculator kocham_obiektowke(a, b, c);
        switch (dzialanie) 
	{
 
            case 1:
            kocham_obiektowke.dodawanie();
                break;
            case 2:
            kocham_obiektowke.odejmowanie();
                break;
 
            case 3:
            kocham_obiektowke.mnozenie();
                break;
 
            case 4:
            kocham_obiektowke.dzielenie();
                break;
            default:
                cout << "Bledna opcja!" << endl;
                timer--;
                if (timer == 0)return 0;
 
         }
            cout << "Wynik to: " << kocham_obiektowke.get(2) << endl;
    return 0;
}
 
