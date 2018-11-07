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
		x[i] = rand();
		y[i] = rand();
	}

	Chromosom c1(x[0], y[0]);
	Chromosom c2(x[1], y[1]);
	Chromosom c3(x[2], y[2]);
	Chromosom c4(x[3], y[3]);
	vector<Chromosom> v;
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(c3);
	v.push_back(c4);

	int N = 1;
	while (N<100)
