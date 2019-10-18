#include "285Z-Main/initRobot.hpp"

void opcontrol() {


	while (ONLINE) {

		//  DRIVE FUNCTIONS  //
		driveStyle(TANK);

		//  ANGLER FUNCTIONS //
		liftVertAngler();
		liftVert();
		lowerFlat();

		// INTAKE FUNCTIONS //
		intakeToggle();
		intakeRev();
		pros::delay(10);
	}
}
