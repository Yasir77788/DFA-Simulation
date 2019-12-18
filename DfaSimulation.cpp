// ***************************************************************                                   *
// DFA Simulation using c++ programing lnaguage.                 *
// This program is to extract all the patterns in a DNA sequence *
// over the alphabet {'A', 'T', 'G', 'C'} that starts and ends   *
// with 'A' or starts and ends with 'T'.                         *
// The DFA has 6 states, including a Dead states                 *
// ***************************************************************

#include <iostream>
#include <string>
using namespace std;

// function prototype
void findPatterns(string dna);

int main()
{
	string dna;   // string for DNA sequence
	cout << "Input a DNA sequence: ";
	cin >> dna;

	cout << endl << "Matching patterns are:" << endl << endl;
	findPatterns(dna); // invoke findPatterns function

	cout << endl;
	system("pause");
	return 0;
}

// ************************************************************
// Definition of function findPatterns                        *
// It accepts a dna string, loops over all substrings of dna  *
// that has two or more characters... It uses inner forloops  *
// to check if substrings in the DNA sequence are part of     *
// the given regular expression..Then it displays the patterns*
// ************************************************************

void findPatterns(string dna)
{
	int i, j, k;  // variables for the For-loop initializations 
	int range;    // substr-range variable (length)
	string subSt; // sub string of the dna
	int state;    // a daf state

	int len = dna.length();

	// For-loop to go over each character in the DNA string
	for (i = 0; i < len; i++) 
	{
		range = 2; // initial number of characters in a sub string

		// loop over all substrings, each with 2 characters or more
		while (range <= len) 
		{
			// create a dna-sub string
			subSt = dna.substr(i, range); 
			range++; 
			state = 0;

			// loop to check if a substr is accepted by the dfa.
			// the start is 0, the final states are state 2 and state 4.
			for (j = 0; j < subSt.length(); j++) 
			{
				if (state == 0)
				{
					if (subSt[j] == 'A')
						state = 1;
					else if (subSt[j] == 'T')
						state = 3;
					else
						break;
				}
				else if (state == 1)
				{
					if (subSt[j] == 'A')
					{
						state = 2;
					}
					else
						state = 1;
				}
				else if (state == 2)
				{
					if (subSt[j] == 'A')
					{
						state = 2;
					}
					else
						state = 1;
				}
				else if (state == 3)
				{
					if (subSt[j] == 'T')
					{
						state = 4;
					}
					else
						state = 3;

				}
				else if (state == 4)
				{
					if (subSt[j] == 'T')
					{
						state = 4;

					}
					else
						state = 3;
				}
			}

            // display the accepted matching patterns
			if (state == 2 || state == 4)
			{
				for (k = 0; k <= j; k++)
				{
					cout << subSt[k];
				}
				cout << endl;
			}

		}
	}
}