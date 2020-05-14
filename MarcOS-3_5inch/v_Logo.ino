
/*  DISPLAY OS VERSION ON CREDIT PAGE AND STARTUP SCREEN  */

void OSVersion()  {

//  tft.setCursor(400, 310);        //  show at bottom right
//  tft.setTextColor(GREY);
//  tft.setTextSize(1);
  tft.println(MarcOS_Version);
}


/*  STARTUP SCREEN  */

void StartupScreen()   {

#define wait1 70 //  50
#define wait2 50

  /*  Horizontal, Vertical, Width, Height  */

  tft.drawRect(0, 0, 480, 320, WHITE);
  tft.drawRect(20, 70, 440, 150, WHITE);
  delay(wait1);
  tft.fillRect(40, 90, 50, 100, RED);
  delay(wait1);
  tft.fillRect(110, 90, 50, 100, RED);
  delay(wait1);
  tft.fillRect(180, 90, 50, 100, RED);
  delay(wait1);
  tft.fillRect(250, 90, 50, 100, RED);    //
  delay(wait1);
  tft.fillRect(320, 90, 50, 100, GREEN);  //
  delay(wait1);
  tft.fillRect(390, 90, 50, 100, GREEN);  //

  delay(150);

  tft.setTextSize(5);
  tft.setTextColor(WHITE);

  /*  Horizontal, Vertical  */
  tft.setCursor(52, 120);
  tft.print("M");
  delay(wait2);
  tft.setCursor(122, 120);
  tft.print("A");
  delay(wait2);
  tft.setCursor(192, 120);
  tft.print("R");
  delay(wait2);
  tft.setCursor(262, 120);
  tft.print("C");
  delay(wait2);
  tft.setCursor(332, 120);
  tft.print("O");
  delay(wait2);
  tft.setCursor(402, 120);
  tft.print("S");
  delay(wait2);

  delay(700);

  tft.setTextSize(1);
  tft.setCursor(180, 230);
  tft.print(MarcOS_Version);
  tft.print("  -  2017");
  tft.setCursor(200, 260);
  tft.print("I can fix it!");
}



