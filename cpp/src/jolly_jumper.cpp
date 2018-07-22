#include <sstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;
    int curr;
    int last;
    bool jolly;
    while (std::cin)
    {
        jolly = true;

        std::cin >> n;
        std::vector<int> nums (n, 0);        

        for (int i = 0; i < n; i++) {
            std::cin >> curr;
            if (i != 0) {
                try {
                    nums.at(curr > last ? curr - last : last - curr) = 1;
                } catch (std::out_of_range) {
                    jolly = false;
                }
            }
            last = curr;
        }

        for (int i = 1; i <= n - 1; i++)
        {
            if (nums[i] != 1)
            {
                jolly = false;
                break;
            }
        }

        if (jolly)
        {
            std::cout << "Jolly\n";
        }
        else
        {
            std::cout << "Not jolly\n";
        }
    }
}