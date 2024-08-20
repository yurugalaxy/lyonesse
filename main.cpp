//Engine stuff
#include <iostream>

#include "base.hpp"
#include "window.hpp"
#include "input.hpp"
#include "shader.hpp"

#include <vector>

//Imgui

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

struct Model
{
  std::vector<GLfloat> Vertices{};

  std::vector<GLfloat> Colours{};

  std::vector<GLfloat> TextureCoords {};

  unsigned long m_vertSize {Vertices.size() * sizeof(GLfloat)};
  unsigned long m_colourSize {Colours.size() * sizeof(GLfloat)};
  unsigned long m_TextureSize {TextureCoords.size() * sizeof(GLfloat)};
};

struct Quad : Model
{
  std::vector<GLfloat> Vertices
  {
    -0.05f, 0.05f, 0.05f,
    -0.05f,-0.05f,-0.05f,
    -0.05f, 0.05f, 0.05f,
    -0.05f, 0.05f, 0.05f
  };

  std::vector<GLfloat> Colours
  {
    1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f
  };

};

struct Cube : Model
{
  std::vector<GLfloat> Vertices
  {
     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
  };

};

Quad baseQuad;

Cube baseCube;

class Entity
{
public:
  void Init(glm::vec3 offset, int ID)
  {
    m_offset = offset;
    inUse = true;
    m_ID = ID;
  }

  ~Entity()
  {
    inUse = false;
    std::cout << "Destroyed entity " << m_ID << ".\n";
  }

  GLuint ID() { return m_ID; }
  bool Alive() { return inUse; }
  glm::vec3 Offset() { return m_offset; }
  void Kill() { inUse = false; }

private:
  Model& m_modelRef = baseQuad;
  glm::vec3 m_offset {0.0f};
  bool inUse{false};
  int m_ID;
};

template<int S>
class EntityContainer
{
public:
  void Create(glm::vec3 offset)
  {
    for (int i = 0; i < m_entityLimit; ++i)
    {
      if (m_entities[i].Alive())
      {
        continue;
      }

      m_entities[i].Init(offset, i);
      std::cout << "Created entity " << i << ".\n";
      return;
    }
    std::cout << "AWFUL. Ran out of room in handler.\n";
  }

  void Murder()
  {
    for (int i = 0; i < m_entityLimit; ++i)
    {
      if (m_entities[i].Alive())
      {
        m_entities[i].Kill();
      }
    }
    std::cout << "KILLED ALL ENTITIES. :3\n";
  }

  void Info()
  {
    for (auto& e: m_entities)
    {
      std::cout << &e << '\n';
    }
    std::cout << '\n';
  }

  Entity& Ent(int i) { return m_entities[i]; }
  int EntLimit() { return m_entityLimit; }

private:
  const int m_entityLimit{S};
  Entity m_entities[S];
};

int main()
{
  Lyonesse::Window window(1920, 1080, "awoo");

  EntityContainer<100> handlerofstuff;

  for (int i = 0; i < 10; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      handlerofstuff.Create(glm::vec3(j * 0.15f - 0.7f, i * 0.15f - 0.7f, 1.0f));
    }
  }

  //TODO: It's not rendering after changing offset to a vec3
  Lyonesse::Shader baseShader("../assets/shaders/instance.vert", "../assets/shaders/instance.frag");
  baseShader.Use();

  for (int i = 0; i < handlerofstuff.EntLimit(); ++i)
  {
    // baseShader.UploadUniformFloat2("offsets[" + std::to_string(i) + "]", LotsofQuads[i].Offset());
    baseShader.UploadUniformFloat3("offsets[" + std::to_string(i) + ']', handlerofstuff.Ent(i).Offset());
  }

  GLuint VBOquads, VBOcolour, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBOquads);
  glGenBuffers(1, &VBOcolour);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBOquads);

  glBufferData(GL_ARRAY_BUFFER, baseQuad.m_vertSize, &baseQuad.Vertices.front(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, VBOcolour);
  glBufferData(GL_ARRAY_BUFFER, baseQuad.m_colourSize, &baseQuad.Colours.front(), GL_STATIC_DRAW);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
  glEnableVertexAttribArray(1);

  while (Lyonesse::Window::Active())
  {
    Lyonesse::InputHandler::HandleInput(window);

    glClearColor(0.1f, 0.135f, 0.145f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindVertexArray(VAO);
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, 100);

    glfwSwapBuffers(window.glWindow());
    glfwPollEvents();
  }
}
