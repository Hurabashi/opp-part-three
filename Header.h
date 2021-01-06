//
// Created by minyk on 12/27/2020.
//
#ifndef INC_2_0V_HEADER_H
#define INC_2_0V_HEADER_H

#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cctype>
#include <chrono>
#include <list>

using std::string;
using std::cout;

using std::vector;
using std::map;
using std::mt19937;


class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{ std::chrono::high_resolution_clock::now() } {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
};



#endif //INC_2_0V_HEADER_H
