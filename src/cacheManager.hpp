#include "Operation.hpp"

class cacheManager {
    private :
        std::string m_command;

    public : 
        cacheManager(std::string command);
        void doCommand();
        void clear();
};