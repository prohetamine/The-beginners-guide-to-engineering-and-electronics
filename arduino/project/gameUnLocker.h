int gameUnLockerData[4] = { 0,0,0,0 };
int gameUnLockerHiddenData[4] = { 
  random(0, 9),
  random(0, 9),
  random(0, 9),
  random(0, 9)
};

boolean gameUnLockerShow = false;

void gameUnLockerController (boolean isShow) {
  gameUnLockerShow = isShow; 
}

void gameUnLockerPlayerController (int offset, int n) {
  if (offset == 0) {
    gameUnLockerData[0] += n;
    if (gameUnLockerData[0] > 9) {
      gameUnLockerData[0] = 0;
    }
    if (gameUnLockerData[0] < 0) {
      gameUnLockerData[0] = 9;
    }
  }

  if (offset == 1) {
    gameUnLockerData[1] += n;
    if (gameUnLockerData[1] > 9) {
      gameUnLockerData[1] = 0;
    }
    if (gameUnLockerData[1] < 0) {
      gameUnLockerData[1] = 9;
    }  
  }

  if (offset == 2) {
    gameUnLockerData[2] += n;
    if (gameUnLockerData[2] > 9) {
      gameUnLockerData[2] = 0;
    }
    if (gameUnLockerData[2] < 0) {
      gameUnLockerData[2] = 9;
    }   
  }

  if (offset == 3) {
    gameUnLockerData[3] += n;
    if (gameUnLockerData[3] > 9) {
      gameUnLockerData[3] = 0;
    }
    if (gameUnLockerData[3] < 0) {
      gameUnLockerData[3] = 9;
    }    
  }
}

void gameUnLockerDriver () {
  if (gameUnLockerShow) {
    if (
      gameUnLockerData[0] == gameUnLockerHiddenData[0] &&
      gameUnLockerData[1] == gameUnLockerHiddenData[1] &&
      gameUnLockerData[2] == gameUnLockerHiddenData[2] &&
      gameUnLockerData[3] == gameUnLockerHiddenData[3] 
    ) {
      viewController(0, String('g'));
      viewController(1, String('o'));
      viewController(2, String('o'));
      viewController(3, String('d')); 
    } else {
      viewController(0, String('b'));
      viewController(1, String('a'));
      viewController(2, String('d'));
      viewController(3, String(' '));   
    } 
  }
}
