#include <AsyncDelay.h>

AsyncDelay delayRenderRowFirst;
AsyncDelay delayRenderRowTwo;
AsyncDelay delayRenderRowThree;
AsyncDelay delayRenderRowFour;
AsyncDelay delayAnimaton;
AsyncDelay delayButtonHandle;

const int BTN_SET_TOP = A5
        , BTN_SET_MIDDLE = A4
        , BTN_SET_BOTTOM = A3;

const int DS = 11
        , ST_CP = 10
        , SH_CP = 9;

const int A = 2
        , B = 4
        , C = 7
        , D = 5
        , E = 1
        , F = 3
        , G = 8
        , DP = 6;

const int BLINK = 13;
const int SIGNAL = 12;

#include "viewer.h"
#include "animation.h"
#include "time.h"
#include "mtimer.h"
#include "timer.h"
#include "gameUnLocker.h"
#include "button.h"

void setup () {
  delayRenderRowFirst.start(1, AsyncDelay::MILLIS);
  delayRenderRowTwo.start(1, AsyncDelay::MILLIS);
  delayRenderRowThree.start(1, AsyncDelay::MILLIS);
  delayRenderRowFour.start(1, AsyncDelay::MILLIS);
  delayButtonHandle.start(1000, AsyncDelay::MILLIS);
  delayAnimaton.start(500, AsyncDelay::MILLIS);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  pinMode(BLINK, OUTPUT);
  pinMode(SIGNAL, OUTPUT);
  
  pinMode(DS, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);

  pinMode(BTN_SET_TOP, INPUT);
  pinMode(BTN_SET_MIDDLE, INPUT);
  pinMode(BTN_SET_BOTTOM, INPUT);

  // reset

  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
  digitalWrite(DP, 0);

  digitalWrite(ST_CP, 0);
  for (int i = 0; i < 8; i++) {
    digitalWrite(SH_CP, 0);
    digitalWrite(DS, 1); 
    digitalWrite(SH_CP, 1);
  }
  digitalWrite(ST_CP, 1);
}

boolean aminationStartActive = true; 

void loop () {   
  viewDriver();
  buttonDriver();
  timeDriver();
  mTimerDriver();
  timerDriver();
  gameUnLockerDriver();
  animationDriver();

  if (millis() > 3000 && aminationStartActive) {
    aminationStartActive = false;
    timeShow = true;
  }

  if (millis() < 1) {
    animationController(false, "hey ");
  }
}
