#include "Operation.hpp"

class cacheManager {
    private :
        int m_size;
        std::string m_command;

    public : 
        cacheManager(int size, std::string command);
        void doCommand();
        void clear();
};