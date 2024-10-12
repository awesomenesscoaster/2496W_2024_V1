#include "autons.h"
#include "main.h"
#include "movement.h"
#include "piston.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"

#include "auton_obj.h"
#include <cmath>
#include <iostream>

// ------- Everything that occurs during driver control (Driver controls)

int abs_sgn(double input) { return input / std::abs(input); }

// int previous_pot_value = 0;
// int rotation_count = 0;
// const int POT_MAX_VALUE = 4095;
// const int RESET_THRESHOLD = 100;

// int pot_init = rotation.get_value()-1500;

// int calculate_liftPosition() {
//   int current_pot = rotation.get_value();
//   if (previous_pot_value > POT_MAX_VALUE - RESET_THRESHOLD &&
//       current_pot < RESET_THRESHOLD) {
//     rotation_count++;
//   }
//   if (previous_pot_value < RESET_THRESHOLD &&
//       current_pot > POT_MAX_VALUE - RESET_THRESHOLD) {
//     rotation_count--;
//   }
//   previous_pot_value = current_pot;
//   return (rotation_count * POT_MAX_VALUE) + current_pot - pot_init;
// }

// void liftMacro() {
//   while (true) {
//     int lift_position = calculate_liftPosition() - 1500;
//     if (lift_position < 3500) {
//       lift.move(60);
//       delay(100);
//       // if(lift_position >= 2045){
//       //   intakeP.set_value(false);
//       //   pros::delay(100);
//       // }
//     } else {
//       lift.move(0);
//       intakeP.set_value(false);
//       break;
//     }
//     pros::delay(10);
//   }
// }
void driver() {

  // ----------- Driver Graph ---------- //

  double rPwr, lPwr, rAxis, lAxis, rawLAxis, rawRAxis;

  // deadzones (if value is less than 10, which is usually due to stick drift,
  // set it to 0)
  rawLAxis = controller.get_analog(ANALOG_LEFT_Y);
  rawRAxis = controller.get_analog(ANALOG_RIGHT_X);
  lAxis = abs(rawLAxis) <= 5 ? 0 : rawLAxis;
  rAxis = abs(rawRAxis) <= 5 ? 0 : rawRAxis;

  lPwr = lAxis + rAxis;
  rPwr = lAxis - rAxis;

  driver_move(lPwr, rPwr);

  // ----------- Vertical Intake Toggle --------- //

  static bool vtoggle_forward = false;
  static bool vtoggle_reverse = false;
  static bool vtoggle_stop = true;

  if (controller.get_digital_new_press(DIGITAL_DOWN)) {
    if (vtoggle_reverse) {
      vtoggle_forward = true;
      vtoggle_reverse = false;
      vtoggle_stop = false;
    } else if (!vtoggle_forward) {
      vtoggle_forward = true;
      vtoggle_stop = false;

    } else if (vtoggle_forward) {
      vtoggle_forward = false;
      vtoggle_reverse = false;
      vtoggle_stop = true;
    }
  }
  if (controller.get_digital_new_press(DIGITAL_B)) {
    if (vtoggle_forward) {
      vtoggle_reverse = true;
      vtoggle_forward = false;
      vtoggle_stop = false;
    } else if (!vtoggle_reverse) {
      vtoggle_reverse = true;
      vtoggle_stop = false;

    } else if (vtoggle_reverse) {
      vtoggle_forward = false;
      vtoggle_reverse = false;
      vtoggle_stop = true;
    }
  }

  // ----------- Vertical Intake Speed Con --------- //

  if (vtoggle_forward) {
    intake.move(127);
  } else if (vtoggle_reverse) {
    intake.move(-85);
  } else if (vtoggle_stop) {
    intake.move(0);
  } else {
    intake.move(0);
  }

  // ----------- First Stage Intake Con --------- //

  if (controller.get_digital(DIGITAL_R1) and vtoggle_reverse and
      not vtoggle_stop) {
    first_stage.move(80);
  } else if (controller.get_digital(DIGITAL_R1) and vtoggle_forward and
             not vtoggle_stop) {
    first_stage.move(127);
  } else if (controller.get_digital(DIGITAL_R1) and vtoggle_stop) {
    first_stage.move(127);
  } else if (controller.get_digital(DIGITAL_R2)) {
    first_stage.move(-127);
  } else {
    first_stage.move(0);
  }
  // ----------- Lift Con --------- //

  if (controller.get_digital(DIGITAL_L1)) {
    lift.move(127);
  } else if (controller.get_digital(DIGITAL_L2)) {
    lift.move(-127);
  } else {
    lift.move(0);
  }
  // static int jam_delay = 0;
  // if (jam_delay == 0 and abs(intake.get_actual_velocity()) < 5 and
  // (vtoggle_forward == true or vtoggle_reverse == true)){
  //   controller.rumble("......");
  //   vtoggle_forward = false;
  //   vtoggle_reverse = false;
  //   vtoggle_stop = true;
  //   jam_delay = 5000;
  // }

  // if (jam_delay > 0){
  //   jam_delay -= 2;
  // }

  // ----------- Piston Con --------- //

  static bool clampState = false;
  if (controller.get_digital_new_press(DIGITAL_Y)) {
    clampState = !clampState;
    clampP.set_value(clampState);
  }

  static bool tiltState = false;
  if (controller.get_digital_new_press(DIGITAL_RIGHT)) {
    tiltState = !tiltState;
    tiltP.set_value(tiltState);
  }

  // ----------- Incorporate with Scuffs --------- //

  static bool intakeState = false;
  if (controller.get_digital_new_press(DIGITAL_LEFT)) {
    intakeState = !intakeState;
    intakeP.set_value(intakeState);
  }

  if (controller.get_digital_new_press(DIGITAL_X)) {
    liftMacro();
    intakeP.set_value(false);
  }
}
