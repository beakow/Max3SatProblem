#include "CGAOptimizer.h"
#include <iostream>
using namespace std;

COptimizer::COptimizer()
{
	i_population_size = 200;
	i_crossover_probability = 40;
	i_mutation_probability = 40;
	v_population = vector<CGAIndividual*>();
	pc_problem = new CMax3SatProblem();
}

COptimizer::~COptimizer()
{
	for (int i = 0; i < v_population.size(); i++) {
		delete v_population[i];
	}
	v_population.clear();
	delete pc_problem;
}

bool COptimizer::bInitialize(string sSourcePath)
{
	if ((*pc_problem).bLoad(sSourcePath)) {
		int i_variables_number = (*pc_problem).iGetNumberVariables() + 1;
		for (int i = 0; i < i_population_size; i++) {
			v_population.push_back(new CGAIndividual(i_variables_number));
		}
		return true;
	}
	return false;
}

void COptimizer::vRunIteration()
{
	vector<CGAIndividual*> v_new_population = vector<CGAIndividual*>();
	CGAIndividual* pc_child1;
	CGAIndividual* pc_child2;
	while (v_new_population.size() < v_population.size()) {
		
		CGAIndividual* pc_parent1 = pcChooseParent();
		CGAIndividual* pc_parent2 = pcChooseParent();

		int i_random_crossover_probability = rand() % 100;

		if (i_random_crossover_probability < i_crossover_probability) {
			pair<CGAIndividual*, CGAIndividual*> pc_children = (*pc_parent1).pcCrossover(pc_parent2);
			pc_child1 = pc_children.second;
			pc_child2 = pc_children.first;
		}
		else {
			pc_child1 = new CGAIndividual(pc_parent1);
			pc_child2 = new CGAIndividual(pc_parent2);
		}

		(*pc_child1).vMutation(i_mutation_probability);
		(*pc_child2).vMutation(i_mutation_probability);

		(*pc_child1).vOptimize(pc_problem);
		(*pc_child2).vOptimize(pc_problem);

		v_new_population.push_back(pc_child1);
		v_new_population.push_back(pc_child2);
	}

	for (int i = 0; i < v_population.size(); i++) {
		delete v_population[i];
	}
	v_population.clear();
	v_population = v_new_population;
}

CGAIndividual* COptimizer::pcChooseParent()
{
	CGAIndividual* pcCandidate1 = v_population[rand() % i_population_size];
	CGAIndividual* pcCandidate2 = v_population[rand() % i_population_size];
	if ((*pcCandidate1).iFitness(pc_problem) > (*pcCandidate2).iFitness(pc_problem)) 
		return pcCandidate1;
	else 
		return pcCandidate2;
}

int COptimizer::iGetBestResult()
{
	int i_best_result = 0;
	for (int i = 0; i < v_population.size(); i++) {
		i_best_result = max(i_best_result, (*v_population[i]).iFitness(pc_problem));
	}
	return i_best_result;
}
