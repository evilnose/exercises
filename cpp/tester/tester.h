#ifndef INPUTSWAP_H
#define INPUTSWAP_H

#include <string>
#include <iostream>
#include <fstream>

namespace tst
{
class InputSwap
{
  public:
    InputSwap(std::string fname = "in.txt");
    void write(std::string towrite);
    void start();
    void end();
};
}; // namespace tst

#endif