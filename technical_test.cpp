#include "world.hpp"
#include "Engine.hpp"
#include "Rendering.hpp"

int main()
{
    // In this example, height = 4, width = 4 and number of active units = 8
    // Renderer renders a 4x4 world space with units randomly displayed
    // Each call to visualize_world() computes the engine statements on the world and renders a new world
    World w(4, 4, 8);
    Rendering Renderer{Engine(w)};
    Renderer.visualize_world();
}