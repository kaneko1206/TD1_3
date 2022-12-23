#include"Novice.h"
#include"Bullet.h"

Bullet::Bullet() {
	transform.posX = 100;
	transform.posY = 100;
	transform.radius = 4;
	transform.speed = 4;
	isShot = 0;
}

Bullet::Bullet(int speed) {
	transform.posX = 100;
	transform.posY = 100;
	transform.radius = 4;
	transform.speed = speed;
	isShot = 0;
}

Bullet::~Bullet() { }

void Bullet::Update() {
	if (isShot == 1) {
		transform.posX += transform.speed;
		if (transform.posX >= 1280) {
			isShot = 0;
		}
	}
}




void Bullet::Draw() {
	if (isShot == 1) {
		Novice::DrawEllipse(transform.posX, transform.posY, transform.radius, transform.radius, 0.0f, WHITE, kFillModeSolid);
	}
}

void Bullet::Shot(Transform transform) {
	this->transform.posX = transform.posX;
	this->transform.posY = transform.posY;
	isShot = 1;
}

int Bullet::IsShot() {
	return isShot;
}