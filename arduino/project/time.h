int timeTicker[4] = { 1,2,4,8 };
int timeSecond = 0;

uint32_t timeDelta;
boolean timeShow = false;

void timeController (boolean isShow) {
  timeShow = isShow;
  viewControllerDot(isShow);
}

void timeTickerController (int offset, int n) {
  if (offset == 0) {
    timeTicker[0] += n;
    if (timeTicker[0] > 2) {
      timeTicker[0] = 0;
    }
    if (timeTicker[0] < 0) {
      timeTicker[0] = 2;
    }
  }

  if (offset == 1) {
    timeTicker[1] += n;

    if (timeTicker[0] < 2) {
      if (timeTicker[1] < 0) {
        timeTicker[1] = 9;
      }
      if (timeTicker[1] > 9) {
        timeTicker[1] = 0;
      }
    } else {
      if (timeTicker[1] < 0) {
        timeTicker[1] = 3;
      }
      if (timeTicker[1] > 3) {
        timeTicker[1] = 0;
      }
    }
  }

  if (offset == 2) {
    timeTicker[2] += n;
    if (timeTicker[2] > 5) {
      timeTicker[2] = 0;
    }
    if (timeTicker[2] < 0) {
      timeTicker[2] = 5;
    }
  }

  if (offset == 3) {
    timeTicker[3] += n;
    if (timeTicker[3] > 9) {
      timeTicker[3] = 0;
    }
    if (timeTicker[3] < 0) {
      timeTicker[3] = 9;
    }
  }
}

void timeDriver () {
  if (timeShow && millis() - timeDelta >= 1000) {   
    timeDelta = millis();              

    timeSecond++;
    viewControllerDot(timeSecond % 2 == 0);
    if (timeSecond > 59) {
      timeSecond = 0;
      timeTicker[3]++;
      if (timeTicker[3] > 9) {
        timeTicker[3] = 0;
        timeTicker[2]++;
        if (timeTicker[2] > 5) {
          timeTicker[2] = 0;
          timeTicker[1]++;
          if ((timeTicker[0] < 2 && timeTicker[1] > 9) || (timeTicker[0] == 2 && timeTicker[1] > 3)) {
            timeTicker[1] = 0;
            timeTicker[0]++;
            if (timeTicker[0] > 2) {
              timeTicker[0] = 0;
            }
          }  
        } 
      }
    }
    
    viewController(0, String(timeTicker[0])); 
    viewController(1, String(timeTicker[1])); 
    viewController(2, String(timeTicker[2])); 
    viewController(3, String(timeTicker[3])); 
  }
}
