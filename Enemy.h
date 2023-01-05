#pragma once
#include"Transform.h""
#include"Bullet.h"

class Enemy
{
private:
	Transform enemy;
	Bullet* bullet;

public:

	Enemy();
	~Enemy();
	void Draw();
	void Update();
	int getPosX() { return enemy.posX_; }
	int getPosY() { return enemy.posY_; }
	int getradius() { return enemy.radius_; }
	int getBulletPosX() { return bullet->getPosX(); }
	int getBulletPosY() { return bullet->getPosY(); }
	int getBulletradius() { return bullet->getradius(); }
};

