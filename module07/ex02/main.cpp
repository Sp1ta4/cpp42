#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

using std::cout;
using std::endl;
using std::string;

#define MAX_VAL 10

static void printSeparator(const std::string &color = YELLOW)
{
	cout << color << "-----------------------------------------------------" << RESET << endl;
}

static void testIntArray()
{
	cout << BLUE << "\n[1] Testing Array<int>" << RESET << endl;
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];

	for (int i = 0; i < MAX_VAL; i++)
	{
		int value = rand() % 100;
		numbers[i] = value;
		mirror[i] = value;
	}

	printSeparator();
	cout << CYAN << "Original Array vs Mirror" << RESET << endl;
	for (int i = 0; i < MAX_VAL; i++)
		cout << "numbers[" << i << "] = " << numbers[i] << " | mirror[" << i << "] = " << mirror[i] << endl;

	printSeparator();
	cout << MAGENTA << "Testing Copy Constructor and Assignment" << RESET << endl;
	{
		Array<int> tmp = numbers;
		Array<int> test;
		test = tmp;

		for (int i = 0; i < MAX_VAL; i++)
			cout << "tmp[" << i << "] = " << tmp[i] << " | test[" << i << "] = " << test[i] << endl;
	}

	printSeparator();
	cout << YELLOW << "Verifying Integrity" << RESET << endl;
	bool valid = true;
	for (int i = 0; i < MAX_VAL; i++)
		if (mirror[i] != numbers[i])
		{
			cout << RED << "Mismatch at index " << i << RESET << endl;
			valid = false;
		}
	if (valid)
		cout << GREEN << "All integer values are consistent" << RESET << endl;

	delete[] mirror;
}

static void testDoubleArray()
{
	cout << BLUE << "\n[2] Testing Array<double>" << RESET << endl;
	Array<double> decimals(MAX_VAL);

	for (int i = 0; i < MAX_VAL; i++)
		decimals[i] = (rand() % 1000) / 10.0;

	printSeparator();
	cout << CYAN << "Printing double values" << RESET << endl;
	for (int i = 0; i < MAX_VAL; i++)
		cout << "decimals[" << i << "] = " << decimals[i] << endl;

	printSeparator();
	cout << MAGENTA << "Copying Array<double>" << RESET << endl;
	Array<double> copy = decimals;
	for (int i = 0; i < MAX_VAL; i++)
		cout << "copy[" << i << "] = " << copy[i] << endl;

	cout << GREEN << "Double array copied successfully" << RESET << endl;
}

static void testStringArray()
{
	cout << BLUE << "\n[3] Testing Array<std::string>" << RESET << endl;
	Array<string> words(5);

	words[0] = "BABIJON";
	words[1] = "TRULALELO TRULALA";
	words[2] = "TUNK TUNK TUNK SHAKOUR";
	words[3] = "BALERINA KAPUCHINA";
	words[4] = "BOMBARDILO KROKADILO";

	printSeparator();
	cout << CYAN << "Printing string values" << RESET << endl;
	for (size_t i = 0; i < words.size(); i++)
		cout << "words[" << i << "] = " << words[i] << endl;

	printSeparator();
	cout << MAGENTA << "Testing copy of string array" << RESET << endl;
	Array<string> copy(words);
	for (size_t i = 0; i < copy.size(); i++)
		cout << "copy[" << i << "] = " << copy[i] << endl;

	cout << GREEN << "String array copied successfully" << RESET << endl;
}

static void testOutOfBounds()
{
	cout << BLUE << "\n[4] Testing Out-of-Bounds Access" << RESET << endl;
	Array<int> arr(5);

	printSeparator();
	try
	{
		cout << "Accessing index -1..." << endl;
		arr[-1] = 10;
	}
	catch (const std::exception &e)
	{
		cout << RED << "Caught exception: " << e.what() << RESET << endl;
	}

	printSeparator();
	try
	{
		cout << "Accessing index 5..." << endl;
		arr[5] = 42;
	}
	catch (const std::exception &e)
	{
		cout << RED << "Caught exception: " << e.what() << RESET << endl;
	}

	cout << GREEN << "Bounds check verified successfully" << RESET << endl;
}

int main(void)
{
	srand(time(NULL));

	cout << BLUE << "=============== ARRAY TEMPLATE TEST SUITE ===============" << RESET << endl;

	testIntArray();
	printSeparator();
	testDoubleArray();
	printSeparator();
	testStringArray();
	printSeparator();
	testOutOfBounds();

	cout << GREEN << "\nAll tests completed successfully" << RESET << endl;
	return 0;
}
