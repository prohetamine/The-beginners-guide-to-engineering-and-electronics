/*
 *                     A                
 *              @@@@@@@@@@@@@@@@@      
 *             @@@@@@@@@@@@@@@@@      
 *         @@                    @@   
 *        @@@                   @@@   
 *        @@@                   @@@   
 *       @@@                    @@@   
 *       @@@ F                 @@@ B   
 *       @@@                   @@@    
 *      @@@                    @@     
 *      @@@                   @@@     
 *      @@          G         @@@     
 *         @@@@@@@@@@@@@@@@@@         
 *         @@@@@@@@@@@@@@@@@          
 *     @@                    @@@      
 *    @@@                   @@@       
 *    @@@                   @@@       
 *    @@                    @@@       
 *   @@@ E                 @@@ C       
 *   @@@                   @@@        
 *   @@                    @@@        
 *  @@@                   @@@         
 *  @@@         D         @@@         
 *     @@@@@@@@@@@@@@@@@@      @@     
 *     @@@@@@@@@@@@@@@@@       @@ DP
 * 
 * 
 */

 int valueRenderRow[4][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

boolean dotShow = false;

void view (int* symbol, int offset) {
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

  delayMicroseconds(1000);

  for (int r = 0; r < 10; r++) {
    digitalWrite(A, symbol[0]);
    digitalWrite(B, symbol[1]);
    digitalWrite(C, symbol[2]);
    digitalWrite(D, symbol[3]);
    digitalWrite(E, symbol[4]);
    digitalWrite(F, symbol[5]);
    digitalWrite(G, symbol[6]);
    digitalWrite(DP, symbol[7]); 
  
    if (dotShow && offset == 4) {
      digitalWrite(DP, 1); 
    } else {
      digitalWrite(DP, 0); 
    }
    
    digitalWrite(ST_CP, 0);
    for (int i = 0; i < 8; i++) {
      digitalWrite(SH_CP, 0);
      digitalWrite(DS, i != offset); 
      digitalWrite(SH_CP, 1);
    }
    digitalWrite(ST_CP, 1); 
  }
  
  delayMicroseconds(1000);
}

void viewDriver () {
  int OFFSET_0 = 6;
  int OFFSET_1 = 4;
  int OFFSET_2 = 3;
  int OFFSET_3 = 5;

  if (delayRenderRowFirst.isExpired()) {
    view(valueRenderRow[0], OFFSET_0);
  }

  if (delayRenderRowTwo.isExpired()) {
    view(valueRenderRow[1], OFFSET_1);
  }

  if (delayRenderRowThree.isExpired()) {
    view(valueRenderRow[2], OFFSET_2);
  }

  if (delayRenderRowFour.isExpired()) {
    view(valueRenderRow[3], OFFSET_3);
  }
}

/////////////////////////////////////////

void viewController (int offset, String symbol) {
  String viewSymbol = "00000000";

  if (symbol[0] == '0') { viewSymbol = "11111100"; }
  if (symbol[0] == '1') { viewSymbol = "01100000"; }
  if (symbol[0] == '2') { viewSymbol = "11011010"; }
  if (symbol[0] == '3') { viewSymbol = "11110010"; }
  if (symbol[0] == '4') { viewSymbol = "01100110"; }
  if (symbol[0] == '5') { viewSymbol = "10110110"; }
  if (symbol[0] == '6') { viewSymbol = "10111110"; }
  if (symbol[0] == '7') { viewSymbol = "11100000"; }
  if (symbol[0] == '8') { viewSymbol = "11111110"; }
  if (symbol[0] == '9') { viewSymbol = "11110110"; }
  if (symbol[0] == ' ') { viewSymbol = "00000000"; }
  if (symbol[0] == '_') { viewSymbol = "00010000"; }
  if (symbol[0] == 'a') { viewSymbol = "11101110"; }
  if (symbol[0] == 'b') { viewSymbol = "00111110"; }
  if (symbol[0] == 'c') { viewSymbol = "00011010"; }
  if (symbol[0] == 'd') { viewSymbol = "01111010"; }
  if (symbol[0] == 't') { viewSymbol = "00011110"; }
  if (symbol[0] == 'e') { viewSymbol = "10011110"; }
  if (symbol[0] == 'f') { viewSymbol = "10001110"; }
  if (symbol[0] == 'g') { viewSymbol = "11110110"; }
  if (symbol[0] == 'h') { viewSymbol = "00101110"; }
  if (symbol[0] == 'i') { viewSymbol = "00001100"; }
  if (symbol[0] == 'j') { viewSymbol = "01111000"; }
  if (symbol[0] == 'k') { viewSymbol = "01101110"; }
  if (symbol[0] == 'l') { viewSymbol = "00011100"; }
  if (symbol[0] == 'm') { viewSymbol = "00101010"; }
  if (symbol[0] == 'n') { viewSymbol = "00101010"; }
  if (symbol[0] == 'o') { viewSymbol = "00111010"; }
  if (symbol[0] == 'p') { viewSymbol = "11001110"; }
  if (symbol[0] == 'q') { viewSymbol = "11100110"; }
  if (symbol[0] == 'r') { viewSymbol = "11001100"; }
  if (symbol[0] == 's') { viewSymbol = "10110110"; }
  if (symbol[0] == 't') { viewSymbol = "00011110"; }
  if (symbol[0] == 'u') { viewSymbol = "00111000"; }
  if (symbol[0] == 'v') { viewSymbol = "01111100"; }
  if (symbol[0] == 'w') { viewSymbol = "00111000"; }
  if (symbol[0] == 'x') { viewSymbol = "01101110"; }
  if (symbol[0] == 'x') { viewSymbol = "01101110"; }
  if (symbol[0] == 'y') { viewSymbol = "01110110"; }
  if (symbol[0] == 'z') { viewSymbol = "11011010"; }
 
  for (int i = 0; i < 8; i++) {
    valueRenderRow[offset][i] = String(viewSymbol[i]).toInt();
  }
}

void viewControllerDot (boolean isShow) {
  dotShow = isShow;
}
