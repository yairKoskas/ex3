#include <iostream>
#include "cacheManager.hpp"
int main(int argc , char** argv) {
    cacheManager cm = cacheManager(argc,std::string(*argv));
    cm.doCommand();
    return 0;
}