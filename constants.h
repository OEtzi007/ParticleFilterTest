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

const double PI=3.14159265359;
extern std::default_random_engine RANDOM_ENGINE;

//ROBOTINTELLIGENCE
const unsigned int NUM_PARTICLES=100;

//MAP
const double MAP_X_MIN=0;
const double MAP_Y_MIN=0;
const double MAP_WIDTH=5;
const double MAP_HEIGHT=5;

//ROBOT
const double ROBOT_RADIUS=0.15;
const std::string LASER_CONFIG_FILE="/Users/David/Documents/Studentenleben Aachen/Hacken und Coden/ParticleFilterTest/2D_12.lcfg";

//SIMULATION
const double TIME_PER_TICK = 0.001;

//LASER
const double LASER_RANGE=5.;
const double LASER_REL_SIGMA_L=0.01;
const double LASER_SIGMA_THETA=2.*PI/360.;
const double LASER_ERROR_PROBABILITY=0.01;

//MOTOR
const double REL_SIGMA_V = 0.01;
const double REL_SIGMA_OMEGA = 0.05;

#endif /* CONSTANTS_H_ */
