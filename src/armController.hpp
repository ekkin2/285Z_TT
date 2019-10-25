#pragma once
#include "main.h"

extern bool armToggle;

class ArmController
{
public:

  enum armStates
  {
    off,
    up,
    down,
    kill
  };

  Motor* arm = nullptr;

  pros::Task task;

  armStates armState = off;
  bool disabled = false;

  ArmController(int);

  void setState(armStates);
  armStates getState();
  void disable();
  void enable();

  void run();
  static void taskFnc(void*);
};
