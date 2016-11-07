#ifndef EQUATIONPARSER_H_
#define EQUATIONPARSER_H_

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "mytype.h"

class equationParser {
public:
	equationParser(const char *filename);                                             // constructor
	~equationParser();                                                                // destructor
	bool parse();                                                                     //method to parse the passing-in file
	void getAllVariables(std::vector<std::string>& var_vec);                          //get all variables on the left side
	bool getExpressionByVariable(std::string var, std::vector<std::string>& exp_vec); //return expression on the right side using variable name
	int  getEquationMapSize();                                                        //return equation hash map size
	void split(const std::string& s, char delim, std::vector<std::string>& v);        //utility method to split string by delimiter
	void print();                                                                     //utility function to print out the equation hash map for debugging

private:
	equation_map equations;                                                           // hash map to store the variables and cooresponding expressions
	const char *filename;                                                             // file name string
};

#endif /* EQUATIONPARSER_H_ */
