#ifndef GAME_H
#define GAME_H

#include <vector>
#include <thread>
#include "Tetromino.h"
#include <atomic>

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

	void start();
	void end();
	void timer();
	void input_handler();
	void block_fall();

private:
	Shape grid_;
	std::unique_ptr<Tetromino> currentBlock_;

	// ��Ƽ������ ȯ�濡�� ������ �����ϰ� �о�, Race condition�� �����Ѵ�.
	std::atomic_bool running;
	
	std::thread timer_thread;
	std::thread input_thread;
	std::thread block_fall_thread;

	void rotate90(RotationDirection);
	void move(MoveDirection);

	Point searchPosition() const;
};

#endif //GAME_H

