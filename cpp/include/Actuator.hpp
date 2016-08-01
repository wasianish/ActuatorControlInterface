/*
 * Actuator.hpp
 *
 *  Created on: Jul 16, 2016
 *      Author: anno
 */

#ifndef ACTUATOR_HPP_
#define ACTUATOR_HPP_

#include <string>

namespace aci {

enum ActuatorType {
	Motor_DC = 0,
	Motor_AC = 1,
	Motor_Stepper = 2,
	Motor_Servo = 3,
	Actuator = 4,
	Other = 5
};

class Actuator {
public:
	std::string name;
	std::string description;
	ActuatorType type;
	double nominal_voltage;
	double stall_torque;
	double no_load_rpm;
	double stall_current;
	double no_load_current;
	double peak_eff_rpm;
	double peak_eff_current;


};
}

#endif /* ACTUATOR_HPP_ */
