#include <iostream> 
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

double f(double x, double y)
{
	return cos(x) + log10(x) + y;
}

struct Chromosom
{
	double x, y;
	double value;
	Chromosom(double x, double y)
	{
		this->x = x;
		this->y = y;
		this->value = f(x, y);
	}
};
int main()
{
	double x[4], y[4];
	for (int i = 0; i < 4; i++) //Заполняем массив аргументов случайными значениями
	{
		x[i] = rand()%2 - 2;
		y[i] = rand()%2 - 2;
	}

	Chromosom c1(x[0], y[0]);
	Chromosom c2(x[1], y[1]);
	Chromosom c3(x[2], y[2]);
	Chromosom c4(x[3], y[3]);
	vector<Chromosom> v; //Создаём вектор хромосом
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(c3);
	v.push_back(c4);

	int N = 1;
	while (N <= 100)
	{
		sort(v.begin(), v.end(), [](Chromosom &c1, Chromosom &c2) //Сортируем в порядке убывания
		{
			return c1.value > c2.value;
		});
		x[3] = x[0];
		swap(y[0], y[1]);
		y[3] = y[2];
		y[2] = y[1]; //Скрещиваем 1-ую хромосому со 2ой и 3ей

		y[rand() % 4] += rand()%2;
		x[rand() % 4] += rand()%2; // Мутация случайной хромосомы

		for (int i = 0; i < 4; i++)
		{
			cout << x[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << y[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << f(x[i], y[i]) << "\t";
		}
		cout << endl;
		cout << "=================================" << endl;
		Chromosom c1(x[0], y[0]); //Создаём новое поколение
		Chromosom c2(x[1], y[1]);
		Chromosom c3(x[2], y[2]);
		Chromosom c4(x[3], y[3]);
		vector<Chromosom> v; //Новый вектор
		v.push_back(c1);
		v.push_back(c2);
		v.push_back(c3);
		v.push_back(c4);

		N++;
	}
}
