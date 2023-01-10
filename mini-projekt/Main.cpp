#include "CGAOptimizer.h"
#include <iostream>


int main(int iArgCount, char** ppcArgValues)
{
	COptimizer c_opt;
	c_opt.bInitialize("test.txt");
	for (int i = 0; i < 10; i++) {
		cout << i << ": ";
		c_opt.vRunIteration();
		int result = c_opt.iGetBestResult();
		cout << result << endl;
	}
}