#include <iostream>
#include "GenAlgFun.h"
#include <time.h> 

using namespace::std;

int main() {
	setlocale(LC_ALL, "");
	srand(time(0));
	double x1, x2;
	cout << "enter x1, x2" << endl;
	cin >> x1 >> x2;
	globmin(x1, x2, myfun1);
	system("pause");
}
