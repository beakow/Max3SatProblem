#pragma once
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
#include <random>
#include <vector>
using namespace std;

class COptimizer
{
public:
	COptimizer();
	~COptimizer();

	bool bInitialize(string sSourcePath);
	void vRunIteration();
	CGAIndividual* pcChooseParent();
	int iGetBestResult();

private:
	int i_population_size;
	int i_crossover_probability;
	int i_mutation_probability;
	vector<CGAIndividual*>  v_population;
	CMax3SatProblem* pc_problem;
};
