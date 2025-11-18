#include <LiquidCrystal.h>

// LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(9, 8, 10, 11, 12, 13);

// Botones
int boton1 = 2;
int boton2 = 4;

// LEDs
int led1 = 3;
int led2 = 5;

// Buzzer
int buzzer = 6;

// Beep normal
void beep() {
  tone(buzzer, 1000, 200); // 1000Hz, 200ms
  delay(300);
}

// Nota MI (330 Hz)
void notaMi(){
  tone(buzzer, 330, 300); // MI - 330 Hz
  delay(350);
}

void setup() {
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);

  lcd.setCursor(0,0);
  lcd.print("Hola!");
  lcd.setCursor(0,1);
  lcd.print("Oprime un boton");
}

void loop() {

  // ------------ BOTON 1: SUMA 2 + 5 ------------
  if (digitalRead(boton1) == LOW) {

    digitalWrite(led1, HIGH);

    int a = 2;
    int b = 5;
    int resultado = a + b;
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Opcion 1: Suma");
    lcd.setCursor(0,1);
    lcd.print("2+5");
    delay(2000);
	
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("2 + 5 = ");
    lcd.setCursor(0,1);
    lcd.print(resultado);
    delay(2000);
    
    lcd.clear();
    lcd.print("Ejecucion terminada");
    delay(1000);

    digitalWrite(led1, LOW);

    lcd.clear();
    lcd.print("Oprime un boton");
    delay(300);
  }

  // ------------ BOTON 2: 2 + (8 - 3) * 3 ------------
  if (digitalRead(boton2) == LOW) {

    digitalWrite(led2, HIGH);

    int a = 2;
    int x = 8;
    int y = 3;
    int z = 3;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Opcion dos:");
    lcd.setCursor(0,1);
    lcd.print("2 + (8 - 3) * 3");
    delay(2000);
    
    // Paso 1: 8-3
    int r1 = x - y;
    lcd.clear();
    lcd.print("8 - 3 = ");
    lcd.print(r1);
    beep();
    notaMi();
    delay(2000);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("2 + (8 - 3) * 3");
    lcd.setCursor(0,1);
    lcd.print("2 + 5 * 3");
    delay(2000);
    
    // Paso 2: 5*3
    int r2 = r1 * z;
    lcd.clear();
    lcd.print("5 * 3 = ");
    lcd.print(r2);
    beep();
    notaMi();
    delay(2000);

    // Paso 3: 2 + 15
    int r3= a + r2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("2 + 5 * 3");
    lcd.setCursor(0,1);
    lcd.print("2 + 15 = ");
    lcd.print(r3);
    beep();
    notaMi();
    delay(2000);

    lcd.clear();
    lcd.print("Ejecucion terminada");
    delay(1000);
    
    digitalWrite(led2, LOW);

    lcd.clear();
    lcd.print("Oprime un boton");
    delay(300);
  }
}
