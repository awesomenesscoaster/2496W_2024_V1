#ifndef AUTONS_H_
#define AUTONS_H_

#include "main.h"
#include "robot.h"
#include "movement.h"
#include "auton_obj.h"

#include "pros/misc.h"
#include "pros/rtos.h"
#include <iostream>
#include <fstream>
#include <list>
#include <iostream>

using namespace pros;
using namespace std;

extern std::vector<Auton> autons;

extern void far_left();

extern void close_right();

extern void far_left();

extern void close_right(); 

extern void close_left();

extern void far_right();

extern void AWP_red();

extern void AWP_blue();

extern void blank();

extern Auton auton_selector(std::vector<Auton> autons); 


#endif