#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
class GameScene :
    public Scene
{
public:
    void initalize() override;
    void update() override;
    void render() override;
    void finalize() override;

private:
    int screen_width;
    int screen_height;
    int selected_menu;
};

#endif

