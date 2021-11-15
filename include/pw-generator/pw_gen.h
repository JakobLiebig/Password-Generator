#ifndef PW_GENERATOR_HEADER_GUARD
#define PW_GENERATOR_HEADER_GUARD

#include <string>
#include <fstream>

namespace pw_gen {
    std::string ReadPoolFile(const std::string& path);
    void Generate(std::string& format, const std::string& pool);
} // namespace pw_gen

#endif // !PW_GENERATOR_HEADER_GUARD