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

//случайное число от 0 до 1
double randver() {
	return ((double)rand()) / RAND_MAX;
}

//генерация популяции из n особей
//на вход подаётся отрезок [a, b]
//на выходе получаем массив чисел pop[] 
void popRandGenerator(double a, double b, double pop[], int n) {
	for (int i = 0; i < n; ++i){
		pop[i] = (rand() % (int)floor(b - a)) + a + randver();
	}
}

//создаёт популяцию из целочисленных особей
void createIntPop(double pop[], long long population[], long n, int acc) {
	for (int i = 0; i < n; ++i) {
		population[i] = (long long)floor(pop[i] * pow(10.0, acc));
	}
}

//на самом деле, это никакой не кроссинговер.
//Это среднее арифметическое брачных пар.
void crossover(long long population[], long long newPopulation[], int n){
	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n - 1; ++ j){
			newPopulation[k] = floor((population[i] + population[j]) / 2);
			++k;
		}
	}
}

//создаёт маску для мутации
long long createMutationMask(long long n){
	
}
