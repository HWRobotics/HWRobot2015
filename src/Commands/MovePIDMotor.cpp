#include "MovePIDMotor.h"

MovePIDMotor::MovePIDMotor(double setPoint)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::pidSubsystem);
	this->setPoint = setPoint;
}

// Called just before this Command runs the first time
void MovePIDMotor::Initialize()
{
	Robot::pidSubsystem->Enable();
}

// Called repeatedly when this Command is scheduled to run
void MovePIDMotor::Execute()
{
	Robot::pidSubsystem->SetSetpoint(this->setPoint);
}

// Make this return true when this Command no longer needs to run execute()
bool MovePIDMotor::IsFinished()
{
	return abs(this->setPoint-Robot::pidSubsystem->GetPosition()) < 0.2;
}

// Called once after isFinished returns true
void MovePIDMotor::End()
{
	Robot::pidSubsystem->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MovePIDMotor::Interrupted()
{
	Robot::pidSubsystem->Disable();
}
