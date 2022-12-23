#include"Novice.h"
#include "Player.h"
#include"Bullet.h"

Player::Player() {
	transform.posX = 400;
	transform.posY = 300;
	transform.radius = 15;
	transform.speed = 5;
	bullet = new Bullet();
}
Player::~Player() {
	delete bullet;
}


void Player::Update(char* keys) {
	if (keys[DIK_W]) {
		transform.posY -= transform.speed;
	}
	if (keys[DIK_A]) {
		transform.posX -= transform.speed;
	}
	if (keys[DIK_S]) {
		transform.posY += transform.speed;
	}
	if (keys[DIK_D]) {
		transform.posX += transform.speed;
	}
	if (keys[DIK_SPACE] && bullet->IsShot() == 0) {
		bullet->Shot(transform);
	}
	bullet->Update();
}


void Player::Draw() {
	Novice::DrawEllipse(transform.posX, transform.posY, transform.radius, transform.radius, 0.0f, WHITE, kFillModeSolid);
	bullet->Draw();
}