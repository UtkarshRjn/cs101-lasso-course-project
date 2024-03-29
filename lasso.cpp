//Utkarsh Ranjan
//200050147

#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"

using namespace simplecpp;

void Lasso::draw_lasso_band() {
  double len = (release_speed/MAX_RELEASE_SPEED)*LASSO_BAND_LENGTH;
  double arad = release_angle_deg*PI/180.0;
  double xlen = len*cos(arad);
  double ylen = len*sin(arad);
  lasso_band.reset(lasso_start_x, lasso_start_y, (lasso_start_x-xlen), (lasso_start_y+ylen));
  lasso_band.setThickness(LASSO_THICKNESS);
} // End Lasso::draw_lasso_band()

void Lasso::initLasso() {
  lasso_start_x = (PLAY_X_START+LASSO_X_OFFSET);
  lasso_start_y = (PLAY_Y_HEIGHT-LASSO_Y_HEIGHT);
  lasso_circle.reset(lasso_start_x, lasso_start_y, LASSO_SIZE);
  lasso_circle.setColor(COLOR("red"));
  lasso_circle.setFill(true);
  lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
  lasso_loop.setColor(COLOR("brown"));
  lasso_loop.setFill(true);
  addPart(&lasso_circle);
  addPart(&lasso_loop);
  magnet_radius = INIT_MAGNET_RADIUS;
  lasso_looped = false;
  magnet_attached = false;
  //the_coin = NULL;
  the_bomb = NULL;
  num_coins = 0;
  lives = 5;

  lasso_line.reset(lasso_start_x, lasso_start_y, lasso_start_x, lasso_start_y);
  lasso_line.setColor(COLOR("brown"));

  lasso_band.setColor(COLOR("BlueViolet"));
  draw_lasso_band();

} // End Lasso::initLasso()

void Lasso::yank() {
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
  lasso_loop.setFill(true);
  lasso_looped = false;
  if(coins.size() != 0) {
  for(size_t i=0;i<coins.size(); i++){
	  if(coins[i]->isGood || coins[i]->isImp){
	    coins[i]->removeCoin();
	  }
	  else{
	    coins[i]->resetCoin();
	  }
	}
	coins.clear();
  }
  if(the_bomb != NULL){
    the_bomb->resetBomb();
    the_bomb = NULL; 
  }
  if(the_magnet != NULL){
    the_magnet->getAttachedTo(this);
    the_magnet->pause();
  }
} // End Lasso::yank()

void Lasso::loopit() {
  if(lasso_looped) { return; } // Already looped
  lasso_loop.reset(getXPos(), getYPos(), LASSO_RADIUS);
  lasso_loop.setFill(false);
  lasso_looped = true;
} // End Lasso::loopit()

void Lasso::addAngle(double angle_deg) {
  release_angle_deg += angle_deg;
  // if(release_angle_deg < MIN_RELEASE_ANGLE_DEG) { release_angle_deg = MIN_RELEASE_ANGLE_DEG; }
  // if(release_angle_deg > MAX_RELEASE_ANGLE_DEG) { release_angle_deg = MAX_RELEASE_ANGLE_DEG; }
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  if(this -> isMagnetAttached()){
    the_magnet->reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  }
} // End Lasso::addAngle()

void Lasso::addSpeed(double speed) {
  release_speed += speed;
  if(release_speed < MIN_RELEASE_SPEED) { release_speed = MIN_RELEASE_SPEED; }
  if(release_speed > MAX_RELEASE_SPEED) { release_speed = MAX_RELEASE_SPEED; }
  bool paused = true, rtheta = true;
  reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  if(this -> isMagnetAttached()){ 
    the_magnet->reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
  }
} // End Lasso::addSpeed()

void Lasso::nextStep(double stepTime) {
  draw_lasso_band();
  MovingObject::nextStep(stepTime);
  if(getYPos() > PLAY_Y_HEIGHT) { yank(); }
  lasso_line.reset(lasso_start_x, lasso_start_y, getXPos(), getYPos());
} // End Lasso::nextStep()

void Lasso::check_for_coin(Coin *coinPtr) {
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double coin_x = coinPtr->getXPos();
  double coin_y = coinPtr->getYPos();
  double xdiff = (lasso_x - coin_x);
  double ydiff = (lasso_y - coin_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  bool good = coinPtr->isGood;
  if(distance <= LASSO_RADIUS  && distance !=0) {
    if(good){
      num_coins+=3;
      score += 5000;
      coinPtr->getAttachedTo(this);
      coins.push_back(coinPtr);
    }
    else{
      num_coins++;	
      score += 1000;
      coinPtr->getAttachedTo(this);
      coins.push_back(coinPtr);
    }
  }
} // End Lasso::check_for_coin()

void Lasso::check_for_bomb(Bomb *bombPtr){
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double bomb_x = bombPtr ->getXPos();
  double bomb_y = bombPtr ->getYPos();
  double xdiff = (lasso_x - bomb_x);
  double ydiff = (lasso_y - bomb_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if(distance <= LASSO_RADIUS && distance!=0){
    score -= 10000;
    lives--;
    if(the_bomb != 0) the_bomb->resetBomb();
    the_bomb = bombPtr;
    the_bomb->getAttachedTo(this);
  } 

} // End Lasso::check_for_bomb()

void Lasso::check_for_alphabet(Alphabet *alphabetPtr){
    
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double alphabet_x = alphabetPtr ->getXPos();
  double alphabet_y = alphabetPtr ->getYPos();
  double xdiff = (lasso_x - alphabet_x);
  double ydiff = (lasso_y - alphabet_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if(distance <= LASSO_RADIUS && distance!=0){
    the_letter = alphabetPtr;
    score += 5000;
    the_letter-> getCollected();
    num_alphabet++;
  } 
} // End Lasso::check_for_alphabet

void Lasso::check_for_magnet(Magnet *magnetPtr){

  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double magnet_x = magnetPtr ->getXPos();
  double magnet_y = magnetPtr ->getYPos();
  double xdiff = (lasso_x - magnet_x);
  double ydiff = (lasso_y - magnet_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if(distance <= LASSO_RADIUS && distance!=0){
    the_magnet = magnetPtr;
    score += 5000;
    the_magnet-> getAttachedTo(this);
    magnet_attached = true;
    magnet_loop.reset(this->getXPos(),this->getYPos(),magnet_radius);
    magnet_loop.setColor(COLOR("pink"));
    addPart(&magnet_loop);
  }

} // End Lasso::check_for_magnet

void Lasso::removeMagnet(){
  the_magnet->removeMagnet();
  magnet_loop = NULL;
} // End Lasso::removeMagnet

void Lasso::attract_coin(Coin* coinPtr){
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double coin_x = coinPtr->getXPos();
  double coin_y = coinPtr->getYPos();
  double xdiff = (lasso_x - coin_x);
  double ydiff = (lasso_y - coin_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  bool good = coinPtr->isGood;
  if(distance <= magnet_radius && distance!=0){
    if(good){
      num_coins+=3;
      score += 5000;
      coinPtr->getAttachedTo(this);
      coins.push_back(coinPtr);
    }
    else{
      num_coins++;
      score += 1000;
      coinPtr->getAttachedTo(this);
      coins.push_back(coinPtr);
    }
  }
} // End Lasso::attract_coin

void Lasso::attract_magnet(Magnet* magnetPtr){
  double lasso_x = getXPos();
  double lasso_y = getYPos();
  double magnet_x = magnetPtr->getXPos();
  double magnet_y = magnetPtr->getYPos();
  double xdiff = (lasso_x - magnet_x);
  double ydiff = (lasso_y - magnet_y);
  double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
  if(distance <= magnet_radius && distance!=0){
    magnet_radius = INIT_MAGNET_RADIUS;
    magnetPtr->removeMagnet();
    score += 5000;
  }
} // End Lasso::attract_magnet


