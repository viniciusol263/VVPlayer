#pragma once

#include "IWindowManager.h"

#include <atomic>
#include <map>
#include <functional>

#include "SFML/Window.hpp"
#include "SFML/OpenGL.hpp"

#include "ThreadSafeQueue/ThreadSafeQueue.h"

namespace WindowManager
{
    using ThreadSafeQueueEvent = Libs::ThreadSafeQueue<sf::Event>;

    class WindowManager : public IWindowManager
    {
    public: 
        WindowManager();
        virtual ~WindowManager() = default;

        WindowsManagerStatusCode InitializeGraphics() final;
        bool GetWindowSync() final;
        void Display() final;
        void PollEvents() final;
    private:
        void InsertDefaultEventCallbacks();

        std::shared_ptr<sf::Window> m_window;
        std::map<sf::Event::EventType, std::function<void(const sf::Event&)>> m_eventCallbacks;

        std::atomic_bool m_isThreadRunning = true;
    };
}