/*
 * constants.h
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string>
#include <random>

#define DEBUG

const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706L;
extern std::default_random_engine RANDOM_ENGINE;

//ROBOTINTELLIGENCE
const unsigned int NUM_PARTICLES=1000;

//MAP
const double MAP_X_MIN=0;
const double MAP_Y_MIN=0;
const double MAP_WIDTH=5;
const double MAP_HEIGHT=5;

//ROBOT
const double ROBOT_RADIUS=0.15;
const std::string LASER_CONFIG_FILE="2D_12.lcfg";

//SIMULATION
const double TIME_PER_TICK = 0.0001;
const unsigned int TOTAL_TICKS = 100000;

//LASER
const double LASER_RANGE=5.;
const double LASER_REL_SIGMA_L=0.01;
const double LASER_SIGMA_THETA=2.*PI/360.;
const double LASER_ERROR_PROBABILITY=0.01;
const double LASER_MEASUREMENT_FREQUENCE=50.;	//Hertz

//MOTOR
const double REL_SIGMA_V = 0.01;
const double REL_SIGMA_OMEGA = 0.05;

#endif /* CONSTANTS_H_ */
