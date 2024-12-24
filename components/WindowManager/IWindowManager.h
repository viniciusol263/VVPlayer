#pragma once

#include <memory>
#include <expected>

namespace WindowManager
{
    enum class WindowsManagerStatusCode
    {
        OK = 0,
        FailedToInitSDL,
        WindowsCreationFailed,
        OpenGLContextCreationFailed,

        UnknownError = sizeof(uint32_t)
    };

    class IWindowManager
    {
    public:
        virtual ~IWindowManager() = default;

        virtual WindowsManagerStatusCode InitializeGraphics() = 0;
        virtual bool GetWindowSync() = 0;
        virtual void Display() = 0;
        virtual void PollEvents() = 0;
    };
    using IWindowManagerPtr = std::shared_ptr<IWindowManager>;
}