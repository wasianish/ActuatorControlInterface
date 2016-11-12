#include "Actuator.hpp"

#include <chrono>

namespace aci {

Actuator::update(double volt, double amp, double fb) {

	ActuatorDataRT data;
	data.volt = volt;
	data.amp = amp;
	ActuatorDataRT prev = data.back();
	data.timestamp = std::chrono::high_resolution_clock::now();
	
	double dt = ((double)std::chrono::duration_cast<std::chrono::microseconds>(data.timestamp - prev.timestamp).count())/1000000;	

	switch( fbType ) {
		case FBAngvel:
			data.angvel = fb*fbConv;
			data.linvel = data.angvel/anglinConv;
			data.angpos = prev.angpos + data.angvel*dt;
			data.linpos = prev.linpos + data.linvel*dt;
			break;
		case FBAngpos:
			data.angpos = fb*fbConv;
			data.linpos = data.angpos/anglinConv;
			data.angvel = (data.angpos - prev.angpos)/dt;
			data.linvel = (data.linpos - prev.linpos)/dt;
			break;
		case FBLinvel:
			data.linvel = fb*fbConv;
			data.angvel = data.anglinConv*linvel;
			data.angpos = prev.angpos + data.angvel*dt;
			data.linpos = prev.linpos + data.linvel*dt;		
			break;
		case FBLinpos:
			data.linpos = fb*fbConv;
			data.angpos = data.anglinConv*linpos;
			data.angvel = (data.angpos - prev.angpos)/dt;
			data.linvel = (data.linpos - prev.linpos)/dt;
			break;
	}
	data.powerE = volt*amp;
	if( tf ) {
		data.torque = tfcOffset + tfcRatio*data.amp;
		data.powerM = data.angvel * data.torque;
	} else {
		data.force = tfcOffset + tfcRatio*data.amp;
		data.powerM = data.linvel * data.force;
	}
	data.efficiency = powerM/powerE;
}






}
