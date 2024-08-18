//
// Created by kae on 18/08/24.
//

#pragma once

#include "window.hpp"

namespace Lyonesse::InputHandler
{
    void HandleInput(Window& window);

    class Event
    {
    public:
        static void OnMouseMove(GLFWwindow* win, double xPos, double yPos);
        static void OnResize(GLFWwindow* win, int width, int height);
    };
}
