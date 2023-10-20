//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_PLAYERSTATE_H
#define GRAPHICS_PLAYERSTATE_H

#include <vector>

class PowerUp;

class PlayerState;

class PlayerStateListener {
public:
    virtual void onPlayerStateChanged(PlayerState *playerState) = 0;
    virtual ~PlayerStateListener() = default;
};

class PlayerState {
    int score;
    int lives;
    int shields;
    double speed;

public:
    std::vector<PlayerStateListener *> listeners;

    std::vector<PowerUp *> appliedPowerUps;

    PlayerState(int score, int lives, int shields, double speed);

    void addListener(PlayerStateListener *listener);

    void setLives(int lives);

    void setShields(int shields);

    void setSpeed(double speed);

    void setScore(int score);

    int getScore() const;

    int getLives() const;

    int getShields() const;

    double getSpeed() const;

    void decrementLives();

    void incrementScore();

    void decrementScore();

    void removeShield();

    void removeExpiredPowerUps();

private:
    void notifyListeners();

    void removePowerUp(PowerUp *up);
};


#endif //GRAPHICS_PLAYERSTATE_H
