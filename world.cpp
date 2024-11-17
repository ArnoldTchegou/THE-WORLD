#include "world.hpp"
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

World::World(int h, int w, int param)
{
    this->height = h;
    this->width = w;
    // 1D vector that contains intial values for units
    vector<bool> units(h * w);
    // check if param is consistent
    if (param < 0 || param > h * w)
    {
        cerr << "Error value param" << endl;
        return;
    }

    // set active units
    for (int i = 0; i < param; i++)
    {
        units[i] = 1;
    }

    // set inactive units
    for (int i = param; i < h * w; i++)
    {
        units[i] = 0;
    }

    // use time based seed for default random generator
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(units.begin(), units.end(), default_random_engine(seed));

    cout << "create space ended" << endl;
    // convert 1D space into 2D space
    setUnit_states(units);
}

int World::getWidth()
{
    return this->width;
}

int World::getHeight()
{
    return this->height;
}

void World::setUnit_states(vector<bool> &v)
{
    if (v.size() != unsigned(getHeight() * getWidth()))
    {
        cerr << "incorrect array size" << endl;
    }
    // initialize space
    unit_states = vector<vector<bool>>(getWidth(), vector<bool>(getHeight()));
    for (int i = 0; i < this->getWidth(); i++)
    {

        for (int j = 0; j < this->getHeight(); j++)
        {
            unit_states[i][j] = v[i * this->getHeight() + j];
        }
    }
}

void World::setUnit(int i, int j, bool val)
{
    this->unit_states[i][j] = val;
}

vector<vector<bool>> World::getUnit_states()
{
    return unit_states;
}

ostream &operator<<(ostream &stream, World &w)
{

    for (int i = 0; i < w.getWidth(); i++)
    {
        for (int j = 0; j < w.getHeight(); j++)
        {
            stream << w.getUnit_states()[i][j] << "  ";
        }
        stream << endl;
    }
    return stream;
}
