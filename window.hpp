//
// Created by kae on 18/08/24.
//

#pragma once

#include "base.hpp"

namespace Lyonesse
{
  class Window
  {
  public:
    Window(float width, float height, const char* title);
    ~Window();

    static void Initialise();
    static bool Active() {return s_active;}
    static void SetActive(const bool active) {s_active = active;}
    float Width() {return m_width;}
    float Height() {return m_height;}
    GLFWwindow* glWindow() {return m_windowPtr;}

  private:
    const char* m_title;
    float m_width;
    float m_height;
    float m_aspectRatio;
    GLFWwindow* m_windowPtr;
    static inline bool s_active {false};
  };
}
