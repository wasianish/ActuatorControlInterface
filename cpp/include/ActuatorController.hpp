#ifndef ACTUATORINTERFACE_HPP
#define ACTUATORINTERFACE_HPP

#include <queue>
#include <vector>
#include <thread>

#include "Actuator.hpp"

namespace aci {

struct ActuatorAction {
	bool ovr;
	uint8_t actuator;
	double* constraintValues;
	uint8_t* constraitTypes;
	uint8_t num_constraints;

	bool valid();
}

class ActuatorController {
	private:
		volatile bool running, stop;
		std::queue<ActuatorAction*> actionQueue;
		std::vector<ActuatorAction*> actionRunning;
		std::vector<Actuator*> actuators;
		volatile bool queue_lock;
		
		bool checkConflict(ActuatorAction* action);
		void removeConflicting(ActuatorAction* action);
	public:
		ActuatorController;
		~ActuatorController;
		void halt();		
		void actuatorControl();
		int queueAction(ActuatorAction* action);
}
