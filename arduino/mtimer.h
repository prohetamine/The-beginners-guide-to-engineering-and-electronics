int mTimerTicker[4] = { 0,3,0,0 };

uint32_t mTimerDelta;
boolean mTimerShow = false;

void mTimerController (boolean isShow) {
  mTimerShow = isShow;
  viewControllerDot(isShow);
}

void mTimerTickerController (int offset, int n) {
  if (offset == 0) {
    mTimerTicker[0] += n;
    if (mTimerTicker[0] > 5) {
      mTimerTicker[0] = 0;
    }
    if (mTimerTicker[0] < 0) {
      mTimerTicker[0] = 5;
    }
  }

  if (offset == 1) {
    mTimerTicker[1] += n;
    if (mTimerTicker[1] > 9) {
      mTimerTicker[1] = 0;
    }
    if (mTimerTicker[1] < 0) {
      mTimerTicker[1] = 9;
    }
  }

  if (offset == 2) {
    mTimerTicker[2] += n;
    if (mTimerTicker[2] > 5) {
      mTimerTicker[2] = 0;
    }
    if (mTimerTicker[2] < 0) {
      mTimerTicker[2] = 5;
    }
  }

  if (offset == 3) {
    mTimerTicker[3] += n;
    if (mTimerTicker[3] > 9) {
      mTimerTicker[3] = 0;
    }
    if (mTimerTicker[3] < 0) {
      mTimerTicker[3] = 9;
    }
  }
}

void mTimerDriver () {
  if (mTimerShow && millis() - mTimerDelta >= 1000) {   
    mTimerDelta = millis();              

    mTimerTicker[3]--;
    viewControllerDot(mTimerTicker[3] % 2 == 0);
    if (mTimerTicker[3] < 0) {
      mTimerTicker[3] = 9;
      mTimerTicker[2]--;
      if (mTimerTicker[2] < 0) {
        mTimerTicker[2] = 5;
        mTimerTicker[1]--;
        if (mTimerTicker[1] < 0) {
          mTimerTicker[1] = 9;
          mTimerTicker[0]--;
          if (mTimerTicker[0] < 0) {
            mTimerTicker[0] = 5;
          }
        }  
      }
    }
        
    viewController(0, String(mTimerTicker[0])); 
    viewController(1, String(mTimerTicker[1])); 
    viewController(2, String(mTimerTicker[2])); 
    viewController(3, String(mTimerTicker[3]));

    if (
      mTimerTicker[0] == 0 && 
      mTimerTicker[1] == 0 && 
      mTimerTicker[2] == 0 && 
      mTimerTicker[3] == 0
    ) {
      mTimerController(false);
      viewControllerDot(false);
      animationController(true, "end");
    } 
  }
}
