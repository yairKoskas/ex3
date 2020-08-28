#include <stdio.h>
#include <string>
#include <vector>

class Operation {
std::vector<std::string> m_input;
std::string m_output;



Operation(const std::vector<std::string>& input);

std::string doInput();

};