#ifndef EQUATIONEVALUATOR_H_
#define EQUATIONEVALUATOR_H_

#include <vector>
#include <string>
#include <map>
#include "mytype.h"
#include "equationParser.h"

class equationEvaluator {
public:
	equationEvaluator(equationParser& obj);                     // constructor
	~equationEvaluator();                                       // destructor 
	int recursiveCalculate(std::vector<std::string>& str_vec);  // utility method to recursively calculate the variable value based on its definition
	void evaluate();                                            // method to loop through all variables and calcuate the values for them
	void print();                                               // utility method to print out the final results

private:
	equationParser* obj;
	result_map results;                                         // hash map to store the variable and its value
};

#endif /* EQUATIONEVALUATOR_H_ */
