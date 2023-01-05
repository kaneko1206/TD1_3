#include"Novice.h"
#include"Bullet.h"

Bullet::Bullet() {
	bullet.posX_ = 100;
	bullet.posY_ = 100;
	bullet.radius_ = 4;
	bullet.speed_ = 4;
	isShot_ = 0;
}

Bullet::Bullet(int speed) {
	bullet.posX_ = 100;
	bullet.posY_ = 100;
	bullet.radius_ = 4;
	bullet.speed_ = speed;
	isShot_ = 0;
}

Bullet::~Bullet() { }

void Bullet::Update() {
	if (isShot_ == 1) {
		bullet.posX_ += bullet.speed_;
		if (bullet.posX_ >= 1280|| bullet.posX_ <= 0) {
			isShot_ = 0;
		}
	}
}




void Bullet::Draw() {
	if (isShot_ == 1) {
		Novice::DrawEllipse(bullet.posX_, bullet.posY_, bullet.radius_, bullet.radius_, 0.0f, WHITE, kFillModeSolid);
	}
}

void Bullet::Shot(Transform transform) {
	this->bullet.posX_ = transform.posX_;
	this->bullet.posY_ = transform.posY_;
	isShot_ = 1;
}

int Bullet::IsShot() {
	return isShot_;
}