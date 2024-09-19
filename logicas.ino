const int btn1 = 2;  // Botón 1 (AND)
const int btn2 = 3;  // Botón 2 (AND)
const int btn3 = 4;  // Botón 3 (OR)
const int btn4 = 5;  // Botón 4 (OR)
const int btn5 = 6;  // Botón 5 (NOT)

// Pines de salida (LEDs)
const int ledAnd = 7;  
const int ledOr = 8;   
const int ledNot = 9;  

void setup() {
  
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  
  // Configurar los pines de los LEDs como salidas
  pinMode(ledAnd, OUTPUT);
  pinMode(ledOr, OUTPUT);
  pinMode(ledNot, OUTPUT);
}

void loop() {

  int inputBtn1 = digitalRead(btn1);
  int inputBtn2 = digitalRead(btn2);

  int inputBtn3 = digitalRead(btn3);
  int inputBtn4 = digitalRead(btn4);
  

  int inputBtn5 = digitalRead(btn5);
  

  if (inputBtn1 == HIGH && inputBtn2 == HIGH) {
    digitalWrite(ledAnd, HIGH);  // Encender el LED AND
  } else {
    digitalWrite(ledAnd, LOW);   // Apagar el LED AND
  }

  // Operación OR: El LED OR se enciende si cualquiera de los botones btn3 o btn4 está presionado
  if (inputBtn3 == HIGH || inputBtn4 == HIGH) {
    digitalWrite(ledOr, HIGH);   // Encender el LED OR
  } else {
    digitalWrite(ledOr, LOW);    // Apagar el LED OR
  }
  
  // Operación NOT: El LED NOT se enciende cuando el botón btn5 NO está presionado
  if (inputBtn5 == HIGH) {
    digitalWrite(ledNot, LOW);   // Apagar el LED NOT cuando btn5 está presionado
  } else {
    digitalWrite(ledNot, HIGH);  // Encender el LED NOT cuando btn5 no está presionado
  }

  delay(100); // Pequeño retraso para estabilizar la lectura de los botones
}