
#include "Robot.h"
#include "Commands/Autonomous.h"

//Initialize each of the components of the robot:
//DriveTrain* Robot::drivetrain = NULL;

OI* Robot::oi = NULL;

void Robot::RobotInit() {
	std::cout << "FRC Team 1148 robot code startup" << std::endl;
	//Init all the components
	//drivetrain = new DriveTrain();
	pidSubsystem = new PIDTest(PID_TEST_MOTOR);

	oi = new OI();

	autonomousCommand = new Autonomous();
	lw = LiveWindow::GetInstance();

	SmartDashboard::PutData(pidSubsystem);
    // Show what command your subsystem is running on the SmartDashboard
    //SmartDashboard::PutData(drivetrain);
}

void Robot::AutonomousInit() {
	autonomousCommand->Start();
	std::cout << "Starting Auto" << std::endl;
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
	std::cout << "Starting Teleop" << std::endl;
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
