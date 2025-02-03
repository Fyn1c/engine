#pragma once 
#include <vector>
#include "Collision.hpp"

class Solver {
public:
    virtual void solve(std::vector<Collision> colls) = 0;
};