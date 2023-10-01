// Programmer:		Thecanniestbadge
// Date:			10/1/2023
// Program Name:	Calories
// Chapter:			Math
// Description:		This program determines how many calories you have ate.

#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf

int GetPosInt(const char PROMPT_TEXT[]);
int CalcCals(int numGrams, int calsPerGram);
void OutputCals(const char TYPE_NAME[], int typeGrams, int typeCals);


// Global Constants
const char START_PROMPT[] = "Enter the number of";
const char END_PROMPT[] = "grams in your meal: ";

int main(void)
{
	// Constant and Variable Declarations
	const char FAT_WORD[] = "fat";
	const char CARB_WORD[] = "carbohydrate";
	const char PROTEIN_WORD[] = "protein";
	const int CALS_PER_FAT = 9;
	const int CALS_PER_CARB = 4;
	const int CALS_PER_PROTEIN = 4;
	// Inpute variables
	int fatGrams = 0;
	int carbGrams = 0;
	int proteinGrams = 0;
	// Calculated variables 
	int fatCals = 0;
	int carbCals = 0;
	int proteinCals = 0;

	// *** Your program goes here ***
	// *** INPUT ***
	// Get the number of fat grams
	fatGrams = GetPosInt(FAT_WORD);
	// Get the number of carbohydrate grams
	carbGrams = GetPosInt(CARB_WORD);
	// Get the number of protein grams 
	proteinGrams = GetPosInt(PROTEIN_WORD);
	printf("\n"); // Blank line

	// *** PROCESSING ***
	// Calculate the calories
	fatCals = CalcCals(fatGrams, CALS_PER_FAT);
	carbCals = CalcCals(carbGrams, CALS_PER_CARB);
	proteinCals = CalcCals(proteinGrams, CALS_PER_PROTEIN);

	// *** OUTPUT ***
	// display the output 
	OutputCals(FAT_WORD, fatGrams, fatCals);
	OutputCals(CARB_WORD, carbGrams, carbCals);
	OutputCals(PROTEIN_WORD, proteinGrams, proteinCals);

	printf("\n"); // Blank line
	return 0;
} // end main()

// *** FUNCTIONS ***
// Get a Positive Integer Function
int GetPosInt(const char PROMPT_TEXT[])
{
	// Get a positive integer (with validation)

	// Local variables 
	int myPosInt = 0;

	// Prompt and get an integer 
	printf("%s %s %s", START_PROMPT, PROMPT_TEXT, END_PROMPT);
	scanf("%d", &myPosInt);


	// Validate the number is positive 
	while (myPosInt < 0)
	{
		// Error message 
		printf("	A positive number was not entered.\n");
		// Re-prompt and re-get
		printf("	%s %s %s", START_PROMPT, PROMPT_TEXT, END_PROMPT);
		scanf("%d", &myPosInt);
	}
	return myPosInt;
} // end

// Value- reutrning functions typically do not get input
// (data needed should be passed to the function)\
// and typically do not display output
// (the answer should be returned to the program that invoked the function)



// Calories Calculation function 
int CalcCals(int numGrams, int calsPerGram)
{
	// Calculate (and return) the number of calories
	// based on the grams passed
	return numGrams * calsPerGram;
} // end CalcCals function 

// Calories output function 
void OutputCals(const char TYPE_NAME[], int typeGrams, int typeCals)
{
	// Display the number of calories (and additional text)
	// in so many grams of the type passed 
	printf("The number of calories from the %d %s gram", typeGrams, TYPE_NAME);
	if (typeGrams != 1) printf("s"); // singular/plural decision
	printf(" consumed is %d calories.\n", typeCals);

	return; // Void functions do not return anything
} // end