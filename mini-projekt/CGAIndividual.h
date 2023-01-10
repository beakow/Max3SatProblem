#pragma once
#include "CMax3SatProblem.h"
#include <vector>
using namespace std;

class CGAIndividual
{
public:
	CGAIndividual();
	CGAIndividual(int iVariablesNumber);
	CGAIndividual(CGAIndividual* pcOther);
	~CGAIndividual() {};
	pair<CGAIndividual*, CGAIndividual*> pcCrossover(CGAIndividual* pcOtherParent);
	void vMutation(int iProbability);
	void vOptimize(CMax3SatProblem* pcProblem);
	int iFitness(CMax3SatProblem* pcProblem);
	vector<bool> getGenotype() { return v_genotype; };

private:
	vector<bool> v_genotype;
};