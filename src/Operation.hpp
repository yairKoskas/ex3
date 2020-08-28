#include <stdio.h>
#include <string>
#include <vector>

class Operation {
    private:
        std::vector<std::string> m_input;
        std::string m_output;
    public:
        Operation(const std::vector<std::string>& input);
        std::string doInput();
};