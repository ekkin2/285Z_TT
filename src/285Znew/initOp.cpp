bool driveStyle = false;
bool intakeToggleBool = false;

void intakeToggle ()
{
    if (intakeToggleButton.changedToPressed())
    {
      intakeToggleBool = !intakeToggleBool;
    }
    else if(intakeToggleBool)
    {
      intake.moveVelocity   (-600);
    }
    else
    {
      intake.moveVelocity	(0);
      intake.setBrakeMode(AbstractMotor::brakeMode::hold);
    }
}
