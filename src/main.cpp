#include "opcontrol.h"
#include "main.h"
#include <cmath>
#include "botConfig.h"

#include "pros/motors.hpp"


//Smooth Driver CODE

/*Initializing local controls for model - controller, motors etc*/
pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::Motor leftBack(8, true);
pros::Motor rightBack(18);
pros::Motor leftMid(9, true);
pros::Motor rightMid(16);
pros::Motor leftFront(17, true);
pros::Motor rightFront(20);
    
    smoothDriver smoothDriver(2, leftBack, rightBack, leftMid, rightMid, leftFront, rightFront);




void initialize() { // Local Intialize function, which runs as soon as model begins
	pros::lcd::initialize();

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::delay(500);

    smoothDriver.resetDrive(); //Reset function allowing Code to be intiialized for use

}


void disabled() {}

void autonomous() {

    smoothDriver.runPIDTune(0.05); //Using the step count, the robot will tune up to that step of a decimal 
}


void competition_initialize() {}

void opcontrol() {

    pros::Controller master(pros::E_CONTROLLER_MASTER);

    smoothDriver.enableBraking(0.5, 0.5, pros::E_CONTROLLER_DIGITAL_A); //Declaring the breaking PID function, with its own seperate control
    
    while(true){
        smoothDriver.startDriver(); //Runs the curve control.
    }

    
    pros::delay(500);

    
}
