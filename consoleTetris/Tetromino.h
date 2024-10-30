#ifndef TEROMINO_H
#define TEROMINO_H

#include <vector>
#include <memory>

using Shape = std::vector<std::vector<bool>>;
using Point = std::pair<int, int>;

enum class TetrominoShape { I, J, L, O, S, T, Z };


class Tetromino
{
public:
	const Shape& getShape() const;
	const Point& getPoint() const;

	void setShape(TetrominoShape);
	void moveShape(Shape);
	void movePoint(Point);
	
	TetrominoShape getRandomShape();

	Tetromino();
	Tetromino(TetrominoShape);
	~Tetromino();

	// insert collision func.
	

	const void printShape() const;
	

private:
	Shape shape_;
	Point point_;
};

using TetrominoPtr = std::unique_ptr<Tetromino>;	// 스마트포인터

#endif
