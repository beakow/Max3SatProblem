#include "CMax3SatProblem.h"
#include <iostream>
#include <fstream>

CMax3SatProblem::CMax3SatProblem()
{
	v_problem_clauses = vector<Clause>();
}

bool CMax3SatProblem::bLoad(string sSourcePath)
{
	ifstream file;
	file.open(sSourcePath);
	if (!file) return false;
	string line;
	while (!file.eof()) {
		getline(file, line);
		if(line != "") v_problem_clauses.push_back(Clause(line));
	}
	file.close();
	return true;
}

int CMax3SatProblem::iCompute(vector<bool> vGenotype)
{
	int i_result = 0;
	for (int i = 0; i < v_problem_clauses.size(); i++) {
		vector<int> v_numbers = v_problem_clauses[i].getVariables();
		vector<bool> v_flags = v_problem_clauses[i].getFlags();
		if ((vGenotype[v_numbers[0]] == true && v_flags[0] == true) || (vGenotype[v_numbers[0]] == false && v_flags[0] == false) ||
			(vGenotype[v_numbers[1]] == true && v_flags[1] == true) || (vGenotype[v_numbers[1]] == false && v_flags[1] == false) ||
			(vGenotype[v_numbers[2]] == true && v_flags[2] == true) || (vGenotype[v_numbers[2]] == false && v_flags[2] == false)) 
			i_result++;
	}
	return i_result;
}

bool CMax3SatProblem::bCheckChosenClause(vector<bool> vGenotype, int iClauseNumber)
{
	vector<int> v_numbers = v_problem_clauses[iClauseNumber].getVariables();
	vector<bool> v_flags = v_problem_clauses[iClauseNumber].getFlags();
	if ((vGenotype[v_numbers[0]] == true && v_flags[0] == true) || (vGenotype[v_numbers[0]] == false && v_flags[0] == false) ||
		(vGenotype[v_numbers[1]] == true && v_flags[1] == true) || (vGenotype[v_numbers[1]] == false && v_flags[1] == false) ||
		(vGenotype[v_numbers[2]] == true && v_flags[2] == true) || (vGenotype[v_numbers[2]] == false && v_flags[2] == false))
		return true;
	else return false;
}

Clause CMax3SatProblem::cGetChosenClause(int iClauseNumber)
{
	return v_problem_clauses[iClauseNumber];
}

int CMax3SatProblem::iGetNumberVariables()
{
	int i_number = 0;
	for (int i = 0; i < v_problem_clauses.size(); i++) {
		i_number = max(v_problem_clauses[i].getMax(), i_number);
	}
	return i_number;
}

int CMax3SatProblem::iGetNumberClauses()
{
	return v_problem_clauses.size();
}
