#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "Scene.h"
class StartScene :
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
    int getConsoleWidth();
    void initalizeConsole();
    void printTetris(int selectedOption);
    void menuNavigation();
    //void PrintCenteredText(const std::string& text, int screenWidth);
    //void SetConsoleCursorPosition(int x, int y);
};

#endif