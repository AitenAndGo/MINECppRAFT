#include "ARES.h"

void ARES::prepare_voas()
{
    for (int i = 0; i < 82; i++)
    {
        VertexArray* voa = new VertexArray();
        voas.push_back(voa);
    }
}

void ARES::InitWindow(unsigned int resx, unsigned int resy)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Initialize the library */
    if (!glfwInit())
        std::cout << "failed initialized library" << std::endl;

    /* Create a windowed mode window and its OpenGL context */

    window = glfwCreateWindow(resx, resy, "MINECRAFT", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout << "Failed" << std::endl;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
    }

    prepare_voas();
}

void ARES::PrepareToDraw(std::vector<chunk*> elements)
{
    int i = 0;
    for (chunk* element : elements)
    {
        if (i == 80) {
            i = 80;
        }
        //delete element->voa;
        //delete element->vb;
        //delete element->ib;

        //element->set_voa(new VertexArray());
        voas[i]->bind();
        element->set_vb(new VertexBuffer(element->get_vertex_data(), element->get_size()));
        element->set_ib(new IndexBuffer(element->get_ind_data(), element->get_count()));
        //element->get_voa()->enable();
        voas[i]->enable();
        i++;
    }
}

//void ARES::PrepareToDraw(std::vector<block*> elements)
//{
//    for (block* element : elements)
//    {
//        //delete element->voa;
//        //delete element->vb;
//        //delete element->ib;
//        element->voa = new VertexArray();
//        element->vb = new VertexBuffer(element->get_ver(), element->get_size());
//        element->ib = new IndexBuffer(element->get_ind(), element->get_count());
//        element->voa->enable();
//    }
//}

void ARES::DrawElements(std::vector<chunk*> elements, Shader& s, Texture& t, mat4x4 cm)
{
    int i = 0;
    for (chunk* element : elements)
    {
        s.bind();
        s.SetUniform_mat4("MVP", cm);
        t.bind();
        voas[i]->bind();
        //element->get_voa()->bind();
        element->get_ib()->bind();
        glDrawElements(GL_TRIANGLES, element->get_ib()->GetCount(), GL_UNSIGNED_INT, nullptr);
        i++;
    }
}

//void ARES::DrawElements(std::vector<block*> elements, Shader& s, Texture& t, mat4x4 cm)
//{
//    for (block* element : elements)
//    {
//        s.bind();
//        s.SetUniform_mat4("MVP", cm);
//        t.bind();
//        element->voa->bind();
//        element->ib->bind();
//        glDrawElements(GL_TRIANGLES, element->ib->GetCount(), GL_UNSIGNED_INT, nullptr);
//    }
//}

GLFWwindow* ARES::getwindow()
{
    return window;
}
