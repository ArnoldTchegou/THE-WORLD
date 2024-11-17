#ifndef ENGINE
#define ENGINE
#include "world.hpp"
class Engine
{
public:
    Engine() = default;
    Engine(World &w);
    World &compute_space_evolution();
    // this method computes the number of active members in a unit's environment
    int count_neighbour_state(int i, int j, string state);
    World &getWorld();

private:
    World w;
};

#endif
