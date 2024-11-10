#include "autons.h"
#include "main.h"
#include "movement.h"
#include "piston.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"
#include "util.h"

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

void print_info_auton(int time, double error, double speed)
{
  if (time % 50 == 0 && time % 2000 != 0)
    controller.print(0, 0, "Error: %.2f : %.2f    ", error, speed);
  if (time % 100 == 0 && time % 150 != 0 && time % 2000 != 0)
    controller.print(1, 0, "%.2f : %.2f          ", imu.get_heading());
  if (time % 150 == 0 && time % 100 != 0 && time % 150 != 0 && time % 2000 != 0)
    controller.print(2, 0, "%.2f | %.0f       ", error, time);
}

void print_info(int counter, float chassis_temp, int lift_pos)
{
  if (counter % 50 == 0 && counter % 100 != 0 && counter % 150 != 0)
  {
    controller.print(0, 0, "C: %f   ", float(chassis_temp));
    // controller.print(0, 0, "Temps: %d , %d          ",
    // int(intake.get_temperature()), int(first_stage.get_temperature()));
    // controller.print(0, 0, "R: %d , %d, %d          ", int(rf.get_actual_velocity()), int(rm.get_actual_velocity()), int(rb.get_actual_velocity()));
  }
  if (counter % 100 == 0 && counter % 150 != 0)
  {
    controller.print(1, 0, "1: %d, 2: %d, L: %d          ", int(first_stage.get_temperature()), int(intake.get_temperature()), int(lift.get_temperature()));
    // controller.print(1, 0, "L: %d , %d, %d          ",
    // int(lf.get_actual_velocity()), int(lm.get_actual_velocity()),
    // int(lb.get_actual_velocity()));
  }
  if (counter % 150 == 0 && counter % 300 != 0)
  {
    controller.print(2, 0, "Lift pos: %d", lift_pos);
    
  }
}
void driver()
{

  // ----------- Driver Graph ---------- //
  double lift_pos = rotation.get_position();
  double rPwr, lPwr, rAxis, lAxis, rawLAxis, rawRAxis;

  // deadzones (if value is less than 10, which is usually due to stick drift,
  // set it to 0)
  rawLAxis = controller.get_analog(ANALOG_LEFT_Y);
  rawRAxis = controller.get_analog(ANALOG_RIGHT_X);
  lAxis = abs(rawLAxis) <= 10 ? 0 : rawLAxis;
  rAxis = abs(rawRAxis) <= 10 ? 0 : rawRAxis;

  lPwr = lAxis + rAxis;
  rPwr = lAxis - rAxis;

  driver_move(lPwr, rPwr);

  // ----------- Intake Con --------- //
  if (controller.get_digital(DIGITAL_R1) && controller.get_digital(DIGITAL_R2))
  {
    first_stage.move(-127);
    intake.move(-127);
  }
  else if (controller.get_digital(DIGITAL_R1))
  {
    first_stage.move(127);
    intake.move(127);
  }
  else if (controller.get_digital(DIGITAL_R2))
  { 
    first_stage.move(-127);
  }
  
  else
  {
    first_stage.move(0);
    intake.move(0);
  } 
  // ----------- Lift Con --------- //


  if (controller.get_digital(DIGITAL_L1))
  {
    if (lift_pos > 17500){
      lift.move(127);
    }
    else{
      lift.move(0);
    }
  }
  else if (controller.get_digital(DIGITAL_L2))
  { 
    lift.move(-127);
  }
  else
  {
    lift.move(0);
  }




  // if (controller.get_digital_new_press(DIGITAL_RIGHT))
  // {
  //   //lift macro 1 -- move to scoring height
  // }
  // if (controller.get_digital_new_press(DIGITAL_Y))
  // {
  //   //lift macro 2 -- move to height where i can intake onto goal
  // }

  // if (controller.get_digital_new_press(DIGITAL_DOWN))
  // {
  //   //lift macro 3 -- move to height where i can put ring on top? holder (1st ring)
  // }

  // if (controller.get_digital_new_press(DIGITAL_B))
  // {
  //   //lift macro 4 -- move to height where i can put ring on bottom? holder (2nd ring)
  // }
  static bool liftmacro = false;
  if (controller.get_digital_new_press(DIGITAL_RIGHT))
  {
    liftmacro = !liftmacro; 
  }

  if (liftmacro){
    if (lift_pos > 25700 && lift_pos < 27000){
      lift.move(0);
      liftmacro = false; 
    }
    else{
      if (lift_pos > 25700 && !(lift_pos < 27000a)){
        lift.move(70);
      }
      else{
        lift.move(0);
      }
    }
  }

  /*if (liftmacro){
    if (lift_pos > 24950 && lift_pos < 25100){
      lift.move(0);
      liftmacro = false; 
    }
    else{
      if (lift_pos > 24950 && !(lift_pos < 25100)){
        lift.move(70);
      }
      else{
        lift.move(-70);
      }
    }
  }*/




  // ----------- Piston Con --------- //

  static bool clampState = false;
  if (controller.get_digital_new_press(DIGITAL_DOWN))
  {
    clampState = !clampState;
    clampP.set_value(clampState);
  }

  static bool intakeState = false;
  if (controller.get_digital_new_press(DIGITAL_Y))
  {
    intakeState = !intakeState;
    intakeP.set_value(intakeState);
  }

  static bool spikeState = false;
  if (controller.get_digital_new_press(DIGITAL_B))
  {
    spikeState = !spikeState;
    spikeP.set_value(spikeState);
  }

}