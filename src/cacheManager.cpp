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
     while (i < com.size()) {
        while (com[i] != ' ') {
            std::string str;
            str = str + com[i]
            i++
        }
        i++;
        command.push_back(str);
     }
    
    Operation operation = Operation(command);

    std::fstream cache;
    std::string line;
    std::string order;
    for (int n = 0; n < command.size - 2; n++) {
        order = order + command[n];
    } 

    cache.open("cache/manage.txt");
    int numline = 0;
    while(getline(cache, line)) {
        string::size_type loc = line.find(order, 0);
        if (loc != string::npos) {
            std::fstream end;
            end.open(command[command.size - 1]);
            std::fstream found;

            std::vector<std::string> lin;
            i = 0;
            while (i < line.size()) {
                while (line[i] != ' ') {
                    std::string str;
                    str = str + line[i]
                    i++;
                    }
                    lin.push_back(str);
                    }
        found.open(lin[lin.size() - 1]);
        copy(found, end);
         end.close();
        found.close();
        std::cout << "found solution in cache" << std::endl;
        return;
        }
    }
    cache << operation.doInput();
    cache << "\n";
    cache.close();
}

void cacheManager::clear() {
   std::experimental::filesystem::remove_all("./bin/cache");
}