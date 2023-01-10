#include "Clause.h"
#include <iostream>

Clause::Clause(string sClause) // klauzula postaci ( liczba  liczba  liczba  )
{
	v_variables = vector<int>(3);
	v_flags = vector<bool>(3);
	int iterator = 1;
	char current_char = ' ';
	for (int i = 0; i < 3; i++) {
		if (current_char == ' ') {
			if (sClause[++iterator] == '-') {
				v_flags[i] = false;
				iterator++;
			}
			else v_flags[i] = true;
				
			current_char = sClause[iterator];
			v_variables[i] = 0;
		}
		while (current_char != ' ') {
			v_variables[i] *= 10;
			v_variables[i] += ((int)current_char - 48);
			current_char = sClause[++iterator];
		}
		current_char = sClause[++iterator];
	}
}

int Clause::getMax()
{
	return max(v_variables[0], max(v_variables[1], v_variables[2]));
}

void Clause::vPrintClause()
{
	for (int i = 0; i < 3; i++) {
		if (!v_flags[i]) cout << "-";
		cout << v_variables[i] << ", ";
	}
}
