#include "main.h"
#include "autons.h"
#include "controls.h"
#include "movement.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"
#include "piston.h"

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
  set_brake_coast();
  lf.set_brake_mode(MOTOR_BRAKE_COAST);
  lm.set_brake_mode(MOTOR_BRAKE_COAST);
  lb.set_brake_mode(MOTOR_BRAKE_COAST);
  rf.set_brake_mode(MOTOR_BRAKE_COAST);
  rm.set_brake_mode(MOTOR_BRAKE_COAST);
  rb.set_brake_mode(MOTOR_BRAKE_COAST);
  lift.move(0);

  while (true) 
  {

    driver();
    lf.set_brake_mode(MOTOR_BRAKE_COAST);
    lm.set_brake_mode(MOTOR_BRAKE_COAST);
    lb.set_brake_mode(MOTOR_BRAKE_COAST);
    rf.set_brake_mode(MOTOR_BRAKE_COAST);
    rm.set_brake_mode(MOTOR_BRAKE_COAST);
    rb.set_brake_mode(MOTOR_BRAKE_COAST);
    
    pros::delay(2);
    time += 2;
  }
}
