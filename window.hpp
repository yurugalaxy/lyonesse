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
    Window();
    ~Window();

    static void Initialise();
    static bool Active() {return s_active;}
    static void SetActive(const bool active) {s_active = active;}
    int Width() {return m_width;}
    int Height() {return m_height;}
    GLFWwindow* glWindow() {return m_windowPtr;}

  private:
    const char* m_title;
    int m_width;
    int m_height;
    float m_aspectRatio;
    GLFWwindow* m_windowPtr;
    static inline bool s_active {false};
  };
}
