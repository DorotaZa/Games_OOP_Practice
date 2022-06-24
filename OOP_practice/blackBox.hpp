#pragma once

class BlackBoxGuess
{
	int hiddenNumber;
public:
	BlackBoxGuess(int range); //hiddenNumber to be generate
	int is(int guess); 
};
