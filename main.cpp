#include <iostream>
#include "GenAlgFun.h"
#include <time.h>  

using namespace::std;

int main() {
	setlocale(LC_ALL, "");
	srand(time(0));
	double x1, x2;
	int acc;
	cout << "enter x1, x2" << endl;
	cin >> x1 >> x2;
	cout << "enter accuracy" << endl;
	cin >> acc;
//	globmin(x1, x2, acc, myfun);
//	int a = 4;
//	long long b = (long long) a;
	const int n = 4;
		double pop[n] = {0, 0, 0, 0};
	long long population[n];
	popRandGenerator(x1, x2, pop, n);
	createIntPop(pop, population, n, acc);
//	cout << (a & 1) << endl;
	for (int i = 0; i < n; ++i) {
		cout << pop[i] << " " << population[i] << endl;
	}
	system("pause");
}
