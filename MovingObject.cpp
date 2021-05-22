//Utkarsh Ranjan
//200050147

#include <simplecpp>
#include "MovingObject.h"
#include "lasso.h"

using namespace simplecpp;

void MovingObject::nextStep(double t) {
  if(paused) { return; }
  // cerr << "x=" << getXPos() << ",y=" << getYPos() << endl;
  // cerr << "vx=" << vx << ",vy=" << vy << endl;
  // cerr << "ax=" << ax << ",ay=" << ay << endl;
  //cout << sqrt(vx*vx + vy*vy) << endl;

  for(size_t i=0; i<parts.size(); i++){
    parts[i]->move(vx*t, vy*t);
  }
  vx += ax*t;
  vy += ay*t;
} // End MovingObject::nextStep()

double MovingObject::getXPos() {
  return (parts.size() > 0) ? parts[0]->getX() : -1;
}

double MovingObject::getYPos() {
  return (parts.size() > 0) ? parts[0]->getY() : -1;
}

void MovingObject::reset_all(double argx, double argy, double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) {
  for(size_t i=0; i<parts.size(); i++){
    parts[i]->moveTo(argx, argy);
  }
  double angle_rad = angle_deg*PI/180.0;
  double argvx = speed*cos(angle_rad);
  double argvy = -speed*sin(angle_rad);
  vx = argvx; vy = argvy; ax = argax; ay = argay; paused = argpaused;
} // End MovingObject::reset_all()

void MovingObject::getAttachedTo(MovingObject *m) {
  double xpos = m->getXPos();
  double ypos = m->getYPos();
  for(size_t i=0; i<parts.size(); i++){
    parts[i]->moveTo(xpos, ypos);
  }
  initMO(m->vx, m->vy, m->ax, m->ay, m->paused);
} // End MovingObject::getAttachedTo

void Alphabet::nextStep(double t) {
  if(paused) { return; }
  // cerr << "x=" << getXPos() << ",y=" << getYPos() << endl;
  // cerr << "vx=" << vx << ",vy=" << vy << endl;
  // cerr << "ax=" << ax << ",ay=" << ay << endl;

  for(size_t i=0; i<parts.size(); i++){
    parts[i]->move(vx*t, vy*t);
  }  
  vx += ax*t;
  vy += ay*t;
} // End Alphabet::nextStep

double Alphabet::getXPos() {
  return (parts.size() > 0) ? parts[0]->getX() : -1;
}

double Alphabet::getYPos() {
  return (parts.size() > 0) ? parts[0]->getY() : -1;
}

void Alphabet::initAlphabet(string text){

  alphabet_in_coin.reset(alphabet_start_x,alphabet_start_y,text);
  alphabet_cover.reset(alphabet_start_x-1.75,alphabet_start_y,COIN_SIZE*1.5);
  alphabet_cover.setColor(COLOR("red"));
  addPart(&alphabet_in_coin);
  addPart(&alphabet_cover);
} // End Alphabet::initAlphabet

void Alphabet::removeAlphabet(){
  alphabet_in_coin = NULL;
  alphabet_cover = NULL;
}

void Alphabet::reset(double speed, double angle_deg, double x, double argax, double argay, bool argpaused, int i, string c){
  release_speed = speed;
  release_angle_deg = angle_deg;
  alphabet_start_x = x;
  alphabet_start_y = PLAY_Y_HEIGHT;
  ax = argax;
  ay = argay;
  double angle_rad = angle_deg*PI/180.0;
  vx = release_speed*cos(angle_rad);
  vy = -release_speed*sin(angle_rad);
  paused = argpaused;
  text = c;
  index = i;
} // End Alphabet::reset

void Alphabet::getCollected() {
  removeAlphabet();
  alphabet_at_top.reset((WINDOW_X)/2-30+index*10,WINDOW_Y/2-20,text);
  collected = true;
} // End Alphabet::getCollected