#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
	virtual ~Scene() = default;

	// ���� �����Լ�: Scene Ŭ������ ��� �޴� ��� Ŭ������ �ݵ�� �����ϵ��� �Ѵ�.
	virtual void initalize() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void finalize() = 0;
};
#endif