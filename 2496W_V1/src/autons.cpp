#include "auton_obj.h"
#include "movement.h"
#include "piston.h"
#include "robot.h"
#include "controls.h"
#include "robotpid.h"
using namespace pid;
// ---------- All autonomous routes --------- //f
using namespace pros;
/*
drive(2000, 2000, 1, 60 );

  intakeP.set_value(false);

  first_stage.move(127);
  intake.move(127);

  
  lift.move(40);
  delay(1000);
  lift.move(0);

  clampP.set_value(true);
  clampP.set_value(false);


*/


void flipout(){}

void rush_blue_left(){
  // drive(2000, 5000);
  // delay(1000);
  // drive(400, 5000);
  



  // turn(135, 5000);
  // delay(1000);
  // turn(165, 5000);
  // delay(2000);
  // turn(180, 5000);

  // drive(-1755, 850);  
  // turn_to(30, 450);
  // delay(10);
  // lift.move(0);

  // drive(-300, 600, 1, 60);
  // drive(-190, 300, 1, 30);

  
  // clampP.set_value(true);

  // drive(-60, 300, 3);
  // intakeP.set_value(true);

  // drive(200, 300, 1.5);
  // // tiltP.set_value(true);

  
  // delay(1000);
 
  // turn_to(-20, 2000, 1, 80);
  // lift.move(-50);
  // turn_to(-50, 800);  
  // lift.move(0);
  // intake.move(-40);
  // first_stage.move(-127);

  // delay(400);
  // intake.move(127);
  // first_stage.move(127);
  // drive(100, 50, 2);

  // delay(300);
  // drive(400, 500, 1, 70);

  // delay(300);
  // turn_to(-135, 700);
  // drive(-435, 900);
  // intake.move(-50);
  // delay(50);
  // // tiltP.set_value(false);
  // clampP.set_value(false);
  // delay(65);
  // intake.move(0);
  
  // turn_to(93.5, 750);
  // intake.move(0);
  // delay(200);
  
  // drive(-1000, 800, 1);
  
  // drive(-275, 800, 1, 35);
  // clampP.set_value(true);
  // delay(150);
  // // tiltP.set_value(true);
  // delay(400);
  // lift.move(17);
  // turn_to(-57, 1000);
  // intake.move(0);
  // intakeP.set_value(false);
  // delay(250);
  // lift.move(0);
  // drive(1215, 1000, 1, 80);
  
  // intakeP.set_value(true);
  // delay(250);
  // first_stage.move(127);
  // delay(75);
  // intake.move(127);
  // delay(200);
  // drive(-200, 300);
  
  // // turn_to(52, 400);
  // // drive(1200, 1000);
  // // drive(-1200, 1000);

  // turn_to(-135, 1000);
  // drive(200, 2000, 1, 30);

  // intake.move(0);
  
  
  // first_stage.move(-127);
  // pros::delay(5000);

}

void rush_red_right() {
  // lift.move(40);
  intakeP.set_value(true);
  drive(-2045, 1050);  
  
  turn_to(-11, 200);
  drive(-255, 350);
  clampP.set_value(true);
  delay(100);
  drive(400, 800);
  turn_to(110, 800);
  first_stage.move(127);
  intake.move(127);
  delay(300);
  drive(700, 800);
  turn_to(200, 500);
  intake.move(0);
  first_stage.move(-127);
  drive(-1500, 850);
  clampP.set_value(false);
  drive(400, 400);
  turn_to(-25, 800);
  delay(1000);
  
  // turn_to(-30, 450);
  // delay(10);
  // lift.move(0);
  // drive(-300, 600, 1, 60);
  // drive(-190, 300, 1, 30);

  
  // clampP.set_value(true);

  // drive(-60, 300, 3);
  // intakeP.set_value(true);

  // drive(200, 300, 1.5);
  // // tiltP.set_value(true);

  
  // delay(1000);
 
  // turn_to(20, 2000, 1, 80);
  // lift.move(-50);
  // turn_to(50, 800);
  // lift.move(0);
  // intake.move(-40);
  // first_stage.move(-127);

  // delay(400);
  // intake.move(127);
  // first_stage.move(127);
  // drive(100, 50, 2);

  // delay(300);
  // drive(400, 500, 1, 70);

  // delay(300);
  // turn_to(135, 700);
  // drive(-435, 900);
  // intake.move(-50);
  // delay(50);
  // // tiltP.set_value(false);
  // clampP.set_value(false);
  // delay(65);
  // intake.move(0);
  
  // turn_to(-93.5, 750);
  // intake.move(0);
  // delay(200);
  
  // drive(-1000, 800, 1);
  
  // drive(-275, 800, 1, 35);
  // clampP.set_value(true);
  // delay(150);
  // // tiltP.set_value(true);
  // delay(400);
  // lift.move(17);
  // turn_to(57, 1000);
  // intake.move(0);
  // intakeP.set_value(false);
  // delay(250);
  // lift.move(0);
  // drive(1215, 1000, 1, 80);
  
  // intakeP.set_value(true);
  // delay(250);
  // first_stage.move(127);
  // delay(75);
  // intake.move(127);
  // delay(200);
  // drive(-200, 300);
  
  // // turn_to(52, 400);
  // // drive(1200, 1000);
  // // drive(-1200, 1000);

  // turn_to(135, 1000);
  // drive(200, 2000, 1, 30);

  // intake.move(0);
  
  
  // first_stage.move(-127);
  // pros::delay(5000);
}

void awp_blue_right(){

} 

void awp_red_left(){
  lift.move(20);
  drive(-1800, 1000, 90);
  //clampP.set_value(true);
  
} 

void skills(){
  //goal 1
  intakeP.set_value(true);
  drive(250, 400);
  turn_to(-92, 800);
  drive(-1150, 1000);
  clampP.set_value(true);
  pros::delay(300);
  turn_to(0, 800);
  // intake.move(127);
  // pros::delay(300);
  // intake.move(-127);
  // pros::delay(150);
  intake.move(127);
  first_stage.move(127);
  pros::delay(300);

  //ring 1
  drive(850, 800);
  pros::delay(500);
  intake.move(-127);
  pros::delay(175);
  intake.move(127);
  pros::delay(250);
  turn_to(45, 800);
  
  //ring 2
  drive(1850, 1300);
  pros::delay(500);
  intake.move(-127);
  pros::delay(195);
  intake.move(127);
  pros::delay(250);
  turn_to(-165, 800);

  //ring 3
  drive(800, 600, 1.5);
  pros::delay(500);
  turn_to(150, 800);

  //ring 4
  drive(1050, 800, 1.5);
  intake.move(-127);
  pros::delay(195);
  intake.move(127);
  pros::delay(250);
  pros::delay(500);

  //ring 5 + 6
  drive(-500, 400);
  turn_to(-170, 800);
  drive(400, 400);
  pros::delay(500);
  drive(500, 500);
  pros::delay(500);
  
  //drop goal 1
  turn_to(-60, 800);
  drive(-1000, 600);
  clampP.set_value(false);

  //go to goal 2
  drive(600, 600);
  turn_to(90, 800);
  intake.move(-127);
  drive(-2700, 1500);
  turn_to(90, 800);
  drive(-400, 400);
  clampP.set_value(true);
  drive(-400, 400);
  turn_to(0, 800);

  intake.move(127);
  first_stage.move(127);
  pros::delay(300);

  // //ring 2-1
  // drive(850, 800);
  // pros::delay(500);
  // intake.move(-127);
  // pros::delay(175);
  // intake.move(127);
  // pros::delay(250);
  // turn_to(-45, 800);
  
  // //ring 2-2
  // drive(1850, 1300);
  // pros::delay(500);
  // intake.move(-127);
  // pros::delay(195);
  // intake.move(127);
  // pros::delay(250);
  // turn_to(165, 800);

  // //ring 2-3
  // drive(800, 600);
  // pros::delay(500);
  // turn_to(-150, 800);

  // //ring 2-4
  // drive(1050, 800);
  // intake.move(-127);
  // pros::delay(195);
  // intake.move(127);
  // pros::delay(250);
  // pros::delay(500);

  // //ring 2-5 + 2-6
  // drive(-500, 400);
  // turn_to(170, 800);
  // drive(400, 400);
  // pros::delay(500);
  // drive(500, 500);
  // pros::delay(500);
  
  // //drop goal 2
  // turn_to(60, 800);
  // drive(-1000, 600);
  // clampP.set_value(false);
}


void blank() {}



std::vector<Auton> autons{
  Auton("red rush right", rush_red_right, "create"),
  Auton("blue rush left", rush_blue_left, "tune"),
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
