#include "C:/Users/strik/CLionProjects/ccc-with-c/tasks/TaskA.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

struct Test {
	std::string input;
	std::string output;
	bool active;
	bool has_output;
};

bool check(std::string expected, std::string actual) {
	while(!expected.empty() && isspace(*--expected.end()))
		expected.erase(--expected.end());
	while(!actual.empty() && isspace(*--actual.end()))
		actual.erase(--actual.end());
	return expected == actual;
}

} // namespace jhelper

int main() {
	std::vector<jhelper::Test> tests = {
		{"10 5 3\n", "3\n", true, true},{"10 5 7\n", "5\n", true, true},{"10 5 12\n", "3\n", true, true},{"10 2 11", "1", true, true},
	};
	bool allOK = true;
	int testID = 0;
	std::cout << std::fixed;
	double maxTime = 0.0;
	int cnt = 0;
	for(const jhelper::Test& test: tests ) {
		std::cout << "Test #" << ++testID << std::endl;
		std::cout << "Input: \n" << test.input << std::endl;
		if (test.has_output) {
			std::cout << "Expected output: \n" << test.output << std::endl;
		}
		else {
			std::cout << "Expected output: \n" << "N/A" << std::endl;
		}
		if (test.active) {
			std::stringstream in(test.input);
			std::ostringstream out;
			std::clock_t start = std::clock();
			TaskA solver;
			solver.solve(in, out);
			std::clock_t finish = std::clock();
			double currentTime = double(finish - start) / CLOCKS_PER_SEC;
			maxTime = std::max(currentTime, maxTime);
			std::cout << "Actual output: \n" << out.str() << std::endl;
			if (test.has_output) {
				bool result = jhelper::check(test.output, out.str());
				allOK = allOK && result;
				std::cout << "Result: " << (result ? "OK" : "Wrong answer") << std::endl;
				if(!result) cnt++;
			}
			std::cout << "Time: " << currentTime << std::endl;
		}
		else {
			std::cout << "SKIPPED\n";
		}

		std::cout << std::endl;

	}
	if(allOK) {
		std::cout << "All OK" << std::endl;
	}
	else {
		std::cout << cnt << " cases failed" << std::endl;
	}
	std::cout << "Maximal time: " << maxTime << "s." << std::endl;
	return 0;
}
