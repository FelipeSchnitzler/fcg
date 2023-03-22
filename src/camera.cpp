#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
    bool freeCam;
    bool UpArrowPressed;
    bool DownArrowPressed;
    bool RightArrowPressed;
    bool LeftArrowPressed;
    float speed;

    glm::vec4 position;
    float theta;
    float phi;
    float distance;

    glm::vec4 view;
    glm::vec4 up;
    glm::vec4 look_at;

    Camera(glm::vec4 initial_position,float initial_theta,float inicial_phi)
    {
        this->freeCam = false;
        this->UpArrowPressed = false;
        this->DownArrowPressed = false;
        this->RightArrowPressed = false;
        this->LeftArrowPressed = false;
        this->speed = 1.0f;

        this->position = initial_position;
        this->theta = initial_theta;
        this->phi = inicial_phi;
        this->distance = 0.5f;
        this->up = glm::vec4(0.0f,1.0f,0.0f,0.0f);
        this->look_at = glm::vec4(0.0f,0.0f,0.0f,0.0f);
    }

    void updateCamera(glm::vec4 playerPosition,float delta_t)
    {
        if (!freeCam)
        {//camera orbital
            this->look_at = playerPosition;
            this->look_at.y += 0.2f;//deslocamento necessario para ir ao centro do objeto



            this->position.x = this->distance * cos(this->phi) * sin(this->theta);
            this->position.y = this->distance * sin(this->phi);
            this->position.z = this->distance * cos(this->phi) * cos(this->theta);

            this->view = this->look_at - this->position;
        }else
        {//camera livre TODO
            glm::vec4 w;
            glm::vec4 u;
            glm::vec4 cross = glm::vec4(0.0f,0.0f,0.0f,0.0f);

            this->view.x = -this->distance * cos(this->phi) * sin(this->theta);
            this->view.y = -this->distance * sin(this->phi);
            this->view.z = -this->distance * cos(this->phi) * cos(this->theta);

            w.x = -this->view.x/norm(this->view);
            w.y = -this->view.y/norm(this->view);
            w.z = -this->view.z/norm(this->view);

            cross = crossproduct(this->up,w);
            u = glm::vec4(cross.x/norm(cross),
                          cross.y/norm(cross),
                          cross.z/norm(cross),
                          0.0f);

            if (this->UpArrowPressed)

            {
                this->position.x += -w.x * this->speed * delta_t;
                this->position.y += -w.y * this->speed * delta_t;
                this->position.z += -w.z * this->speed * delta_t;
            }

            if (this->DownArrowPressed)
            {
                this->position.x += w.x * this->speed * delta_t;
                this->position.y += w.y * this->speed * delta_t;
                this->position.z += w.z * this->speed * delta_t;
            }

            if (this->LeftArrowPressed)
            {
                this->position.x += -u.x * this->speed * delta_t;
                this->position.z += -u.z * this->speed * delta_t;
            }

            if (this->RightArrowPressed)
            {
                this->position.x += u.x * this->speed * delta_t;
                this->position.z += u.z * this->speed * delta_t;
            }
        }
    }

    void UpdateCameraAngle(float dx, float dy)
    {
        this->theta -= dx;
        this->phi   += dy;

        float phimax = 3.141592f / 2;
        float phimin = -phimax;

        if (this->phi > phimax)
            this->phi = phimax;

        if (this->theta < phimin)
            this->theta = phimin;
    }
};
