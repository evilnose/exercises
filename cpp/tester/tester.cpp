#include <string>
#include <iostream>
#include <fstream>

namespace tst
{
class InputSwap
{
  private:
    std::string inputfname;
    std::ofstream file;
    std::streambuf *cinbuf;

  public:
    InputSwap(std::string fname = "in.txt")
    {
        inputfname = fname;

        std::ofstream file;
        file.open(fname);
    }

    void write(std::string towrite)
    {
        file << towrite;
    }

    void start()
    {
        std::ifstream in(inputfname);
        cinbuf = std::cin.rdbuf();  //save old buf
        std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    }

    void end()
    {
        std::cin.rdbuf(cinbuf); //reset to standard input again
        file.close();
    }
};
}; // namespace tst