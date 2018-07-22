// UVa Problem ID 100
#include <cstdio>
#include <algorithm>
using namespace std;

#ifndef THREEN_P_ONE_H
#define THREEN_P_ONE_H

#include <cstdio>
#include <algorithm>
extern void answer();

#endif

extern void answer() {
	int a, b;

	while (scanf("%d %d", &a, &b) != EOF) {
		int initA = a;
		int initB = b;

		if (a > b)
			swap(a, b);

		unsigned int max = 0, cyc, n;
		while (a <= b) {
			cyc = 1;
			n = a;
			while (n != 1) {
				if (n % 2 == 0) {
					n >>= 1;
				} else {
					n = n * 3 + 1;
				}
				cyc++;
			}
			if (cyc > max)
				max = cyc;
			a++;
		}

		printf("%d %d %d\n", initA, initB, max);
	}
}

// int main() {
// 	answer();
// 	return 0;
// }
