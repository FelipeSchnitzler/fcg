// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

class Goomba
{
public:
    glm::vec4 position;

    Goomba(glm::vec4 initial_position)
    {
        this->position = initial_position;
    }
};
