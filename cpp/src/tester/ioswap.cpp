#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ioswap.h"

IOSwap::IOSwap(std::string infile, std::string expfile)
{
	this->input_fname = infile;
	this->expected_fname = expfile;

	this->file.open(infile);
}

void IOSwap::start()
{
	// save and redirect std::cin
	std::ifstream in(this->input_fname);
	this->cinbuf = std::cin.rdbuf();

	if (in)
	{
		std::cin.rdbuf(in.rdbuf());
	}
	else
	{
		std::cout << "ERROR: expected file '" + this->input_fname + "' does not exist!" << std::endl;
	}

	// save and redirect std::cout
	this->coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(this->out.rdbuf());
	std::cout << "I/O setup complete. Testing...";
}

void IOSwap::verify()
{
	std::ifstream in{ this->expected_fname };
	if (in)
	{
		std::stringstream buf;
		in.rdbuf >> buf;
		in.close();
	}
	else
	{
		this->reset();
		std::cout << "ERROR: expected file '" + this->expected_fname + "' does not exist!" << std::endl;
	}
}

void IOSwap::end()
{
	std::cout << "Testing complete.";
}

void IOSwap::reset()
{
	std::cin.rdbuf(this->cinbuf); //reset to standard input again
	this->file.close();
	std::cout.rdbuf(this->coutbuf);
	std::cout << "I/O reset.";
}