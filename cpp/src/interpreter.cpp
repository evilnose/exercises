#include <vector>
#include <iostream>
#include <string>
#include <map>

class Interpreter;
typedef void (Interpreter::*pfn)(unsigned, unsigned);

class Interpreter {
	std::vector<unsigned> rams;
	std::vector<unsigned> regs;
	std::map<unsigned, pfn> fmap;
	unsigned count;
	unsigned i;
public:
	Interpreter() {
		this->i = 0;
		this->count = 0;
		
		regs = std::vector<unsigned>(10, 0);
		// fmap[1] is halt
		this->fmap[1] = &Interpreter::halt;
		this->fmap[2] = &Interpreter::set_reg;
		this->fmap[3] = &Interpreter::add_reg;
		this->fmap[4] = &Interpreter::mult_reg;
		this->fmap[5] = &Interpreter::set_reg_ref;
		this->fmap[6] = &Interpreter::add_reg_ref;
		this->fmap[7] = &Interpreter::mult_reg_ref;
		this->fmap[8] = &Interpreter::set_reg_by_ram;
		this->fmap[9] = &Interpreter::set_ram_by_reg;
		this->fmap[0] = &Interpreter::go_to;
	}

	void add_ram(unsigned ram) {
		rams.push_back(ram);
	}

	void start() {
		// Default the unspecified RAMs to zero
		for (std::size_t i{ this->rams.size() }; i < 1000; i++) {
			rams.push_back(0);
		}

		unsigned ram;
		for (; this->i < 1000; this->i++) {
			this->execute(this->rams[i]);
			this->count++;
		}
	
		std::cout << this->count << "\n\n";
	}

	void execute(unsigned ram) {
		unsigned cmd = ram / 100;
		pfn f = this->fmap[cmd]; // get pointer to function
		(*this.*f)((ram % 100) / 10, ram % 10); // de-reference both the "this" and "f" pointer
	}


private:
	void halt(unsigned a, unsigned b) {
		// halt. Setting i to 1000 terminates the for-loop
		this->i = 1000;
	}

	void set_reg(unsigned d, unsigned n) {
		// sets register d to n
		this->regs[d] = n;
	}

	void add_reg(unsigned d, unsigned n) {
		// add n to register d
		this->regs[d] += n;
		this->regs[d] %= 1000;
	}

	void mult_reg(unsigned d, unsigned n) {
		// multiply register d by n
		this->regs[d] *= n;
		this->regs[d] %= 1000;
	}

	void set_reg_ref(unsigned d, unsigned s) {
		// sets register d to the value of register s
		this->regs[d] = this->regs[s];
	}

	void add_reg_ref(unsigned d, unsigned s) {
		this->regs[d] += this->regs[s];
		this->regs[d] %= 1000;
	}

	void mult_reg_ref(unsigned d, unsigned s) {
		this->regs[d] *= this->regs[s];
		this->regs[d] %= 1000;
	}

	void set_reg_by_ram(unsigned d, unsigned a) {
		this->regs[d] = this->rams[this->regs[a]];
	}

	void set_ram_by_reg(unsigned s, unsigned a) {
		this->rams[this->regs[a]] = this->regs[s];
	}

	void go_to(unsigned d, unsigned s) {
		if (this->regs[s] != 0)
			this->i = this->regs[d] - 1; // -1 to compensate for i++ at the end of for-loop
	}
};

int main() {
	unsigned n_cases;
	std::cin >> n_cases;
	std::string line;

	// skip a line
	getline(std::cin, line);
	getline(std::cin, line);

	unsigned last_input;
	for (int i = 0; i < n_cases; ++i) {
		Interpreter itp;
		unsigned last_input;
		while (std::getline(std::cin, line)) {
			if (line == "") break;
			itp.add_ram((unsigned)std::stoi(line));
		}
		itp.start();
	}
}