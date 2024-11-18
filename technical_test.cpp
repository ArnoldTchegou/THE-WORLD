#include "world.hpp"
#include "Engine.hpp"
#include "Rendering.hpp"

int main()
{
    // In this example, height = 8, width = 6 and number of active units = 14
    // The number of active units can be adjusted by providing the value of param
    // The units to shuffled to provide randomness
    // Renderer renders a 4x4 world space with units randomly displayed
    // Each call to visualize_world() computes the engine statements on the world and renders a new world
    World w(8, 6, 20);
    Rendering Renderer{Engine(w)};
    Renderer.visualize_world();
    // To create various engines with ability to customize compute statements, we can include constructors in the Engine class, each with different parameters
}