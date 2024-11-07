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

    // �ܼ� ȭ�� ���� ũ�� ���� (���� ũ�� ���� �� �ϸ� ��ũ�� ����)
    SMALL_RECT rect = { 0, 0, width / 8 - 1, height / 16 - 1 };  // �ؽ�Ʈ ȭ���� ũ�� (���� ũ�� ���)
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);

    // �ܼ� ȭ���� ���� ũ�� ����
    COORD coord = { width / 8, height / 16 };  // ȭ�� ũ�� ����
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // �ܼ� â ��ġ ���� (ȭ�� �߰�����)
    HWND hwnd = GetConsoleWindow();  // ���� �ܼ� â �ڵ� ���
    RECT rectWindow;
    GetWindowRect(hwnd, &rectWindow);  // ���� �������� ��ġ �� ũ�� ���� ���

    // ȭ�� ũ�� ��������
    screen_width = GetSystemMetrics(SM_CXSCREEN);  // ȭ�� ���� ũ��
    screen_height = GetSystemMetrics(SM_CYSCREEN);  // ȭ�� ���� ũ��

    // �ܼ� â�� ȭ�� �߰����� ��ġ��Ű��
    int posX = (screen_width - width) / 2;  // ȭ�� ���� �߰�
    int posY = (screen_height - height) / 2;  // ȭ�� ���� �߰�

    // �ܼ� â ��ġ ����
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
    
    // �� ���� ���̸� ����Ͽ� ���� �� ���� ���̸� ã��
    for (auto& row : T) {
        if (row.length() > max_line_length) {
            max_line_length = row.length();
        }
    }

    // �� ���� �߾ӿ� ���� ���
    for (auto& row : T) {
        int padding = (console_width - max_line_length) / 2; // ���ʿ� ���� ���� ���
        std::string spaces(padding, ' ');  // ���� ����
        std::cout << spaces << row << std::endl;  // ����� ���ڸ� ���
    }

    for (int i = 0; i < 3; ++i)
        std::cout << std::endl;

    for (int i = 0; i < 3; ++i) {
        int padding = (console_width - max_line_length) / 2; // ���ʿ� ���� ���� ���
        std::string spaces(padding, ' ');  // ���� ����

        if (i == selectedOption) {
            std::cout << spaces << menu[i] << " <" << std::endl;  // ���� ǥ��
        }
        else {
            std::cout << spaces << menu[i] << std::endl;  // ����� ǥ��
        }
    }

}

int StartScene::menuNavigation()
{
    int selectedOption = 0;  // ������ �� ���õ� �׸��� 0 (start)
    char ch;

    while (true) {
        
        if (_kbhit()) {  // Ű �Է��� ���� ��
            ch = _getch();  // �Էµ� Ű �б�

            if (ch == 27) {  // ESC Ű�� ������ ����
                return -1;
            }
            else if (ch == 72) {  // �� ����Ű (Arrow Up)
                selectedOption = (selectedOption - 1 + 3) % 3;  // ���� �׸��� ���� �̵�
            }
            else if (ch == 80) {  // �Ʒ� ����Ű (Arrow Down)
                selectedOption = (selectedOption + 1) % 3;  // ���� �׸��� �Ʒ��� �̵�
            }
            else if (ch == 13) {  // Enter Ű�� ������ ����
                if (selectedOption == 0) {
                    std::cout << "Game Starting...\n";
                    return 0;  // ���� ����
                }
                else if (selectedOption == 1) {
                    std::cout << "Showing Ranking...\n";
                    return 1;  // ��ŷ ����
                }
                else if (selectedOption == 2) {
                    std::cout << "Exiting...\n";
                    return 2;  // ����
                }
            }

            system("cls");  // ȭ�� �����
            printTetris(selectedOption);  // ���� ���õ� �׸��� ���
        }
    }
}