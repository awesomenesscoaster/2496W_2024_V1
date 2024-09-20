#include "main.h"
#include "autons.h"
#include "controls.h"
#include "movement.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"
#include "piston.h"
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

void opcontrol() {
  long long time = 0; 
  //ik theres a better way to do this 😿
  double chassis_temp = (lf.get_temperature() + lm.get_temperature() + lb.get_temperature() + rf.get_temperature() + rm.get_temperature() + rb.get_temperature()) / 6;

  set_brake_coast();
  
  controller.clear();
  rotation.reset_position();
  int counter = 0;
  
  while (true) 
  {
    if (!(counter % 25)) {
    controller.print(1, 0, "Temps: %d , %d ", int(intake.get_temperature()), int(first_stage.get_temperature()));
    controller.print(2, 0, "Chassis Temp: %f  ", round(chassis_temp));
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
