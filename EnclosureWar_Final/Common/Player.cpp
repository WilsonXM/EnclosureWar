#include "Player.h"

Player::Player(Color playercolor) : QPoint(0, 0)
{
    playercolor_ = playercolor;
    move_ = Move::STOP;
    is_locked_ = false;
    is_out_ = false;
    speed_ = InitSpeed;
    passinglist_ = {};
    occupantlist_ = {};
    leftup_ = QPoint(0, 0);
    rightdown_ = QPoint(0, 0);
}

Player::Player(int x, int y, Color playercolor) : QPoint(x, y)
{
    playercolor_ = playercolor;
    move_ = Move::STOP;
    is_locked_ = false;
    is_out_ = false;
    speed_ = InitSpeed;
    passinglist_ = {};
    occupantlist_ = {};
    leftup_ = QPoint(0, 0);
    rightdown_ = QPoint(0, 0);
}

Color Player::GetPlayerColor() { return playercolor_; }

Move Player::GetMove() { return move_; }

bool Player::IsLocked() { return is_locked_; }

bool Player::IsOut() { return is_out_; }

int Player::GetSpeed() { return speed_; }

QList<QPoint> Player::GetPassingList() { return passinglist_; }

QList<QPoint> Player::GetOccupantList() { return occupantlist_; }

QPoint Player::GetLeftUp() { return leftup_; }

QPoint Player::GetRightDown() { return rightdown_; }

void Player::SetMove(Move move) { move_ = move; }

void Player::Lock() { is_locked_ = true; }

void Player::UnLock() { is_locked_ = false; }

void Player::SetOut(bool out) { is_out_ = out; }

void Player::SpeedUp() { speed_ = UpSpeed; }

void Player::SpeedDown() { speed_ = InitSpeed; }

void Player::SetPassingList(QList<QPoint> passinglist) { passinglist_ = passinglist; }

void Player::SetOccupantList(QList<QPoint> occupantlist) { occupantlist_ = occupantlist; }

void Player::SetLeftUp(QPoint leftup) { leftup_ = leftup; }

void Player::SetRightDown(QPoint rightdown) { rightdown_ = rightdown; }
