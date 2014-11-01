#pragma once

#include <memory>

#include "graphics/window/CGlfwWindow.h"

#include "input/IInputListener.h"

class CFreeCamera;
class IInputProvider;

class CCameraController : public IInputListener, public IGlfwWindowListener
{
   public:
    CCameraController();
    ~CCameraController();

    void setCamera(std::shared_ptr<CFreeCamera> camera);
    void setInputProvider(IInputProvider* provider);

    void animate(float dt);

    virtual void handleKeyEvent(EKeyEventType type, int keyCode) override;
    virtual void handleMouseMovementEvent(int x, int y) override;
    virtual void handleMouseButtonEvent(EMouseButtonEventType type, int buttonCode) override;
    
    virtual void handleResizeEvent(int width, int height) override;

   private:
    float m_speed = 1.0f;
   
    std::shared_ptr<CFreeCamera> m_camera = nullptr;
    IInputProvider* m_inputProvider = nullptr;
};