#ifndef ACTUATOR_HPP
#define ACTUATOR_HPP

#include <vector>
#include <string>
#include <chrono>

namespace aci {

struct ActuatorDataRT {
	double volt, amp, linvel, linpos, angvel, angpos, torque, force, powerM, powerE, efficiency;
	std::chrono::high_resolution_clock::time_point timestamp;
}

enum OutputType { OutSpeed, OutPos, OutBin };
enum FeedbackType { FBAngvel, FBAngpos, FBLinvel, FBLinpos };

class Actuator {
	private:
		std::string name, description;
		uint8_t id;
		double fbConv, anglinConv, maxCurrent, tfcRatio, tfcOffset;
		bool tf;
		std::vector<ActuatorDataRT> data;
		OutputType outType;
		FeedbackType fbType;
	public:
		double update(double volt, double amp, double fb);
		ActuatorDataRT getState();
		Actuator(std::string file);
		~Actuator();
}

}
