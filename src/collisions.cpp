#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cmath>
#include <cstdio>
#include <cstdlib>

bool collisionSpherePlane(glm::vec4 sphereCenter, float sphereRadius,glm::vec4 planePoint,glm::vec4 planeNormal)
{
    if (sphereCenter.w != 1.0f || planePoint.w != 1.0f || planeNormal.w != 0.0f)
    {
        fprintf(stderr, "ERROR: Collision between sphere and plane needs 2 points and 1 vector.\n");
        std::exit(EXIT_FAILURE);
    }

    float distance = ((planeNormal.x*(sphereCenter.x-planePoint.x))
                     +(planeNormal.y*(sphereCenter.y-planePoint.y))
                     +(planeNormal.z*(sphereCenter.z-planePoint.z))
                     /sqrtf(pow(planeNormal.x,2) + pow(planeNormal.y,2) + pow(planeNormal.z,2)));

    if(distance <= sphereRadius)
    {
        return true;
    }
    return false;
}

bool collisionSphereSphere(glm::vec4 sphereCenter1, float sphereRadius1,glm::vec4 sphereCenter2, float sphereRadius2)
{
    if (sphereCenter1.w != 1.0f || sphereCenter2.w != 1.0f)
    {
        fprintf(stderr, "ERROR: Collision between two spheres needs 2 points.\n");
        std::exit(EXIT_FAILURE);
    }

    float distance = sqrtf(pow(sphereCenter1.x-sphereCenter2.x,2)
                          +pow(sphereCenter1.y-sphereCenter2.y,2)
                          +pow(sphereCenter1.z-sphereCenter2.z,2));

    if(distance <= sphereRadius1 + sphereRadius2)
    {
        return true;
    }
    return false;
}
