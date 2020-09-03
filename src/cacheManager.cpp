#include "cacheManager.hpp"

#include <iostream>
#include <filesystem>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <experimental/filesystem>
#include <unistd.h>

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

    operation.doInput();
}

void cacheManager::clear() {
   std::experimental::filesystem::remove_all("./bin/cache");
}