#include <glad/glad.h>
#include <iostream>
#include <vector>
using namespace std; 
class DrawClass
{
private:
    unsigned int VAO;
    unsigned int VertexCount = 24;
    float CubeVertices[64] = {0};

    unsigned int __indices[24] = {
        /*CLOCK WISE*/
        0, 3, 2, 1,
        2, 3, 7, 6,
        0, 4, 7, 3,
        1, 2, 6, 5,
        4, 5, 6, 7,
        0, 1, 5, 4

        /*Counter Clock Wise*/
        //0, 1, 2, 3,
        //2, 6, 7, 3,
        //0, 3, 7, 4,
        //1, 5, 6, 2,
        //4, 7, 6, 5,
        //0, 4, 5, 1
    };


public:
    void Cube(float PosX, float PosY, float PosZ, float X, float Y, float Z)
    {   
        srand(time(NULL));
        float _cubeVertices[] =           //XYZWRGB
        {
            -PosX + X, -PosY + Y, -PosZ + Z,   1,   rand()%2, rand()%2, rand()%2, rand()%2,        //0
            +PosX + X, -PosY + Y, -PosZ + Z,   1,   rand()%2, rand()%2, rand()%2, rand()%2,        //1
            +PosX + X, +PosY + Y, -PosZ + Z,   1,   rand()%2, rand()%2, rand()%2, rand()%2,        //2
            -PosX + X, +PosY + Y, -PosZ + Z,   1,   rand()%2, rand()%2, rand()%2, rand()%2,        //3
            -PosX + X, -PosY + Y, +PosZ + Z,   1,   rand()%2, rand()%2, rand()%2, rand()%2,        //4
            +PosX + X, -PosY + Y, +PosZ + Z,   1,   rand()%2, rand()%2, rand()%2, rand()%2,        //5
            +PosX + X, +PosY + Y, +PosZ + Z,   1,   rand()%2, rand()%2, rand()%2, rand()%2,        //6
            -PosX + X, +PosY + Y, +PosZ + Z,   1,   rand()%2, rand()%2, rand()%2, rand()%2         //7
        };

        for (int i = 0; i < 64; i++) {
            this->CubeVertices[i] = _cubeVertices[i];
        }
    }

    //void CreateBufferCubePosCol(float arraySize = 192, unsigned int _vertexCount = 24) {
    //    VertexCount = _vertexCount;
    //    /*VAO*/
    //    glGenVertexArrays(1, &VAO);
    //    glBindVertexArray(VAO);
    //    {
    //        /*VBO*/
    //        unsigned int VBO;
    //        glGenBuffers(1, &VBO);
    //        {
    //            glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //            glBufferData(GL_ARRAY_BUFFER, arraySize, CubeVertices, GL_STATIC_DRAW);
    //            glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
    //            glEnableVertexAttribArray(0);
    //            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float)));
    //            glEnableVertexAttribArray(1);
    //        }
    //        glBindBuffer(GL_ARRAY_BUFFER, 0);   //Unbind VBO
    //    }
    //    glBindVertexArray(0);   //Unbind VAO
    //}
    void CreateBufferCubeIndices() {
        //VertexCount = _vertexCount;
        unsigned int EBO;
        /*VAO*/
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        {
            /*VBO*/
            unsigned int VBO;
            glGenBuffers(1, &VBO);
            {
                /*EBO*/ /*Element Buffer Object*/
                glGenBuffers(1, &EBO);
                {
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
                    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(__indices), __indices, GL_STATIC_DRAW);
                }
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(CubeVertices), CubeVertices, GL_STATIC_DRAW);
                glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float)));
                glEnableVertexAttribArray(1);
            }
            glBindBuffer(GL_ARRAY_BUFFER, 0);   //Unbind VBO
        }
        glBindVertexArray(0);                   //Unbind VAO
    }

    void draw() {
        glBindVertexArray(VAO);
        glDrawElements(GL_QUADS, VertexCount, GL_UNSIGNED_INT, 0);
    }
};





