#include "window.h"
#include <iostream>
#include <linmath/linmath.h>

Window::Window(int x, int y)
{
    camera.set_ratio(x, y);
    time = 0;
    last_frame_time = 0;
    delta_time = 0;
    ares.InitWindow(x, y);
    camera.set_pointer(ares.getwindow());
}

void Window::loop(void) {

    float x, z, y;

    WordGeneration World;
    World.generate_world_map();

    Texture MAIN_TEXTURE;
        
    ares.PrepareToDraw(World.get_render_input());

    Shader shader;

    bool change = true;
    while (!glfwWindowShouldClose(ares.getwindow()))
    {
        if (glfwGetKey(ares.getwindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(ares.getwindow(), GL_TRUE);
        }
        glClearColor(0.5294f, 0.8078f, 0.9217f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // Enable depth test
        glEnable(GL_DEPTH_TEST);
        // Accept fragment if it closer to the camera than the former one
        glDepthFunc(GL_LESS);

        update_ratio();
        update_time();

        camera.camera_control(delta_time, ares.getwindow());

        ares.DrawElements(World.get_render_input(), shader, MAIN_TEXTURE, *camera.get_matrix());

        /* Swap front and back buffers */
        glfwSwapBuffers(ares.getwindow());

        /* Poll for and process events */
        glfwPollEvents();

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        x = camera.get_position_x();
        z = camera.get_position_z();
        y = camera.get_position_y();
        if (World.upgrade_chunks((float)x, (float)z)) {
            ares.PrepareToDraw(World.get_render_input());
        }

        //test
        //for (int i = 0; i < 8; i++)
        //{
        //    vec3* dir = camera.get_dir();
        //    if (World.get_map()[int(x + (i * *dir[0]))][int(z + (i * *dir[2]))] >= y + (i * *dir[1])) {
        //        std::cout << "x: " << int(x + (i * *dir[0])) << " z: " << int(z + (i * *dir[2])) << " y: " << y + (i * *dir[1]) << std::endl;
        //        break;
        //    }
        //}
    }

    glfwTerminate();
}

void Window::update_time() {
    time = glfwGetTime();
    delta_time = time - last_frame_time;
    last_frame_time = time;
}

void Window::update_ratio()
{
    glfwGetFramebufferSize(ares.getwindow(), &X, &Y);
    glViewport(0, 0, X, Y);
    camera.set_ratio(X, Y);
}
