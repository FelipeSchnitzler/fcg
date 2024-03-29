// Headers da biblioteca GLM: cria��o de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>
#ifndef COLLISIONS_H_INCLUDED
    #include "collisions.h"
#endif // COLLISIONS_H_INCLUDED

class Egg
{
public:
    glm::vec4 position;
    float gravity;

    Egg(glm::vec4 initial_position)
    {
        this->position = initial_position;
        this->position.y -= 0.175f;
        this->position.w = 1.0f;
        this->gravity = 1.5f;
    }

    void updateEgg(float delta_t)
    {
        this->position.y -= this->gravity * delta_t;
    }

    bool floorColision(float floorY, float eggResize)
    {
        if(collisionSpherePlane(position,1.25f*eggResize,glm::vec4(0.0f,floorY,0.0f,1.0f),glm::vec4(0.0f,1.0f,0.0f,0.0f)))
        {
            return true;
        }


        /*if (floorY >= this->position.y-(1.25f*eggResize))//because of the egg resize factor(original lowest point * resize)
        {
            return true;
        }*/
        return false;

    }
};
