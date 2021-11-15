cmake_minimum_required(VERSION 3.20.0)

add_executable(pw-gen
    ../src/pw_gen.cpp    
    app.cpp)


target_include_directories(pw-gen PUBLIC ../include/)