#include "equationEvaluator.h"
#include "equationParser.h"
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "Please only pass in the full file name as argument, include file extension!!" << endl; 
	} else {
		equationParser parser(argv[1]);
		if (parser.parse() == true) {
			equationParser& obj = parser;

			equationEvaluator evaluator(obj);
			evaluator.evaluate();
			evaluator.print();
		} else {
			cout << "Parse file failed. Please check if the file exists!!" << endl;
		}		
	}
}

