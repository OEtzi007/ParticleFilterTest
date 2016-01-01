/*
 * constants.h
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string>

const double PI=3.14159265359;
const unsigned int NUM_PARTICLES=100;

//MAP
const double MAP_X_MIN=0;
const double MAP_Y_MIN=0;
const double MAP_WIDTH=5;
const double MAP_HEIGHT=5;

//ROBOT
const double ROBOT_RADIUS=0.15;
const std::string LASER_CONFIG_FILE="2D_12.lcfg";

//SIMULATION
const long double TIME_PER_TICK = 0.001;

//LASER
const double LASER_RANGE=5.;
const double REL_SIGMA_L=0.01;
const double SIGMA_PHI=2.*PI/360.;

//MOTOR
const double REL_SIGMA_V = 0.01;
const double REL_SIGMA_OMEGA = 0.05;

#endif /* CONSTANTS_H_ */
