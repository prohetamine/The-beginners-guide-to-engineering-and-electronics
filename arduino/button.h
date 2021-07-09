int modeId = -1;
int selectId = 0;
int carret = 0;

/*
 * 0 - time
 * 1 - timer
 * 2 - minutes timer
 * 3 - game
 */
 
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
  if (selectId == 0) {
    viewController(0, String('c'));
    viewController(1, String(' '));
    viewController(2, String(' '));
    viewController(3, String(' ')); 
  }

  if (selectId == 1) {
    viewController(0, String('t'));
    viewController(1, String(' '));
    viewController(2, String(' '));
    viewController(3, String(' ')); 
  }

  if (selectId == 2) {
    viewController(0, String('m'));
    viewController(1, String('t'));
    viewController(2, String(' '));
    viewController(3, String(' ')); 
  }

  if (selectId == 3) {
    viewController(0, String('g'));
    viewController(1, String(' '));
    viewController(2, String(' '));
    viewController(3, String(' ')); 
  }
}

void buttonFristEvent (int clickedFirst, int clickedMiddle, int clickedLast) {
  if (modeId == -1) {
    selectId++;
    if (selectId > 3) {
      selectId = 0;
    }
    mainOffControllers();
    menuList();
  }

  if (clickedLast == 1 || clickedLast == 2 || clickedLast == 3 || clickedLast == 4) {
    if (modeId == 0) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          timeTickerController(i, 1);
          viewController(carret, String(timeTicker[i]));
        }
      }
    }

    if (modeId == 1) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          timerTickerController(i, 1);
          viewController(carret, String(timerTicker[i]));
        }
      } 
    }

    if (modeId == 2) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          mTimerTickerController(i, 1);
          viewController(carret, String(mTimerTicker[i]));
        }
      }     
    }

    if (modeId == 3) {
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
  if (modeId == -1) {
    selectId--;
    if (selectId < 0) {
      selectId = 3;
    }
    mainOffControllers();
    menuList();
  }

  if (clickedLast == 1 || clickedLast == 2 || clickedLast == 3 || clickedLast == 4) {
    if (modeId == 0) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          timeTickerController(i, -1);
          viewController(carret, String(timeTicker[i]));
        }
      }
    }

    if (modeId == 1) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          timerTickerController(i, -1);
          viewController(carret, String(timerTicker[i]));
        }
      } 
    }

    if (modeId == 2) {
      for (int i = 0; i < 4; i++) {
        if (carret == i) {
          mTimerTickerController(i, -1);
          viewController(carret, String(mTimerTicker[i]));
        }
      }     
    }

    if (modeId == 3) {
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
  if (modeId == -1) {
    modeId = selectId;
    buttonController(0, 0, 0);
  
    if (modeId == 0) {
      timeController(true);
    }

    if (modeId == 1) {
      timerController(true);
    }

    if (modeId == 2) {
      mTimerController(true);
    }

    if (modeId == 3) {
      gameUnLockerController(true);
    }
    return; 
  }

  if (clickedLast == 1 && modeId == 0) {
    mainOffControllers();
    for (int i = 0; i < 4; i++) {
      viewController(i, String(timeTicker[i]));
    }
    viewController(carret, String('_'));  
    animationController(false, "edit"); 
    return;
  }

  if (modeId == 0) {
    for (int i = 0; i < 4; i++) {
      viewController(i, String(timeTicker[i]));   
    } 
  
    if (carret < 3) {
      carret++;
      viewController(carret, String('_'));  
      return;
    } else {
      carret = 0;
      modeId = -1;
      timeController(true);
      buttonController(0, 0, 0);
    }
  }

  if (clickedLast == 1 && modeId == 1) {
    mainOffControllers();
    for (int i = 0; i < 4; i++) {
      viewController(i, String(timerTicker[i]));
    }
    viewController(carret, String('_'));  
    animationController(false, "edit"); 
    return;
  }

  if (modeId == 1) {
    for (int i = 0; i < 4; i++) {
      viewController(i, String(timerTicker[i]));   
    } 
  
    if (carret < 3) {
      carret++;
      viewController(carret, String('_'));  
      return;
    } else {
      carret = 0;
      modeId = -1;
      timerController(true);
      buttonController(0, 0, 0);
    }
  }

  if (clickedLast == 1 && modeId == 2) {
    mainOffControllers();
    for (int i = 0; i < 4; i++) {
      viewController(i, String(mTimerTicker[i]));
    }
    viewController(carret, String('_'));  
    animationController(false, "edit"); 
    return;
  }

  if (modeId == 2) {
    for (int i = 0; i < 4; i++) {
      viewController(i, String(mTimerTicker[i]));   
    } 
  
    if (carret < 3) {
      carret++;
      viewController(carret, String('_'));  
      return;
    } else {
      carret = 0;
      modeId = -1;
      mTimerController(true);
      buttonController(0, 0, 0);
    }
  }

  if (clickedLast == 1 && modeId == 3) {
    mainOffControllers();
    for (int i = 0; i < 4; i++) {
      viewController(i, String(gameUnLockerData[i]));
    }
    viewController(carret, String('_'));  
    animationController(false, "play"); 
    return;
  }

  if (modeId == 3) {
    for (int i = 0; i < 4; i++) {
      viewController(i, String(gameUnLockerData[i]));   
    } 
  
    if (carret < 3) {
      carret++;
      viewController(carret, String('_'));  
      return;
    } else {
      carret = 0;
      modeId = -1;
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
