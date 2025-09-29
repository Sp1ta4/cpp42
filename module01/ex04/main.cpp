#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "\033[35mUsage: " << argv[0] << " <file> <string_from> <string_to>\n\033[0m";
		return 1;
	}

	std::string filename = argv[1];
	std::string from = argv[2];
	std::string to = argv[3];

	if (from.empty())
	{
		std::cerr << "\033[31m<string_from> cannot be empty\033[0m" << "\n";
		return 1;
	}

	std::ifstream inFile(filename.c_str());
	if (!inFile)
	{
		std::cerr << "\033[31mCannot open the file: \033[0m" << filename << "\n";
		return 1;
	}

	std::string output_name = filename + ".replace";
	std::ofstream outFile(output_name.c_str());
	if (!outFile)
	{
		std::cerr << "\033[31mCannot create file: \033[0m" << output_name << "\n";
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(from, pos)) != std::string::npos)
		{
			line.erase(pos, from.length());
			line.insert(pos, to);
			pos += to.length();
		}
		outFile << line << "\n";
	}

	std::cout << "\033[32mFile saved as \033[0m" << output_name << "\n";
	return 0;
}
