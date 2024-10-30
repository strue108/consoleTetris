#include "Game.h"
#include <iostream>
#include <algorithm>

Game::Game()
    : grid_(20, std::vector<bool>(10, false)), // 20x10 크기의 그리드
    currentBlock_() // Tetromino의 기본 생성자 호출
{
    // 추가 초기화 코드가 필요하다면 여기에 작성
}


const void Game::printGrid() const
{
    int x = currentBlock_->getPoint().first;
    int y = currentBlock_->getPoint().second;

    int shapeHeight = currentBlock_->getShape().size();
    int shapeWidth = currentBlock_->getShape()[0].size();

    Shape blockShape = currentBlock_->getShape();
    Shape tmpGrid = grid_;

    for (auto j = y; j < y + shapeHeight; ++j) {
        for (auto i = x; i < x + shapeWidth; ++i) {
            tmpGrid[j][i] = grid_[j][i] + blockShape[j - y][i - x];
        }
    }

    for (auto row : tmpGrid) {
        for (auto element : row) {
            auto box = element ? "■" : "□";
            std::cout << box;
        }
        std::cout << std::endl;
    }

	return void();
}

void Game::setCurrentBlock(Tetromino block)
{
    currentBlock_ = std::make_unique<Tetromino>(std::move(block));
}

bool Game::isNewBlock()
{
    if (currentBlock_->getPoint().first == 0 && currentBlock_->getPoint().second == 0)
        return true;
    return false;
}


void Game::dropBlock()
{
    Point newPos = searchPosition();
    int x = newPos.first;
    int y = newPos.second;
    // if passed testc
    //int x = currentBlock_->getPoint().first;
    //int y = currentBlock_->getPoint().second;

    const Shape& blockShape = currentBlock_->getShape();
    int shapeHeight = blockShape.size();
    int shapeWidth = blockShape[0].size();
    
    for (auto j = 0; j < shapeHeight; ++j) {
        for (auto i = 0; i < shapeWidth; ++i) {
            if (blockShape[j][i])
                grid_[y + j][x + i] = true;
        }
    }
    
    *currentBlock_ = Tetromino();
}

void Game::handleInput(char input)
{
    switch (input)
    {
    case 'q':
        rotate90(RotationDirection::ccw);
        break;
    case 'e':
        rotate90(RotationDirection::cw);
        break;
    case 'a':
        move(MoveDirection::Left);
        break;
    case 's':
        move(MoveDirection::Down);
        break;
    case 'd':
        move(MoveDirection::Right);
        break;
    case 'f':
        dropBlock();
        break;
    }
}

void Game::deleteLine()
{
    for (auto rowNumber = 0; rowNumber < grid_.size(); ++rowNumber) {
        auto row = grid_[rowNumber];

        if (std::all_of(row.begin(), row.end(), [](bool v) {return v; })) {
            for (auto target = rowNumber; target > 0 ; --target) {
                grid_[target] = grid_[target -1];
            }
            std::fill(grid_[0].begin(), grid_[0].end(), false);
        }
    }
    
    
    // -> 여기에 점수 계산;

}

bool Game::checkCollision(const Shape& nextBlock, const Point& offset) const
{
    Point currentPos = currentBlock_->getPoint();
    int xOffset = currentPos.first + offset.first;
    int yOffset = currentPos.second + offset.second;

    int y = 0;
    for (const auto& row : nextBlock) {
        int x = 0;  
        for (bool element : row) {  
            int newX = xOffset + x;
            int newY = yOffset + y;

            if (element) {
                if (newX < 0 || newX >= grid_[0].size() || newY < 0 || newY >= grid_.size())
                    return true;

                if (grid_[newY][newX])
                    return true;
            }
            ++x;
        }
        ++y;
    }
    return false;  // 모든 요소를 검사했을 때 충돌이 없으면 false 반환
}

void Game::testFunc()
{
        char c;
        //while(true){
        std::cin >> c;
        handleInput(c);
        //printShape();    
}

void Game::rotate90(RotationDirection dir)
{
    const auto& shape = currentBlock_->getShape();
    int shapeWidth = shape.size();
    int shapeHeight = (shapeWidth > 0) ? shape[0].size() : 0;

    Shape rotatedShape(shapeHeight, std::vector<bool>(shapeWidth, false));

    if (dir == RotationDirection::cw) {
        for (int i = 0; i < shapeWidth; ++i)
            for (int j = 0; j < shapeHeight; ++j)
                rotatedShape[j][shapeWidth - 1 - i] = shape[i][j];
    }
    else if (dir == RotationDirection::ccw) {
        for (int i = 0; i < shapeWidth; ++i) {
            for (int j = 0; j < shapeHeight; ++j) {
                rotatedShape[shapeHeight - 1 - j][i] = shape[i][j];
            }
        }
    }

    if (!checkCollision(rotatedShape, { 0,0 }))
        currentBlock_->moveShape(rotatedShape);
    else
        std::cout << "Cannot Moved" << std::endl;
}

void Game::move(MoveDirection dir)
{
    const auto& shape = currentBlock_->getShape();

    switch (dir) {
    case MoveDirection::Left:
        if (!checkCollision(shape, { -1,0 }))
            currentBlock_->movePoint({ -1,0 });
        break;
    case MoveDirection::Right:
        if (!checkCollision(shape, { 1,0 }))
            currentBlock_->movePoint({ 1,0 });
        break;
    case MoveDirection::Down:
        if (!checkCollision(shape, { 0,1 }))
            currentBlock_->movePoint({ 0,1 });
        else
            dropBlock();
        break;
    }
}

Point Game::searchPosition() const 
{
    const Point curPoint = currentBlock_->getPoint();
    const Shape& curShape = currentBlock_->getShape(); 
    int dropDistance = 0;

    while (!checkCollision(curShape, { 0,dropDistance })) {
        ++dropDistance;
    }

    // 최종 위치는 충돌 직전 위치임.
    return { curPoint.first, curPoint.second + dropDistance - 1 };
}
