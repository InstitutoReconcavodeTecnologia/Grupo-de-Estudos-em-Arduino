//Programa: Teste de Display LCD 16 x 2
//Autor: FILIPEFLOP

int const MAX_SCREEN_SIZE = 16;
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
String defaultChar = "B*"; 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String message = "";

void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}
 
void loop()
{
  lcd.clear();
  lcd.print(defaultChar);

  moveRight(MAX_SCREEN_SIZE * 2);
}

void moveLeft(int positions) {
  for (int posicao = 0; posicao < positions; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
}

void moveRight(int positions) {
  for (int posicao = 0; posicao < positions; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
}

