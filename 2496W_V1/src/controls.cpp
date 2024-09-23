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
  static bool vtoggle_stop = true;
  
  
  if(controller.get_digital_new_press(DIGITAL_DOWN)){ 
      if (vtoggle_reverse){
        vtoggle_forward = true;
        vtoggle_reverse = false;
        vtoggle_stop = false; 
      }
      else if (!vtoggle_forward){
        vtoggle_forward = true;
        vtoggle_stop = false; 
        
      }
      else if (vtoggle_forward){
        vtoggle_forward = false;
        vtoggle_reverse = false;
        vtoggle_stop = true;
      }
  }
  if(controller.get_digital_new_press(DIGITAL_B)){
      if (vtoggle_forward){
        vtoggle_reverse = true;
        vtoggle_forward = false;
        vtoggle_stop = false; 
      }
      else if (!vtoggle_reverse){
        vtoggle_reverse = true;
        vtoggle_stop = false; 
        
      }
      else if (vtoggle_reverse){
        vtoggle_forward = false;
        vtoggle_reverse = false;
        vtoggle_stop = true;
      }    
  }
  


  // ----------- Vertical Intake Speed Con --------- //

  if (vtoggle_forward){
    intake.move(127);
  }
  else if (vtoggle_reverse){
    intake.move(-80);
  }
  else if (vtoggle_stop){
    intake.move(0);
  }
  else{
    intake.move(0);
  }
  
  // ----------- First Stage Intake Con --------- //

  if (controller.get_digital(DIGITAL_R1) and vtoggle_reverse and not vtoggle_stop){
    first_stage.move(60);
  } 
  else if (controller.get_digital(DIGITAL_R1) and vtoggle_forward and not vtoggle_stop){
    first_stage.move(127);
  } 
  else if (controller.get_digital(DIGITAL_R1) and vtoggle_stop){
    first_stage.move(127);
  }
  else if (controller.get_digital(DIGITAL_R2)){
    first_stage.move(-127);
  } 
  else{
    first_stage.move(0);
  }
  // ----------- Lift Con --------- //

  if (controller.get_digital(DIGITAL_L1)){
    lift.move(127);
  } 
  else if (controller.get_digital(DIGITAL_L2)){
    lift.move(-127);
  } 
  else{
    lift.move(0);
  }

  // ----------- Piston Con --------- //

  static bool clampState = false;
  if (controller.get_digital_new_press(DIGITAL_Y)){
    clampState = !clampState;
    clampP.set_value(clampState);
  }

  static bool tiltState = false;
  if (controller.get_digital_new_press(DIGITAL_RIGHT)){
    tiltState = !tiltState;
    tiltP.set_value(tiltState);
  }

  // ----------- Incorporate with Scuffs --------- //

  static bool liftState = false;
  if (controller.get_digital_new_press(DIGITAL_X)){
    liftState = !liftState;
    liftP.set_value(liftState);
  }

  static bool intakeState = true;
  if (controller.get_digital_new_press(DIGITAL_LEFT)){
    intakeState = !intakeState;
    intakeP.set_value(intakeState);
  }

}

  
void rotation_val(int time){

  // ----------- Rotation Get Value --------- //

  if (time % 4 == 0){
    
    int lift_pos = rotation.get_position();
    controller.print(0, 0, "Lift pos: %d", lift_pos);
  
  }
  
}

