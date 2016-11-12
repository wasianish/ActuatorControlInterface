#include <ActuatorController.hpp>

namespace aci {

bool ActuatorAction::valid() {
}

void ActuatorController::halt() {
	stop = true;
}

int ActuatorController::queueAction(ActuatorAction* action) {
	if(action->ovr) {
		removeConflicting(action);
	} else {
		if(checkConflict(action)) {
			return 1;
		}
	}
	while(queue_lock) {}
	queue_lock = true;
	actionQueue.push(action);
	queue_lock = false;
	return 0;
}

void ActuatoractuatorControl() {
	while(!stop) {



	}
}

}
