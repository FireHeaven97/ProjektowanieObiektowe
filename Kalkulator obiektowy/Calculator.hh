#ifndef Calculator_hh
#define Calculator_hh 

class Calculator
{ 
private:
	float a;
	float b;
	float c;
	
public:
	void dodawanie();
	void odejmowanie();
	void mnozenie();
	void dzielenie();
	Calculator(float x, float y, float z);
	~Calculator(){}
	float get(int x);
};

#endif
