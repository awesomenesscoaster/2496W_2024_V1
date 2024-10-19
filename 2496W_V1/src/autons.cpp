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
  drive(-1730, 850);
  lift.move(30);
  turn_to(33.5, 450);
  lift.move(0);
  drive(-395, 600, 1, 60);
  drive(-75, 300, 1, 30);

  
  clampP.set_value(true);
  intakeP.set_value(true);
  delay(25);

  drive(200, 300);
  tiltP.set_value(true);

  
  delay(100);
  turn_to(-20, 800);
  turn_to(-49, 800);

  intake.move(-40);
  first_stage.move(-127);
  lift.move(-50);
  delay(100);
  lift.move(0);
  delay(300);
  intake.move(127);
  first_stage.move(127);
  drive(100, 50, 2);

  delay(300);
  drive(400, 500, 1, 70);

  delay(300);
  turn_to(-135, 700);
  drive(-432, 900);
  intake.move(-50);
  delay(50);
  tiltP.set_value(false);
  clampP.set_value(false);
  delay(65);
  intake.move(0);
  
  turn_to(93.5, 750);
  intake.move(0);
  delay(200);
  
  drive(-1000, 800, 1);
  
  drive(-200, 800, 1, 30);
  clampP.set_value(true);
  delay(50);
  tiltP.set_value(true);
  delay(300);
  lift.move(25);
  turn_to(-65, 1000);
  intake.move(0);
  intakeP.set_value(false);
  delay(250);
  lift.move(0);
  drive(1235, 1000, 1, 80);
  
  intakeP.set_value(true);
  delay(250);
  first_stage.move(127);
  delay(75);
  intake.move(127);
  delay(200);
  drive(-200, 300);
  
  // turn_to(52, 400);
  // drive(1200, 1000);
  // drive(-1200, 1000);

  turn_to(-135, 1000);

  drive(500, 1000);
  intake.move(0);
  
  // first_stage.move(-127);
  // pros::delay(5000);

}

void rush_red_right() {


}

void awp_blue_right(){

} 

void awp_red_left(){
  
} 

void skills(){
  //Flipout + 1st Ring
  lift.move(35);
  drive(-250, 800, 1, 20);
  lift.move(0);
  clampP.set_value(true);
  pros::delay(200);
  drive(180, 200);
  tiltP.set_value(true);
  first_stage.move(127);
  pros::delay(700);
  turn_to(-56.5, 800);
  intakeP.set_value(true);
  pros::delay(200);
  intake.move(127);
  pros::delay(900);
  intake.move(-75);
  pros::delay(150);
  intake.move(127);
  pros::delay(200);
  drive(650, 950, 1, 60);
  pros::delay(1000);
  intake.move(0);

  //3 + 4
  intakeP.set_value(false);
  turn_to(-152, 800);
  lift.move(-65);
  pros::delay(400);
  lift.move(0);
  intakeP.set_value(true);
  pros::delay(200);
  intake.move(127);
  pros::delay(200);
  drive(500, 500, 1.7);
  pros::delay(400);
  turn_to(170, 800);
  drive(1350, 900);
  pros::delay(400);
  turn_to(-58, 800);
  lift.move(60);
  pros::delay(150);
  lift.move(0);
  drive(1500, 1000, 1.5);
  pros::delay(400);
  turn_to(20, 800);
  drive(2000, 1200);

}


void blank() {}



std::vector<Auton> autons{
  Auton("blue rush left", rush_blue_left, "tune"),
  Auton("red rush right", rush_red_right, "create"),
  Auton("blue awp right", awp_blue_right, "create"),
  Auton("red awp left", awp_red_left, "create"),
  Auton("skills", skills, "create"),
  Auton("No Auton", blank, "")

  
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
