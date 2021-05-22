//Utkarsh Ranjan
//200050147

#include "coin.h"
#include "lasso.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

 double path[25][3] = {{80,60,WINDOW_X/2-2*OBJECT_GAP},{100,60,WINDOW_X/2-2*OBJECT_GAP},{120,60,WINDOW_X/2-2*OBJECT_GAP},{80,90,WINDOW_X/2-2*OBJECT_GAP},{100,90,WINDOW_X/2-2*OBJECT_GAP},
						  {100,60,WINDOW_X/2-OBJECT_GAP},{100,60,WINDOW_X/2-OBJECT_GAP},{100,60,WINDOW_X/2-OBJECT_GAP},{100,60,WINDOW_X/2-OBJECT_GAP},{100,60,WINDOW_X/2-OBJECT_GAP},
						  {100,95,WINDOW_X/2},{105,85,WINDOW_X/2},{85,90,WINDOW_X/2},{100,105,WINDOW_X/2},{105,75,WINDOW_X/2},
						  {100,110,WINDOW_X/2+OBJECT_GAP},{130,110,WINDOW_X/2+OBJECT_GAP},{60,120,WINDOW_X/2+OBJECT_GAP},{90,105,WINDOW_X/2+OBJECT_GAP},{95,90,WINDOW_X/2+OBJECT_GAP},
						  {100,110,WINDOW_X/2+2*OBJECT_GAP},{120,110,WINDOW_X/2-2*OBJECT_GAP},{125,120,WINDOW_X/2-2*OBJECT_GAP},{80,105,WINDOW_X/2-2*OBJECT_GAP},{95,100,WINDOW_X/2-2*OBJECT_GAP}};


void Coin::initCoin() {
  coin_start_x = -(PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("gold"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
  isGood = false;
  isImp = false;
}

void Coin::initGoodCoin(){
  coin_start_x = -(PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE*1.5);
  coin_circle.setColor(COLOR("green"));
  coin_circle.setFill(true);
  coin_refulgence.reset(coin_start_x, coin_start_y, COIN_SIZE*2);
  coin_refulgence.setColor(COLOR("gold"));
  addPart(&coin_refulgence);
  addPart(&coin_circle);
  isGood = true;
  isImp = false;
}

void Coin::initImpCoin(){
  coin_start_x = -(PLAY_X_START+WINDOW_X)/2;
  coin_start_y = PLAY_Y_HEIGHT;
  coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
  coin_circle.setColor(COLOR("red"));
  coin_circle.setFill(true);
  addPart(&coin_circle);
  isImp = true;
  isGood = false;
}

void Coin::reset(double speed, double angle_deg, double x){ // reset coin speed, angle and x coordinate
  	coin_start_x = x;
  	release_speed = speed;
  	release_angle_deg = angle_deg;
    double angle_rad = angle_deg*PI/180.0;
    double argvx = speed*cos(angle_rad);
    double argvy = -speed*sin(angle_rad);
    this -> set_vx(argvx);
    this -> set_vy(argvy); 
}

void Coin::resetCoin() {
  bool paused = true, rtheta = true;
  int temp = rand()%25;
  reset(path[temp][0],path[temp][1],path[temp][2]);
  reset_all(coin_start_x, coin_start_y, release_speed, release_angle_deg, coin_ax, coin_ay, paused, rtheta);
}

void Coin::removeCoin(){
  coin_circle = NULL;
  coin_refulgence = NULL;
  this -> set_vx(0);
  this -> set_vy(0);
  this -> set_ax(0);
  this -> set_ay(0);
}

void Bomb::initBomb() {
  bomb_start_x = -(PLAY_X_START+WINDOW_X)/2;
  bomb_start_y = PLAY_Y_HEIGHT;
  bomb_core.reset(bomb_start_x, bomb_start_y, BOMB_SIZE);
  bomb_core.setColor(COLOR("brown"));
  bomb_core.setFill(true);
  bomb_head.reset(bomb_start_x + BOMB_SIZE/4, bomb_start_y - BOMB_SIZE/4 , BOMB_SIZE/2);
  bomb_head.setColor(COLOR("black"));
  bomb_head.setFill(true);
  bomb_wick.reset(bomb_start_x + BOMB_SIZE/4, bomb_start_y - BOMB_SIZE/4, bomb_start_x + BOMB_SIZE, bomb_start_y - BOMB_SIZE);
  bomb_wick.setColor(COLOR("orange"));
  bomb_wick.setThickness(BOMB_WICK_THICKNESS);
  addPart(&bomb_core);
  addPart(&bomb_head);
  addPart(&bomb_wick);
}

void Bomb::resetBomb() { // reset Bomb speed, angle and x coordinate
  bomb_ax = 0;
  bomb_ay = BOMB_G;
  bool paused = true, rtheta = true;
  int temp = rand()%25;
  reset(path[temp][0],path[temp][1],path[temp][2]);
  reset_all(bomb_start_x, bomb_start_y, release_speed, release_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
  bomb_wick.reset(bomb_start_x + BOMB_SIZE/4, bomb_start_y - BOMB_SIZE/4, bomb_start_x + BOMB_SIZE, bomb_start_y - BOMB_SIZE);
  bomb_head.reset(bomb_start_x + BOMB_SIZE/4, bomb_start_y - BOMB_SIZE/4 , BOMB_SIZE/2);
  bomb_wick.setThickness(BOMB_WICK_THICKNESS);
}

void Bomb::reset(double speed, double angle_deg, double x){
  	bomb_start_x = x;
  	release_speed = speed;
  	release_angle_deg = angle_deg;
    double angle_rad = angle_deg*PI/180.0;
    double argvx = speed*cos(angle_rad);
    double argvy = -speed*sin(angle_rad);
    this -> set_vx(argvx);
    this -> set_vy(argvy); 
}

void Magnet::initMagnet() {

  magnet_start_x = -(PLAY_X_START+WINDOW_X)/2;
  magnet_start_y = PLAY_Y_HEIGHT;
  magnet_bar1.reset(magnet_start_x-MAGNET_BAR_LENGTH/sqrt(2),magnet_start_y,magnet_start_x,magnet_start_y-MAGNET_BAR_LENGTH/sqrt(2));
  magnet_bar2.reset(magnet_start_x+MAGNET_BAR_LENGTH/sqrt(2),magnet_start_y,magnet_start_x,magnet_start_y+MAGNET_BAR_LENGTH/sqrt(2));
  magnet_base1.reset(magnet_start_x-2.5,magnet_start_y-MAGNET_BAR_LENGTH/sqrt(2)-2.5,magnet_start_x+MAGNET_BAR_LENGTH/2 ,magnet_start_y-MAGNET_BAR_LENGTH/2 );
  magnet_base2.reset(magnet_start_x+MAGNET_BAR_LENGTH/sqrt(2)+2.5,magnet_start_y+2.5,magnet_start_x+MAGNET_BAR_LENGTH/2 ,magnet_start_y-MAGNET_BAR_LENGTH/2 );
  magnet_bar1.setColor(COLOR("red"));
  magnet_bar2.setColor(COLOR("blue"));
  magnet_base1.setColor(COLOR("red"));
  magnet_base2.setColor(COLOR("blue"));
  magnet_bar1.setThickness(MAGNET_THICKNESS);
  magnet_bar2.setThickness(MAGNET_THICKNESS);
  magnet_base1.setThickness(MAGNET_THICKNESS);
  magnet_base2.setThickness(MAGNET_THICKNESS);  
  addPart(&magnet_base1);
  addPart(&magnet_base2);
  addPart(&magnet_bar1);
  addPart(&magnet_bar2);
}

void Magnet::reset(double speed, double angle_deg, double x){
  	magnet_start_x = x;
  	release_speed = speed;
  	release_angle_deg = angle_deg;
    double angle_rad = angle_deg*PI/180.0;
    double argvx = speed*cos(angle_rad);
    double argvy = -speed*sin(angle_rad);
    this -> set_vx(argvx);
    this -> set_vy(argvy); 
}

void Magnet::resetMagnet() { // reset Magnet speed, angle and x coordinate

  magnet_ax = 0;
  magnet_ay = BOMB_G;
  bool paused = true, rtheta = true;
  int temp = rand()%25;
  reset(path[temp][0],path[temp][1],path[temp][2]);
  reset_all(magnet_start_x, magnet_start_y, release_speed, release_angle_deg, magnet_ax, magnet_ay, paused, rtheta);
  magnet_bar1.reset(magnet_start_x-MAGNET_BAR_LENGTH/sqrt(2),magnet_start_y,magnet_start_x,magnet_start_y-MAGNET_BAR_LENGTH/sqrt(2));
  magnet_bar2.reset(magnet_start_x+MAGNET_BAR_LENGTH/sqrt(2),magnet_start_y,magnet_start_x,magnet_start_y+MAGNET_BAR_LENGTH/sqrt(2));
  magnet_base1.reset(magnet_start_x-2.5,magnet_start_y-MAGNET_BAR_LENGTH/sqrt(2)-2.5,magnet_start_x+MAGNET_BAR_LENGTH/2 ,magnet_start_y-MAGNET_BAR_LENGTH/2 );
  magnet_base2.reset(magnet_start_x+MAGNET_BAR_LENGTH/sqrt(2)+2.5,magnet_start_y+2.5,magnet_start_x+MAGNET_BAR_LENGTH/2 ,magnet_start_y-MAGNET_BAR_LENGTH/2 );
  magnet_bar1.setThickness(MAGNET_THICKNESS);
  magnet_bar2.setThickness(MAGNET_THICKNESS);
  magnet_base1.setThickness(MAGNET_THICKNESS);
  magnet_base2.setThickness(MAGNET_THICKNESS); 
  
}

void Magnet::removeMagnet(){
  magnet_bar1 = NULL;
  magnet_bar2 = NULL;
  magnet_base1 = NULL;
  magnet_base2 = NULL;
}