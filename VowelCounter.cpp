// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype> //allows the use of toupper() and tolower()


int main(int argc, char* argv[])
{
	// Returns an error message if the user doesn't provide two arguments to launch the file.
	if (argc < 2)
	{
		std::cout << "Error with input agrs.." << std::endl;
		return 1;
	}

	// For debugging purposes only
	for (int i = 0; i < argc; i++)
	{
		std::cout << i << ":" << argv[i] << std::endl;
	}

	//Opens our file, declaring it as the stream variable inFile, and tests to see if our file opens properly.
	std::ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile)
	{
		std::cout << "Error with file name.." << std::endl;
		return 1;
	}

	//Heading intro for the program
	std::cout << std::setfill('*') << std::setw(56) << " " << std::endl;
	std::cout << std::setw(10) << " " << "Welcome to my Letter Count Program" << " " << std::setw(10) << "" << std::endl;
	std::cout << std::setw(55) << "*" << std::endl << std::endl;

	std::cout << "Analyzing file \'" << argv[1] << "\'..." << std::endl << std::endl;

	//Variable bank to update as we progress through our document.
	int numA = 0;
	int numE = 0;
	int numI = 0;
	int numO = 0;
	int numU = 0;
	int numY = 0;
	int numM = 0;
	int numH = 0;

	//Local changing variable to monitor the current character
	char currentLetter;

	//Will progress through the file until the end of the document is reached. .eof() meaning end of the file/document.
	while (!inFile.eof()) {

		//Progresses through our opened file with the next itterated char, currentLetter, each time it progresses through the loop
		inFile >> currentLetter;

		//converts our current letter to uppercase for ease of analysis
		currentLetter = toupper(currentLetter);

		//Updates the corresponding variable for each vowel if found
		if (currentLetter == 'A') {
			numA++;
		}
		else if (currentLetter == 'E') {
			numE++;
		}
		else if (currentLetter == 'I') {
			numI++;
		}
		else if (currentLetter == 'O') {
			numO++;
		}
		else if (currentLetter == 'U') {
			numU++;
		}
		else if (currentLetter == 'Y') {
			numY++;
		}
		else if (currentLetter == 'M') {
			numM++;
		}
		else if (currentLetter == 'H') {
			numH++;
		}

	}

	//Outputs to the console the number of vowels found and the total number of vowels.
	std::cout << "The number of A's: " << std::right << std::setfill('.') << std::setw('4')<< "" << numA << std::endl;
	std::cout << "The number of E's: " << std::right << std::setw('4') << "" << numE << std::endl;
	std::cout << "The number of I's: " << std::right << std::setw('4') << "" << numI << std::endl;
	std::cout << "The number of O's: " << std::right << std::setw('4') << "" << numO << std::endl;
	std::cout << "The number of U's: " << std::right << std::setw('4') << "" << numU << std::endl;
	std::cout << "The number of H's: " << std::right << std::setw('4') << "" << numH << std::endl;
	std::cout << "The number of M's: " << std::right << std::setw('4') << "" << numM << std::endl;
	std::cout << "The number of Y's: " << std::right << std::setw('4') << "" << numY << std::endl;
	std::cout << "The vowel count is: " << std::right << std::setw('3') << "" << numA + numE + numI + numO + numU + numH + numM + numY << std::endl;

	//Closes our open file for cleanup sake
	inFile.close();

	//returns 0 so other programs that may reference this know we reached this point
	return 0;
}

