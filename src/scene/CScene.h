#pragma once

#include <vector>
#include <memory>

class CSceneObject;

class CScene
{
   public:
    CScene();
    ~CScene();

    void addObject(std::shared_ptr<CSceneObject> object);
    const std::vector<std::shared_ptr<CSceneObject>>& getObjects();

   private:
    std::vector<std::shared_ptr<CSceneObject>> m_objects;
};