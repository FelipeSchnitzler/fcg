// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

class Player
{
public:
    glm::vec4 movement;
    glm::vec4 position;
    float speed;

    Player(glm::vec4 initial_position)
    {
        this->speed = 0.0f;
        this->movement = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
        this->position = initial_position;
        this->position.w = 1.0f;
    }

    void updateSpeed(float acceleration, float delta_t)
    {
        if (this->speed + acceleration != 0.0)
        {
            this->speed = this->speed + acceleration * delta_t;
        }
        if (this->movement.x == 0)
        {
            this->movement.x += acceleration;
        }
    }

    void updatePosition(float delta_t)
    {
        this->position.x += this->movement.x * this->speed * delta_t; // mantem o personagem sempre em movimento
        this->position.z += this->movement.z * this->speed * delta_t;
    }
};
