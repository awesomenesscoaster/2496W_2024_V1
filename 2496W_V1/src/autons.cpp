#include "auton_obj.h"
#include "movement.h"
#include "piston.h"
#include "robot.h"
#include "controls.h"
#include "robotpid.h"
using namespace pid;
// ---------- All autonomous routes --------- //f

void far_left() {
 // alice do pid here
  drive(1000);
  // turn_to(90);
}

void close_right() { 
  driver_move(-80, -80);
  pros::delay(800);
  driver_move(-15, -15);
  tiltP.set_value(true);
  pros::delay(200);
  driver_move(0, 0);

}

void close_left() {
  spin_right(127);
  pros::delay(100);
  spin_right(0);
}

void far_right() { 
  rf.move(100); 
}

void AWP_red(){

}

void AWP_blue(){

}

void blank() {}



std::vector<Auton> autons{
  Auton("far left", far_left, "done"),
  Auton("No Auton", blank, ""),
  Auton("close left", close_left, "done"),
  Auton("far right", far_right, "done"),
  Auton("close right", close_right, "done"),
  Auton("red awp", AWP_red, "tune"),
  Auton("blue awp", AWP_blue, "test")
  
};

Auton auton_selector(std::vector<Auton> autons) {
  short int selected = 0;
  int timer = 0;

  while (true) {
    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
      if (timer % 50 == 0 && timer % 100 != 0) {
        controller.print(0, 0, "Select: %s         ",
                         autons.at(selected).get_name());
      }
      //   if (timer % 100 == 0){
      //     controller.print(1, 0, "%s            ",
      //     autons.at(selected).get_d());
      //   }
      if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT) &&
          selected > 0) {
        selected--;
      }
      if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT) &&
          selected < autons.size() - 1) {
        selected++;
      }
    } else {
      pros::delay(50);
      controller.clear();
      pros::delay(50);
      controller.print(0, 0, "selected:         ");
      pros::delay(50);
      // glb::con.print(0, 0, "Selected           ");
      controller.print(1, 0, "auton: %s         ",
                       autons.at(selected).get_name());
      //   pros::delay(50);
      // glb::con.print(0, 0, "Selected           ");
      //   controller.print(2, 0, "%s             ",
      //   autons.at(selected).get_d());
      pros::delay(800);
      controller.clear();
      return autons.at(selected);
    }

    pros::delay(1);
    timer++;
  }
}
