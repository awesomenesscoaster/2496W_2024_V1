#include "autons.h"
#include "main.h"
#include "movement.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"
#include "piston.h"

// ------- Everything that occurs during driver control (Driver controls)  ---------- //

int abs_sgn(double input) { return input / std::abs(input); }

void driver() {

  // ----------- Driver Graph ---------- //
  
  double rPwr, lPwr, rAxis, lAxis;
  
  lAxis = controller.get_analog(ANALOG_LEFT_Y);
  rAxis = controller.get_analog(ANALOG_RIGHT_X);

  lPwr = lAxis + rAxis;
  rPwr = lAxis - rAxis;

  driver_move(lPwr, rPwr);

  // ----------- Vertical Intake Toggle --------- //

  static bool vtoggle_forward = false;
  static bool vtoggle_reverse = false;
  
  if(not controller.get_digital(DIGITAL_DOWN)){
    if(controller.get_digital_new_press(DIGITAL_L1)){ 
        
        if (vtoggle_reverse){
            vtoggle_forward = true;
            vtoggle_reverse = false;
        }
        else{
            vtoggle_forward = true;
        }
    }
    if(controller.get_digital_new_press(DIGITAL_L2)){
        if (vtoggle_forward){
            vtoggle_reverse = true;
            vtoggle_forward = false;
        }
        else{
            vtoggle_reverse = true;
        }    
    }
    
  }
  else{
    // shift key whatever 

  }

  // ----------- Vertical Intake Speed Con --------- //

  if (vtoggle_forward){
      intake.move(127);
  }
  else if (vtoggle_reverse){
      intake.move(-127);
  }
  else{
      intake.move(0);
  }
  
  // ----------- First Stage Intake Con --------- //

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
