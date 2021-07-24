float animationTicker = -1;
int animationSound = true;
String animationMessage = "";
int animationSaveValueRow[4][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

void animationSaveState () {
  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 8; x++) {
      animationSaveValueRow[y][x] = valueRenderRow[y][x];
    }  
  }
}

void animationPushState () {
  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 8; x++) {
      valueRenderRow[y][x] = animationSaveValueRow[y][x];
    }  
  }
}

void animationDriver () {
  if (delayAnimaton.isExpired()) {
    if (animationTicker != -1) {
      animationTicker += 0.2;      
    }

    if (animationTicker > 32 || (animationMessage.length() == 0 && animationTicker > 16)) {
      animationPushState();
      animationTicker = -1;
      return;
    }

    if (animationTicker == -1) {
      return;
    }

    viewController(0, String(' ')); 
    viewController(1, String(' ')); 
    viewController(2, String(' ')); 
    viewController(3, String(' ')); 

    if (animationSound) {
      if (int(animationTicker) > 23) {
        tone(SIGNAL, (100 * (int(animationTicker) + 1) + 500), 50);
      } else {
        if (int(animationTicker) % 23) {
          tone(SIGNAL, (20 * (int(animationTicker) + 1) + 500), 50);
        } else {
          noTone(SIGNAL); 
        }
      }
    }

    if (animationMessage.length() != 0 && int(animationTicker) > 8 && int(animationTicker) < 24) {
      for (int x = 0; x < 4; x++) { 
        viewController(x, String(animationMessage[x]));
      }
      return;
    } else {
      if (int(animationTicker) % 8 < 4) {
        viewController(int(animationTicker) % 4, String('0')); 
        return;
      } else {
        viewController(int(animationTicker) % 4, String(' '));
        return;
      } 
    }
  }
}

void animationController (boolean isSound, String message) {  
  animationSaveState();
  animationMessage = message;
  animationSound = isSound;
  animationTicker = 0;
}
