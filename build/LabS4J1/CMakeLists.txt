cmake_minimum_required(VERSION 3.10)
project(LabS4J1)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_C_STANDARD 90)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -static-libgcc -static-libstdc++")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")
include_directories(
)
set(SOURCE_FILES
  "D:/COURS DEC/1ère Année/Session Hiver/Technique de programmation/labo-TechProg/Sources/labo.c"
  "D:/COURS DEC/1ère Année/Session Hiver/Technique de programmation/labo-TechProg/Sources/labo.h"
  "D:/COURS DEC/1ère Année/Session Hiver/Technique de programmation/labo-TechProg/Sources/main.c"
)
add_executable(LabS4J1 ${SOURCE_FILES})
target_link_libraries(LabS4J1
)
