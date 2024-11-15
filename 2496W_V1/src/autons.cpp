#include "auton_obj.h"
#include "controls.h"
#include "movement.h"
#include "piston.h"
#include "robot.h"
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

void contingency() {
  intake.move(-127);
  delay(300);
  intake.move(127);
}

void rush_blue_left() {
   // lift.move(40);
  intakeP.set_value(true);
  drive(-1810, 1100);
  turn_to(23, 800);
  drive(-690, 900);
  delay(300);
  clampP.set_value(true);
  delay(150);
  drive(310, 800);
  first_stage.move(127);
  turn_to(-45, 800);
  intake.move(127);
  drive(200, 200);
  delay(300);

  delay(700);
  intake.move(-127);
  delay(300);
  intake.move(127);
  drive(650, 800);
  delay(200);
  turn_to(-200, 800);
  intake.move(-127);
  first_stage.move(-127);

  drive(-1300, 1050);

  delay(100);
  clampP.set_value(false);

  drive(75, 400);
  turn_to(25, 900);
  drive(-800, 800);
  drive(-100, 100, 1, 40);
  delay(50);
  clampP.set_value(true);
  delay(200);
  drive(100, 200);
  turn_to(-63, 600);
  first_stage.move(127);
  intake.move(127);
  intakeP.set_value(false);
  turn_to(-70, 400);
  drive(1000, 900);
  intakeP.set_value(true);
  delay(750);


  drive(-500, 500);
  

  // turn_to(-90, 900);
  // drive(-200, 400);
  // delay(200);

  // drive(-1200, 2000);
  // turn(135, 900);
  // delay(100);

  /*// lift.move(40);
  intakeP.set_value(true);
  drive(-1930, 950);

  turn_to(21, 600);
  drive(-280, 350);
  delay(100);
  clampP.set_value(true);
  delay(200);
  drive(310, 800);
  turn_to(-85, 800);
  delay(300);
  first_stage.move(127);
  intake.move(127);
  delay(800);
  intake.move(-127);
  delay(300);
  intake.move(127);
  drive(650, 800);
  delay(400);
  turn_to(-200, 800);
  intake.move(-127);
  first_stage.move(-127);

  drive(-2000, 1050);

  delay(100);
  clampP.set_value(false);

  drive(290, 400);
  turn_to(17, 900);
  drive(-715, 800);
  delay(50);
  clampP.set_value(true);
  delay(100);
  turn_to(-62, 600);
  first_stage.move(127);
  intake.move(127);
  intakeP.set_value(false);
  drive(920, 900);
  intakeP.set_value(true);
  delay(850);
  drive(-200, 400);
  delay(600);

  turn_to(-148, 900);
  delay(200);
  drive(500, 2000, 1, 75);*/
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

  // lift.move(40);
  intakeP.set_value(true);
  drive(-1850, 1250, 1.53);
  turn_to(-25, 900);
  drive(-200, 150, 1.5);
  drive(-325, 400, 1, 60);
  delay(20);
  clampP.set_value(true);
  delay(100);
  drive(310, 900);
  first_stage.move(127);
  turn_to(40, 800);
  intake.move(127);
  drive(200, 200);

  delay(600);
  intake.move(-127);
  delay(200);
  intake.move(127);
  drive(550, 800);
  delay(200);
  turn_to(200, 800);
  

  drive(-1300, 1050, 2);
  intake.move(-127);
  first_stage.move(-127);

  delay(50);
  clampP.set_value(false);

  drive(10, 100);
  turn_to(-26, 900);
  drive(-500, 400);
  turn_to(-22, 200);
  drive(-600, 500, 1, 40);
  delay(20);
  clampP.set_value(true);
  delay(50);
  drive(50, 50);
  turn_to(67, 600);
  first_stage.move(127);
  intake.move(127);
  intakeP.set_value(false);
  drive(1050, 900, 3);
  intakeP.set_value(true);
  delay(400);
  drive(-300, 200);
  turn_to(145, 400);
  drive(600, 500, 2);

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

void awp_blue_right() {

  drive(200, 400);

  turn_to(-36, 1000);
  drive(-1510, 1500);
  intakeP.set_value(true);
  delay(100);
  drive(-300, 400);

  clampP.set_value(true);
  delay(400);
  first_stage.move(127);
  intake.move(127);
  drive(-200, 500);
  delay(600);
  turn_to(-90, 500);
  intake.move(-127);
  delay(100);
  intake.move(127);
  drive(950, 900);
  delay(300);
  drive(-50, 200);
  turn_to(-178, 600);
  intake.move(-127);
  delay(500);
  intake.move(127);
  drive(600, 800, 1, 90);
  delay(200);
  drive(-300, 400);
  delay(200);
  turn_to(-155, 600);
  intake.move(-127);
  delay(500);
  intake.move(127);
  drive(400, 500, 1, 90);
  delay(100);
  drive(-400, 400);
  delay(300);
  turn_to(-230, 600);
  drive(675, 2000, 1, 55);
  intake.move(0);
  first_stage.move(0);
  // lift.move(20);
  // drive(-1800, 1000, 90);
  // //clampP.set_value(true);
}

void awp_red_left() {
  drive(200, 400);

  turn_to(36, 1000);
  drive(-1510, 1500);
  intakeP.set_value(true);
  delay(100);
  drive(-300, 400);

  clampP.set_value(true);
  delay(400);
  first_stage.move(127);
  intake.move(127);
  drive(-200, 500);
  delay(600);
  turn_to(90, 500);
  intake.move(-127);
  delay(100);
  intake.move(127);
  drive(950, 900);
  delay(300);
  drive(50, 200);
  turn_to(-178, 600);
  intake.move(-127);
  delay(500);
  intake.move(127);
  drive(600, 800, 1, 90);
  delay(200);
  drive(-300, 400);
  delay(200);
  turn_to(155, 600);
  intake.move(-127);
  delay(500);
  intake.move(127);
  drive(400, 500, 1, 90);
  delay(100);
  drive(-400, 400);
  delay(300);
  turn_to(230, 600);
  drive(675, 2000, 1, 55);
  intake.move(0);
  first_stage.move(0);
  // lift.move(20);
  // drive(-1800, 1000, 90);
  // //clampP.set_value(true);
}

void skills() {

  // goal 1
  intakeP.set_value(true);
  drive(290, 600);
  turn_to(-89, 1000);
  drive(-700, 1000);
  delay(400);
  clampP.set_value(true);
  drive(-200, 400);
  pros::delay(300);
  turn_to(0, 800);

  // ring 1
  intake.move(127);
  first_stage.move(127);
  pros::delay(600);
  contingency();


  // ring 2
  drive(850, 800, 2);
  pros::delay(1000);
  contingency();
  pros::delay(150);
  drive(240, 400);
  turn_to(90, 800);
  
  drive(1000, 800, 1.75);
  delay(600);
  drive(720, 600);
  contingency();
  turn_to(179, 800);
  drive(1100, 800);
  delay(600);
  contingency();
  delay(100);
  turn_to(160, 800);
  drive(-1200, 1000);
  turn_to(-181, 800);

  drive(1100, 1000);
  pros::delay(1000);
  contingency();
  drive(600, 700);
  pros::delay(1000);
  contingency();
  turn_to(-55, 800);
  drive(-300, 400);
  clampP.set_value(false);
  drive(-300, 600);
  turn_to(-60, 500);
  drive(965, 900);
  turn_to(90, 900);
  drive(-1500, 1200);
  turn_to(89.5, 900);
  drive(-900, 1200);
  delay(200);
  clampP.set_value(true);
  
  drive(-400, 500);
  turn_to(0, 800);
  intake.move(127);
  delay(400);
  drive(825, 1000);
  pros::delay(1000);
  contingency();
  pros::delay(150);
  drive(225, 400);
  

}

void blank() {}

std::vector<Auton> autons{Auton("red awp left", awp_red_left, "create"),
                          Auton("red rush right", rush_red_right, "create"),
                          Auton("blue rush left", rush_blue_left, "tune"),
                          Auton("blue awp right", awp_blue_right, "create"),
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
