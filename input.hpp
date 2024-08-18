//
// Created by kae on 18/08/24.
//

#pragma once

#include "window.hpp"

namespace Lyonesse
{
    class InputHandler
    {
    public:
        static void HandleInput(Window& window);
        static void OnMouseMove(GLFWwindow* win, double xPos, double yPos);
        static void OnResize(GLFWwindow* win, int width, int height);
    };
}
