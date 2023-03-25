#ifndef COLLISIONS_H_INCLUDED
#define COLLISIONS_H_INCLUDED

bool collisionSpherePlane(glm::vec4 sphereCenter, float sphereRadius,glm::vec4 planePoint,glm::vec4 planeNormal);
bool collisionSphereSphere(glm::vec4 sphereCenter1, float sphereRadius1,glm::vec4 sphereCenter2, float sphereRadius2);

#endif // COLLISIONS_H_INCLUDED
