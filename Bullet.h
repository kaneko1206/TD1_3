#pragma once
#include"Transform.h"


class Bullet {
private:
	Transform bullet;
	int isShot_;

public:
	Bullet();
	Bullet(int speed);
	~Bullet();
	void Update();
	void Draw();
	void Shot(Transform transform);
	int IsShot();
	int getPosX() { return bullet.posX_; }
	int getPosY() { return bullet.posY_; }
	int getradius() { return bullet.radius_; }

};