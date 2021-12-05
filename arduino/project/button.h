int modeId = -1;
int selectId = 0;
int carret = 0;

#define MODE_NONE -1
#define MODE_TIME 0
#define MODE_TIMER 1
#define MODE_MINUTES_TIMER 2
#define MODE_GAME 3
 
int clickedFirstButton = 0;
int clickedMiddleButton = 0;
int clickedLastButton = 0;

void buttonController (int first, int middle, int last) {
  if (first != -1) {
    clickedFirstButton = first;
  }

  if (middle != -1) {
    clickedMiddleButton = middle;
  }

  if (last != -1) {
    clickedLastButton = last;  
  }
}

void mainOffControllers () {
  timeController(false);
  mTimerController(false);
  timerController(false);
  gameUnLockerController(false);
}

void menuList () {
  if (selectId == MODE_TIME) {
    viewController(0, String('c'));
    viewController(1, String(' '));
    viewController(2, String(' '));
    viewController(3, String(' ')); 
  }

  if (selectId == MODE_TIMER) {
    viewController(0, String('t'));
    viewController(1, String(' '));
    viewController(2, String(' '));
    viewController(3, String(' ')); 
  }

  if (selectId == MODE_MINUTES_TIMER) {
    viewController(0, String('m'));
    viewController(1, String('t'));
    viewController(2, String(' '));
    viewController(3, String(' ')); 
  }

  if (selectId == MODE_GAME) {
    viewController(0, String('g'));
    viewController(1, String(' '));
    viewController(2, String(' '));
    viewController(3, String(' ')); 
  }
}

void buttonFristEvent (int clickedFirst, int clickedMiddle, int clickedLast) {
  if (modeId == MODE_NONE) {
    selectId++;
    if (selectId > 3) {
      selectId = MODE_TIME;
    }
    mainOffControllers();
    menuList();
  }

  if (clickedLast == 1 || clickedLast == 2 || clickedLast == 3 || clickedLast == 4) {
    if (modeId == MODE_TIME) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          timeTickerController(i, 1);
          viewController(carret, String(timeTicker[i]));
        }
      }
    }

    if (modeId == MODE_TIMER) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          timerTickerController(i, 1);
          viewController(carret, String(timerTicker[i]));
        }
      } 
    }

    if (modeId == MODE_MINUTES_TIMER) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          mTimerTickerController(i, 1);
          viewController(carret, String(mTimerTicker[i]));
        }
      }     
    }

    if (modeId == MODE_GAME) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          gameUnLockerPlayerController(i, 1);
          viewController(carret, String(gameUnLockerData[i]));
        }
      }     
    }
  }
}

void buttonMiddleEvent (int clickedFirst, int clickedMiddle, int clickedLast) {
  if (modeId == MODE_NONE) {
    selectId--;
    if (selectId < 0) {
      selectId = MODE_MINUTES_TIMER;
    }
    mainOffControllers();
    menuList();
  }

  if (clickedLast == 1 || clickedLast == 2 || clickedLast == 3 || clickedLast == 4) {
    if (modeId == MODE_TIME) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          timeTickerController(i, -1);
          viewController(carret, String(timeTicker[i]));
        }
      }
    }

    if (modeId == MODE_TIMER) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          timerTickerController(i, -1);
          viewController(carret, String(timerTicker[i]));
        }
      } 
    }

    if (modeId == MODE_MINUTES_TIMER) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          mTimerTickerController(i, -1);
          viewController(carret, String(mTimerTicker[i]));
        }
      }     
    }

    if (modeId == MODE_GAME) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          gameUnLockerPlayerController(i, -1);
          viewController(carret, String(gameUnLockerData[i]));
        }
      }     
    }
  }
}

void buttonLastEvent (int clickedFirst, int clickedMiddle, int clickedLast) {
  if (modeId == MODE_NONE) {
    modeId = selectId;
    buttonController(0, 0, 0);
  
    if (modeId == MODE_TIME) {
      timeController(true);
    }

    if (modeId == MODE_TIMER) {
      timerController(true);
    }

    if (modeId == MODE_MINUTES_TIMER) {
      mTimerController(true);
    }

    if (modeId == MODE_GAME) {
      gameUnLockerController(true);
    }
    return; 
  }

  if (clickedLast == 1 && modeId == MODE_TIME) {
    mainOffControllers();
    for (int i = 0; i < 4; i++) {
      viewController(i, String(timeTicker[i]));
    }
    viewController(carret, String('_'));  
    animationController(false, "edit"); 
    return;
  }

  if (modeId == MODE_TIME) {
    for (int i = 0; i < 4; i++) {
      viewController(i, String(timeTicker[i]));   
    } 
  
    if (carret < 3) {
      carret++;
      viewController(carret, String('_'));  
      return;
    } else {
      carret = 0;
      modeId = MODE_NONE;
      timeController(true);
      buttonController(0, 0, 0);
    }
  }

  if (clickedLast == 1 && modeId == MODE_TIMER) {
    mainOffControllers();
    for (int i = 0; i < 4; i++) {
      viewController(i, String(timerTicker[i]));
    }
    viewController(carret, String('_'));  
    animationController(false, "edit"); 
    return;
  }

  if (modeId == MODE_TIMER) {
    for (int i = 0; i < 4; i++) {
      viewController(i, String(timerTicker[i]));   
    } 
  
    if (carret < 3) {
      carret++;
      viewController(carret, String('_'));  
      return;
    } else {
      carret = 0;
      modeId = MODE_NONE;
      timerController(true);
      buttonController(0, 0, 0);
    }
  }

  if (clickedLast == 1 && modeId == MODE_MINUTES_TIMER) {
    mainOffControllers();
    for (int i = 0; i < 4; i++) {
      viewController(i, String(mTimerTicker[i]));
    }
    viewController(carret, String('_'));  
    animationController(false, "edit"); 
    return;
  }

  if (modeId == MODE_MINUTES_TIMER) {
    for (int i = 0; i < 4; i++) {
      viewController(i, String(mTimerTicker[i]));   
    } 
  
    if (carret < 3) {
      carret++;
      viewController(carret, String('_'));  
      return;
    } else {
      carret = 0;
      modeId = MODE_NONE;
      mTimerController(true);
      buttonController(0, 0, 0);
    }
  }

  if (clickedLast == 1 && modeId == MODE_GAME) {
    mainOffControllers();
    for (int i = 0; i < 4; i++) {
      viewController(i, String(gameUnLockerData[i]));
    }
    viewController(carret, String('_'));  
    animationController(false, "play"); 
    return;
  }

  if (modeId == MODE_GAME) {
    for (int i = 0; i < 4; i++) {
      viewController(i, String(gameUnLockerData[i]));   
    } 
  
    if (carret < 3) {
      carret++;
      viewController(carret, String('_'));  
      return;
    } else {
      carret = 0;
      modeId = MODE_NONE;
      gameUnLockerController(true);
      buttonController(0, 0, 0);
    }
  }
}

boolean buttonDriverFlag = false;

void buttonDriver () {
  if (delayButtonHandle.isExpired()) {
    if (analogRead(BTN_SET_TOP) >= 128) {
      if (!buttonDriverFlag) {
        tone(SIGNAL, 1700, 50);
        clickedFirstButton++;
        buttonFristEvent(clickedFirstButton, clickedMiddleButton, clickedLastButton);
      }
      buttonDriverFlag = true;
      return;
    }

    if (analogRead(BTN_SET_MIDDLE) >= 128) {
      if (!buttonDriverFlag) {
        tone(SIGNAL, 1700, 50);
        clickedMiddleButton++;
        buttonMiddleEvent(clickedFirstButton, clickedMiddleButton, clickedLastButton);
      }
      buttonDriverFlag = true;
      return;
    }
    
    if (analogRead(BTN_SET_BOTTOM) >= 128) {
      if (!buttonDriverFlag) {
        tone(SIGNAL, 1700, 50);
        clickedLastButton++;
        buttonLastEvent(clickedFirstButton, clickedMiddleButton, clickedLastButton);
      }
      buttonDriverFlag = true;
      return;
    }

    buttonDriverFlag = false;
  }
}
