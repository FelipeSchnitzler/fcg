// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

class Egg
{
public:
    glm::vec4 position;
    float gravity;

    Egg(glm::vec4 initial_position)
    {
        this->position = initial_position;
        this->position.y -= 0.175f;
        this->gravity = 0.015f;
    }

    void updateEgg(float delta_t)
    {
        this->position.y -= this->gravity;
    }

    bool floorColision(float floorY, float eggResize)
    {
        if (floorY >= this->position.y-(1.25f*eggResize))//because of the egg resize factor
        {
            return true;
        }
        return false;
    }
};
