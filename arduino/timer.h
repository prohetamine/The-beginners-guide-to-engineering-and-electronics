int timerTicker[4] = { 0, 0, 3, 0 };
int timerSecond = 59;

uint32_t timerDelta;
boolean timerShow = false;

void timerController (boolean isShow) {
  timerShow = isShow;
  viewControllerDot(isShow);
}

void timerTickerController (int offset, int n) {
  if (offset == 0) {
    timerTicker[0] += n;
    if (timerTicker[0] > 2) {
      timerTicker[0] = 0;
    }
    if (timerTicker[0] < 0) {
      timerTicker[0] = 2;
    }
  }

  if (offset == 1) {
    timerTicker[1] += n;

    if (timerTicker[0] < 2) {
      if (timerTicker[1] < 0) {
        timerTicker[1] = 9;
      }
      if (timerTicker[1] > 9) {
        timerTicker[1] = 0;
      }
    } else {
      if (timerTicker[1] < 0) {
        timerTicker[1] = 3;
      }
      if (timerTicker[1] > 3) {
        timerTicker[1] = 0;
      }
    }
  }

  if (offset == 2) {
    timerTicker[2] += n;
    if (timerTicker[2] > 5) {
      timerTicker[2] = 0;
    }
    if (timerTicker[2] < 0) {
      timerTicker[2] = 5;
    }
  }

  if (offset == 3) {
    timerTicker[3] += n;
    if (timerTicker[3] > 9) {
      timerTicker[3] = 0;
    }
    if (timerTicker[3] < 0) {
      timerTicker[3] = 9;
    }
  }
}

void timerDriver () {
  if (timerShow && millis() - timerDelta >= 1000) {   
    timerDelta = millis();              

    timerSecond--;
    viewControllerDot(timerSecond % 2 == 0);
    if (timerSecond < 0) {
      timerSecond = 60;
      timerTicker[3]--;
      if (timerTicker[3] < 0) {
        timerTicker[3] = 9;
        timerTicker[2]--;
        if (timerTicker[2] < 0) {
          timerTicker[2] = 5;
          timerTicker[1]--;
          if (timerTicker[1] < 0) {
            timerTicker[1] = 9;
            timerTicker[0]--;
            if (timerTicker[0] < 0) {
              timerTicker[0] = 0;
            } 
          }
        }
      }
    }
        
    viewController(0, String(timerTicker[0])); 
    viewController(1, String(timerTicker[1])); 
    viewController(2, String(timerTicker[2])); 
    viewController(3, String(timerTicker[3]));

    if (
      timerTicker[0] == 0 && 
      timerTicker[1] == 0 && 
      timerTicker[2] == 0 && 
      timerTicker[3] == 0
    ) {
      timerController(false);
      viewControllerDot(false);
      animationController(true, "end");
    } 
  }
}
