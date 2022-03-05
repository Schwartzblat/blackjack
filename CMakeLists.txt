cmake_minimum_required(VERSION 3.17)
project(blackjack)

set(CMAKE_CXX_STANDARD 14)

add_executable(blackjack main.cpp Card.cpp Deck.cpp)