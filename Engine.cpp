#include "Engine.hpp"
#include <set>
using namespace std;

Engine::Engine(World &w)
{
    this->w = w;
}

World &Engine::compute_space_evolution()
{
    set<int> inactive_to_active{3, 6, 7, 8};
    set<int> active_to_active{3, 4, 6, 7, 8};
    vector<bool> units(w.getHeight() * w.getWidth());
    for (int i = 0; i < w.getWidth(); i++)
    {

        for (int j = 0; j < w.getHeight(); j++)
        {
            int active = count_neighbour_state(i, j, "active");
            // int inactive = count_neighbour_state(w, i, j, "inactive");
            if (w.getUnit_states()[i][j] == 0 && inactive_to_active.find(active) != inactive_to_active.end())
            {

                units[i * w.getHeight() + j] = 1;
                // cout << active << "(" << i << " ," << j << ")" << endl;
            }
            else if (w.getUnit_states()[i][j] == 1 && !(active_to_active.find(active) != active_to_active.end()))
            {
                units[i * w.getHeight() + j] = 0;
                // cout << active << "(" << i << " ," << j << ")" << endl;
            }
            else
            {
                units[i * w.getHeight() + j] = w.getUnit_states()[i][j];
            }
        }
    }
    w.setUnit_states(units);
    return w;
}

int Engine::count_neighbour_state(int i, int j, string state)
{
    int count = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            // skip the element itself
            if (x == 0 && y == 0)
            {
                continue;
            }

            int next_i = i + x;
            int next_j = j + y;

            // check bounds
            if (next_i >= 0 && next_i < w.getWidth() && next_j >= 0 && next_j < w.getHeight())
            {
                if (state == "active")
                {
                    count += w.getUnit_states()[next_i][next_j] == 1 ? 1 : 0;
                }
                else if (state == "inactive")
                {
                    count += w.getUnit_states()[next_i][next_j] == 0 ? 1 : 0;
                }
            }
        }
    }
    return count;
}

World &Engine::getWorld()
{
    return this->w;
}
