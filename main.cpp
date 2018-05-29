/**
 * Started by Najib 3/21/18
 **/
//Author: Jason Yang
///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "functions.h"
#include "bigint/bigint.h"

/* 
CONCISE DESCRIPTION OF FUNCTION:
By initializing a vector as the "trigram" of the file given by the user,
each term of the vector is printed to the command line, seperated by spaces.
If there are more arguments than 2, the program will compare frequency vectors
with that of the files of each previous argument to the last argument.
*/
int main(int argc, char *argv[]) {
	if (argc == 2){
  		std::vector <int> gram = trigram(argv[1]);
  		std::cout << gram[0];	
  		for (size_t i = 1; i < gram.size(); ++i){
  			std::cout << " ";
    		std::cout << gram[i];		
   		}
   		std::cout << std::endl;
	} else {
		std::vector <int> testfreq = trigram(argv[argc-1]);	//Note to self: last argument in command line is test. Freqvec for test is found.
		double simnumber = learn(testfreq,trigram(argv[1]));	
		double newsim = 0;
		char *language = argv[1];
		for (int n = 2; n < argc - 1; ++n){	
			newsim = learn(testfreq, trigram(argv[n])); 	
			std::cout << newsim;
			std::cout << " ";
			std::cout << argv[n];
			std::cout << std::endl;
			if (simnumber < newsim){
				simnumber = newsim;		//Going through each argument as a file name, The highest cos^2(theta) is stored in simnumber,
				language = argv[n];		//and the language corresponding to that simnumber is stored in language
			}
  			
   		}
   		std::cout << "Answer: ";
   		std::cout << language;
   		std::cout << std::endl;
	}
    return 0;
}
