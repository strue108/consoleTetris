#ifndef GAME_H
#define GAME_H

#include <vector>
#include <thread>
#include "Tetromino.h"
#include <atomic>
#include <mutex>

using Shape = std::vector<std::vector<bool>>;
enum class RotationDirection { cw, ccw };
enum class MoveDirection { Left, Right, Down };

class Game
{
public:
	Game();
	const void printGrid() const;

	void setCurrentBlock(Tetromino);

	// 테스트용 함수, 생성된 블록의 좌표 (0,0)으로 생성여부를 파악
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

	std::atomic_bool running;

private:
	Shape grid_;
	std::unique_ptr<Tetromino> currentBlock_;

	// 멀티스레드 환경에서 변수를 안전하게 읽어, Race condition을 방지한다.
	std::mutex mtx;
	std::condition_variable cv;
	std::thread timer_thread;
	std::thread input_thread;
	std::thread block_fall_thread;

	void rotate90(RotationDirection);
	void move(MoveDirection);

	Point searchPosition() const;
};

#endif //GAME_H

