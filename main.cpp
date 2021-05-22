//Utkarsh Ranjan
//200050147

#include <simplecpp>
#include <string>
#include <fstream>
#include <bits/stdc++.h> 
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace simplecpp;

// Sort players in the decreasing order of their score
void list_leaderboard(string name[], int highscores[]){
	int temp_score[10];
	string temp_name[10];
	for(int i=0;i<10;i++){temp_name[i] = name[i];}
	for(int i=0;i<10;i++){temp_score[i] = highscores[i];}
	sort(highscores,highscores+10, greater<int>());
  for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(highscores[i] == temp_score[j]){
				name[i] = temp_name[j];
			}
		}
	}
}

main_program {

  //Enters username in the highscores.txt	
  string name;
  cout << "Enter your user name:" << endl;
  getline(cin,name);
  fstream nameFile("highscores.txt", ios::app | ios::out);
  nameFile << endl << name;;
  nameFile.close();

  //Main menu
  initCanvas("Lasso Menu", WINDOW_X, WINDOW_Y);
  bool restart = true;
  int level;
for(;restart==true;){ //This loop goes throughout the game (main menu + gaming window)
      
      restart = false; // 
      bool new_game = false;
      bool levels_page = false;
      bool leaderboard_page = false;
      bool score_page = false;
      bool home_page = true;
      bool quit_menu = false;
	  
      Text l1,l2,l3; // For headings of leaderboard
	  Text s1,s2,s3,s4,s5,s6,s7,s8,s9,s10; //For leaderboard S.No.
	  Text player1,player2,player3,player4,player5,player6,player7,player8,player9,player10; //For leaderboard names
	  Text score1,score2,score3,score4,score5,score6,score7,score8,score9,score10; // For leaderboard scores
      
      Line b1_main_menu,b2_main_menu,b3_main_menu,b4_main_menu; // Line covering the boundary

      Text c1,c2,c3,c4,c5,c6,c7,c8; // For contorls

      char score1Str[256], score2Str[256], score3Str[256], score4Str[256],
       		 score5Str[256], score6Str[256], score7Str[256], score8Str[256],
        	 score9Str[256], score10Str[256];

      Rectangle newgame(WINDOW_X*0.5,WINDOW_Y*0.4,MAIN_MENU_RECT_LENGTH,MAIN_MENU_RECT_WIDTH);
      Rectangle levels(WINDOW_X*0.5,WINDOW_Y*0.5,MAIN_MENU_RECT_LENGTH,MAIN_MENU_RECT_WIDTH);
      Rectangle controls(WINDOW_X*0.5,WINDOW_Y*0.6,MAIN_MENU_RECT_LENGTH,MAIN_MENU_RECT_WIDTH);
      Rectangle leaderboard(WINDOW_X*0.5,WINDOW_Y*0.7,MAIN_MENU_RECT_LENGTH,MAIN_MENU_RECT_WIDTH);
      Rectangle quitgame(WINDOW_X*0.5,WINDOW_Y*0.8,MAIN_MENU_RECT_LENGTH,MAIN_MENU_RECT_WIDTH);
      
      Rectangle navigator(WINDOW_X*0.5,WINDOW_Y*0.4,MAIN_MENU_RECT_LENGTH+5,MAIN_MENU_RECT_WIDTH+5);
      navigator.setColor(COLOR("blue"));
      double navigator_y = WINDOW_Y*0.4;
      
      Text t_newgame(WINDOW_X*0.5,WINDOW_Y*0.4, "NEW GAME");
      Text t_levels(WINDOW_X*0.5,WINDOW_Y*0.5, "LEVELS");
      Text t_controls(WINDOW_X*0.5,WINDOW_Y*0.6, "CONTROLS");
      Text t_leaderboard(WINDOW_X*0.5,WINDOW_Y*0.7, "LEADERBOARD");
      Text t_quitgame(WINDOW_X*0.5,WINDOW_Y*0.8, "QUIT");

      Text help1(WINDOW_X - PLAY_X_START*3.25, PLAY_Y_HEIGHT - 40 , "PRESS");
      Text help2(WINDOW_X - PLAY_X_START*2.95, PLAY_Y_HEIGHT - 40 , "ESC");
      help2.setColor(COLOR("red"));
      Text help3(WINDOW_X - PLAY_X_START*2, PLAY_Y_HEIGHT - 40 , "TO RETURN BACK TO MAIN MENU");

      Text help4(WINDOW_X - PLAY_X_START*3.3, PLAY_Y_HEIGHT - 60 , "USE");
      Text help5(WINDOW_X - PLAY_X_START*2.9, PLAY_Y_HEIGHT - 60 , "ARROW KEY");
      help5.setColor(COLOR("red"));
      Text help6(WINDOW_X - PLAY_X_START*2.25, PLAY_Y_HEIGHT - 60 , "TO NAVIGATE");

      Text help7(WINDOW_X - PLAY_X_START*3.22, PLAY_Y_HEIGHT - 80 , "PRESS");
      Text help8(WINDOW_X - PLAY_X_START*2.8, PLAY_Y_HEIGHT - 80 , "ENTER");
      help8.setColor(COLOR("red"));
      Text help9(WINDOW_X - PLAY_X_START*1.5, PLAY_Y_HEIGHT - 80 , "TO ENTER ANOTHER MENU OR START GAME");

      // LASSO Title As sets of polygon and Circle
      double title_L[6][2], title_A[4][2], title_S1[6][2];
      title_L[0][0] = 0;
	  title_L[0][1] = 0;
	  title_L[1][0] = 37.93; 
	  title_L[1][1] = -15.17;
	  title_L[2][0] = 74.14; 
	  title_L[2][1] = 75.34;
	  title_L[3][0] = 118.28;
	  title_L[3][1] = 57.69;
	  title_L[4][0] = 132.76; 
	  title_L[4][1] = 93.9;
	  title_L[5][0] = 50.69; 
	  title_L[5][1] = 126.72;

	  title_A[0][0] = 0;
	  title_A[0][1] = 0;
	  title_A[1][0] = 35.71; 
	  title_A[1][1] = -142.86;
	  title_A[2][0] = 52.05; 
	  title_A[2][1] = 20.55;
	  title_A[3][0] = 25;
	  title_A[3][1] = -52.5;

	  title_S1[0][0] = 0;
	  title_S1[0][1] = 0;
	  title_S1[1][0] = 43.5*0.75;
	  title_S1[1][1] = -156.6*0.75;
	  title_S1[2][0] = 24.79*0.75;
	  title_S1[2][1] = -14.38*0.75;
	  title_S1[3][0] = 62.25*0.75;
	  title_S1[3][1] = 53.05*0.7;
	  title_S1[4][0] = -2.96*0.75;
	  title_S1[4][1] = 196.52*0.75;  
	  title_S1[5][0] = 31.67*0.75;
	  title_S1[5][1] = 53.83*0.75;

      Polygon L(WINDOW_X /2 - 250 , WINDOW_Y - PLAY_Y_HEIGHT, title_L ,6);
      L.setColor(COLOR("yellow"));
      L.setFill(true);
      Polygon A(WINDOW_X /2 - 100 , WINDOW_Y - PLAY_Y_HEIGHT+100, title_A ,4);
      A.setColor(COLOR("red"));
      A.setFill(true);
	  Polygon S1(WINDOW_X /2 -20 , WINDOW_Y - PLAY_Y_HEIGHT+50, title_S1 ,6);
      S1.setColor(COLOR("blue"));
      S1.setFill(true);
	  Polygon S2(WINDOW_X /2 + 50, WINDOW_Y - PLAY_Y_HEIGHT+50, title_S1 ,6);
      S2.setColor(COLOR("blue"));
      S2.setFill(true);
      Circle O2(WINDOW_X /2 + 180, WINDOW_Y - PLAY_Y_HEIGHT+ 50, 70);
      O2.setColor(COLOR("green"));
      O2.setFill(true);
      Circle O1(WINDOW_X /2 + 180, WINDOW_Y - PLAY_Y_HEIGHT+ 50, 37.5);
      O1.setColor(COLOR("white"));
      O1.setFill(true);
      // Lasso Title Ends

      // Inputs from files highscore.txt, level1.txt, level2.txt, level3.txt
	  int highscores_level1[LEADERBOARD_SIZE];
	  int highscores_level2[LEADERBOARD_SIZE];
	  int highscores_level3[LEADERBOARD_SIZE];
	  int overall_highscore[LEADERBOARD_SIZE];
	  string name[LEADERBOARD_SIZE];
	  string line;
	  int num_file_line = 0;
	  ifstream file_num("highscores.txt");
	  while(!file_num.eof()){
		getline(file_num,line);
		num_file_line++;
	  }
	  file_num.close();
		
	  ifstream file("highscores.txt");
	  for(int j=0; j<num_file_line; j++){ getline(file,name[j]);}
	  file.close();

	  num_file_line = 0;
	  ifstream file1_num("level1.txt");
	  while(!file1_num.eof()){
		getline(file1_num,line);
		num_file_line++;
	  }
	  file1_num.close();

	  ifstream file1("level1.txt");
	  for(int j=0; j<num_file_line; j++){ file1 >> highscores_level1[j];}
	  file1.close();

	  num_file_line = 0;
	  ifstream file2_num("level2.txt");
	  while(!file2_num.eof()){
		getline(file2_num,line);
		num_file_line++;
	  }
	  file2_num.close();

	  ifstream file2("level2.txt");
	  for(int j=0; j<num_file_line; j++){ file2 >> highscores_level2[j];}
	  file2.close();
		
	  num_file_line = 0;
	  ifstream file3_num("level3.txt");
	  while(!file3_num.eof()){
		getline(file3_num,line);
		num_file_line++;
	  }
	  file3_num.close();

	  ifstream file3("level3.txt");
	  for(int j=0; j<num_file_line; j++){ file3 >> highscores_level3[j];}
	  file3.close();
	  	
	  for(int i=0;i<LEADERBOARD_SIZE;i++){ overall_highscore[i] = highscores_level1[i] + highscores_level2[i] + highscores_level3[i];}

    
    for(;quit_menu == false && restart==false;){ // Loop for menu menu navigation
      
      XEvent e;
      bool pendingEv = checkEvent(e);
        
      if(pendingEv) {
      char c = charFromEvent(e);
      
      switch(c) {
            case 'T': // char for downward arrow key
	      if(navigator_y <= WINDOW_Y*0.7 && !score_page){
	        navigator_y += WINDOW_Y*0.1; 
	        navigator.reset(WINDOW_X*0.5,navigator_y,MAIN_MENU_RECT_LENGTH+5,MAIN_MENU_RECT_WIDTH+5);
	      }
      break;
            case 'R': // char for upward arrow key
	      if(navigator_y >= WINDOW_Y*0.5 && !score_page){
	        navigator_y -= WINDOW_Y*0.1; 
	        navigator.reset(WINDOW_X*0.5,navigator_y,MAIN_MENU_RECT_LENGTH+5,MAIN_MENU_RECT_WIDTH+5);
	      }
      break;
            case 13: // ASCII code for [Enter] key 
      if(navigator_y == WINDOW_Y*0.4 && home_page){ level = 0;new_game = true; quit_menu = true; break;}
      else if(navigator_y == WINDOW_Y*0.5 && home_page){ 
          
        t_newgame.reset(WINDOW_X*0.5,WINDOW_Y*0.4, "TUTORIAL");
        t_levels.reset(WINDOW_X*0.5,WINDOW_Y*0.5, "LEVEL 1");
        t_controls.reset(WINDOW_X*0.5,WINDOW_Y*0.6, "LEVEL 2");
        t_leaderboard.reset(WINDOW_X*0.5,WINDOW_Y*0.7, "LEVEL 3");
        t_quitgame.reset(WINDOW_X*0.5,WINDOW_Y*0.8, "BACK");
        home_page = false;
        levels_page = true;
        leaderboard_page = false;

      }
      else if(navigator_y == WINDOW_Y*0.6 && home_page){
        
        newgame = NULL;
        levels = NULL;
        controls = NULL;
        leaderboard = NULL;
        quitgame = NULL;
        navigator = NULL;
        t_newgame = NULL;
        t_levels = NULL;
        t_controls = NULL;
        t_leaderboard = NULL;
        t_quitgame = NULL;
        L = NULL;
        A = NULL;
        S1 = NULL;
        S2 = NULL;
        O1 = NULL;
        O2 = NULL;
        help4 = NULL;
        help5 = NULL;
        help6 = NULL;
        help7 = NULL;
        help8 = NULL;
        help9 = NULL;

        double release_speed = INIT_RELEASE_SPEED; // m/s
        double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
        double lasso_ax = 0;
        double lasso_ay = LASSO_G;
        bool paused = true;
        bool rtheta = true;
        Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
        lasso.set_pos(PLAY_X_START + LASSO_X_OFFSET*2 , PLAY_Y_HEIGHT - LASSO_Y_HEIGHT*2);

        bool quit_controls = false;

        b1_main_menu.reset(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
		b1_main_menu.setColor(COLOR("blue"));
		b2_main_menu.reset(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
		b2_main_menu.setColor(COLOR("blue"));

		b3_main_menu.reset(0, WINDOW_Y - PLAY_Y_HEIGHT, WINDOW_X, WINDOW_Y - PLAY_Y_HEIGHT);
		b3_main_menu.setColor(COLOR("blue"));
		b4_main_menu.reset(WINDOW_X -100 , 0, WINDOW_X-100 , WINDOW_Y);
		b4_main_menu.setColor(COLOR("blue"));

		c1.reset(WINDOW_X*0.5,WINDOW_Y*0.2,"C O N T R O L S");
		c2.reset(CONTROLS_INS_X,CONTROLS_INS_Y,"Press ' + ' to increase speed");
		c3.reset(CONTROLS_INS_X,CONTROLS_INS_Y+20,"Press ' - ' to decrease speed");
		c4.reset(CONTROLS_INS_X,CONTROLS_INS_Y+40,"Press ' ] ' to rotate clockwise");
		c5.reset(CONTROLS_INS_X,CONTROLS_INS_Y+60,"Press ' [ ' to rotate counter clockwise");
		c6.reset(CONTROLS_INS_X,CONTROLS_INS_Y+80,"Press ' T ' to release lasso");
		c7.reset(CONTROLS_INS_X,CONTROLS_INS_Y+100,"Press ' L ' to loop");
		c8.reset(CONTROLS_INS_X,CONTROLS_INS_Y+120,"Press ' Y ' to yank");

        for(;quit_controls==false;) { // loop for movement of lasso in controls
          
          XEvent e;
          bool pendingEv = checkEvent(e);
          if(pendingEv) {
            char c = charFromEvent(e);
            switch(c) {
            case 't':
        	  lasso.unpause();
          break;
            case 'y':
          	  lasso.yank();
          break;
            case 'l':
          	  lasso.loopit();
          break;
            case '[':
          	  if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG); }
          break;
            case ']':
          	  if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
          break;
            case '-':
          	  if(lasso.isPaused()) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
          break;
            case '=':
          	  if(lasso.isPaused()) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
          break;
            case 27:
	          quit_controls = true;
	          restart = true;
          break;
            default:
          break;
              }
            }
            if(quit_controls){continue;}
            lasso.nextStep(STEP_TIME);
            wait(STEP_TIME);
        } // loop for movement in controls ends
      }
      else if(navigator_y == WINDOW_Y*0.7 && home_page){

        t_newgame.reset(WINDOW_X*0.5,WINDOW_Y*0.4, "OVERALL HIGHSCORES");
        t_levels.reset(WINDOW_X*0.5,WINDOW_Y*0.5, "LEVEL 1 HIGHSCORES");
        t_controls.reset(WINDOW_X*0.5,WINDOW_Y*0.6, "LEVEL 2 HIGHSCORES");
        t_leaderboard.reset(WINDOW_X*0.5,WINDOW_Y*0.7, "LEVEL 3 HIGHSCORES");
        t_quitgame.reset(WINDOW_X*0.5,WINDOW_Y*0.8, "BACK");
        home_page = false;
        leaderboard_page = true;
        levels_page = false;
      }
      else if(navigator_y == WINDOW_Y*0.8 && home_page){ exit(0);}
      else if(navigator_y == WINDOW_Y*0.4 && levels_page){ level = 0; quit_menu = true; break;}
      else if(navigator_y == WINDOW_Y*0.5 && levels_page){ level = 1; quit_menu = true; break;}
      else if(navigator_y == WINDOW_Y*0.6 && levels_page){ level = 2; quit_menu = true; break;}
      else if(navigator_y == WINDOW_Y*0.7 && levels_page){ level = 3; quit_menu = true; break;}
      else if(navigator_y == WINDOW_Y*0.8 && levels_page){

		t_newgame.reset(WINDOW_X*0.5,WINDOW_Y*0.4, "NEW GAME");
		t_levels.reset(WINDOW_X*0.5,WINDOW_Y*0.5, "LEVELS");
		t_controls.reset(WINDOW_X*0.5,WINDOW_Y*0.6, "CONTROLS");
		t_leaderboard.reset(WINDOW_X*0.5,WINDOW_Y*0.7, "LEADERBOARD");
		t_quitgame.reset(WINDOW_X*0.5,WINDOW_Y*0.8, "QUIT");
		home_page = true;
		leaderboard_page = false;
		levels_page = false;
      }
      else if(navigator_y != WINDOW_Y*0.8 && leaderboard_page){
          
        score_page = true;
        newgame = NULL;
        levels = NULL;
        controls = NULL;
        leaderboard = NULL;
        quitgame = NULL;
        navigator = NULL;
        t_newgame = NULL;
        t_levels = NULL;
        t_controls = NULL;
        t_leaderboard = NULL;
        t_quitgame = NULL;
        L = NULL;
        A = NULL;
        S1 = NULL;
        S2 = NULL;
        O1 = NULL;
        O2 = NULL;
        help4 = NULL;
        help5 = NULL;
        help6 = NULL;
        help7 = NULL;
        help8 = NULL;
        help9 = NULL;

        b1_main_menu.reset(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
		b1_main_menu.setColor(COLOR("blue"));
		b2_main_menu.reset(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
		b2_main_menu.setColor(COLOR("blue"));

		b3_main_menu.reset(0, WINDOW_Y - PLAY_Y_HEIGHT, WINDOW_X, WINDOW_Y - PLAY_Y_HEIGHT);
		b3_main_menu.setColor(COLOR("blue"));
		b4_main_menu.reset(WINDOW_X -100 , 0, WINDOW_X-100 , WINDOW_Y);
		b4_main_menu.setColor(COLOR("blue"));

        l1.reset(WINDOW_X*0.25,WINDOW_Y*0.3, "S.No");
		l1.setColor(COLOR("red"));
        s1.reset(WINDOW_X*0.25,WINDOW_Y*0.35, "1");
        s2.reset(WINDOW_X*0.25,WINDOW_Y*0.4, "2");
        s3.reset(WINDOW_X*0.25,WINDOW_Y*0.45, "3");
        s4.reset(WINDOW_X*0.25,WINDOW_Y*0.5, "4");
        s5.reset(WINDOW_X*0.25,WINDOW_Y*0.55, "5");
        s6.reset(WINDOW_X*0.25,WINDOW_Y*0.6, "6");
        s7.reset(WINDOW_X*0.25,WINDOW_Y*0.65, "7");
        s8.reset(WINDOW_X*0.25,WINDOW_Y*0.7, "8");
        s9.reset(WINDOW_X*0.25,WINDOW_Y*0.75, "9");
        s10.reset(WINDOW_X*0.25,WINDOW_Y*0.8, "10");

        l2.reset(WINDOW_X*0.4,WINDOW_Y*0.3, "P L A Y E R S");
      	l2.setColor(COLOR("red"));
        player1.reset(WINDOW_X*0.4,WINDOW_Y*0.35, "-----------------------");
        player2.reset(WINDOW_X*0.4,WINDOW_Y*0.4, "-----------------------");
        player3.reset(WINDOW_X*0.4,WINDOW_Y*0.45, "-----------------------");
        player4.reset(WINDOW_X*0.4,WINDOW_Y*0.5, "-----------------------");
        player5.reset(WINDOW_X*0.4,WINDOW_Y*0.55, "-----------------------");
        player6.reset(WINDOW_X*0.4,WINDOW_Y*0.6, "-----------------------");
        player7.reset(WINDOW_X*0.4,WINDOW_Y*0.65, "-----------------------");
        player8.reset(WINDOW_X*0.4,WINDOW_Y*0.7, "-----------------------");
        player9.reset(WINDOW_X*0.4,WINDOW_Y*0.75, "-----------------------");
        player10.reset(WINDOW_X*0.4,WINDOW_Y*0.8, "-----------------------");
            
        l3.reset(WINDOW_X*0.7,WINDOW_Y*0.3, "H I G H S C O R E S");    	 
      	l3.setColor(COLOR("red"));
        score1.reset(WINDOW_X*0.7,WINDOW_Y*0.35, "-----------------------");
        score2.reset(WINDOW_X*0.7,WINDOW_Y*0.4, "-----------------------");
        score3.reset(WINDOW_X*0.7,WINDOW_Y*0.45, "-----------------------");
        score4.reset(WINDOW_X*0.7,WINDOW_Y*0.5, "-----------------------");
        score5.reset(WINDOW_X*0.7,WINDOW_Y*0.55, "-----------------------");
        score6.reset(WINDOW_X*0.7,WINDOW_Y*0.6, "-----------------------");
        score7.reset(WINDOW_X*0.7,WINDOW_Y*0.65, "-----------------------");
        score8.reset(WINDOW_X*0.7,WINDOW_Y*0.7, "-----------------------");
        score9.reset(WINDOW_X*0.7,WINDOW_Y*0.75, "-----------------------");
        score10.reset(WINDOW_X*0.7,WINDOW_Y*0.8, "-----------------------");
          
        if(navigator_y == WINDOW_Y*0.4){
          
        list_leaderboard(name, overall_highscore);
		player1.setMessage(name[0]);
        player2.setMessage(name[1]);
        player3.setMessage(name[2]);
        player4.setMessage(name[3]);
        player5.setMessage(name[4]);
        player6.setMessage(name[5]);
        player7.setMessage(name[6]);
        player8.setMessage(name[7]);
        player9.setMessage(name[8]);
        player10.setMessage(name[9]);

	    sprintf(score1Str, "%d" , overall_highscore[0]);
	    sprintf(score2Str, "%d" , overall_highscore[1]);
	    sprintf(score3Str, "%d" , overall_highscore[2]);
	    sprintf(score4Str, "%d" , overall_highscore[3]);
	    sprintf(score5Str, "%d" , overall_highscore[4]);
	    sprintf(score6Str, "%d" , overall_highscore[5]);
	    sprintf(score7Str, "%d" , overall_highscore[6]);
	   	sprintf(score8Str, "%d" , overall_highscore[7]);
	    sprintf(score9Str, "%d" , overall_highscore[8]);
	    sprintf(score10Str, "%d" , overall_highscore[9]);

        score1.setMessage(score1Str);
        score2.setMessage(score2Str);
        score3.setMessage(score3Str);
        score4.setMessage(score4Str);
        score5.setMessage(score5Str);
        score6.setMessage(score6Str);
        score7.setMessage(score7Str);
        score8.setMessage(score8Str);
        score9.setMessage(score9Str);
        score10.setMessage(score10Str);
        
        }

        else if(navigator_y == WINDOW_Y*0.5){
          
        list_leaderboard(name,highscores_level1);
        player1.setMessage(name[0]);
        player2.setMessage(name[1]);
        player3.setMessage(name[2]);
        player4.setMessage(name[3]);
        player5.setMessage(name[4]);
        player6.setMessage(name[5]);
        player7.setMessage(name[6]);
        player8.setMessage(name[7]);
        player9.setMessage(name[8]);
        player10.setMessage(name[9]);

	    sprintf(score1Str, "%d" , highscores_level1[0]);
	    sprintf(score2Str, "%d" , highscores_level1[1]);
	    sprintf(score3Str, "%d" , highscores_level1[2]);
	    sprintf(score4Str, "%d" , highscores_level1[3]);
	    sprintf(score5Str, "%d" , highscores_level1[4]);
	    sprintf(score6Str, "%d" , highscores_level1[5]);
	    sprintf(score7Str, "%d" , highscores_level1[6]);
	    sprintf(score8Str, "%d" , highscores_level1[7]);
	    sprintf(score9Str, "%d" , highscores_level1[8]);
	    sprintf(score10Str, "%d" , highscores_level1[9]);

        score1.setMessage(score1Str);
        score2.setMessage(score2Str);
        score3.setMessage(score3Str);
        score4.setMessage(score4Str);
        score5.setMessage(score5Str);
        score6.setMessage(score6Str);
        score7.setMessage(score7Str);
        score8.setMessage(score8Str);
        score9.setMessage(score9Str);
        score10.setMessage(score10Str);
        
        }

        else if(navigator_y == WINDOW_Y*0.6){
          
        list_leaderboard(name,highscores_level2);
        player1.setMessage(name[0]);
        player2.setMessage(name[1]);
        player3.setMessage(name[2]);
        player4.setMessage(name[3]);
        player5.setMessage(name[4]);
        player6.setMessage(name[5]);
        player7.setMessage(name[6]);
        player8.setMessage(name[7]);
        player9.setMessage(name[8]);
        player10.setMessage(name[9]);

	    sprintf(score1Str, "%d" , highscores_level2[0]);
	    sprintf(score2Str, "%d" , highscores_level2[1]);
	    sprintf(score3Str, "%d" , highscores_level2[2]);
	    sprintf(score4Str, "%d" , highscores_level2[3]);
	    sprintf(score5Str, "%d" , highscores_level2[4]);
	    sprintf(score6Str, "%d" , highscores_level2[5]);
	    sprintf(score7Str, "%d" , highscores_level2[6]);
	    sprintf(score8Str, "%d" , highscores_level2[7]);
	    sprintf(score9Str, "%d" , highscores_level2[8]);
	    sprintf(score10Str, "%d" , highscores_level2[9]);

        score1.setMessage(score1Str);
        score2.setMessage(score2Str);
        score3.setMessage(score3Str);
        score4.setMessage(score4Str);
        score5.setMessage(score5Str);
        score6.setMessage(score6Str);
        score7.setMessage(score7Str);
        score8.setMessage(score8Str);
        score9.setMessage(score9Str);
        score10.setMessage(score10Str);
          
        }
       
        else if(navigator_y == WINDOW_Y*0.7){
          	
        list_leaderboard(name,highscores_level3);
        player1.setMessage(name[0]);
        player2.setMessage(name[1]);
        player3.setMessage(name[2]);
        player4.setMessage(name[3]);
        player5.setMessage(name[4]);
        player6.setMessage(name[5]);
        player7.setMessage(name[6]);
        player8.setMessage(name[7]);
        player9.setMessage(name[8]);
        player10.setMessage(name[9]);
	    	
	    sprintf(score1Str, "%d" , highscores_level3[0]);
	    sprintf(score2Str, "%d" , highscores_level3[1]);
	    sprintf(score3Str, "%d" , highscores_level3[2]);
	    sprintf(score4Str, "%d" , highscores_level3[3]);
	    sprintf(score5Str, "%d" , highscores_level3[4]);
	    sprintf(score6Str, "%d" , highscores_level3[5]);
	    sprintf(score7Str, "%d" , highscores_level3[6]);
	    sprintf(score8Str, "%d" , highscores_level3[7]);
	    sprintf(score9Str, "%d" , highscores_level3[8]);
	    sprintf(score10Str, "%d" , highscores_level3[9]);

        score1.setMessage(score1Str);
        score2.setMessage(score2Str);
        score3.setMessage(score3Str);
        score4.setMessage(score4Str);
        score5.setMessage(score5Str);
        score6.setMessage(score6Str);
        score7.setMessage(score7Str);
        score8.setMessage(score8Str);
        score9.setMessage(score9Str);
        score10.setMessage(score10Str);
       
        }

      }
      
      else if(navigator_y == WINDOW_Y*0.8 && leaderboard_page){
      
        t_newgame.reset(WINDOW_X*0.5,WINDOW_Y*0.4, "NEW GAME");
        t_levels.reset(WINDOW_X*0.5,WINDOW_Y*0.5, "LEVELS");
        t_controls.reset(WINDOW_X*0.5,WINDOW_Y*0.6, "CONTROLS");
        t_leaderboard.reset(WINDOW_X*0.5,WINDOW_Y*0.7, "LEADERBOARD");
        t_quitgame.reset(WINDOW_X*0.5,WINDOW_Y*0.8, "QUIT");
        leaderboard_page = false;
        home_page = true;
        levels_page = false;	
      
      }
        
      break;
            case 27 : // ASCII code for [Esc] key
      	restart = true; 
      break;
            default:
      break;
          } // Ends switch

      } // Ends if(pendingEv)
    } // End for(;;) loop for main menu navigation
    
    if(restart){ continue;}
    closeCanvas();
    initCanvas("Lasso", WINDOW_X, WINDOW_Y);

 for(;;){
    
    srand((time(NULL)));

    int stepCount = 0;
    float stepTime = STEP_TIME;
    float runTime = LEVEL_TIME; // sec;
    float currTime = 0;
    bool skipTut = false;
    
    // This array contains the word which would appear in the game alphabet bwise
    // Whenever the program compiles anyone of these five words are randomly choosen by the computer using the rand() function present in <ctime> library
    char word[5][20] = {"LASSO","COIN","MAGNET","PROJECT","BOMB"}; 
    
    // This array stores different values of time in sec
    float objectTimeGap[10];
    for(int i=0;i<10;i++){
    	objectTimeGap[i] = OBJECT_TIME_GAP*(i+1)*0.5;
    }
    
    // Heart shaped polygon for lives
    double heartV[8][2];
	
	heartV[0][0] = 5*sqrt(3); 
	heartV[0][1] = 0;
	heartV[1][0] = 5*sqrt(3); 
	heartV[1][1] = -5;
	heartV[2][0] = 2.5*sqrt(3); 
	heartV[2][1] = -7.5;
	heartV[3][0] = 0;
	heartV[3][1] = -5;
	heartV[4][0] = -2.5*sqrt(3); 
	heartV[4][1] = -7.5;
	heartV[5][0] = -5*sqrt(3); 
	heartV[5][1] = -5;
	heartV[6][0] = -5*sqrt(3); 
	heartV[6][1] = -0;
	heartV[7][0] = 0; 
	heartV[7][1] = 5*sqrt(3);
    Polygon heart[5];

    // Arrays of path {speed,angle,x-coordinate} followed by projectiles
    double path[25][3] = {{80,60,WINDOW_X/2-2*OBJECT_GAP},{100,60,WINDOW_X/2-2*OBJECT_GAP},{120,60,WINDOW_X/2-2*OBJECT_GAP},{80,90,WINDOW_X/2-2*OBJECT_GAP},{100,90,WINDOW_X/2-2*OBJECT_GAP},
						  {100,60,WINDOW_X/2-OBJECT_GAP},{100,60,WINDOW_X/2-OBJECT_GAP},{100,60,WINDOW_X/2-OBJECT_GAP},{100,60,WINDOW_X/2-OBJECT_GAP},{100,60,WINDOW_X/2-OBJECT_GAP},
						  {100,95,WINDOW_X/2},{105,85,WINDOW_X/2},{85,90,WINDOW_X/2},{100,105,WINDOW_X/2},{105,75,WINDOW_X/2},
						  {100,110,WINDOW_X/2+OBJECT_GAP},{130,110,WINDOW_X/2+OBJECT_GAP},{60,120,WINDOW_X/2+OBJECT_GAP},{90,105,WINDOW_X/2+OBJECT_GAP},{95,90,WINDOW_X/2+OBJECT_GAP},
						  {100,110,WINDOW_X/2+2*OBJECT_GAP},{120,110,WINDOW_X/2-2*OBJECT_GAP},{125,120,WINDOW_X/2-2*OBJECT_GAP},{80,105,WINDOW_X/2-2*OBJECT_GAP},{95,100,WINDOW_X/2-2*OBJECT_GAP}};
    // These are used in resetCoin, resetBomb, resetMagnet functions of coin.cpp to make sure that whenever
    // they are reset they follow a different path among one of these, choosen randomly by computer using the rand() function 

    // Draw lasso at start position
    double release_speed = INIT_RELEASE_SPEED; // m/s
    double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
    double lasso_ax = 0;
    double lasso_ay = LASSO_G;
    bool paused = true;
    bool rtheta = true;
    Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);

    // Initialisation of coins, bomb and magnet with dummy anguments (0 speed , 0 angle_deg)
    // Dummy arguments has been used to define them to make sure that, they can be called in the switch statement using the reset function defined in coin.cpp 
    double coin_ax = 0;
    double coin_ay = COIN_G;
    Coin coin1(0,0, coin_ax, coin_ay, paused, rtheta);
    Coin coin2(0,0, coin_ax, coin_ay, paused, rtheta);
    Coin coin3(0,0, coin_ax, coin_ay, paused, rtheta);
    Coin coin4(0,0, coin_ax, coin_ay, paused, rtheta);
    float gap_coin4 = objectTimeGap[rand()%10];
    Coin goodcoin1(0,0, coin_ax, coin_ay, paused, rtheta);
    float gap_goodcoin1 = objectTimeGap[rand()%10];
    Coin goodcoin2(0,0, coin_ax, coin_ay, paused, rtheta);
    float gap_goodcoin2 = objectTimeGap[rand()%10];
    Coin goodcoin3(0,0, coin_ax, coin_ay, paused, rtheta);
    float gap_goodcoin3 = objectTimeGap[rand()%10];
    Coin impcoin1(0,0, coin_ax, coin_ay, paused, rtheta);
    float gap_impcoin1 = objectTimeGap[rand()%10]; 
    Coin impcoin2(0,0, coin_ax, coin_ay, paused, rtheta);
    float gap_impcoin2 = objectTimeGap[rand()%10];
    Coin impcoin3(0,0, coin_ax, coin_ay, paused, rtheta);
    float gap_impcoin3 = objectTimeGap[rand()%10];

    double bomb_ax = 0;
    double bomb_ay = BOMB_G;
    Bomb bomb1(0,0,bomb_ax,bomb_ay,paused,rtheta);
    Bomb bomb2(0,0,bomb_ax,bomb_ay,paused,rtheta);
    float gap_bomb2 =  objectTimeGap[rand()%10];
    Bomb bomb3(0,0,bomb_ax,bomb_ay,paused,rtheta);
    float gap_bomb3 = objectTimeGap[rand()%10];

    double magnet_ax = 0;
    double magnet_ay = MAGNET_G;
    Magnet magnet1(0,0, magnet_ax, magnet_ay, paused, rtheta);
    float gap_magnet1 = objectTimeGap[rand()%10];
    Magnet magnet2(0,0, magnet_ax, magnet_ay, paused, rtheta);
    float gap_magnet2 = objectTimeGap[rand()%10];
    
    double alphabet_ax = 0;
    double alphabet_ay = ALPHABET_G;
    Alphabet alphabet[100];
    int L =0;
    int random_index = rand()%5;
    while(word[random_index][L] != '\0') L++;

    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    b1.setColor(COLOR("blue"));
    Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
    b2.setColor(COLOR("blue"));

    string msg("Cmd: _");
    Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg);
    char timeLeftStr[256];
    char scoreStr[256];
    char coinScoreStr[256];
    char bestScoreStr[256];

    Text timeLeft_1(WINDOW_X - PLAY_X_START*1.5, (WINDOW_Y - PLAY_Y_HEIGHT)*2 - 20, "Each level would be 60 sec long");
    Text timeLeft(WINDOW_X - PLAY_X_START*1.5, (WINDOW_Y - PLAY_Y_HEIGHT)*2, "Here the time left would be displayed");
    Text score(WINDOW_X - PLAY_X_START*1.5, (WINDOW_Y - PLAY_Y_HEIGHT)*2 + 20, "Total score would be displayed here");
    Text bestScore(PLAY_X_START*2.5,(WINDOW_Y - PLAY_Y_HEIGHT)*2 + 20,"Highest score for the respective level");
    Text bestScore_1(PLAY_X_START*2.5,(WINDOW_Y - PLAY_Y_HEIGHT)*2 + 40, "would be displayed here");
    timeLeft_1.setColor(COLOR("red"));
	if(level == 0){
	    timeLeft.setColor(COLOR("red"));
	    score.setColor(COLOR("red"));
	    bestScore.setColor(COLOR("red"));
    }
    bestScore_1.setColor(COLOR("red"));

    Text timeLeft_text(WINDOW_X - PLAY_X_START*3, (WINDOW_Y - PLAY_Y_HEIGHT)*2, "TIME LEFT");
    Text score_text(WINDOW_X - PLAY_X_START*3, (WINDOW_Y - PLAY_Y_HEIGHT)*2 + 20, "SCORE");
    Text coin_text(WINDOW_X - PLAY_X_START*3, (WINDOW_Y - PLAY_Y_HEIGHT)*2 + 40, "COINS");
    Text bestScore_text(PLAY_X_START*2.5,(WINDOW_Y - PLAY_Y_HEIGHT)*2,"B E S T  S C O R E");
    Text timeUp;
   	timeUp.setColor(COLOR("red"));
    Text GameOver;
   	GameOver.setColor(COLOR("red"));
    timeLeft_text.setColor(COLOR("blue"));
   	score_text.setColor(COLOR("blue"));
    coin_text.setColor(COLOR("blue"));
    bestScore_text.setColor(COLOR("blue"));
    
    // for instructions in tutorial
    Text instructions, instructions_1, instructions_2, instructions_3, 
    	 instructions_4, instructions_5, instructions_6, instructions_7, 
    	 instructions_8, instructions_9, instructions_10, instructions_11,
    	 instructions_12, instructions_13, instructions_14, instructions_15a,
    	 instructions_15b, instructions_15c, instructions_16a, instructions_16b,
    	 instructions_16c, instructions_17, instructions_18, instructions_19;
    Text level_text;

    if(level != 0){
    	timeLeft_1 = NULL;
    	bestScore_1 = NULL;
	    sprintf(scoreStr, "%d" , 0);
	    sprintf(bestScoreStr, "%d", 0);
	    sprintf(timeLeftStr, "%f", runTime-currTime);
	    timeLeft.reset(WINDOW_X - PLAY_X_START*2, (WINDOW_Y - PLAY_Y_HEIGHT)*2, timeLeftStr);
    	score.reset(WINDOW_X - PLAY_X_START*2, (WINDOW_Y - PLAY_Y_HEIGHT)*2 + 20, scoreStr);
    	bestScore.reset(PLAY_X_START*2.5,(WINDOW_Y - PLAY_Y_HEIGHT)*2 + 20, bestScoreStr);
    }

    sprintf(coinScoreStr, "%d x ", lasso.getNumCoins());
    Text coinScore(WINDOW_X - PLAY_X_START*2, (WINDOW_Y - PLAY_Y_HEIGHT)*2 + 40, coinScoreStr);

    // Initialization of dummy objects in tutorial
    Coin ScoreCoin(0,0,0,0,true,true);
    Coin tut_coin(0,0,0,0,true,true);
    Coin tut_impcoin(0,0,0,0,true,true);
    Coin tut_goodcoin(0,0,0,0,true,true);
    Bomb tut_bomb(0,0,0,0,true,true);
    Magnet tut_magnet(0,0,0,0,true,true);
    Alphabet tut_alphabet;
    ScoreCoin.initCoin();
    ScoreCoin.set_pos(WINDOW_X - PLAY_X_START*1.85,(WINDOW_Y - PLAY_Y_HEIGHT)*2 + 40);

    // Initialization of lives
    for(int i=0;i<5;i++){
    	heart[i].reset(WINDOW_X - PLAY_X_START*3 +20*i,(WINDOW_Y - PLAY_Y_HEIGHT)*2+60,heartV,8);
    	heart[i].setColor(COLOR("red"));
    	heart[i].setFill(true);
	}

	// This switch statement design every level
    switch(level){
       case 0: // Tutorial
    	level_text.reset(WINDOW_X/2, WINDOW_Y-PLAY_Y_HEIGHT-50 ,"T U T O R I A L");
    	coin1.initCoin();
    	bomb1.initBomb();
    	impcoin1.initImpCoin();
    	goodcoin1.initGoodCoin();
    	magnet1.initMagnet();
    	for(int i=0;i<L;i++){
	      paused = true;
	      string letter(1, word[random_index][i]);
	      int temp = rand()%25;
	      	alphabet[i].reset(path[temp][0],path[temp][1],path[temp][2],alphabet_ax,alphabet_ay, paused, i ,letter);
    	}
    	tut_coin.initCoin();
    	tut_impcoin.initImpCoin();
    	tut_goodcoin.initGoodCoin();
    	tut_bomb.initBomb();
    	tut_magnet.initMagnet();
    	tut_alphabet.initAlphabet("A");
    	tut_coin.set_pos(WINDOW_X/2 - PLAY_X_START*2.5, (WINDOW_Y - PLAY_Y_HEIGHT));
    	tut_bomb.set_pos(WINDOW_X/2 - PLAY_X_START*2.5, (WINDOW_Y - PLAY_Y_HEIGHT) + 50);
    	tut_impcoin.set_pos(WINDOW_X/2 - PLAY_X_START*2.5, (WINDOW_Y - PLAY_Y_HEIGHT) + 100);
    	tut_goodcoin.set_pos(WINDOW_X/2 - PLAY_X_START*2.5, (WINDOW_Y - PLAY_Y_HEIGHT) + 150);
    	tut_magnet.set_pos(WINDOW_X/2 - PLAY_X_START*2.5, (WINDOW_Y - PLAY_Y_HEIGHT) + 250);
    	tut_alphabet.set_pos(WINDOW_X/2 - PLAY_X_START*3, (WINDOW_Y - PLAY_Y_HEIGHT) + 300, "A");

    	instructions.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT), "This is a simple coin, collecting it would");
    	instructions_1.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 20, "increase the number of coins by 1 and score by 1000 points");
    	instructions_2.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 50, "This is bomb, collecting it would reduce 1 life");
    	instructions_3.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 70, "and would decrease score by 10000 points");
    	instructions_4.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 100, "This is an important coin, if not collected it");
    	instructions_5.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 120, "would cost you a life.It increase score by 1000 points");
    	instructions_6.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 150, "This is a special coin, collecting it is equivalent to 3 simple coins");
    	instructions_7.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 170, "and collecting it would increase score by 5000 points");
    	instructions_8.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 200, "Both important and special coin would appear only once,");
    	instructions_9.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 220, "they would get removed if not collected");
    	instructions_10.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 250, "This is a magnet. Once you loop it, it starts attracting simple coins,");
    	instructions_11.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 270, "important coins and special coins but it doesn't attract bomb and alphabet");
    	instructions_12.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 300, "Alphabets pop up on the screen ocassionally, collect them to form any one of the five words");
    	instructions_13.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 320, "'LASSO','COIN','MAGNET','CS101','BOMB' the formation of word would appear at the top of the screen");
    	instructions_14.reset(WINDOW_X/2, (WINDOW_Y - PLAY_Y_HEIGHT) + 340, "each alphabet would increase score by 5000 points and formation of a word would fetch an extra 20000 points");
    	
    	if(new_game){
	    	instructions_15a.reset(WINDOW_X - PLAY_X_START*2.35, PLAY_Y_HEIGHT - 100 , "PRESS");
	    	instructions_15b.reset(WINDOW_X - PLAY_X_START*2, PLAY_Y_HEIGHT - 100 , "SPACE");
	    	instructions_15b.setColor(COLOR("red"));
    		instructions_15c.reset(WINDOW_X - PLAY_X_START*1.25, PLAY_Y_HEIGHT - 100 , "TO SKIP TUTORIAL");
    	}
    	instructions_16a.reset(WINDOW_X - PLAY_X_START*2.35, PLAY_Y_HEIGHT - 80 , "PRESS");
    	instructions_16b.reset(WINDOW_X - PLAY_X_START*2, PLAY_Y_HEIGHT - 80 , "ESC");
    	instructions_16b.setColor(COLOR("red"));
    	instructions_16c.reset(WINDOW_X - PLAY_X_START, PLAY_Y_HEIGHT - 80 , "TO RETURN BACK TO MAIN MENU");
    	instructions_17.reset(WINDOW_X - PLAY_X_START*2,(WINDOW_Y - PLAY_Y_HEIGHT)*2 + 100, "At the beggining of each level five lives are present,");
    	instructions_18.reset(WINDOW_X - PLAY_X_START*2,(WINDOW_Y - PLAY_Y_HEIGHT)*2 + 120, "if you fail to catch a bomb or an important coin your life");
    	instructions_19.reset(WINDOW_X - PLAY_X_START*2,(WINDOW_Y - PLAY_Y_HEIGHT)*2 + 140, "get deducted, GAME gets over if you get short of lives");
    	instructions_17.setColor(COLOR("red"));
    	instructions_18.setColor(COLOR("red"));
    	instructions_19.setColor(COLOR("red"));

      break;
       case 1: // Level 1
    	lasso.score = 0;
    	instructions_16a.reset(WINDOW_X - PLAY_X_START*2.35, PLAY_Y_HEIGHT - 80 , "PRESS");
    	instructions_16b.reset(WINDOW_X - PLAY_X_START*2, PLAY_Y_HEIGHT - 80 , "ESC");
    	instructions_16b.setColor(COLOR("red"));
    	instructions_16c.reset(WINDOW_X - PLAY_X_START, PLAY_Y_HEIGHT - 80 , "TO RETURN BACK TO MAIN MENU");
    	level_text.reset(WINDOW_X/2, WINDOW_Y-PLAY_Y_HEIGHT ,"L E V E L  1");
    	coin1.initCoin();
    	coin2.initCoin();
    	coin3.initCoin();
    	bomb1.initBomb();
    	bomb2.initBomb();
    	impcoin1.initImpCoin();
    	impcoin2.initImpCoin();
      break;
       case 2: // Level 2
    	lasso.score = 0;
    	instructions_16a.reset(WINDOW_X - PLAY_X_START*2.35, PLAY_Y_HEIGHT - 80 , "PRESS");
    	instructions_16b.reset(WINDOW_X - PLAY_X_START*2, PLAY_Y_HEIGHT - 80 , "ESC");
    	instructions_16b.setColor(COLOR("red"));
    	instructions_16c.reset(WINDOW_X - PLAY_X_START, PLAY_Y_HEIGHT - 80 , "TO RETURN BACK TO MAIN MENU");
    	level_text.reset(WINDOW_X/2, WINDOW_Y-PLAY_Y_HEIGHT ,"L E V E L  2");
    	coin1.initCoin();
    	coin2.initCoin();
    	coin3.initCoin();
    	impcoin1.initImpCoin();
    	impcoin2.initImpCoin();
    	goodcoin1.initGoodCoin();
    	goodcoin2.initGoodCoin();
    	bomb1.initBomb();
    	bomb2.initBomb();
    	magnet1.initMagnet();
    	magnet2.initMagnet();
      break;
       case 3: // Level 3
    	lasso.score = 0;
		instructions_16a.reset(WINDOW_X - PLAY_X_START*2.35, PLAY_Y_HEIGHT - 80 , "PRESS");
    	instructions_16b.reset(WINDOW_X - PLAY_X_START*2, PLAY_Y_HEIGHT - 80 , "ESC");
    	instructions_16b.setColor(COLOR("red"));
    	instructions_16c.reset(WINDOW_X - PLAY_X_START, PLAY_Y_HEIGHT - 80 , "TO RETURN BACK TO MAIN MENU");
    	level_text.reset(WINDOW_X/2, WINDOW_Y-PLAY_Y_HEIGHT ,"L E V E L  3");
    	coin1.initCoin();
    	coin2.initCoin();
    	coin3.initCoin();
    	coin4.initCoin();
    	bomb1.initBomb();
    	bomb2.initBomb();
    	bomb3.initBomb();
    	impcoin1.initImpCoin();
    	impcoin2.initImpCoin();
    	impcoin3.initImpCoin();
    	goodcoin1.initGoodCoin();
    	goodcoin2.initGoodCoin();
    	magnet1.initMagnet();
    	magnet2.initMagnet();
    	for(int i=0;i<L;i++){
	      paused = true;
	      string letter(1, word[random_index][i]);
	      int temp = rand()%25;
	      alphabet[i].reset(path[temp][0],path[temp][1],path[temp][2],alphabet_ax,alphabet_ay, paused, i ,letter);
    	}
      break;
       default:
      break;
    }

  for(;restart==false;) { // loop for the gaming window

      srand((time(NULL))); // Ensures different integer generated by rand() everytime the program is executed

      // Breaks the loop whenever level ends and saves the score in the leaderboard
      if((currTime > runTime && level != 0) || skipTut){
      	
	    if(level == 1){
    		fstream file_level1("level1.txt", ios::app | ios::out);
		    file_level1 << endl << lasso.score;
		    file_level1.close();
		}
		else if(level == 2){
    		fstream file_level2("level2.txt", ios::app | ios::out);
		    file_level2 << endl << lasso.score;
		    file_level2.close();
		}
		else if(level == 3){
    		fstream file_level3("level3.txt", ios::app | ios::out);
		    file_level3 << endl << lasso.score;
		    file_level3.close();
      	}
      	level++; 
      	break;
      } 

      // When t is pressed, throw lasso
      // If lasso within range, make coin stick
      // When y is pressed, yank lasso
      // When l is pressed, loop lasso
      // When q is pressed, quit

      XEvent e;
      bool pendingEv = checkEvent(e);
      if(pendingEv) {
        char c = charFromEvent(e);
        msg[msg.length()-1] = c;
        charPressed.setMessage(msg);
        switch(c) {
        case 't':
		  	lasso.unpause();
		  	if(lasso.isMagnetAttached()){
		      magnet1.unpause();
		      magnet2.unpause();
    		}
  		break;
        case 'y':
  			lasso.yank();
  		break;
        case 'l':
		  	lasso.loopit();
		    lasso.check_for_coin(&coin1);
		    lasso.check_for_coin(&coin2);
		    lasso.check_for_coin(&coin3);
		    lasso.check_for_coin(&coin4);
		    
		    lasso.check_for_bomb(&bomb1);
		    lasso.check_for_bomb(&bomb2);
		    lasso.check_for_bomb(&bomb3);

		    lasso.check_for_coin(&goodcoin1);
		    lasso.check_for_coin(&goodcoin2);
		    lasso.check_for_coin(&goodcoin3);
		    
		    lasso.check_for_coin(&impcoin1);
		    lasso.check_for_coin(&impcoin2);
		    lasso.check_for_coin(&impcoin3);
    
		    if(!lasso.isMagnetAttached()){
		      lasso.check_for_magnet(&magnet1);
		      lasso.check_for_magnet(&magnet2);
		    }

	    for(int i=0;i<L;i++){lasso.check_for_alphabet(&alphabet[i]);}
	    if(lasso.num_alphabet == L){lasso.score += 20000;}
    
  		break;
        case '[':
  			if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);	}
  		break;
        case ']':
  			if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
  		break;
        case '-':
  			if(lasso.isPaused()) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
  		break;
        case '=':
  			if(lasso.isPaused()) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
  		break;
        case 27:
    		restart = true;
    	case 32:
		    if(new_game){
		    	if(level == 0) skipTut = true;
		    }
    	break;
        default:
  		break;
        }
      }
      
      // ensures that every object moves in each iteration 
      lasso.nextStep(stepTime);
      coin1.nextStep(stepTime);
      coin2.nextStep(stepTime);
      coin3.nextStep(stepTime);
      coin4.nextStep(stepTime);
      goodcoin1.nextStep(stepTime);
      goodcoin2.nextStep(stepTime);
      goodcoin3.nextStep(stepTime);
      impcoin1.nextStep(stepTime);
      impcoin2.nextStep(stepTime);
      impcoin3.nextStep(stepTime);

      bomb1.nextStep(stepTime);
      bomb2.nextStep(stepTime);
      bomb3.nextStep(stepTime);
      magnet1.nextStep(stepTime);
      magnet2.nextStep(stepTime);
      for(int i=0;i<L;i++){
        alphabet[i].nextStep(stepTime);
      }

    // Following lines of codes unpause every object and remove/reset them whenever they are out of playzone
    if(coin1.isPaused()) { coin1.unpause();}
    if(coin1.getYPos() > PLAY_Y_HEIGHT) { coin1.resetCoin();}

    if(coin2.isPaused()) { coin2.unpause();}
    if(coin2.getYPos() > PLAY_Y_HEIGHT) { coin2.resetCoin();}

    if(coin3.isPaused()) { coin3.unpause();}
    if(coin3.getYPos() > PLAY_Y_HEIGHT) { coin3.resetCoin();}

    if(coin4.isPaused() && currTime > gap_coin4) { coin4.unpause();} 
    if(coin4.getYPos() > PLAY_Y_HEIGHT) { coin4.resetCoin();}
	// currTime > gap_coin4 ensures that the 4th coin comes in the screen after a fixed time gap_coin4 defined earlier, where coin4 was intitialized 
    // similar condition is passed through if statement of other objects as well. 

    if(bomb1.isPaused()) { bomb1.unpause();}
    if(bomb1.getYPos() > PLAY_Y_HEIGHT) { bomb1.resetBomb();}

    if(bomb2.isPaused() && currTime > gap_bomb2) { bomb2.unpause();}
    if(bomb2.getYPos() > PLAY_Y_HEIGHT) { bomb2.resetBomb();}

    if(bomb3.isPaused() && currTime > gap_bomb3) { bomb3.unpause();}
    if(bomb3.getYPos() > PLAY_Y_HEIGHT) { bomb3.resetBomb();}
    
    if(goodcoin1.isPaused() && currTime > gap_goodcoin1) { goodcoin1.unpause();} 
    if(goodcoin1.getYPos() > PLAY_Y_HEIGHT) {
        if(goodcoin1.getXPos() > 0 ) goodcoin1.removeCoin(); // goodcoins are removed, once they exit the playzone, they are not repeated like bombs and coins
      	else goodcoin1.resetCoin();
    }

    if(goodcoin2.isPaused() && currTime > gap_goodcoin2) { goodcoin2.unpause();}
    if(goodcoin2.getYPos() > PLAY_Y_HEIGHT) {
        if(goodcoin2.getXPos() > 0 ) goodcoin2.removeCoin();
      	else goodcoin2.resetCoin();
    } 

    if(goodcoin3.isPaused() && currTime > gap_goodcoin3) { goodcoin3.unpause();}
    if(goodcoin3.getYPos() > PLAY_Y_HEIGHT) {
        if(goodcoin3.getXPos() > 0 ) goodcoin3.removeCoin();
      	else goodcoin3.resetCoin();
    } 

    if(impcoin1.isPaused() && currTime > gap_impcoin1) { impcoin1.unpause();}
    if(impcoin1.getYPos() > PLAY_Y_HEIGHT) {
        if(impcoin1.getXPos() > 0 ) {lasso.lives--; impcoin1.removeCoin();} // impcoins are removed, once they exit the playzone, they are not repeated like bombs and coins
      	else impcoin1.resetCoin();
    }

    if(impcoin2.isPaused() && currTime > gap_impcoin2) { impcoin2.unpause();}
    if(impcoin2.getYPos() > PLAY_Y_HEIGHT) {
        if(impcoin2.getXPos() > 0 ) {lasso.lives--; impcoin2.removeCoin();}
      	else impcoin2.resetCoin();
    }

    if(impcoin3.isPaused() && currTime > gap_impcoin3) { impcoin3.unpause();}
    if(impcoin3.getYPos() > PLAY_Y_HEIGHT) {
        if(impcoin3.getXPos() > 0 ) {lasso.lives--; impcoin3.removeCoin();}
      	else impcoin3.resetCoin();
    }

    for(int i=0;i<L;i++){
     	if(alphabet[i].isPaused() && currTime > OBJECT_TIME_GAP*(i+1)){
      string letter(1, word[random_index][i]);
      alphabet[i].initAlphabet(letter);
      alphabet[i].unpause();
        }
    }

    for(int i=0;i<L;i++){
        if(alphabet[i].getYPos() > PLAY_Y_HEIGHT) {
          alphabet[i].removeAlphabet();  // alphabets are removed, once they exit the playzone, they are not repeated like bombs and coins
        }
    }

    if(magnet1.isPaused() && currTime > gap_magnet1) {
        if(!lasso.isMagnetAttached()) {
    magnet1.unpause();
        }
      }

    if(magnet2.isPaused() && currTime > gap_magnet2) {
        if(!lasso.isMagnetAttached()) {
    magnet2.unpause();
        }
      }
    	
    if(magnet1.getYPos() > PLAY_Y_HEIGHT) {
        if(magnet1.getXPos() > 0 ) magnet1.removeMagnet(); // Magnets are removed, once they exit the playzone, they are not repeated like bombs and coins
      	else magnet1.resetMagnet();
      }

    if(magnet2.getYPos() > PLAY_Y_HEIGHT) {
        if(magnet2.getXPos() > 0 ) magnet2.removeMagnet();
      	else magnet2.resetMagnet();
      }

    if(lasso.isMagnetAttached()){
        
        lasso.reduce_magnet_radius(lasso.get_magnet_radius() - STEP_MAG_RAD_DEC); // In every iteration the radius of magnet reduces 
        if(lasso.get_magnet_radius() < LASSO_RADIUS){
          lasso.removeMagnet();  // Once magnet radius gets lower than the loop radius, magnet is removed (as its effectively same as looping)
          lasso.magnet_attached = false;
        }

        // Call to attract objects if magnet is attached with the loop 
        lasso.attract_coin(&coin1);
        lasso.attract_coin(&coin2);
        lasso.attract_coin(&coin3);
        lasso.attract_coin(&coin4);
        lasso.attract_coin(&goodcoin1);
        lasso.attract_coin(&goodcoin2);
        lasso.attract_coin(&goodcoin3);
        lasso.attract_coin(&impcoin1);
        lasso.attract_coin(&impcoin2);
        lasso.attract_coin(&impcoin3);
        // Whenever another magnet is attracted by a magnet already attached to the lasso, the radius of magnet is reset to its original value :)
        lasso.attract_magnet(&magnet1);
        lasso.attract_magnet(&magnet2);
      
    }

      sprintf(coinScoreStr, "%d x ", lasso.getNumCoins());
      coinScore.setMessage(coinScoreStr);

      stepCount++;
      currTime += stepTime;
      lasso.score += 500*stepTime;
      
      // If the level is not tutorial then this if statement sets the timeleft and bestscore displayed on the screen
      if(level != 0){
      	  sprintf(scoreStr, "%d" , lasso.score);
	      sprintf(timeLeftStr, "%f", runTime-currTime);
	      sprintf(timeLeftStr, "%f", runTime-currTime);
	  	  if(level == 1) {
          	list_leaderboard(name,highscores_level1);
	  	  	sprintf(bestScoreStr, "%d", highscores_level1[0]);
	  	  }
	  	  else if(level == 2){
			list_leaderboard(name,highscores_level2);
	  	  	sprintf(bestScoreStr, "%d", highscores_level2[0]);
	  	  }
	  	  else if(level == 3){
			list_leaderboard(name,highscores_level3);
	  	  	sprintf(bestScoreStr, "%d", highscores_level3[0]);
	      }
	      timeLeft.setMessage(timeLeftStr);
	      score.setMessage(scoreStr);
    	  bestScore.setMessage(bestScoreStr);
      	
      }

      // It reduces lives of the lasso by unfilling the red heart polygon intially filled with color
      for(int i=lasso.lives;i<5;i++){
    	heart[i].setFill(false);
	  }

	  // Exits game if all five lives are lost
      if(lasso.lives == 0){
      	GameOver.reset(WINDOW_X/2,WINDOW_Y/2,"G A M E  O V E R  ! ! !"); 
      	wait(3); 
      	break;
      }
      wait(stepTime);
    } // End for(;;) of controls
	
	if(!new_game && !restart && lasso.lives != 0 && !skipTut){
		timeUp.reset(WINDOW_X/2,WINDOW_Y/2,"T I M E ' S   U P  ! ! !");
		wait(3);
		restart=true;
	}
	if(lasso.lives == 0){restart = true;}
	if(level == 4 && new_game){
		GameOver.reset(WINDOW_X/2,WINDOW_Y/2,"C O N G R A T U L A T I O N S  Y O U  P A S S E D  A L L  L E V E L S  ! ! !"); 
		wait(3) ; 
		restart=true;
	}
	if(restart){break;}
	if(new_game){
		if(!skipTut){
			timeUp.reset(WINDOW_X/2,WINDOW_Y/2,"T I M E ' S   U P  ! ! !"); 
			wait(3) ;
		}
		closeCanvas();
		initCanvas("lasso", WINDOW_X, WINDOW_Y);
		continue;
	}
   } // End for(;;) of level
   
   closeCanvas();
   if(restart){initCanvas("Lasso Menu", WINDOW_X, WINDOW_Y); continue;}
   wait(3);
 
 } // End for(;;) of whole game

}// End main program