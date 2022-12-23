#pragma once

#include"Transform.h"


class Bullet {
private:
	Transform transform;
	int isShot;

public:
	Bullet();
	Bullet(int speed);
	~Bullet();
	void Update();
	void Draw();
	void Shot(Transform transform);
	int IsShot();

};