#include "Enemy.h"
#include"Novice.h"
#include"Bullet.h"

Enemy::Enemy() {
	enemy.posX_ = 800;
	enemy.posY_ = 300;
	enemy.radius_ = 15;
	enemy.speed_ = 5;
	bullet = new Bullet(-5);

}
Enemy::~Enemy() {
	delete bullet;
}


void Enemy::Update() {
	if ( bullet->IsShot() == 0) {
		bullet->Shot(enemy);
	}
	bullet->Update();
}


void Enemy::Draw() {
	Novice::DrawEllipse(enemy.posX_, enemy.posY_, enemy.radius_, enemy.radius_, 0.0f, WHITE, kFillModeSolid);
	bullet->Draw();
}