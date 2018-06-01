// UVa Problem ID 10189
#include <iostream>
#include <string>
#include <vector>

const char MINE {'*'};

unsigned get_mine_count(std::vector<std::vector<char>> &field, unsigned r, unsigned c)
{
	unsigned count {0};
	const unsigned n = field.size();
	const unsigned m = field[0].size();

	for (unsigned i {std::min<unsigned>(r - 1, r)}; i <= std::min<unsigned>(r + 1, n - 1); i++) {
		for (unsigned j {std::min<unsigned>(c - 1, c)}; j <= std::min<unsigned>(c + 1, m - 1); j++) {
			if (field[i][j] == MINE) {
				count++;
			}
		}
	}
	return count;
}

int main()
{
	std::string result = "";
	
	unsigned n, m;
	unsigned field_count {0};
	std::string line;

	while (std::cin >> n >> m) {
		if (m == n && m == 0)
			break;

		if (field_count > 0)
			result += "\n";

		std::vector<std::vector<char>> field(n, std::vector<char>(m));

		// Skip newline
		std::cin.ignore();

		for (unsigned i {0}; i < n; i++) {
			std::getline(std::cin, line);
			for (unsigned j {0}; j < m; j++) {
				field[i][j] = line[j];
			}
		}

		result += "Field #" + std::to_string(++field_count) + ":\n";

		for (unsigned i {0}; i < n; i++) {
			for (unsigned j {0}; j < m; j++) {
				if (field[i][j] == MINE) {
					result += MINE;
				} else {
					result += std::to_string(get_mine_count(field, i, j));
				}
			}
			result += "\n";
		}
	}

	std::cout << result;
	return 0;
}