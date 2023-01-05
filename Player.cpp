#include"Novice.h"
#include"Bullet.h"
#include "Player.h"

Player::Player() {
	player.posX_ = 400;
	player.posY_ = 300;
	player.radius_ = 15;
	player.speed_ = 5;
	player.color_ = WHITE;
	bullet = new Bullet();
}
Player::~Player() {
	delete bullet;
}


void Player::Update(char* keys) {
	if (keys[DIK_W] && player.posY_ > player.radius_) {
		player.posY_ -= player.speed_;
	}
	if (keys[DIK_A] && player.posX_ > player.radius_) {
		player.posX_ -= player.speed_;
	}
	if (keys[DIK_S] && player.posY_ < 720 - player.radius_) {
		player.posY_ += player.speed_;
	}
	if (keys[DIK_D] && player.posX_ < 1280 - player.radius_) {
		player.posX_ += player.speed_;
	}
	if (keys[DIK_SPACE] && bullet->IsShot() == 0) {
		bullet->Shot(player);
	}

	bullet->Update();
	player.color_ = WHITE;
}

void Player::Oncollision(){
	player.color_ = RED;
}

void Player::Draw() {
	Novice::DrawEllipse(player.posX_, player.posY_, player.radius_, player.radius_, 0.0f, player.color_, kFillModeSolid);
	bullet->Draw();
}