//Utkarsh Ranjan
//200050147

#ifndef __LASSO_H__
#define __LASSO_H__

#include "MovingObject.h"
#include "coin.h"


//#define WINDOW_X 3000
//#define WINDOW_Y 2000
// #define WINDOW_X 800
// #define WINDOW_Y 600
//#define WINDOW_X 1800
//#define WINDOW_Y 960
#define WINDOW_X 1400
#define WINDOW_Y 1000

#define MAIN_MENU_RECT_LENGTH WINDOW_X/3.5
#define MAIN_MENU_RECT_WIDTH WINDOW_Y/15

#define LEADERBOARD_SIZE 50
#define STEP_TIME 0.05
#define LEVEL_TIME 60
#define OBJECT_TIME_GAP 10

#define PLAY_X_START 100
#define PLAY_Y_START 0
#define PLAY_X_WIDTH (WINDOW_X-PLAY_X_START)
#define PLAY_Y_HEIGHT (WINDOW_Y-100)
#define OBJECT_GAP WINDOW_X*0.05
#define CONTROLS_INS_X WINDOW_X*0.6
#define CONTROLS_INS_Y WINDOW_Y*0.5

#define LASSO_X_OFFSET 100
#define LASSO_Y_HEIGHT 100
#define LASSO_BAND_LENGTH LASSO_X_OFFSET
#define LASSO_THICKNESS 5

#define COIN_GAP 1

#define RELEASE_ANGLE_STEP_DEG 5
#define MIN_RELEASE_ANGLE_DEG 0
#define MAX_RELEASE_ANGLE_DEG (360-RELEASE_ANGLE_STEP_DEG)
#define INIT_RELEASE_ANGLE_DEG 45

#define RELEASE_SPEED_STEP 20
#define MIN_RELEASE_SPEED 0
#define MAX_RELEASE_SPEED 200
#define INIT_RELEASE_SPEED 100

#define COIN_SPEED 60
#define BOMB_SPEED 120
#define ALPHABET_SPEED 120
#define COIN_ANGLE_DEG 90
#define BOMB_ANGLE_DEG 75
#define ALPHABET_ANGLE_DEG 120

#define LASSO_G 30
#define COIN_G 30
#define BOMB_G 30
#define ALPHABET_G 30
#define MAGNET_G 30

#define LASSO_SIZE 10
#define LASSO_RADIUS 50
#define COIN_SIZE 5
#define BOMB_SIZE 10
#define STEP_MAG_RAD_DEC 0.3
#define INIT_MAGNET_RADIUS LASSO_RADIUS*2
#define BOMB_WICK_THICKNESS LASSO_THICKNESS
#define MAGNET_BAR_LENGTH 15
#define MAGNET_THICKNESS LASSO_THICKNESS*1.5

class Lasso : public MovingObject {
  double lasso_start_x;
  double lasso_start_y;
  double release_speed;
  double release_angle_deg;
  double lasso_ax;
  double lasso_ay;
  double magnet_radius;

  // Moving parts
  Circle lasso_circle;
  Circle lasso_loop;
  Circle magnet_loop;

  // Non-moving parts
  Line lasso_line;
  Line lasso_band;

  // State info
  bool lasso_looped;
  vector<Coin*> coins;
  Bomb *the_bomb;
  Alphabet *the_letter;
  Magnet *the_magnet;

  void initLasso();
 public:
 Lasso(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    lasso_ax = argax;
    lasso_ay = argay;
    initLasso();
  }

  int score;
  int lives;
  int num_coins;
  int num_alphabet = 0;
  bool magnet_attached;
  void draw_lasso_band();
  void yank();
  void loopit();
  void addAngle(double angle_deg);
  void addSpeed(double speed);

  void nextStep(double t);
  void check_for_coin(Coin *coin);
  void check_for_bomb(Bomb *bomb);
  void check_for_alphabet(Alphabet *alphabet);
  void check_for_magnet(Magnet *magnet);
  void attract_coin(Coin *coin);
  void attract_magnet(Magnet *magnet);
  int getNumCoins() { return num_coins; }
  bool isMagnetAttached() {return magnet_attached;}
  double get_magnet_radius(){ return magnet_radius;}
  void reduce_magnet_radius(double new_magnet_radius){
    
    magnet_loop.reset(this->getXPos(),this->getYPos(),new_magnet_radius);
    magnet_radius = new_magnet_radius;
  
  }
  void removeMagnet();
  void set_pos(double x,double y){ // Changes the x and y coordinate of lasso
  	
  	lasso_start_x = x;
  	lasso_start_y = y;
  	lasso_circle.reset(x, y, LASSO_SIZE);
  	lasso_loop.reset(x, y, LASSO_SIZE/2);
  
  }

}; // End class Lasso

#endif
