//
// Created by Mathew Hany on 15/10/2023.
//

#include "PlayerState.h"
#include "iostream"
#include "Shield.h"

PlayerState::PlayerState(int score, int lives, int shields, double speed) :
        score(score), lives(lives), shields(shields), speed(speed) {}

void PlayerState::addListener(PlayerStateListener *listener) {
    listeners.push_back(listener);
}

void PlayerState::setLives(int lives) {
    this->lives = lives;
    notifyListeners();
}

void PlayerState::setShields(int shields) {
    this->shields = shields;
    notifyListeners();
}

void PlayerState::setSpeed(double speed) {
    this->speed = speed;
    notifyListeners();
}

void PlayerState::setScore(int score) {
    this->score = score;
    notifyListeners();
}

void PlayerState::notifyListeners() {
    for (auto listener: listeners) {
        listener->onPlayerStateChanged(this);
    }
}

int PlayerState::getScore() const {
    return score;
}

int PlayerState::getLives() const {
    return lives;
}

int PlayerState::getShields() const {
    return shields;
}

double PlayerState::getSpeed() const {
    return speed;
}

void PlayerState::decrementLives() {
    lives--;
    notifyListeners();
}

void PlayerState::incrementScore() {
    score++;
    notifyListeners();
}

void PlayerState::decrementScore() {
    score--;
    notifyListeners();
}

void PlayerState::removeShield() {
    for (auto powerUp: appliedPowerUps) {
        if (dynamic_cast<Shield *>(powerUp)) {
            removePowerUp(powerUp);
            return;
        }
    }
    notifyListeners();
}

void PlayerState::removeExpiredPowerUps() {
    std::vector<PowerUp *> expiredPowerUps;

    for (auto const &powerUp: appliedPowerUps) {
        if (powerUp->isExpired()) {
            expiredPowerUps.push_back(powerUp);
        }
    }

    for (const auto &powerUp: expiredPowerUps) {
        removePowerUp(powerUp);
    }
}

void PlayerState::removePowerUp(PowerUp *powerUp) {
    powerUp->deactivate(this);

    for (int i = 0; i < appliedPowerUps.size(); i++) {
        if (appliedPowerUps[i] != powerUp) continue;

        appliedPowerUps[i] = appliedPowerUps.back();
        appliedPowerUps.pop_back();
    }
}

