#pragma once

#include"Transform.h"
#include"Bullet.h"

class Player {
private:
	Transform transform;
	Bullet* bullet;

public:
	Player();
	~Player();
	void Draw();
	void Update(char* keys);
};