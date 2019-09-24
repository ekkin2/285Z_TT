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

extern ControllerButton btnShoot;
extern ControllerButton btnBallIntake;
extern ControllerButton btnReverseBallSystem;
extern ControllerButton btnDoubleShot;

extern ControllerButton btnLUsager;

extern ControllerButton btnLazyMode;

extern ChassisControllerIntegrated drive;
extern MotorGroup driveL;
extern MotorGroup driveR;

extern ChassisControllerIntegrated aut;
extern AsyncMotionProfileController profile;

extern Motor ballIntake;
extern Motor ballIndexer;
extern Motor flywheel;
extern Motor l;

extern Motor fl;
extern Motor bl;
extern Motor fr;
extern Motor br;

// Opertion Control Declarations //
extern bool intakeStyleToggle;
extern bool ballIntakeToggle;
extern bool driveStyleToggle;
extern bool doubleShot;
extern bool lUsage;
extern bool lazy;

void lControl          ();
void intakeStyle       ();
void ballControl       ();
void doubleShotControl ();
void flywheelControl();

void lazyMode ();

void doArcade ();
void doTank   ();
void driveStyle();

void lControlTask (void*);

// Autonomous Declarations //

extern bool number;

void shoot (bool number);
void turn  (QAngle degrees, float rpm);
