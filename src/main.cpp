#include <iostream>
#include "cacheManager.hpp"
int main(int argc, char** argv) {
    cacheManager cm = cacheManager(std::string(*argv));
    cm.doCommand();
    return 0;
}