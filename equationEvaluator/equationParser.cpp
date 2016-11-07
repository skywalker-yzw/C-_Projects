#include "equationParser.h"
#include <iostream>

using namespace std;

equationParser::equationParser(const char *filename){
	this->filename = filename;
	equations.clear();
}


void equationParser::split(const std::string& str, char delim, std::vector<std::string>& v) {
	size_t i = 0;
	size_t pos = str.find(delim);
	size_t pos_tmp;

	// if there is not delimiter
	if (pos == string::npos) {
		//skip extra spaces
		while (str.at(i) == ' ') {
			i++;
		}
		v.push_back(str.substr(i, str.length()));
	} else {
		while ( pos != string::npos) {
			// skip the extra spaces
			pos_tmp = pos - 1;
			while (str.at(pos_tmp) == ' ') {
				pos_tmp--;
			}
			v.push_back(str.substr(i, pos_tmp - i + 1));

			i = ++pos;
			//skip the extra spaces here
			while(str.at(i) == ' ') {
				i++;
			}
			pos= str.find(delim, pos);

			if (pos == string::npos) {
				//skip extra spaces
				while (str.at(i) == ' ') {
					i++;
				}
				v.push_back(str.substr(i, str.length()));
			}
		}
	}
}

void equationParser::getAllVariables(std::vector<std::string>& var_vec) {
	equation_map::iterator it;

	for(it = equations.begin(); it != equations.end(); ++it) {
		var_vec.push_back(it->first);
	}
}

bool equationParser::getExpressionByVariable(std::string var, std::vector<std::string>& exp_vec) {
	//check if the variable exists
	if (equations.find(var) != equations.end()) {
		exp_vec = equations[var];
		return true;
	} else {
		return false;
	}
}

int equationParser::getEquationMapSize() {
	return equations.size();
}

bool equationParser::parse() {
	string line;
	string sub;
	ifstream file;
	string left_var;
	vector<string> right_side;
    size_t pos;
    size_t pos_tmp;

	file.open(filename);

	cout << "Reading from file " << filename << "..." << endl;

	if (file.is_open()) {
		while ( getline(file, line) ) {
			//split the line with = delimiter to get the variable
			pos = line.find('=');
			
			// skip the extra spaces
			pos_tmp = pos - 1;
			while (line.at(pos_tmp) == ' ') {
				pos_tmp--;
			}
			left_var = line.substr(0, pos_tmp + 1);
			
			//skip the extra spaces in the begining of the right side
			pos_tmp = pos + 1;
			while (line.at(pos_tmp) == ' ') {
				pos_tmp++;
			}
			sub = line.substr(pos_tmp, line.length());

			//split the line with + delimiter
			split(sub, '+', right_side);

			//add the components inside the righthand side into the equation hash map
			equations.insert(pair< string, vector<string> >(left_var, right_side));
			left_var.clear();
			right_side.clear();
		}

		//Debugging, print out the equation hash map
		//print();

		file.close();

		return true;
	} else {
		cout << "Can't open file " << filename << endl;
		return false;
	}
}

void equationParser::print() {
	//Debug, print out the values in the hash map
	equation_map::iterator it;
	vector<string>::iterator it_right;

	cout << "The " << getEquationMapSize() << " elements in the map are as follow: " << endl;

	for(it = equations.begin(); it != equations.end(); ++it) {
		//print the left part, which is the variables
		cout << it->first << ", ";

		//print the right part of the equation
		for(it_right = it->second.begin(); it_right != it->second.end(); ++it_right) {
			cout << (*it_right) << " ";
		}

		cout << endl;
	}
}

equationParser::~equationParser() {}
