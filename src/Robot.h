/*
 * Robot.h
 *
 *  Created on: Jun 3, 2014
 *      Author: alex
 */

#ifndef MY_ROBOT_H_
#define MY_ROBOT_H_

#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Autonomous.h"
#include "Subsystems/PIDTest.h"
#include "RobotMap.h"

#include "OI.h"

class Robot: public IterativeRobot {
public:
	static OI* oi;
	static PIDTest* pidSubsystem;

private:
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};


#endif /* ROBOT_H_ */
