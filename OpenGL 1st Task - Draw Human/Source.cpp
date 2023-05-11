#include <glad/glad.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Source.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "shader_m.h"
#include "DrawClass.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

//void Initialize();
//void DrawCommands();
//void GameplayLoop();
//void SetupWindow(sf::Window& window);
//
//float timeCounter = -1.5f;
//
//sf::Window window;
//Shader ourShader;
//DrawClass Head, Body;
//
//glm::vec3 cameraPos = glm::vec3(0, 0, 3);
//glm::vec3 cameraForward = glm::vec3(0, 0, -1);
//
//
//int main()
//{
//    // create the window
//    SetupWindow(window);
//
//    // load resources, initialize the OpenGL states, ...
//    Initialize();
//
//    // run the main loop
//    GameplayLoop();
//
//    // release resources...
//
//    return 0;
//}
//
//void Initialize()
//{
//    ourShader.compile("vertex_shader.vert", "fragment_shader.frag");    //بقوله خد الفايلين دول و جهزهم للاستخدام
//    //Draw will be Counter Clockwise
//    float _Head[] = {    //el array de 3awz ab3atha fel GPU memory (hya kda fel PC memory)
//        //Head
//        -0.5, 0.35, 0.5, 1,       1,1,0,1,         //Point 1 XYZ + RGBA
//         0.5, 0.35, 0.5, 1,       1,0,1,1,         //Point 2 XYZ + RGBA
//         0.5,  0.9, 0.5, 1,       1,0,0,1,         //Point 3 XYZ + RGBA
//        -0.5,  0.9, 0.5, 1,       1,0,0,1,         //Point 4 XYZ + RGBA
//
//        
//    };
//    float _Body[] = {
//        //Body mid
//        -0.25, -0.345, 0.5, 1,       1,1,0,1,
//         0.25, -0.345, 0.5, 1,       1,0,1,1,
//         0.25,  0.345, 0.5, 1,       1,0,0,1,
//        -0.25,  0.345, 0.5, 1,       1,0,0,1,
//    };
//
//    //float Quad[] = {    //el array de 3awz ab3atha fel GPU memory (hya kda fel PC memory)
//    //-0.5, -0.5, 0.5, 1,
//    // 0.5, -0.5, 0.5, 1,
//    // 0.5,  0.5, 0.5, 1,
//    //-0.5,  0.5, 0.5, 1,
//    //};
//
//    //unsigned int Indices[] = {
//    //    0, 1, 2,        //1st triangle
//    //    2, 3, 0,        //2nd triangle
//    //};
//
//    Head.CreateBufferColorOnlyXYZWRGBA(_Head, sizeof(_Head), 4);
//    Body.CreateBufferColorOnlyXYZWRGBA(_Body, sizeof(_Body), 4);
//}
//
//void DrawCommands()
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     //clear buffers
//    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);                   //7ot lon lel 5alfeya
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//        cameraPos.z -= 0.005f;
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//        cameraPos.z += 0.005f;
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//        cameraPos.x += 0.005f;
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//        cameraPos.x -= 0.005f;
//    }
//
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//        //cameraForward = glm::rotate(cameraForward, -0.2f, glm::vec3(0, 1, 0));
//    }                                             //angel
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//        //cameraForward = glm::rotate(cameraForward, 0.2f, glm::vec3(0, 1, 0));
//    };
//
//    ourShader.use();
//
//    glm::mat4 model = glm::mat4(1.0f);
//    model = glm::translate(model, glm::vec3(0, -0.5, 0));
//    model = glm::rotate(model, -80.0f, glm::vec3(1, 0, 0));
//    model = glm::scale(model, glm::vec3(1, 3, 1));
//    
//    //glm::mat4 view = glm::lookAt(
//    //    glm::vec3(cameraPos.x, 0, cameraPos.z),         //camera position
//    //    glm::vec3(0, 0, 0),                             //point iam looking at
//    //    glm::vec3(0, 1, 0)                              //up vector
//    //);   
//    
//    glm::mat4 view = glm::lookAt(
//        cameraPos,
//        cameraPos + cameraForward,
//        glm::vec3(0, 1, 0)                              
//    );
//
//    glm::mat4 projection = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
//                                            //FOV   ASPECT RATIO    اقرب مسافه اشوف منها - z ابعد مسافه اشوفها    
//
//    ourShader.setMat4("model", model);
//    ourShader.setMat4("view", view);
//    ourShader.setMat4("projection", projection);
//    //Draw is Counter Clockwise
//    Head.DrawCube();
//    Body.DrawCube();
//}
//
//void GameplayLoop()
//{
//    bool running = true;
//    while (running)
//    {
//        // handle events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                // end the program
//                running = false;
//            }
//            else if (event.type == sf::Event::Resized)
//            {
//                // adjust the viewport when the window is resized
//                glViewport(0, 0, event.size.width, event.size.height);
//            }
//        }
//
//        //Draw the buffers
//        DrawCommands();
//
//        // end the current frame (internally swaps the front and back buffers)
//        window.display();
//    }
//}
//
//void SetupWindow(sf::Window& window)
//{
//    window.create(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));      //بعمل دي عشان اربط ال
//    //SFML + OpenGl
//    window.setVerticalSyncEnabled(true);
//    // activate the window
//    window.setActive(true);
//
//    gladLoadGL();
//    glEnable(GL_DEPTH_TEST);
//}
//


#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 1080

void Initialize();
void DrawCommands();
void GameplayLoop();
void SetupWindow(sf::Window& window);

sf::Window window;
Shader ourShader;
DrawClass Head, Body, RightLeg, LeftLeg, RightArm, LeftArm;

glm::vec3 cameraPos = glm::vec3(0, 2.5, 12.5);
glm::vec3 cameraForward = glm::vec3(0, 0, -1);


int main()
{
    // create the window
    SetupWindow(window);

    // load resources, initialize the OpenGL states, ...
    Initialize();

    // run the main loop
    GameplayLoop();

    // release resources...

    return 0;
}

void Initialize()
{
    ourShader.compile("vertex_shader.vert", "fragment_shader.frag");
    
    Head.Cube(2.5, 1.125, 0.5, 0, 5, 0.5);
    Head.CreateBufferCubeIndices();
    Body.Cube(1.5, 1.5, 0.5, 0, 2.5, 0.5);
    Body.CreateBufferCubeIndices();
    RightLeg.Cube(0.5, 1, 0.5, 0.666, 0, 0.5);
    RightLeg.CreateBufferCubeIndices();
    LeftLeg.Cube(0.5, 1, 0.5, -0.666, 0, 0.5);
    LeftLeg.CreateBufferCubeIndices();
    RightArm.Cube(0.5, 1.25, 0.5, 2, 2, 0.5);
    RightArm.CreateBufferCubeIndices();
    LeftArm.Cube(0.5, 1.25, 0.5, -2, 2, 0.5);
    LeftArm.CreateBufferCubeIndices();
}

void DrawCommands()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);                  

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        cameraPos.z -= 0.05f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        cameraPos.z += 0.05f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        cameraPos.x += 0.05f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        cameraPos.x -= 0.05f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        cameraPos.y += 0.05f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        cameraPos.y -= 0.05f;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        cameraForward = glm::rotate(cameraForward, -0.2f, glm::vec3(0, 1, 0));
    }                                             
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        cameraForward = glm::rotate(cameraForward, 0.2f, glm::vec3(0, 1, 0));
    };

    ourShader.use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0, 0, 0));
    model = glm::rotate(model, 0.0f, glm::vec3(0, 1, 0));
    model = glm::scale(model, glm::vec3(1, 1, 1));
    glm::mat4 view = glm::lookAt(
        cameraPos,                  //camera pos
        cameraPos + cameraForward,  //pos iam looking at
        glm::vec3(0, 1, 0)          //up vector
    );

    glm::mat4 projection = glm::perspective(45.0f, (float) WINDOW_WIDTH / WINDOW_HEIGHT, 0.01f, 100.0f);

    ourShader.setMat4("model", model);
    ourShader.setMat4("view", view);
    ourShader.setMat4("projection", projection);

    //Draw is Counter Clockwise
    Head.draw();
    Body.draw();
    RightLeg.draw();
    LeftLeg.draw();
    RightArm.draw();
    LeftArm.draw();
}

void GameplayLoop()
{
    bool running = true;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        //Draw the buffers
        DrawCommands();

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }
}

void SetupWindow(sf::Window& window)
{
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "OpenGL", sf::Style::Default, sf::ContextSettings(32));      //بعمل دي عشان اربط ال
    //SFML + OpenGl
    window.setVerticalSyncEnabled(true);
    // activate the window
    window.setActive(true);

    gladLoadGL();
    glEnable(GL_DEPTH_TEST);
}

