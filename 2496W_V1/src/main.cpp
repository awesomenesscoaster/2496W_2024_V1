#include "main.h"
#include "autons.h"
#include "controls.h"
#include "movement.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"

void on_center_button() {}

void initialize() { pros::lcd::initialize(); }

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
  while (true) {
    driver();
    pros::delay(10);
  }
}
