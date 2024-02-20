cmake_minimum_required(VERSION 3.13)

# Project name and a few useful settings. Other commands can pick up the results
project(
  MonsterGame
  VERSION 0.1
  DESCRIPTION "learncpp.com Chapter 24 Quiz Project"
  LANGUAGES CXX)


set(SOURCES
    apps/app.cpp
    src/Creature.cpp
    src/Monster.cpp
    src/Player.cpp
)

add_executable(MonsterGame ${SOURCES})

target_include_directories(MonsterGame
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)