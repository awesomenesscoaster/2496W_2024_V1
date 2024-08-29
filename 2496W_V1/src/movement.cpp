#include "display/lv_misc/lv_task.h"
#include "main.h"
#include "robot.h"
#include <cmath>
#include <math.h>
#include <vector>

// ------------ Chassis movement functions (PID, arcs, etc....) ------------ //

void driver_move(float lPwr, float rPwr){
    left = lPwr;
    right = rPwr;
}

void spin_left(float lPwr){
    left.move(lPwr);
}

void spin_right(float rPwr){
   right.move(rPwr);
}

void set_brake_coast(){
    lf.set_brake_mode(MOTOR_BRAKE_COAST);
    lm.set_brake_mode(MOTOR_BRAKE_COAST);
    lb.set_brake_mode(MOTOR_BRAKE_COAST);
    rf.set_brake_mode(MOTOR_BRAKE_COAST);
    rm.set_brake_mode(MOTOR_BRAKE_COAST);
    rb.set_brake_mode(MOTOR_BRAKE_COAST);
}