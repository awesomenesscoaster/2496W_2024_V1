#ifndef ROBOT_H_
#define ROBOT_H_

#include "main.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "piston.h"

extern pros::Controller controller;

extern pros::Motor lf;
extern pros::Motor lm;
extern pros::Motor lb;
extern pros::Motor rf;
extern pros::Motor rm;
extern pros::Motor rb;

extern pros::Motor_Group left;
extern pros::Motor_Group right;

extern pros::Motor first_stage;
extern pros::Motor intake;

extern pros::Motor lift;

extern pros::IMU imu;

extern pros::ADIPotentiometer rotation;

extern pros::ADIDigitalOut clampP;
extern pros::ADIDigitalOut tiltP;
extern pros::ADIDigitalOut intakeP;
extern pros::ADIDigitalOut blankP;




#endif