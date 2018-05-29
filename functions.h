/**
 * Started by Najib 3/21/18
 **/
 //Author: Jason Yang

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

///////////////////////////////////////////////////////////////////
// INCLUDES GO HERE
///////////////////////////////////////////////////////////////////
#include "bigint/bigint.h"
#include <vector>
#include <fstream>

///////////////////////////////////////////////////////////////////
// FUNCTION HEADERS GO HERE
///////////////////////////////////////////////////////////////////
//vector starts as a bunch of zeroes of size 26^3
std::vector <int> trigram(char *file);
double learn(std::vector <int> a, std::vector <int> b);	//Note to self: We'll call this double the "simnumber".
							//Note to self: The main will send the frequency vector of the test case



#endif
