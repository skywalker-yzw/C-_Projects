#include "equationEvaluator.h"

using namespace std;

equationEvaluator::equationEvaluator(equationParser& obj) {
	this->obj = &obj;
}

int equationEvaluator::recursiveCalculate(vector<string>& str_vec) {
	int sum = 0;
	int value;
	vector<string>::iterator it;
	vector<string> exp_vec;
	vector<string>::iterator it_tmp;

	for(it = str_vec.begin(); it != str_vec.end(); ++it) {
		string s = *it;

		//extract numbers and variables from the expression vector
		if (s.find('0') != string::npos || s.find('1') != string::npos ||
			s.find('2') != string::npos || s.find('3') != string::npos ||
			s.find('4') != string::npos || s.find('5') != string::npos ||
			s.find('6') != string::npos || s.find('7') != string::npos ||
			s.find('8') != string::npos || s.find('9') != string::npos) {
			//the assumption is variable and numbers are all well formatted, this will indicate a number in the expression
			sum += stoi(s);
		} else {  //it indicates another variable in the expression
			
			// first check the result hash map to see if we already calculate the value of that variable
			if (results.find(*it) != results.end()) {
				sum += results[(*it)];
			} else {   // this is a new variable
				exp_vec.clear();
				obj->getExpressionByVariable((*it), exp_vec);

				//recursive call to calculate the new variable
				value = recursiveCalculate(exp_vec);

				//also insert the new variable pair into the hash map to avoid redundant calculation
				results.insert(pair<string, int>((*it), value));
				
				// add up the new variable value
				sum += value;
		   }
		}
	}

	return sum;
}


void equationEvaluator::evaluate() {
	vector<string> var_vec;
	vector<string> exp_vec;
	vector<string>::iterator it;
	int sum = 0;

	obj->getAllVariables(var_vec);

	//loop through all the variables and calculate the values
	for(it = var_vec.begin(); it != var_vec.end(); ++it) {
		//only calculate the unknown variables to avoid redundant calculation
		if (results.find((*it)) == results.end()) {
			obj->getExpressionByVariable((*it), exp_vec);

			// recursively calculate the variable value
			sum = recursiveCalculate(exp_vec);

			//insert the value into the result hash map, only once
			results.insert(pair<string, int>((*it), sum));
		}
	}
}

void equationEvaluator::print() {
	result_map::iterator it;
	
	cout << "The final results are as follow: " << endl;
	for(it = results.begin(); it != results.end(); ++it) {
		cout << it->first << " = " << it->second << endl;
	}

}

equationEvaluator::~equationEvaluator() {}
