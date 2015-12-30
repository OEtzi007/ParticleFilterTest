/*
 * constants.h
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string>

class CoordinateSystem;

const double PI=3.14159265359;
const unsigned int NUM_PARTICLES=100;
const double REL_SIGMA_L = 0.01;
const double REL_SIGMA_V = 0.01;
const double SIGMA_OMEGA = 2*PI/360;

//MAP
const double MAP_XORIGIN=0;
const double MAP_YORIGIN=0;
const double MAP_ZORIGIN=0;
const double MAP_WIDTH=5;
const double MAP_HEIGHT=5;

//ROBOT
const double ROBOT_RADIUS=.15;
const std::string LASER_CONFIG_FILE="2D_12.lcfg";


#endif /* CONSTANTS_H_ */
