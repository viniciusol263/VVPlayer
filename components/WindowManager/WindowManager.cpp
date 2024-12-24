#include "WindowManager.h"

#include <chrono>
#include <print>
#include <numbers>

namespace WindowManager
{
    WindowManager::WindowManager()
    {
        InsertDefaultEventCallbacks();
    }

    bool WindowManager::GetWindowSync()
    {
        return m_isThreadRunning;
    }

    void WindowManager::Display()
    {
        m_window->display();
    }

    void WindowManager::PollEvents()
    {
        sf::Event event;
        while(m_window->pollEvent(event))
        {
            if(auto search = m_eventCallbacks.find(event.type); search != m_eventCallbacks.end())
            {
                search->second(event);
            }
        }
    }

    WindowsManagerStatusCode WindowManager::InitializeGraphics()
    {
        sf::ContextSettings settings;
        settings.depthBits = 24;
        settings.majorVersion = 3;
        settings.minorVersion = 3; // OpenGL 3.3
        settings.attributeFlags = sf::ContextSettings::Default;

        m_window = std::make_shared<sf::Window>(sf::VideoMode(800,600), "OpenGL", sf::Style::Default, settings);
    
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glMatrixMode(GL_PROJECTION);
        
        glLoadIdentity();
        double aspectRatio = 800.0 / 600.0;
        double nearPlane = 1.0;
        double farPlane = 100.0;
        double fovY = 45.0; // Field of view in the Y direction
        double top = nearPlane * tan(fovY * std::numbers::pi / 360.0);
        double bottom = -top;
        double left = bottom * aspectRatio;
        double right = top * aspectRatio;
        glFrustum(left, right, bottom, top, nearPlane, farPlane);

        glMatrixMode(GL_MODELVIEW);

        return WindowsManagerStatusCode::OK;
    }

    void WindowManager::InsertDefaultEventCallbacks()
    {
        m_eventCallbacks[sf::Event::Closed] = [this](const sf::Event& event)
        {
            m_isThreadRunning = false;
        };
    }

}