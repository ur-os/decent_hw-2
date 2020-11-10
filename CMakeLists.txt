cmake_minimum_required(VERSION 3.17)
project(decent_hw-2)

set(CMAKE_CXX_STANDARD 17)



add_executable(decent_hw-2
        main.cpp
        Trinket.cpp
        Trinket.h
        Car.cpp
        Car.h
        utils.h
        )

target_link_libraries(decent_hw-2 cryptopp)
