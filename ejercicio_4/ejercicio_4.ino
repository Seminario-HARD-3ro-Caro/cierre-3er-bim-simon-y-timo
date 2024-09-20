// Ejercicio evaluatorio 3er bimestre
/*
  Integrantes
    Nombre: Simon
    Apellido: Mersich
    Curso:3E
    
    Nombre: Timoteo
    Apellido: czerwiak
    Curso: 3A
  
Congisgnas
  Conexionado:
    En la protoboard, conectar 4 LEDs para que cada uno pueda ser controlado individualmente. Cada LED deberá tener su respectiva resistencia.
    Se debe conectar tambien, un pulsador que permita recibir información de un usuario.
    Indicar a continuación los pines a los cuales se conectó cada elemento y el valor de resistencias utilizado:
      Pines:
        Boton: 12
        LED1: 2
        LED2: 4
        LED3: 7
        LED4: 8
      Valor:
        R_boton:  330 ohms
        R_LEDs: 4730 ohms

  Progamas:
    Se deben entregar un programa distinto por cada punto. Los programas son una modificación entre ellos.
    El código deberá estar comentado indicando qué se propone hacer con cada línea de código
    1.  El primer programa sirve para corroborar la correcta conexión de los elementos de hardware.
        El mismo deberá encender TODOS los LEDs cuando se presione el pulsador y apagarlos cuando éste se suelte.
    2.  En el siguiente programa se deberá prender de a UN LED POR VEZ.
        Por cada pulsación se deberá apagar el LED prendido y prender el LED más próximo de la derecha.
        En caso de no haber, se deberá volver a empezar la vuelta, empezando desde el LED de la izquierda.
    3.  A continnuación se desea fabricar un contador binario de 4 bits.
        El programa deberá contar de 0 a 15 mostrando la cuenta actual a través de los 4 LEDs.
        Se interpreta 0 si el LED está apagado y 1 si el LED está prendido. 
        La cuenta aumenta cada vez que el pulsador es presionado, al llegar a 15 deberá volver a empezar en 0.
        IMPORTANTE: la cuenta debe aumentar UNA SOLA VEZ por cada pulsación.
    4. Opcional:
        Utilizando comunicación serie, se desea crear un programa que muestre mediante los LEDs, el nro ingresado en el monitor serie.
        El programa deberá mostrar el número binario prendiendo los LEDs según el criterio del programa 3.
        El nro mostrado será ingresado por el usuario mediante el monitor serie.
        IMPORTANTE: si el nro es mayor a 15 se deberá enviar un mensaje de error. 

*/ 
// definir los pines
#define PINBOTON 12
#define LED1 2
#define LED2 4
#define LED3 7
#define LED4 8

// estado del boton para que no haya rebounce
bool estado = false;

// ejercicio 1
void setup() {
  // Configuración del arduino
  // configurar los pines

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
 
 // empezar serial
  Serial.begin(9600);

  
}

int i = 0;
void loop() {

  // array para iterar por los leds
  int arr[4];  
  arr[0] = LED1;
  arr[1] = LED2;
  arr[2] = LED3;
  arr[3] = LED4;
  
  //leer serial y asignaro a i
  i = Serial.parseInt();

  // si i es mayor a 15
if (i > 15) {
      Serial.println("Error: Ingrese un número menor o igual a 15");
    } else {
    
    for (int j = 0; j < 4; j++) {
      // shiftear i j veces y tomar el bit menos significativo, si es 0 se apaga ese led y si es 1 se prende
      digitalWrite(arr[j], (i >> j) & 1); // prender o apagar el LED según el bit correspondiente
    }
    }

  }
