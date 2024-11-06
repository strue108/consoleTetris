#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
	virtual ~Scene() = default;

	// 순수 가상함수: Scene 클래스를 상속 받는 모든 클래스가 반드시 구현하도록 한다.
	virtual void initalize() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void finalize() = 0;
};
#endif