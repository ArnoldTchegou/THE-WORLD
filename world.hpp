#ifndef WORLD
#define WORLD
#include <iostream>
#include <vector>
using namespace std;

class World
{
public:
    // default constructor
    World() = default;
    // constructor used to create world object and generate initial states
    // param value is used to ajust the distribution ratio between active and inactive units
    // param sets the number of initial active units
    World(int h, int w, int param);

    // accesssors
    int getWidth();
    int getHeight();
    void setUnit_states(vector<bool> &v);
    void setUnit(int i, int j, bool val);
    vector<vector<bool>> getUnit_states();

private:
    int width;
    int height;
    vector<vector<bool>> unit_states;
};

ostream &operator<<(ostream &stream, World &w);

#endif