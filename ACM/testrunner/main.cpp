#include "D:/xyiyy/icpc/ACM/tasks/ACM/poj/problem set/poj2417bsgs.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

namespace jhelper {

struct Test {
	std::string input;
	std::string output;
	bool active;
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
		{"5 2 1\n5 2 2\n5 2 3\n5 2 4\n5 3 1\n5 3 2\n5 3 3\n5 3 4\n5 4 1\n5 4 2\n5 4 3\n5 4 4\n12345701 2 1111111\n1111111121 65537 1111111111", "0\n1\n3\n2\n0\n3\n1\n2\n0\nno solution\nno solution\n1\n9584351\n462803587", true},
	};
	bool allOK = true;
	int testID = 0;
	for(const jhelper::Test& test: tests ) {
		std::cout << "Test #" << ++testID << std::endl;
		std::cout << "Input: \n" << test.input << std::endl;
		std::cout << "Expected output: \n" << test.output << std::endl;
		if (test.active) {
			std::stringstream in(test.input);
			std::ostringstream out;
			poj2417bsgs solver;
			solver.solve(in, out);
			std::cout << "Actual output: \n" << out.str() << std::endl;
			bool result = jhelper::check(test.output, out.str());
			allOK = allOK && result;
			std::cout << "Result: " << (result ? "OK" : "Wrong answer") << std::endl;
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
		std::cout << "Some cases failed" << std::endl;
	};
	return 0;
}
