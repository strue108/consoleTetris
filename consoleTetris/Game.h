#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Tetromino.h"
using Shape = std::vector<std::vector<bool>>;
enum class RotationDirection { cw, ccw };
enum class MoveDirection { Left, Right, Down };

class Game
{
public:
	Game();
	const void printGrid() const;

	void setCurrentBlock(Tetromino);

	// �׽�Ʈ�� �Լ�, ������ ����� ��ǥ (0,0)���� �������θ� �ľ�
	bool isNewBlock();

	void dropBlock();
	void handleInput(char input);

	void deleteLine();

	bool checkCollision(const Shape&, const Point&) const;
	void testFunc();

private:
	Shape grid_;
	std::unique_ptr<Tetromino> currentBlock_;



	void rotate90(RotationDirection);
	void move(MoveDirection);

	Point searchPosition() const;
};

#endif //GAME_H

