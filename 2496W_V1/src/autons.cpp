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

void flipout() {}

void rush_blue_left() {

  // lift.move(40);
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
  drive(500, 2000, 1, 75);
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
  drive(-1930, 950);

  turn_to(-21, 600);
  drive(-280, 350);
  delay(100);
  clampP.set_value(true);
  delay(200);
  drive(310, 800);
  turn_to(85, 800);
  delay(300);
  first_stage.move(127);
  intake.move(127);
  delay(700);
  intake.move(-127);
  delay(300);
  intake.move(127);
  drive(650, 800);
  delay(200);
  turn_to(200, 800);
  intake.move(-127);
  first_stage.move(-127);

  drive(-2000, 1050);

  delay(100);
  clampP.set_value(false);

  drive(290, 400);
  turn_to(-17, 900);
  drive(-760, 800);
  delay(50);
  clampP.set_value(true);
  delay(100);
  turn_to(62, 600);
  first_stage.move(127);
  intake.move(127);
  intakeP.set_value(false);
  drive(920, 900);
  intakeP.set_value(true);
  delay(750);
  drive(-200, 400);
  delay(200);

  turn_to(148, 900);
  delay(100);
  drive(500, 2000, 1, 75);

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
  drive(250, 400);
  turn_to(-90, 800);
  drive(-650, 1000);
  turn_to(-94, 200);
  drive(-100, 800, 1, 30);
  clampP.set_value(true);
  drive(-300, 400);
  pros::delay(300);
  turn_to(0, 800);

  // intake.move(127);
  // pros::delay(300);
  // intake.move(-127);
  // pros::delay(150);
  // ring 1
  intake.move(127);
  first_stage.move(127);
  pros::delay(300);

  intake.move(-127);
  delay(200);
  intake.move(127);

  // ring 2
  drive(850, 800);
  pros::delay(500);
  intake.move(-127);
  pros::delay(175);
  intake.move(127);
  pros::delay(250);
  drive(200, 400);
  turn_to(90, 800);

  // ring 3
  drive(1200, 1300);

  // pros::delay(500);
  // intake.move(-127);
  // pros::delay(195);
  // intake.move(127);
  // pros::delay(250);
  // turn_to(-165, 800);

  // //ring 3
  // drive(800, 600, 1.5);
  // pros::delay(500);
  turn_to(150, 800);
  intake.move(-127);
  pros::delay(195);
  intake.move(127);

  // ring 4
  drive(950, 800, 1.5);
  pros::delay(500);
  intake.move(-127);
  pros::delay(200);
  intake.move(127);

  // ring 5 + 6
  drive(-1300, 400);
  turn_to(-180, 800);
  drive(600, 400);
  pros::delay(500);
  drive(800, 500);
  pros::delay(700);

  // drop goal 1
  turn_to(-80, 800);
  drive(-650, 600);
  intake.move(-127);
  clampP.set_value(false);
  pros::delay(300);

  // go to goal 2
  drive(1500, 1000);
  delay(400);
  intake.move(0);
  turn_to(90, 1000);
  delay(2000);
  drive(-1300, 2000);
  delay(200);
  turn_to(87, 200);
  drive(-600, 1000, 1, 70);
  delay(200);
  clampP.set_value(true);
  intake.move(127);
  drive(-300, 400);

  // ring 2-1
  turn_to(0, 800);
  drive(900, 800);
  pros::delay(500);
  intake.move(-127);
  pros::delay(175);
  intake.move(127);
  pros::delay(250);
  turn_to(-50, 800);

  // ring 2-2
  drive(1900, 1300);
  pros::delay(500);
  intake.move(-127);
  pros::delay(195);
  intake.move(127);
  pros::delay(250);
  turn_to(160, 800);

  // ring 2-3
  drive(800, 600);
  pros::delay(500);
  turn_to(-153, 800);

  // ring 2-4
  drive(1050, 800);
  intake.move(-127);
  pros::delay(195);
  intake.move(127);
  pros::delay(250);
  pros::delay(500);

  // ring 2-5 + 2-6
  drive(-600, 400);
  turn_to(170, 800);
  drive(400, 400);
  pros::delay(500);
  drive(500, 500);
  pros::delay(500);

  // drop goal 2
  turn_to(60, 800);
  drive(-1000, 600);
  clampP.set_value(false);

  // turn_to(87, 600);
  // drive(-1300, 800);
  // clampP.set_value(true);
  // drive(-400, 400);
  // turn_to(0, 800);

  // intake.move(127);
  // first_stage.move(127);
  // pros::delay(300);

  /*


  //goal 1
  intakeP.set_value(true);
  drive(250, 400);
  turn_to(-91, 800);
  drive(-800, 1000);
  clampP.set_value(true);
  drive(-300, 400);
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
  drive(1900, 1300);
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
  pros::delay(700);

  //drop goal 1
  turn_to(-60, 800);
  drive(-1000, 600);
  clampP.set_value(false);
  pros::delay(300);

  //go to goal 2
  drive(400, 400);
  turn_to(90, 1000);
  drive(-1500, 1000);
  turn_to(87, 600);
  drive(-1300, 800);
  clampP.set_value(true);
  drive(-400, 400);
  turn_to(0, 800);

  intake.move(127);
  first_stage.move(127);
  pros::delay(300);

  */
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
