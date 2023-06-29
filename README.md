# **The Official Helios Code**

The Code for the Helios Rover, incorprating the Smooth Driver library, designed by team Helios. Please see the Src Folder for the main C++ Files.

Version: 0.5.0

## Autonomous Control

### Self Tuning PID

The Smooth Driver Control also comes with a self tuning PID, using a combination of a hill climbing optimization algorithm and the Zieger-Nichols Tuning method. This is a function that can be run on any surface, and will output the rough PID constants.

### Adaptive PID

The above algorithm can be paired with the adaptive PID control algorithm. This utilizes an RLS control algorithm to constantly tune the PID values dependant on the robots overshoot and resistance it faces while driving.

### Odometry Algorithm and HectorSLAM

Combining a high level Odometry algorithm and HectorSLAM, the robot is able to map the two dimensional plane that it travels on, in distance and position, and can relay this back to a control system


## Driver Control

Currently, smoothDriver only supports tank drive controls. The smoothDriver uses a double-S curve drive for its control, with two variables that are able to be adjusted according to user preference. You can find the mathematics of the positive curve [here.](https://www.desmos.com/calculator/oldghlasqy)
The negative version is a reflection of this in the negative quadrant.

Note you do not need to tune your active braking or curve K and A values, and can instead skip to starting the driver control.

### K and A values
The curve above has two indicators, the K value and the A value. The K value acts as the gradient, and shouldn't be less than 0. The A value defines the gradient of the tail of the curve - if you increase K, you need to increase A to ensure your robot doesn't stop driving at certain positions. You do not need to adjust this, but may wish to dependant on your drive curve.

Tune your k and a values according to the curve, using `smoothDriver.setKcurve(newK)` and  `smoothDriver.setAcurve(newA)`, replacing newK and newA with a double of your choice. The default is 0.1 and 0.4 respectively.

### Active Braking PD Lock

While in driver control mode, the robot can be designed to engage in an active brake lock, using a P and D value for the system. The purpose of this is to push back against any robot that may be pushing at you. You may need to tune these, although since it is in braking, you do not need it to be too accurate. If not set, the robot will not active brake.
