#include <iostream>
#include <cctype>
#include <span>

int main(int argc, const char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return EXIT_SUCCESS;
	}
	for (std::string str : std::span(argv + 1, argc - 1))
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			str[i] = std::toupper(str[i]);
		}
		std::cout << str;
	}
	std::cout << "\n";
	return EXIT_SUCCESS;
}
