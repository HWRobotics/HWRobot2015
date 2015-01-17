#ifndef PIDTest_H
#define PIDTest_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class PIDTest: public PIDSubsystem
{
public:
	Talon *motor;

	PIDTest(int port);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
