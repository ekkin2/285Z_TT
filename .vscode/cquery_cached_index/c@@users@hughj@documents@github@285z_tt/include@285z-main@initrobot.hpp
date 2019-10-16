//Where the things are declared
#pragma once
#include "../main.h"

#define RED 1
#define BLUE 0

#define FWD 0
#define BWD 1

#define ARCADE 1
#define TANK 0

#define TOGGLE 1
#define HOLD 0

#define ONLINE 1

//extern auto anglerController;
extern ControllerButton btnLazyMode;
extern ControllerButton btnVert; //Make stack vertical
extern ControllerButton btnAngle; //Make stack angled
extern ControllerButton btnIntake; //Start Intake
extern ControllerButton btnIntakeRev;

extern ChassisControllerIntegrated drive;
extern MotorGroup driveL;
extern MotorGroup driveR;

extern ChassisControllerIntegrated aut;
extern AsyncMotionProfileController profile;

extern Motor fl;
extern Motor bl;
extern Motor fr;
extern Motor br;

extern Motor intakeL;
extern Motor intakeR;

extern Motor angler1;
extern Motor angler2;

extern MotorGroup intake;
extern MotorGroup angler;

// Opertion Control Declarations //
extern bool driveStyleToggle;
extern bool intakeToggleBool;
extern bool liftUp;
extern bool lazy;

void lazyMode ();

// TELEOP DECLARATIONS //
void intakeToggle();
void intakeRev();

void liftVert();
void lowerFlat();

void doArcade ();
void doTank   ();
void driveStyle(int style);

void lControlTask (void*);

// Autonomous Declarations //

extern bool number;

//  Auton Drive  //
void turn  (QAngle degrees, float rpm);

//  Angler //
void liftVertAut();

// Intakes //
void intakeSpeed(int x);

// Autons //
void testAut();
void redAut();
void redSimple();
