#include "Rendering.hpp"
#include <set>

Rendering::Rendering(Engine E)
{
    this->E = E;
}

void Rendering::visualize_world()
{
    bool do_quit;
    set<char> s{'Y', 'y', 'N', 'n'};
    char exit;
    while (true)
    {
        cout << "\033[2J" << endl;
        cout << "World space before compute ..." << endl;
        cout << E.getWorld();
        E.compute_space_evolution();
        cout << "New World space after compute ..." << endl;
        cout << E.getWorld();
        while (!do_quit)
        {
            cout << "Do you want to exit? Enter Y/y to quit or N/n to continue generating" << endl;
            cin >> exit;
            if (s.find(exit) != s.end())
            {
                do_quit = true;
            }
        }
        if (exit == 'N' || exit == 'n')
        {
            exit = ' ';
            do_quit = false;
            continue;
        }
        else if (exit == 'Y' || exit == 'y')
        {
            break;
        }
    }
}
