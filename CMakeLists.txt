cmake_minimum_required(VERSION 3.21)
project(Blumen_giessen)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Blumen_giessen
        measureHumidity.ino
        watering.ino)
