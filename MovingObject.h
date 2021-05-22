//Utkarsh Ranjan
//200050147

#ifndef _MOVINGOBJECT_INCLUDED_
#define _MOVINGOBJECT_INCLUDED_

#include <simplecpp>
#include <vector>
#include <composite.h>
#include <sprite.h>

#define COIN_SIZE 5

using namespace simplecpp;

class MovingObject : public Sprite {
  vector<Sprite*> parts;
  double vx, vy;
  double ax, ay;
  bool paused;
  void initMO(double argvx, double argvy, double argax, double argay, bool argpaused=true) {
    vx=argvx; vy=argvy; ax=argax; ay=argay; paused=argpaused;
  }
 public:
 MovingObject(double argvx, double argvy, double argax, double argay, bool argpaused=true)
    : Sprite() {
    initMO(argvx, argvy, argax, argay, argpaused);
  }
 MovingObject(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : Sprite() {
   double angle_rad = angle_deg*PI/180.0;
   double argvx = speed*cos(angle_rad);
   double argvy = -speed*sin(angle_rad);
   initMO(argvx, argvy, argax, argay, argpaused);
  }
  void set_vx(double argvx) { vx = argvx; }
  void set_vy(double argvy) { vy = argvy; }
  void set_ax(double argax) { ax = argax; }
  void set_ay(double argay) { ay = argay; }
  double getXPos();
  double getYPos();
  void reset_all(double argx, double argy, double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta);

  void pause() { paused = true; }
  void unpause() { paused = false; }
  bool isPaused() { return paused; }

  void addPart(Sprite* p) {
    parts.push_back(p);
  }
  void nextStep(double t);
  void getAttachedTo(MovingObject *m);
}; // End Class MovingObject

class Alphabet : public Sprite {
  vector<Sprite*> parts;
  double alphabet_start_x;
  double alphabet_start_y;

  double release_speed;
  double release_angle_deg;
  double ax, ay, vx, vy;
  bool paused, collected = false;
  int index;
  string text;
  Text alphabet_at_top; // This is the text which appears at the top of the screen
  //Moving Parts
  Text alphabet_in_coin;
  Circle alphabet_cover;

public:

  void initAlphabet(string text);
  void reset(double speed, double angle_deg, double x, double argax, double argay, bool argpaused, int i, string c);
  void removeAlphabet();
  void nextStep(double t);
  double getXPos();
  double getYPos();
  void addPart(Sprite* p) {
    parts.push_back(p);
  }
  void pause() { paused = true; }
  void unpause() { paused = false; }
  bool isPaused() { return paused; }
  void getCollected();
  void set_pos(double x,double y, string text){
  	alphabet_start_x = x;
  	alphabet_start_y = y;
  	alphabet_in_coin.reset(x,y,text);
  	alphabet_cover.reset(x-1.75,y,COIN_SIZE*1.5);
  }
}; // End Class Alphabet

#endif
