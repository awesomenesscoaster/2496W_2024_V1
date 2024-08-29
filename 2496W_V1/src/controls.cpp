#include "autons.h"
#include "main.h"
#include "movement.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"

// ------- Everything that occurs during driver control (Driver controls)  ---------- //

int abs_sgn(double input) { return input / std::abs(input); }

void driver() {

  // ----------- Driver Graph ---------- //
  float rPwr, lPwr, rAxis, lAxis;

  lAxis = controller.get_analog(ANALOG_LEFT_Y);
  rAxis = controller.get_analog(ANALOG_RIGHT_Y);

  rPwr = rAxis; // math happens here
  lPwr = lAxis;

  driver_move(lPwr, rPwr);

  // ----------- Intake --------- //

  if (controller.get_digital(DIGITAL_L1)){
    intake.move(127);
  } 
  else if (controller.get_digital(DIGITAL_L2)){
    intake.move(-127);
  } 
  else{
    intake.move(0);
  }

  if (controller.get_digital(DIGITAL_R1)){
    first_stage.move(127);
  } 
  else if (controller.get_digital(DIGITAL_R2)){
    first_stage.move(-127);
  } 
  else{
    first_stage.move(0);
  }


  
}
