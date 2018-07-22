#ifndef IOSwap_H
#define IOSwap_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class IOSwap
{
private:
	std::string input_fname;
	std::string expected_fname;
	std::ofstream file;

	// saved default input buffer
	std::streambuf *cinbuf;
	// saved default output buffer
	std::streambuf *coutbuf;
	// replaces default output
	std::stringstream out;

	void reset();
public:
	IOSwap(std::string infile = "in.txt", std::string = "expected.txt");
	void start();
	void verify();
	void end();
};

#endif