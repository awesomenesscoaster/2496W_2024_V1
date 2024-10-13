#include "auton_obj.h"
#include "movement.h"
#include "piston.h"
#include "robot.h"


// ---------- All autonomous routes --------- //f

void far_left() {
  spin_right(127);
  pros::delay(100);
  spin_right(0);
}

void close_right() { rf.move(100); }

std::vector<Auton> autons{Auton("far left", far_left, "none"),
                          Auton("close right", close_right, "none")

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
