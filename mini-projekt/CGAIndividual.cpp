#include "CGAIndividual.h"
#include <iostream>

CGAIndividual::CGAIndividual()
{
	v_genotype = vector<bool>();
}

CGAIndividual::CGAIndividual(int iVariablesNumber)
{
	v_genotype = vector<bool>();
	for (int i = 0; i < iVariablesNumber; i++) {
		int randomValue = std::rand() % 2;
		if (randomValue == 0) v_genotype.push_back(false);
		else v_genotype.push_back(true);
	}
}

CGAIndividual::CGAIndividual(CGAIndividual* pcOther)
{
	v_genotype = vector<bool>();
	for (int i = 0; i < (*pcOther).v_genotype.size(); i++) {
		v_genotype.push_back((*pcOther).v_genotype[i]);
	}
}

pair<CGAIndividual*, CGAIndividual*> CGAIndividual::pcCrossover(CGAIndividual* pcOtherParent)
{
	CGAIndividual* pc_child1 = new CGAIndividual;
	CGAIndividual* pc_child2 = new CGAIndividual;
	for (int i = 0; i < v_genotype.size(); i++) {
		int randomParent = rand() % 2;
		if (randomParent == 0) {
			(*pc_child1).v_genotype.push_back(v_genotype[i]);
			(*pc_child2).v_genotype.push_back((*pcOtherParent).v_genotype[i]);
		}
		else {
			(*pc_child1).v_genotype.push_back((*pcOtherParent).v_genotype[i]);
			(*pc_child2).v_genotype.push_back(v_genotype[i]);
		}
	}
	return make_pair(pc_child1, pc_child2);
}

void CGAIndividual::vMutation(int iMutationProbability)
{
	for (int i = 0; i < v_genotype.size(); i++) {
		int genMutationProbability = rand() % 100;
		if (genMutationProbability < iMutationProbability) v_genotype[i] = !v_genotype[i];
	}
}

void CGAIndividual::vOptimize(CMax3SatProblem* pcProblem)
{
	int random_clause_number = rand() % (*pcProblem).iGetNumberClauses();
	if (!(*pcProblem).bCheckChosenClause(v_genotype, random_clause_number)) {
		vector<int> v_variables = (*pcProblem).cGetChosenClause(random_clause_number).getVariables();
		for (int i = 0; i < v_variables.size(); i++) {
			int i_variable = v_variables[i];
			v_genotype[i_variable] = !v_genotype[i_variable];
		}
	}
}

int CGAIndividual::iFitness(CMax3SatProblem* pcProblem)
{
	return (*pcProblem).iCompute(v_genotype);
}
