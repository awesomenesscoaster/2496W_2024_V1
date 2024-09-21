#include "main.h"
#include "autons.h"
#include "controls.h"
#include "movement.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"
#include "piston.h"
#include <cmath>
#include <iostream>

using namespace std;

void on_center_button() {}

void initialize() { }

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

void competition_initialize() {}

void autonomous() {}

double truncate2(double var){
  return std::trunc(var * 100)/100;
}

void opcontrol() {
  long long time = 0; 
  set_brake_coast();
  
  controller.clear();
  rotation.reset_position();
  int counter = 0;
  
  while (true)
  {
    double chassis_temp = (lf.get_temperature() + lm.get_temperature() + lb.get_temperature() + rf.get_temperature() + rm.get_temperature() + rb.get_temperature()) / 6;
    int lift_pos = rotation.get_position();

    if (counter % 50 == 0 && counter % 100 != 0 && counter % 150 != 0) {
      controller.print(0, 0, "Temps: %d , %d          ", int(intake.get_temperature()), int(first_stage.get_temperature()));
    }
    else if (counter % 100 == 0 && counter % 150 != 0){
      controller.print(1, 0, "Chassis: %f   ", float(chassis_temp));
    }
    else if (counter % 150 == 0){
      controller.print(2, 0, "Lift pos: %d", lift_pos);
    }
    counter++;
    
    driver();
    //rotation_val(time);    
    pros::delay(2);
    time += 2;
    // if(intake.get_temperature() >= 50) {
    //   controller.rumble("-");
    // }

  }
}
