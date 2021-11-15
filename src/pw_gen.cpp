#include "pw-generator/pw_gen.h"

namespace pw_gen {
    std::string ReadPoolFile(const std::string& path) {
        std::string pool = "";
        
        std::fstream pool_file(path);
        
        if(pool_file.is_open()) 
        {
            while(pool_file.good())
                pool_file >> pool;
    
            pool_file.close();
        } else {
            throw std::invalid_argument("Unable to open file '" + path + "'!");
        }

        return pool;
    }

    void Generate(std::string& format, const std::string& pool) {
        // format: XX:XX:XX or XXXX-XXXX-XXXX-XXXX or XXX
        
        for(unsigned int i = 0; i < format.size(); i++) {
            if(format[i] == 'X') {
                unsigned int rand_index = rand() % pool.size();
                
                format[i] = pool[rand_index];
            }
        }
    }
} // namespace pw_gen
