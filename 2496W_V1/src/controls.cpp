#include "autons.h"
#include "main.h"
#include "movement.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"
#include "piston.h"


#include "auton_obj.h"
#include <iostream>
#include <cmath>

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
    intake.move(-98);
  }
  else if (vtoggle_stop){
    intake.move(0);
  }
  else{
    intake.move(0);
  }
  
  // ----------- First Stage Intake Con --------- //

  if (controller.get_digital(DIGITAL_R1) and vtoggle_reverse and not vtoggle_stop){
    first_stage.move(100);
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

  static bool hangState = false;
  if (controller.get_digital_new_press(DIGITAL_X)){
    hangState = !hangState;
    hangP.set_value(hangState);
  }

  static bool intakeState = true;
  if (controller.get_digital_new_press(DIGITAL_LEFT)){
    intakeState = !intakeState;
    intakeP.set_value(intakeState);
  }

}

Auton auton_selector(std::vector<Auton> autons)
{
  short int selected = 0;
  int timer = 0;

  while(true)
  {
      if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_A))
      {
          if(timer % 50 == 0 && timer % 100 != 0) 
              controller.print(0, 0, "Select: %s         ", autons.at(selected).get_name());
          if(timer % 100 == 0) 
              controller.print(1, 0, "%s            ", autons.at(selected).get_d());
          if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT) && selected > 0)
              selected--;
          if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT) && selected < autons.size()-1)
              selected++;
      }
      else
      {
          pros::delay(50);
          controller.clear();
          pros::delay(50);
          controller.print(0, 0, "selected:         "); 
          pros::delay(50);
          //glb::con.print(0, 0, "Selected           ");   
          controller.print(1, 0, "auton: %s         ", autons.at(selected).get_name());   
          pros::delay(50);
          //glb::con.print(0, 0, "Selected           ");   
          controller.print(2, 0, "%s             ", autons.at(selected).get_d()); 
          pros::delay(800);
          controller.clear();
          return autons.at(selected);
      }

      pros::delay(1);
      timer++;
  }
}