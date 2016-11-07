This is a brief user guide on how to use the code.

1: what's included in this package

A: This package includes the following items:
   1) source code files: 
   		mytype.h 
        equationParser.h
		equationEvaluator.h
		equationParser.cpp
		equationEvaluator.cpp
		main.cpp
		
   2) one make file: 
   	    makefile
		
   3) two self-made test files
   	    equations1.txt
		equations2.txt
 
   4) one user guide file
   	   ReadMe.txt


2: how to build and execute the code
 
A: It's easy to compile and run the code. To compile it, just go inside this folder and do "make all". It will generate a "Tesla" executable file. 
To run the code, just do "./Tesla testfile". Note that the application is expecting a text file and the file name as the command line argument. 
Error messages will be printed out if we fail to provide the file name or the file doesn't exist.  


3. Example output. 

A: Let's use the test file "equations1.txt" as an example. The output will like below:
Reading from file equations1.txt...
The final results are as follow: 
location = 26
offset = 17
origin = 8
random = 12
test = 51


4: what are the limitations of the program

A; Due to the time limitation, based on the problem descriptions, here are some assumptions made inside the code:
   1) we assume that the variable names inside the equation file are well formatted. It shouldn't contain any numbers, otherwise, the code logic might break
   
   2) All variables shown up on the right side of the equation should be defined, meaning, it should have a definied value, otherwise, the program will default the          variable value to 0
   
   3) A recursive approach is used to calculate the variable value in the program. So if we have huge amount of variables/expressions inside the file, we might face
      shortage of the stack space
    