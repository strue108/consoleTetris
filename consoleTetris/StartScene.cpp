#include "StartScene.h"
#include "GameScene.h"
#include <iostream>
#include <conio.h> 
#include <Windows.h>
#include <string>


void StartScene::initalize()
{
    initalizeConsole();
    printTetris(0);
}

void StartScene::update()
{
    
}

void StartScene::render()
{

}

void StartScene::finalize()
{
}

int StartScene::menuSelecting()
{
    return menuNavigation();
}


int StartScene::getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void StartScene::initalizeConsole()
{
    const int width = 400;
    const int height = 400;

    // 콘솔 화면 버퍼 크기 설정 (버퍼 크기 설정 안 하면 스크롤 막힘)
    SMALL_RECT rect = { 0, 0, width / 8 - 1, height / 16 - 1 };  // 텍스트 화면의 크기 (글자 크기 고려)
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);

    // 콘솔 화면의 버퍼 크기 설정
    COORD coord = { width / 8, height / 16 };  // 화면 크기 설정
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // 콘솔 창 위치 설정 (화면 중간으로)
    HWND hwnd = GetConsoleWindow();  // 현재 콘솔 창 핸들 얻기
    RECT rectWindow;
    GetWindowRect(hwnd, &rectWindow);  // 현재 윈도우의 위치 및 크기 정보 얻기

    // 화면 크기 가져오기
    screen_width = GetSystemMetrics(SM_CXSCREEN);  // 화면 가로 크기
    screen_height = GetSystemMetrics(SM_CYSCREEN);  // 화면 세로 크기

    // 콘솔 창을 화면 중간으로 위치시키기
    int posX = (screen_width - width) / 2;  // 화면 가로 중간
    int posY = (screen_height - height) / 2;  // 화면 세로 중간

    // 콘솔 창 위치 설정
    MoveWindow(hwnd, posX, posY, width, height, TRUE);
}

void StartScene::printTetris(int selectedOption) {
    std::string T[7] = {
        "######  ####### ###### ######  ######  ##### ",
        "  ##    ##        ##   ##   ##   ##   ##   ##",
        "  ##    ##        ##   ##   ##   ##   ##     ",
        "  ##    #####     ##   ######    ##    ##### ",
        "  ##    ##        ##   ## ##     ##        ##",
        "  ##    ##        ##   ##  ##    ##   ##   ##",
        "  ##    #######   ##   ##   ## ######  ##### "
    };
    std::string menu[3] = {
        "                   START",
        "                  RANKING",
        "                    END"
    };

    int console_width = getConsoleWidth();
    int max_line_length = 0;

    
    for (int i = 0; i < 5; ++i)
        std::cout << std::endl;
    
    // 각 줄의 길이를 계산하여 가장 긴 줄의 길이를 찾음
    for (auto& row : T) {
        if (row.length() > max_line_length) {
            max_line_length = row.length();
        }
    }

    // 각 줄을 중앙에 맞춰 출력
    for (auto& row : T) {
        int padding = (console_width - max_line_length) / 2; // 왼쪽에 넣을 공백 계산
        std::string spaces(padding, ' ');  // 공백 생성
        std::cout << spaces << row << std::endl;  // 공백과 글자를 출력
    }

    for (int i = 0; i < 3; ++i)
        std::cout << std::endl;

    for (int i = 0; i < 3; ++i) {
        int padding = (console_width - max_line_length) / 2; // 왼쪽에 넣을 공백 계산
        std::string spaces(padding, ' ');  // 공백 생성

        if (i == selectedOption) {
            std::cout << spaces << menu[i] << " <" << std::endl;  // 강조 표시
        }
        else {
            std::cout << spaces << menu[i] << std::endl;  // 평범한 표시
        }
    }

}

int StartScene::menuNavigation()
{
    int selectedOption = 0;  // 시작할 때 선택된 항목은 0 (start)
    char ch;

    while (true) {
        
        if (_kbhit()) {  // 키 입력이 있을 때
            ch = _getch();  // 입력된 키 읽기

            if (ch == 27) {  // ESC 키를 누르면 종료
                return -1;
            }
            else if (ch == 72) {  // 위 방향키 (Arrow Up)
                selectedOption = (selectedOption - 1 + 3) % 3;  // 선택 항목을 위로 이동
            }
            else if (ch == 80) {  // 아래 방향키 (Arrow Down)
                selectedOption = (selectedOption + 1) % 3;  // 선택 항목을 아래로 이동
            }
            else if (ch == 13) {  // Enter 키를 누르면 선택
                if (selectedOption == 0) {
                    std::cout << "Game Starting...\n";
                    return 0;  // 게임 시작
                }
                else if (selectedOption == 1) {
                    std::cout << "Showing Ranking...\n";
                    return 1;  // 랭킹 보기
                }
                else if (selectedOption == 2) {
                    std::cout << "Exiting...\n";
                    return 2;  // 종료
                }
            }

            system("cls");  // 화면 지우기
            printTetris(selectedOption);  // 현재 선택된 항목을 출력
        }
    }
}