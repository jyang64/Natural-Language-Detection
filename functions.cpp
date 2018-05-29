/**
 * Started by Najib 3/21/18
 **/
//Author: Jason Yang

///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "functions.h"
#include "bigint/bigint.h"
#include <deque>
#include "math.h"

///////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS GO HERE
///////////////////////////////////////////////////////////////////

/* 
CONCISE DESCRIPTION OF FUNCTION:
"trigram()" creates a vector of zeroes first. 
It creates a deque for each set of 3 letters from a file, 
pushing them as their decimal equivalent. 
Each deque is a 3 digit base-26 number.
This number is converted to decimal.
The result is used as the location in the vector to add 1 to (counting the # of instances).
This vector is returned.
*/
std::vector <int> trigram(char *file){
	std::vector <int> frequency(17576, 0);
	std::deque <char> number;	//No other types allow me to pop_front and also access elements with []
	std::ifstream infile;
	char ch;
	infile.open(file);
	if(!infile.fail()){
		while(infile.get(ch)){
			if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')){	//These operators skip over punctuation and numbers.
				if (ch < 96){	//The case for capital letters: first convert to lowercase by adding 32
					number.push_back(ch + 32 - 'a');	
				} else{
					number.push_back(ch - 'a');
				}
				if(number.size() == 4){		// Note to self: {c,b,a} --> {d,c,b}
					number.pop_front();
					frequency[(number[0] * 26 * 26)+ (number[1] * 26) + number[2]]+=1;	
				}
			} else{

			}
		}
	} else{
		std::cerr << "Could not open file";
		frequency.clear();
	}
	return frequency;
}

/* 
CONCISE DESCRIPTION OF FUNCTION:
"learn" returns cos^2(theta).
It takes the frequency vector of the testing language 
and the frequency fector of the training language
as arguments a and b. These vectors are plugged into the equation, 
with the Sigma sums calculated using a for loop
and the result stored in the variable called "numerator". 
We use scaled division to keep this result from dropping into decimals illegally.
The result must be converted into a string first before becoming a double.
*/
double learn(std::vector <int> a, std::vector <int> b){
	bigint numerator = 0;
	bigint denoma = 0;
	bigint denomb = 0;
	double result = 0;
	std::string temp;
	for (size_t i = 0; i < a.size(); ++i){
		bigint a_element = a[i];	//By constructing the buckets here as bigints, we can avoid overflow in the arithmetic
		bigint b_element = b[i];
		numerator += a_element*b_element;		
		denoma += a_element*a_element; 		
		denomb += b_element*b_element;
	}
	numerator *= numerator;
	numerator *= 1000000;
	numerator = numerator/(denoma * denomb);
	temp = numerator.to_string();		//There is no way to convert from bigint to double directly, so it first must become a string.
	result = sqrt(std::stod(temp)/1000000);		

	return result;
}
