#ifndef GEN_ALG_FUN_H 
#define GEN_ALG_FUN_H 


	struct select{
		double y;
		double x;
	};

	typedef double (* DFD)(double);
	
	double myfun(double x);
	double myfun1(double x);
	double randver();
	void popRandGenerator(double a, double b, double pop[], int n);
	void createIntPop(double pop[], long long population[], long n, int acc);
	void crossover(long long population[], long long newPopulation[], int n);
	

#endif /* GEN_ALG_FUN_H */
