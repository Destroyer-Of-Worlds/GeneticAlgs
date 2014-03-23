#include <locale.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "GenAlgFun.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace::std;

//пример целевой функции
double myfun(double x) {
	return 5 - 24 * x + 17 * pow(x, 2) - (11/3.0) * pow(x, 3) + (1/4.0) * pow(x, 4);
}

//ещё один пример целевой функции
double myfun1(double x){
	return sin(5 * x) - 2 * cos(x) + 3;
}

//совсем бяка
double byaka(double x){
	return fabs(sin(10 * x) + 0.8*cos(20*sqrt(2.0)*x)+0.5*sin(15*sqrt(3.0)*x));
}

//случайное число от 0 до 1
double randver() {
	return ((double)rand()) / RAND_MAX;
}

//генерация популяции из n особей
//на вход подаётся отрезок [a, b]
//на выходе получаем массив чисел pop[] 
void popRandGenerator(double a, double b, vector<double> & pop, int n) {
	pop.push_back(a);
	pop.push_back(b);
	for (int i = 0; i < n; ++i){
		double buf = (rand() % (int)floor(b - a)) + a + randver();
		pop.push_back(buf);
	}
}

//на самом деле, это никакой не кроссинговер.
//теперь это промежуточная рекомбинация
void crossover(vector <double> & population, vector<double> & newPopulation, int n, int m, double x1, double x2){
	int k = 0;
	for (int i = 0; i < m; ++i){
		double pop;
		do{
		int ind1 = rand() % n;
		int ind2 = rand() % n;
		double alpha = randver()*1.5-0.25;
		 pop = alpha * population[ind1] + (1 - alpha)* population[ind2];
		} while ((pop>x2)||(pop<x1));
	newPopulation.push_back(pop);
		}
}

//мутация
void mutation(vector<double> & newPopulation, int n, double x1, double x2){
	double alpha = 0.5 * (x2-x1);
	for	(int i = 0; i < n; ++i) {
		double pop=0;
		do{ 
			pop=newPopulation[i];
		if (randver() > 0.25)
			continue;
		int signum = randver() > 0.5 ? -1 : 1;
		double delta = 0;
		for (int j = 0; j < 20; ++j){
			int a = randver() > 1.0/20. ? 0 : 1;
			delta += a * pow(2.0, -j);
		}
		pop += signum * alpha * delta;
		}while ((pop>x2)||(pop<x1));
		newPopulation[i]=pop;
	}
}

//компаратор для sort
bool compare (vector<double> & a, vector<double> & b){
	return (a[a.size()-1] < b[b.size()-1]);
}

/*
union{
struct {
	int a1:1;
	int a2:1;
	...
		int a32:1;
}a;
float b;
}
*/
//поиск глобального минимума функции f на отрезке [x1, x2]
void globmin(double x1, double x2, DFD f) {
	const int n = 50;
	const int m = 500;
	vector<double> population;
	vector<double> newPopulation;
	vector<vector<double> > generation;
	generation.assign(m, vector<double>(2));
	int counter = 0;
	popRandGenerator(x1, x2, population, n);
	while (counter < 1000){
		crossover(population, newPopulation, n,m,x1,x2);
		mutation(newPopulation, m, x1,x2);
		for (int i = 0; i < m; ++i){
			generation[i][0] = (newPopulation[i]);
			generation[i][1] = f(generation[i][0]);
		}
		sort(generation.begin(), generation.end(), compare);
		for (int i = 0; i < n; ++i){
			population[i] = generation[i][0];
		}		
		++counter;
//		cout << counter << endl;
	}
	cout << "globmin is " << generation[0][1] << " in x =  " << generation[0][0] << endl;
}

