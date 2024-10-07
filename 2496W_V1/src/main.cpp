#include "main.h"
#include "autons.h"
#include "controls.h"
#include "movement.h"
#include "pros/misc.h"
#include "auton_obj.h"
#include "pros/motors.h"

#include "robot.h"
#include "piston.h"
#include <cmath>
#include <iostream>

using namespace std;

Auton *auton;
string names;

void on_center_button() {}

void initialize() { 
  controller.clear();
	static Auton temp = auton_selector(autons);
	names = temp.get_name();
	auton = &temp;
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

void competition_initialize() {}

void autonomous() {
  (*auton).run();
}

// double truncate2(double var){
//   return std::trunc(var * 100)/100;
// }

void opcontrol() {
  long long time = 0;
  int counter = 0; 

  // brake types
  set_brake_coast(); // chassis coast
  lift.set_brake_mode(MOTOR_BRAKE_HOLD);
  intake.set_brake_mode(MOTOR_BRAKE_COAST);
  first_stage.set_brake_mode(MOTOR_BRAKE_COAST);
  
  controller.clear();
  rotation.reset_position();
  
  while (true)
  {
    double chassis_temp = (lf.get_temperature() + lm.get_temperature() + lb.get_temperature() + rf.get_temperature() + rm.get_temperature() + rb.get_temperature()) / 6;
    int lift_pos = rotation.get_position();

    if (counter % 50 == 0 && counter % 100 != 0 && counter % 150 != 0) {
      //controller.print(0, 0, "Temps: %d , %d          ", int(intake.get_temperature()), int(first_stage.get_temperature()));
      controller.print(0, 0, "R: %d , %d, %d          ", int(rf.get_actual_velocity()), int(rm.get_actual_velocity()), int(rb.get_actual_velocity()));
    }
    else if (counter % 100 == 0 && counter % 150 != 0){
      //controller.print(1, 0, "Chassis: %f   ", float(chassis_temp));
      controller.print(1, 0, "L: %d , %d, %d          ", int(lf.get_actual_velocity()), int(lm.get_actual_velocity()), int(lb.get_actual_velocity()));
    }
    else if (counter % 150 == 0){
      //controller.print(2, 0, "Lift pos: %d", lift_pos);
      controller.print(2, 0, "Temps: %d , %d          ", int(intake.get_temperature()), int(first_stage.get_temperature()));

    }
    counter++;

    if(controller.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)){
		  autonomous();
		}
    
    driver();
    pros::delay(2);
    time += 2;
    // if(intake.get_temperature() >= 50) {
    //   controller.rumble("-");
    // }

  }
}
