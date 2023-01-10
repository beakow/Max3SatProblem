#pragma once
#include <string>
#include <vector>
using namespace std;

class Clause 
{
public:
	Clause() {};
	Clause(string sClause);
	vector<int> getVariables() { return v_variables; };
	vector<bool> getFlags() { return v_flags; };
	int getMax();
	void vPrintClause();

private:
	vector<int> v_variables;
	vector<bool> v_flags; //true dla dodatniej
};