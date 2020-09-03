#include "cacheManager.hpp"
#include <iostream>

cacheManager::cacheManager(std::string command) {
    this->m_command = command;
}

void cacheManager::doCommand() {
    std::vector<std::string> command;
    std::string com = this->m_command;
    int i = 0;
    int j = 0;
    while (!com.empty()) {
        if (com[i] == ' ') {
            i++;
            j++;
        }
        command[j].push_back(com[i]);
    }
    Operation operation = Operation(command);
    std::fstream cache;
    std::string line;
    std::string order;
    for (int n = 0; n < command.size - 2; n++) {
        order = order + command[n];
    } 

    cache.open("cache/manage.txt");
    while(getline(cache, line)) {
        string::size_type loc = line.find(order, 0);
        if (loc != string::npos) {
            //copy the result
        } else {
            cache << operation.doInput();
        }

    }
}