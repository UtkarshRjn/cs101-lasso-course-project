//Utkarsh Ranjan
//200050147

#ifndef __COIN_H__
#define __COIN_H__

#include "MovingObject.h"
#include <sprite.h>
#include <vector>
#include <simplecpp>

#define COIN_SIZE 5
#define BOMB_SIZE 10
#define MAGNET_BAR_LENGTH 15
#define MAGNET_THICKNESS LASSO_THICKNESS*1.5
#define LASSO_THICKNESS 5

class Coin : public MovingObject {
  double coin_start_x;
  double coin_start_y;
  double release_speed;
  double release_angle_deg;
  double coin_ax;
  double coin_ay;
  // Moving parts
  Circle coin_circle;
  Circle coin_refulgence;

 public:
 Coin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    coin_ay = argay;
  }

  bool isGood;
  bool isImp;
  void initCoin();
  void resetCoin();
  void initGoodCoin();
  void initImpCoin();
  void removeCoin();
  void set_pos(double x,double y){
  	coin_start_x = x;
  	coin_start_y = y;
  	coin_circle.reset(x, y, COIN_SIZE);
  	if(isGood) coin_refulgence.reset(x,y, COIN_SIZE*2);
	}
  void reset(double speed, double angle_deg , double x);
}; // End class Coin

class Bomb : public MovingObject {
  double bomb_start_x; 
  double bomb_start_y; 
  double release_speed; 
  double release_angle_deg; 
  double bomb_ax;  
  double bomb_ay; 

  // Moving parts
  Circle bomb_core; 
  Circle bomb_head;
  Line bomb_wick;
  Circle bomb_fire1;
  Circle bomb_fire2;

 public:
 Bomb(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed; 
    release_angle_deg = angle_deg; 
    bomb_ax = argax; 
    bomb_ay = argay; 
  }

  void initBomb();
  void resetBomb();
  void reset(double speed, double angle_deg , double x);
  void set_pos(double x,double y){
  	bomb_start_x = x;
  	bomb_start_y = y;
  	bomb_core.reset(x, y, BOMB_SIZE);
  	bomb_head.reset(x + BOMB_SIZE/4, y - BOMB_SIZE/4, BOMB_SIZE/2 );
  	bomb_wick.reset(x + BOMB_SIZE/4, y - BOMB_SIZE/4, x + BOMB_SIZE, y - BOMB_SIZE);
  }

}; // End class Bomb

class Magnet : public MovingObject {
  double magnet_start_x; 
  double magnet_start_y; 
  double release_speed; 
  double release_angle_deg; 
  double magnet_ax;  
  double magnet_ay; 

  // Moving parts
  Line magnet_bar1, magnet_bar2, magnet_base1, magnet_base2;

 public:
 Magnet(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed; 
    release_angle_deg = angle_deg; 
    magnet_ax = argax; 
    magnet_ay = argay;
  }

  void initMagnet();
  void resetMagnet();
  void removeMagnet();
  void reset(double speed, double angle_deg , double x);
  void set_pos(double x,double y){
  magnet_start_x = x;
  magnet_start_y = y;
  magnet_bar1.reset(x-MAGNET_BAR_LENGTH/sqrt(2),y,x,y-MAGNET_BAR_LENGTH/sqrt(2));
  magnet_bar2.reset(x+MAGNET_BAR_LENGTH/sqrt(2),y,x,y+MAGNET_BAR_LENGTH/sqrt(2));
  magnet_base1.reset(x-2.5,y-MAGNET_BAR_LENGTH/sqrt(2)-2.5,x+MAGNET_BAR_LENGTH/2 ,y-MAGNET_BAR_LENGTH/2 );
  magnet_base2.reset(x+MAGNET_BAR_LENGTH/sqrt(2)+2.5,y+2.5,x+MAGNET_BAR_LENGTH/2 ,y-MAGNET_BAR_LENGTH/2 );
  magnet_bar1.setThickness(MAGNET_THICKNESS);
  magnet_bar2.setThickness(MAGNET_THICKNESS);
  magnet_base1.setThickness(MAGNET_THICKNESS);
  magnet_base2.setThickness(MAGNET_THICKNESS); 
  }
}; // End class Magnet

#endif
