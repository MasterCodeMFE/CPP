#include "BitcoinExchance.cpp"

int main(int argc, chat **argv)
{
	if(argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
	}
	else
	{
		bitcoinExchance(argv);
	}

}
