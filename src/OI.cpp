/*
 * OI.cpp
 *
 *  Created on: Jun 3, 2014
 *      Author: alex
 */

#include "OI.h"

#include "Commands/Autonomous.h"

OI::OI() {
	//Place commands on the dashboard, like so:
	//SmartDashboard::PutData("Open Claw", new OpenClaw());
	SmartDashboard::PutData("Move to Zero", new MovePIDMotor(0));
	SmartDashboard::PutData("Move to 50%", new MovePIDMotor(0.5));

	//Setup the joystick:
	joy= new Joystick(0);


    // Create some buttons
    JoystickButton* d_up = new JoystickButton(joy, 5);
    JoystickButton* d_right= new JoystickButton(joy, 6);
    JoystickButton* d_down= new JoystickButton(joy, 7);
    JoystickButton* d_left = new JoystickButton(joy, 8);
    JoystickButton* l2 = new JoystickButton(joy, 9);
    JoystickButton* r2 = new JoystickButton(joy, 10);
    JoystickButton* l1 = new JoystickButton(joy, 11);
    JoystickButton* r1 = new JoystickButton(joy, 12);

    // Connect the buttons to commands, for example:
    //d_up->WhenPressed(new CloseClaw());
    //l2->WhenPressed(new Autonomous());
    l2->WhenPressed(new MovePIDMotor(0));
    r2->WhenPressed(new MovePIDMotor(0.5));
}


Joystick* OI::GetJoystick() {
	return joy;
}
