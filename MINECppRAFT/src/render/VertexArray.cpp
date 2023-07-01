#include "VertexArray.h"
#include <iostream>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &ID);
    glBindVertexArray(ID);
}

void VertexArray::enable()
{
    //glVertexAttribPointer(0, 1, GL_DOUBLE, GL_FALSE, sizeof(uint64_t), 0);
    //glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void VertexArray::bind() {
    glBindVertexArray(ID);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}
