#ifndef MovePIDMotor_H
#define MovePIDMotor_H

#include "WPILib.h"
#include "../Subsystems/PIDTest.h"
#include <cmath>

class MovePIDMotor: public Command
{
public:
	MovePIDMotor(double setPoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double setPoint;
};

#endif
