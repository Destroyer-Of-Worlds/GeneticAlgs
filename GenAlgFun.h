#ifndef GEN_ALG_FUN_H 
#define GEN_ALG_FUN_H 
#include <vector>

	typedef double (* DFD)(double);
	
	double myfun(double x);
	double myfun1(double x);
	double byaka(double x);
	double randver();
	void popRandGenerator(double a, double b, std::vector<double> & pop, int n);
	void crossover(std::vector<double> & population, std::vector<double> & newPopulation, int n, int m, double x1, double x2);
	void mutation(std::vector<double> & newPopulation, int n, double x1, double x2);
	bool compare (std::vector<double> & a, std::vector<double> & b);
	void globmin(double x1, double x2, DFD f);

#endif /* GEN_ALG_FUN_H */
