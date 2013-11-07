#include <locale.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "GenAlgFun.h"
#include <iostream>
#include <cmath>

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
void popRandGenerator(double a, double b, double pop[], int n) {
//	pop[0] = a;
//	pop[1] = b;
	for (int i = 0; i < n; ++i){
		pop[i] = (rand() % (int)floor(b - a)) + a + randver();
	}
}

//создаёт популяцию из целочисленных особей
void createIntPop(double pop[], long long population[], long n, int acc) {
	for (int i = 0; i < n; ++i) {
		population[i] = (long long)(pop[i] * pow(10.0, acc));
	}
}

//на самом деле, это никакой не кроссинговер.
//Это среднее арифметическое брачных пар.
void crossover(long long population[], long long newPopulation[], int n){
	int k = n;
	for (int i = 0; i < n; ++i)
		newPopulation[i] = population[i];
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++ j){
			newPopulation[k] = (population[i] + population[j]) / 2;
			++k;
		}
	}
}

//создаёт случайную маску для мутации
long long createRandMutationMask(long long n){
	int mp = 0;
	while (n > 1) {
		n /= 2;
		++mp;
	}
	return (long long)pow(2.0, rand() % (mp - 1));
}

//мутация
void mutation(long long newPopulation[], int n, int m){
	for	(int i = n; i < m; ++i) {
		double ver = randver(); 
		if (ver > 0.7)
			newPopulation[i] = newPopulation[i] ^ createRandMutationMask(newPopulation[i]);
	}
}

//компаратор для qsort
int compare (const void * a, const void * b){
	select* c = (select*)a;
    select* d = (select*)b;
  return (c->y > d->y);
}

//возведение числа base в степень exp для целых
int intpow(int base, int exp){
	int res = 1;
	if (exp < 0)
		return 0;
	if (exp == 0)
		return 1;
	for (int i = 1; i <= exp; ++i)
		res *= base;
	return res;
}

//поиск глобального минимума функции f на отрезке [x1, x2]
void globmin(double x1, double x2, int acc, DFD f) {
	const int n = 4;
	const int m = 10;
	double pop[n];
	long long population[n];
	long long newPopulation[m];
	select generation[m];
	bool flag = true;
	int counter = 0;
	popRandGenerator(x1, x2, pop, n);
	while ( counter < 1000){                     //magic
		createIntPop(pop, population, n, acc);
		crossover(population, newPopulation, n);
		mutation(newPopulation, n, m);
		for (int i = 0; i < m; ++i){
			generation[i].x = (newPopulation[i] / pow(10.0, acc));
			generation[i].y = f(generation[i].x);
		}
		qsort(generation, m, sizeof(select), compare);
		for (int i = 0; i < n; ++i){
			pop[i] = generation[i].x;
		}
//		flag = (generation[m - 1].y - generation[0].y) > 0.001;
		++counter;
	}
//	cout << "globmin is " << generation[0].y << " in x =  " << generation[0].x << endl;
	printf("globmin is %7.5f in x = %7.5f \n", generation[0].y, generation[0].x);
}
