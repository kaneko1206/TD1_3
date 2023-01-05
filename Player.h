#pragma once

#include"Transform.h"
#include"Bullet.h"

class Player {
private:
	Transform player;
	Bullet* bullet;

public:
	Player();
	~Player();
	void Draw();
	void Update(char* keys);
	void Oncollision();
	int getPosX() { return player.posX_; }
	int getPosY() { return player.posY_; }
	int getradius() { return player.radius_; }
};