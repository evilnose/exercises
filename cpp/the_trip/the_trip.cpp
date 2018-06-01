// UVa Problem ID 10137
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>

void answer() {
    unsigned n;
    std::vector<double> amts;
    double pos_sum, neg_sum;
    double amt;
    double avg;
    while (std::cin >> n && n != 0) {
        amts.clear();
        avg = 0;
        pos_sum = 0;
        neg_sum = 0;

        for (unsigned i = 0; i < n; i++) {
            std::cin >> amt;
            amts.push_back(amt);
            avg += amt;
        }
        avg /= n;
        
        for (double amt : amts) {
            if (amt > avg)
                pos_sum += (long) ((amt - avg) * 100) / 100.0;
            else
                neg_sum -= (long) ((amt - avg) * 100) / 100.0;
        }
        pos_sum = (pos_sum > neg_sum) ? pos_sum : neg_sum;
        std::cout << "$" << std::setprecision(2) << std::fixed << pos_sum << std::endl;
    }
}

int main() {
    answer();
    return 0;
}