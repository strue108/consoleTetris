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
    int menuSelecting();

private:
    int selected_menu;
    int screen_width;
    int screen_height;
    int getConsoleWidth();
    void initalizeConsole();
    void printTetris(int selectedOption);
    int menuNavigation();
    //void PrintCenteredText(const std::string& text, int screenWidth);
    //void SetConsoleCursorPosition(int x, int y);
};

#endif