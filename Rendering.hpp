#ifndef RENDERING
#define RENDERING
#include "Engine.hpp"
class Rendering
{
public:
    Rendering(Engine E);
    void visualize_world();

private:
    Engine E;
};

#endif