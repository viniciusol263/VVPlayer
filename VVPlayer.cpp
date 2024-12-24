#include "VVPlayer.h"
#include "WindowManager.h"

namespace VVPlayer
{
    VVPlayer::VVPlayer()
    {
        WindowManager::IWindowManagerPtr window = std::make_shared<WindowManager::WindowManager>();
        window->InitializeGraphics();
        float angle = 0.0f;
        while(window->GetWindowSync())
        {
            window->PollEvents(); 
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();
            glTranslatef(0.0f, 0.0f, -10.0f);
            glRotatef(angle, 1.0f, 1.0f, 1.0f);

            glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 1.0f);
            glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.0f, 0.5f, 1.0f);
            glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 1.0f);

            glEnd();

            window->Display();

            angle += 0.05f;
            if (angle > 360.0f) {
                angle -= 360.0f;
            }
        }
    }
}