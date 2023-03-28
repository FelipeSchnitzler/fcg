// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>
#define M_PI_2 1.57079632679489661923

class Goomba
{
public:
    glm::vec4 position;
    glm::vec4 center;
    glm::vec4 controlPoints[4];
    int quadrant;
    int spins;
    float initialTime;
    float currentTime;
    float lifetime;



    Goomba(glm::vec4 initial_center, float initial_time,float initial_lifetime)
    {
        this->center = initial_center;
        this->initialTime = initial_time;
        this->currentTime = initial_time;
        this->lifetime = initial_lifetime;


        //FONTE valores dos pontos de controle retirados de https://spencermortensen.com/articles/bezier-circle/
        this->controlPoints[0] = glm::vec4(0.0f,0.0f,1.00005519f,1.0f);
        this->controlPoints[1] = glm::vec4(0.55342686f,0.0f,0.99873585f,1.0f);
        this->controlPoints[2] = glm::vec4(0.99873585f,0.0f,0.55342686f,1.0f);
        this->controlPoints[3] = glm::vec4(1.00005519f,0.0f,0.0f,1.0f);

        this->position = glm::vec4(0.0f,0.0f,0.0f,1.0f);

        this->quadrant = 0;
        this->spins = 0;
    }

    bool updateEnemy(float delta_t)
    {
        this->currentTime += delta_t;
        float t = this->currentTime - (this->initialTime + (float) (4*spins+quadrant));
        double maxT = 1.0;

        if(this->currentTime - this->initialTime >= this->lifetime)
        {
            return true;
        }

        if(t >= 1.0f)
        {
            updateQuadrant();
            this->quadrant++;
            if(this->quadrant == 4)
            {
                this->spins++;
                this->quadrant = 0;
            }
        }
        t = (float)modf((double)t,&maxT);
        if(t >= 1.0f)
        {
            updateQuadrant();
            this->quadrant++;
            this->quadrant = this->quadrant % 4;
        }


        float t1 = 1.0f-t;

        this->position.x = (((float)pow(t1,3)) * this->controlPoints[0].x)
                     + (((float)3*t*pow(t1,2)) * this->controlPoints[1].x)
                     + (((float)3*(t1)*pow(t,2)) * this->controlPoints[2].x)
                     + (((float)pow(t,3)) * this->controlPoints[3].x);

        this->position.z = ((float)pow(t1,3)) * this->controlPoints[0].z
                     + ((float)3*t*pow(t1,2)) * this->controlPoints[1].z
                     + ((float)3*(t1)*pow(t,2)) * this->controlPoints[2].z
                     + ((float)pow(t,3)) * this->controlPoints[3].z;

        return  false;
    }

    void updateQuadrant()
    {
        float x;
        for (int i = 0; i < 4; i++)
        {
            x = this->controlPoints[i].x;
            this->controlPoints[i].x = this->controlPoints[i].z;
            this->controlPoints[i].z = -x;

        }
    }

    glm::vec4 getGlobalCoordinates()
    {
        glm::vec4 globalCoords = (this->position + this->center);
        globalCoords.w = 1.0f;//ERRADO POREM DIMINUI O NR DE OPERAÇÕES NECESSARIAS
        return globalCoords;
    }

};
