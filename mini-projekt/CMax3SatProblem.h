#pragma once
#include "Clause.h"
#include <string>
#include <vector>
using namespace std;

class CMax3SatProblem
{
public:
	CMax3SatProblem();

	virtual ~CMax3SatProblem() {};

	bool  bLoad(string sSourcePath);

	int iCompute(vector<bool> vGenotype);

	bool bCheckChosenClause(vector<bool> vGenotype, int iClauseNumber);

	Clause cGetChosenClause(int iClauseNumber);

	int iGetNumberVariables();

	int iGetNumberClauses();


protected:
	vector<Clause> v_problem_clauses;
};



