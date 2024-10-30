#include "Tetromino.h"
#include <iostream>
#include "Game.h"
#include <random>   

Tetromino::Tetromino()
    : shape_(Shape(1, std::vector<bool>(1, false))), // 1x1 ũ���� �� ������� �ʱ�ȭ
    point_(0, 0) // �ʱ� ��ġ (0, 0)
{
    setShape(getRandomShape());
    // �߰� �ʱ�ȭ�� �ʿ��ϴٸ� ���⿡ �ۼ�
}

Tetromino::Tetromino(TetrominoShape ts)
{
    setShape(ts);
}

const Shape& Tetromino::getShape() const
{
    return shape_;
}

const Point& Tetromino::getPoint() const
{
    return point_;
}

void Tetromino::setShape(TetrominoShape ts)
{
    switch (ts) {
    case TetrominoShape::I:
        shape_ = std::move(Shape{ {1}, {1}, {1}, {1} });
        break;
    case TetrominoShape::J:
        shape_ = std::move(Shape{ {1,1,1}, {0,0,1} });
        break;
    case TetrominoShape::L:
        shape_ = std::move(Shape{ {0,0,1}, {1,1,1} });
        break;
    case TetrominoShape::O:
        shape_ = std::move(Shape{ {1,1},{1,1} });
        break;
    case TetrominoShape::S:
        shape_ = std::move(Shape{ {1,1,0}, {0,1,1} });
        break;
    case TetrominoShape::T:
        shape_ = std::move(Shape{ {0,1,0}, {1,1,1} });
        break;
    case TetrominoShape::Z:
        shape_ = std::move(Shape{ {1,1,0}, {0,1,1} });
        break;
    }
}

void Tetromino::moveShape(Shape shape)
{
    shape_ = std::move(shape);
}

void Tetromino::movePoint(Point point)
{
    point_.first += point.first;
    point_.second += point.second;
}

TetrominoShape Tetromino::getRandomShape() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 6);

    // ������ TetrominoShape�� ��ȯ
    return static_cast<TetrominoShape>(dist(gen));
}

Tetromino::~Tetromino()
{
}



const void Tetromino::printShape() const
{
    for (auto row : shape_) {
        for (auto element : row) {
            auto box = element ? "��" : "��";
            std::cout << box;
        }
        std::cout << std::endl;
    }
}