#include<iostream>
#include<string>
#include<windows.h>

using namespace std;

bool isNumberNumeric();
int inputNumber(int a);

class  Appliances            	 //базовый 
{
protected:
	double buy;
public:
	Appliances(int w) {
		buy = w;
	}				 // конструктор 
	virtual void proc() = 0;
	virtual void print() = 0;
};

class technik_sen : public Appliances //произв
{
public:
	technik_sen(int buy) :Appliances(buy) {}
	void print()
	{
		cout << "Клиенты в сентябре";
	}
	void proc()
	{
		cout << "купили" << buy << " единиц техники. Процент покупок:" << buy / 20 * 100 << "%." << endl;
	}
};

class technik_ok : public Appliances //производный 
{
public:
	technik_ok(int buy) :Appliances(buy) {}
	void print()
	{
		cout << "Клиенты в октябре";
	}
	void proc()
	{
		cout << "купили " << buy << " единиц техники. Процент покупок:" << buy / 32 * 100 << "%." << endl;
	}
};

class technik_nov : public Appliances //производный
{
public:
	technik_nov(int buy) :Appliances(buy) {}
	void print()
	{
		cout << "Клиннты в ноябре ";
	}
	void proc()
	{
		cout << "купили " << buy << " единиц техники. Процент покупок:" << (buy / 25) * 100 << "%." << endl;
	}
};


int main() {

	setlocale(0, " ");
	int s, o, n;
	cout << "Количество техники, которую купили в:" << endl
		<< "сентябре (из колличества 20 штук):";  s = inputNumber(20); technik_sen sen(s);
	cout << "октябре (из колличества 32 штук):"; o = inputNumber(32); technik_ok ok(o);
	cout << "ноябре (из колличества 25 штук):"; n = inputNumber(25); technik_nov nov(n);
	cout << endl;

	Appliances* h[3];
	h[0] = &sen; h[1] = &ok; h[2] = &nov;

	for (int i = 0; i < 3; i++) {
		h[i]->print(); h[i]->proc(); cout << endl;
	}
}

bool isNumberNumeric()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
}
int inputNumber(int a)
{
	double number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric() && number >= 0 && number <= a && number - int(number) == 0)
			return number;
		else
			cout << "Некорректный ввод! Повторите попытку: ";
	}
}
