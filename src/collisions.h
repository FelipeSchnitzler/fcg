#ifndef COLLISIONS_H_INCLUDED
#define COLLISIONS_H_INCLUDED

bool collisionSpherePlane(glm::vec4 sphereCenter, float sphereRadius,glm::vec4 planePoint,glm::vec4 planeNormal);
bool collisionSphereSphere(glm::vec4 sphereCenter1, float sphereRadius1,glm::vec4 sphereCenter2, float sphereRadius2);
bool collisionCubePlane(glm::vec4 BBMin,glm::vec4 BBMax,glm::vec4 planePoint,glm::vec4 planeNormal);

#endif // COLLISIONS_H_INCLUDED
