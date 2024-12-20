#include "robot.h"
#include "piston.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

// -------- All electronic definitions -------- //

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor lf(13, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lm(10, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES); 
pros::Motor lb(11, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rf(3, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 
pros::Motor rm(21, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 
pros::Motor rb(9, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES); 

pros::Motor_Group left({lf, lm, lb});
pros::Motor_Group right({rf, rm, rb});

pros::Motor first_stage(20, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES); 
pros::Motor intake(17, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor lift(15, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES); //change port on this

pros::IMU imu(16);

pros::Rotation rotation(14);

pros::ADIDigitalOut clampP(1, false);
pros::ADIDigitalOut intakeP(2, false);
pros::ADIDigitalOut spikeP(3, false);

pros::ADIDigitalOut blankP(6, false);