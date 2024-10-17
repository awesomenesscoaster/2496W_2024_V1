#include "auton_obj.h"
#include "movement.h"
#include "piston.h"
#include "robot.h"
#include "controls.h"
#include "robotpid.h"
using namespace pid;
// ---------- All autonomous routes --------- //f
using namespace pros;

void flipout(){
  lift.move(127);
  pros::delay(100);
  lift.move(0);
  intakeP.set_value(true);
  drive(300, 200, 2);
  drive(-300, 200, 2);
  pros::delay(100);
  lift.move(-127);
  pros::delay(400);
  lift.move(0);

}

void rush_blue_left(){
  drive(-1700, 800);
  lift.move(35);
  turn_to(31, 450);
  lift.move(0);
  drive(-450, 500, 1, 60);
  intakeP.set_value(true);
  drive(-150, 200, 1, 22);
  clampP.set_value(true);
  delay(150);
  
  drive(300, 300);
  lift.move(-40);
  
  tiltP.set_value(true);
  delay(100);
  turn_to(-62, 1000);
  lift.move(0);
  intake.move(127);
  first_stage.move(127);
  drive(400, 1000, 1, 70);
  delay(100);
  first_stage.move(-127);
  turn_to(-135, 700);
  drive(-425, 900);
  intake.move(0);
  tiltP.set_value(false);
  clampP.set_value(false);
  
  delay(200);
  turn_to(90.5, 750);
  delay(600);
  drive(-1000, 800, 1);
  drive(-200, 800, 1, 30);
  clampP.set_value(true);
  delay(350);
  tiltP.set_value(true);
  delay(50);
  lift.move(45);
  turn_to(-44, 700);
  intake.move(0);
  delay(10);
  intakeP.set_value(false);
  delay(50);
  lift.move(0);
  drive(1235, 800);
  delay(200);
  
  intakeP.set_value(true);
  delay(300);
  first_stage.move(127);
  intake.move(127);
  delay(800);
  drive(-200);
  pros::delay(200);
  first_stage.move(-127);  
  turn_to(52, 1000);
  first_stage.move(127);
  intake.move(127);
  drive(1700, 1000);
  drive(-1000, 1000);
  turn_to(-135, 1000);
  drive(1000, 800);


  
  // first_stage.move(-127);
  // pros::delay(5000);

}

void far_left() {
 // alice do pid here
  // drive(100);
  // delay(100);
  drive(1000, 4000);
  // delay(200);
  // drive(1000);
  // turn_to(90);
  // pros::delay(500);
  // turn_to(45);
  // pros::delay(500);
  // turn_to(15);
  // pros::delay(500);
  // turn_to(0);
  // delay(500);
  // turn_to(105);
  // delay(500);
  // turn_to(180);
  // delay(500);
  // turn_to(150);
  
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
  Auton("blue rush left", rush_blue_left, ""),
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
