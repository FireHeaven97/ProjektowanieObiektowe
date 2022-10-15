#include <iostream>
#include <cstring>
#include <ctype.h>
#include "Calculator.hh"

using namespace std;

bool isNumber(string &str);

Calculator::Calculator(float x, float y, float z)
{
	this->a=x;
	this->b=y;
	this->c=z;
}

void Calculator::dodawanie(){
	c=a+b;
}

void Calculator::odejmowanie(){
	c=a-b;
}

void Calculator::mnozenie(){
	c=a*b;
}

void Calculator::dzielenie(){
if (b == 0) {
        cout << "Blad matematyczny!" << endl; return;
        }
        else {
            c = a / b;
        }
}

float Calculator::get(int x)
{if(x==0) return a;
 if(x==1) return b;
 else return c;
}
