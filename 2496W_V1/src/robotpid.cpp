#include "movement.h"
#include "main.h"
#include "robot.h"
#include "controls.h"
#include "piston.h"
#include <cmath>
#include "util.h"
#include <math.h>
#include <vector>

#include "pros/misc.h"
#include "pros/rtos.h"
#include <iostream>
#include <fstream>
#include <list>

namespace pid{
    double start_head = 0; 
    double end_head = 0;
    double global_heading;

    
    double rCount = 0;
    

    // void drive(double target_dist, int timeout=2000, double mult=1.0, double max_speed=127, pros::ADIDigitalOut pis = blankP, int piston_time = 0, int piston_open_time = 0, int exit_time=100)
    // {
    //     double drive_kp = 4.62646 * std::pow(fabs(target_dist), -0.689989) + 0.7; 

    //     //double drive_kp = 5;
    //     //NEW:
    //     // 4.62646 * std::pow(fabs(target_dist), -0.689989) + 0.107432 for 0
    //     // 2.04035 * std::pow(fabs(target_dist), -0.534162) + 0.0949831 for 2.5

    //     double drive_ki = 0; // 0.00049
    //     double drive_kd = 0.0005; //0 for good
    //     double imu_k = 2;
    //     // this changed nothing lmao 

    //     if (fabs(end_head) - fabs(imu.get_heading()) > 1) {
    //         start_head += end_head-imu.get_heading();
    //     }

    //     int starting = 180;
    //     start_head -= starting;
    //     imu.set_heading(starting);
    //     lf.tare_position();
    //     lm.tare_position();
    //     lb.tare_position();
    //     rf.tare_position();
    //     rm.tare_position();
    //     rb.tare_position();
    //     double chas_pos = (lm.get_position() + rm.get_position()) / 2;
    //     //Set Variables
    //     double target = target_dist + chas_pos;
    //     double error = target - chas_pos;
    //     double prev_error;
    //     double integral = 0;
    //     double kintegral = 0;
    //     double derivative = 0;
    //     double init_heading = imu.get_heading();
    //     double heading_error = 0;
    //     double error_range_time = 0;
    //     bool start_positive = target_dist >= 0 ? true : false;

    //     bool exit = false;
    //     bool same_error = false;

    //     int scaler = 100;
    //     int time = 0;
    //     pis.set_value(false);

    //     int piston_on_time = piston_time + piston_open_time;

    //     while (time < timeout)
    //     {
    //         if (time>piston_on_time) pis.set_value(false);
    //         else if (time>piston_time) pis.set_value(true);

    //         prev_error = error;
    //         chas_pos = (lm.get_position() + rm.get_position()) / 2;
    //         //P
    //         error = target - chas_pos;
    //         //I
    //         if(fabs(error)<30) {
    //             integral += error;
    //         }
    //         //D
    //         derivative = (error - prev_error) * 1000;

    //         //Correct sides, ensure heading stays same as beginning
    //         heading_error = init_heading - imu.get_heading();

    //         //PID
    //         double speed = mult * (error * drive_kp + integral * drive_ki + derivative * drive_kd);

    //         //Heading correction
    //         kintegral += heading_error;

    //         double correction = (kintegral * imu_k);

    //         //Cap speed and correction sum to max
    //         if (fabs(speed) + fabs(correction) > max_speed) 
    //         {
    //             double multiplier = max_speed/(fabs(speed) + fabs(correction));
    //             speed *= multiplier;
    //             correction *= multiplier;
    //         }

    //         //Exit Loop
    //         if (fabs(error) < 6) 
    //         {
    //             if(!exit)
    //                 exit = true;
    //             else
    //                 error_range_time++;
    //             if (exit_time <= error_range_time)
            
    //                 break;
    //         }
        

    //         //Keep sides moving the same distances
    //         // chas.spin_left(speed + correction * speed / 127.0);
    //         // chas.spin_right(speed - correction * speed / 127.0);
    //         spin_left(speed);
    //         spin_right(speed);

    //         //Logging
    //         print_info_auton(time, error, speed);
        
    //         //Prevent infinite loops
    //         pros::delay(1);
    //         time++;
    //     }
    //     spin_left(0);
    //     spin_right(0);
    //     double diff = imu.get_heading() - starting;
    //     if (fabs(diff)>2) {
    //         start_head+=diff;
    //     }

    //     end_head = imu.get_heading();

    //     global_heading += imu.get_heading() - starting;

    //     //pis.set(false);
    // }

     void drive(double target_dist, int timeout=2000, double mult=1.0, double max_speed=127, pros::ADIDigitalOut pis = blankP, int piston_time = 0, int piston_open_time = 0, int exit_time=100)
    {

        lf.tare_position();
        lm.tare_position();
        lb.tare_position();
        rf.tare_position();
        rm.tare_position();
        rb.tare_position();
        
        float encoder_average;
        float voltage;
        float curr_pos = 0;
        int count = 0;
        int printTimer = 0;
        float imuInit = imu.get_heading();
        float heading;
        double maxI = 200;
        double error = 0;

        double prev_error;
        double integral = 0;
        double kintegral = 0;
        double derivative = 0;
        
        double error_range_time = 0;


        double drive_kp = 4.62646 * std::pow(fabs(target_dist), -0.689989) + 0.22; 

        //double drive_kp = 5;
        //NEW:
        // 4.62646 * std::pow(fabs(target_dist), -0.689989) + 0.107432 for 0
        // 2.04035 * std::pow(fabs(target_dist), -0.534162) + 0.0949831 for 2.5

        double drive_ki = 0.053; // 0.00049
        double drive_kd = 2.8; //0 for good
        imuInit = imu.get_rotation();

        Timer t2000;
        while (true) {
            encoder_average = (lb.get_position() + rb.get_position()) / 2;

            // if (t2000.getTime()>piston_time) pis.set_value(false);
            // else if (t2000.getTime()>(piston_open_time + piston_time)) pis.set_value(true);

            heading = imuInit - imu.get_rotation();
            heading = heading*5;
            
            prev_error = error;
            error = target_dist - encoder_average;

            derivative = error - prev_error;

            if(fabs(error)<30) {
                integral += error;
            }

            if (integral > 0) {
            integral = std::min(integral, maxI);
            } else {
            integral = std::max(integral, -maxI);
            }

            double speed = mult * (error * drive_kp + integral * drive_ki + derivative * drive_kd);
            
            if (fabs(speed) > max_speed) {
                speed = max_speed * speed / std::abs(speed);
            }

            print_info_auton(t2000.getTime(), error, speed);

            spin_left(speed + heading);
            spin_right(speed - heading);

            if(t2000.getTime() > timeout){
                break;
            }

            if (std::abs(target_dist - encoder_average) <= 0.8) {
            count++;
            }
            if (count >= 10) {
            break;
            }
            pros::delay(10);
        }
        spin_left(0);
        spin_right(0);
        }

    
    double turn_f(double error)
    {
        return error / fabs(error) * (25 * log(0.25 * (fabs(error) + 4)) + 5);
    }

    void turn(double target_deg, int timeout=1000, bool early_exit = true, double multi=1.0, double max_speed=127, int exit_time=75, double tolerance = 0.8)
    {  
        
        // fix turns more/less than 180
        if (target_deg > 180) target_deg -= 360;
        else if (target_deg <= -180) target_deg += 360;

        
        double TURN_KP;
        double TURN_KI;
        double TURN_KD;

        TURN_KP = 4.6;
        TURN_KI = 1.05; 
        TURN_KD = 0.37;  

        
        if (fabs(target_deg) <= 185) 
        {
            TURN_KP = 4.6;
            TURN_KI = 1.05; 
            TURN_KD = 0.37;  
        }
        if (fabs(target_deg) < 150) { 
            TURN_KP = 4.75; //last=4.75//4.3, 4.5
            TURN_KI = 0.47; //last=.4//0.08, .1, .42
            TURN_KD = 0.33; //last=.26//.25, .26(earlier), .27(90)
        }
        if (fabs(target_deg) < 110){
            TURN_KP = 4.75; 
            TURN_KI = 0.47; 
            TURN_KD = 0.33; 
        }
        if (fabs(target_deg) < 65){
            TURN_KP = 4.28; 
            TURN_KI = 0.37; 
            TURN_KD = 0.32; 
        }

        int starting;

        if (fabs(end_head) - fabs(imu.get_heading()) > 1) {
            start_head += end_head-imu.get_heading();
        }
        if (target_deg > 150)
            starting = 30;
        else if (target_deg < -150)
            starting = 330;
        else
            starting = 180;
        
        imu.set_heading(starting);

        double target = target_deg + imu.get_heading();
        double error = target_deg;
        double prev_error;
        double integral = 0;
        double derivative = 0;
        double error_range_time;
        double early_exit_time = 0;

        bool exit = false;
        bool same_error = false;


        int time = 0;

        //int scaler = (target_deg<20 ? 1000 : 100);
        int scaler = 100;


        while (time<timeout)
        {
            double speed;
            prev_error = error;
            error = target - imu.get_heading();
            
            if (target_deg < 120){
                if(fabs(error) < 2){
                    integral += error / 100;
                }
            }
            else{
                if(fabs(error) < 2){
                    integral += error / 100;
                }
            }
            derivative = (error - prev_error) * 100;

            if (derivative){
                speed = error * TURN_KP + integral * TURN_KI + derivative * TURN_KD;
            }

            if (fabs(speed) > max_speed) 
            {
                double multiplier = max_speed/fabs(speed);
                speed *= multiplier;
            }

            if (fabs(error) < tolerance) // 0.15
            {
                if(!exit)
                    exit = true;
                else
                    error_range_time += 10;
                if (exit_time <= error_range_time)
                    break;
            }

            // if (fabs(error) < 2 && (std::round(prev_error * scaler) / scaler - std::round(error * scaler) / scaler < 0.02)) // 0.15
            // {
            //     if(!same_error)
            //         same_error = true;
            //     else
            //         early_exit_time += 10;
            //     if (exit_time <= early_exit_time)
            //         break;
            // }
            // if (target_deg > 0 && speed < 0 &&(-6<error && error<0.3)) speed *= K_BOOST;
            // else if (target_deg < 0 && speed > 0 && (0.3<error && error<6)) speed *= K_BOOST;

            spin_left(speed);
            spin_right(-speed);

           print_info_auton(time, error, speed); 


            pros::delay(10);
            time+= 10;
        }
        spin_left(0);
        spin_right(0);

        double diff = imu.get_heading() - starting;
        
        start_head+=diff;
        
        end_head = imu.get_heading();

        global_heading += imu.get_heading() - starting;
    }

    void turn_to(double degree_to, int timeout=1000, double multi=1.0, double max_speed=100, int exit_time=100, double tolerance = 0.15)
    {
        double degree = degree_to - global_heading;
        degree = (degree > 180) ? -(360 - degree) : ((degree < -180) ? (360 + degree) : (degree)); // optimize the turn direction
        //turn(degree, timeout, multi, max_speed, exit_time);
        turn(degree, timeout, true, multi, max_speed, exit_time, tolerance);
    }
    

    void spin_lift(double position, int timeout=2000, double max_speed=127, int exit_time=100){
        double lift_pos = rotation.get_position();

        
        double LIFT_KP;
        double LIFT_KI;
        double LIFT_KD;

        LIFT_KP = 4.6;
        LIFT_KI = 1.05; 
        LIFT_KD = 0.37;  

        double target = position + lift_pos; 
        double error = position;
        double prev_error;
        double integral = 0;
        double derivative = 0;
        double error_range_time;
        double early_exit_time = 0;

        double speed;

        bool exit = false;
        bool same_error = false;


        int time = 0;

        //int scaler = (target_deg<20 ? 1000 : 100);
        int scaler = 100;


        while (time < timeout)
        {
            double speed;
            prev_error = error;
            error = target - rotation.get_position();
            
            if(fabs(error) < 300){
                integral += error;
            }

    
            derivative = (error - prev_error) * 100;

            if (derivative){
                speed = error * LIFT_KP + integral * LIFT_KI + derivative * LIFT_KD;
            }


            if (fabs(error) < 200) // 0.15
            {
                if(!exit){
                    exit = true;
                }
                else{
                    error_range_time += 10;
                }
                if (exit_time <= error_range_time){
                    break;
                }
            }

            // if (fabs(error) < 2 && (std::round(prev_error * scaler) / scaler - std::round(error * scaler) / scaler < 0.02)) // 0.15
            // {
            //     if(!same_error)
            //         same_error = true;
            //     else
            //         early_exit_time += 10;
            //     if (exit_time <= early_exit_time)
            //         break;
            // }
            // if (target_deg > 0 && speed < 0 &&(-6<error && error<0.3)) speed *= K_BOOST;
            // else if (target_deg < 0 && speed > 0 && (0.3<error && error<6)) speed *= K_BOOST;

            lift.move(speed);

           print_info_auton(time, error, speed); 


            pros::delay(10);
            time+= 10;
        }
        lift.move(0);

    }


    

}