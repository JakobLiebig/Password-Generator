#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "pw-generator/pw_gen.h"

#define LOG(x) std::cout << x << std::endl

int main(int argc, char* argv[]) {
    srand(time(0));

    std::string pool_path = "./pool.txt";
    std::string format = "XXXX-XXXX-XXXX";

    try {
        for(unsigned int i = 1; i < argc; i+=2) {
            std::string label = argv[i];
            
            if(label == "--help")
            {
                LOG("pw-gen <-f format> <-p pool path>\n\nformat example: XXX:XXX");
                return 0;
            }
            else if(label == "-f") 
            {
                format = argv[i+1];
            }
            else if(label == "-p")
            {
                pool_path = argv[i+1];
            }
        }
    }
    catch (const std::logic_error& ex)
    {
        LOG("Error, wrong input format! (--help for help!)");

        return -1;
    }

    try
    {
        std::string pw = format;

        std::string pool = pw_gen::ReadPoolFile(pool_path);
        pw_gen::Generate(pw, pool);

        LOG(pw);
    }
    catch (const std::invalid_argument ex) 
    {
        LOG("Error, " << ex.what() << "!");
        
        return -1;
    }
    
    return 0;
}