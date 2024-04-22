/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica_3 Bimestre II
   Dev: Sebastian Enrique Lemus Salvador
   Fecha: 19 de abril
   
   Link de la simulación en Tinkercad: https://www.tinkercad.com/things/7O4lBu4a2Rl-practica-3-taller-ii-bimestre
   
*/

#define pausa delay(1000);

byte producto = 0;

struct stocks_productos{
  char Nombre[50];
  byte Cantidad;
  char Variable[50];
};

stocks_productos Dorito = {"Dorito", 33, "A."};
stocks_productos CocaCola = {"CocaCola", 45, "B."};          
stocks_productos Tortrix = {"Tortrix de Limon", 25, "C."};
stocks_productos Hersheys = {"Hershey Blanco", 50, "D."};         


void setup() {
  Serial.begin(9600); // Inicio la comunicación serial.
  pinMode(2, INPUT);  // Pongo los 3 push button como entrada
  pinMode(3, INPUT);
  
  Serial.println("Bienvenido  \n");
  Serial.println("A continuacion se muestra los 4 productos en la maquina expendedora: \n");
  Serial.println("---para seguir presionar el 1er boton---\n---para regresar pulsar el 2do boton--- \n");
}

int maquina_expendedora(){
  
  if(producto == 1){
    Serial.println("El primer producto es: \n");
    Serial.println(Dorito.Nombre);
    Serial.println(Dorito.Cantidad);
    Serial.println(Dorito.Variable);
    Serial.println("\n");
    pausa;
  }
  if(producto == 2){
    Serial.println("El segundo producto es: \n");
    Serial.println(CocaCola.Nombre);
    Serial.println(CocaCola.Cantidad);
    Serial.println(CocaCola.Variable);
    Serial.println("\n");
    pausa;
  }
  if(producto == 3){
    Serial.println("El tercer producto es: \n");
    Serial.println(Tortrix.Nombre);
    Serial.println(Tortrix.Cantidad);
    Serial.println(Tortrix.Variable);
    Serial.println("\n");
    pausa;
  }
  if(producto == 4){
    Serial.println("El cuarto producto es: \n");
    Serial.println(Hersheys.Nombre);
    Serial.println(Hersheys.Cantidad);
    Serial.println(Hersheys.Variable);
    Serial.println("\n");
    pausa;
  }
  if(producto == 5){
    Serial.println("Se ha excedido de los 4 productos \n");
    Serial.println("Por favor presionar el 2do boton para regresar \n");
    pausa;
  }
}

void loop(){ 
  if (digitalRead(2) == HIGH) {
    producto = (producto + 1);
    maquina_expendedora();
  }
  if (digitalRead(3) == HIGH) {
    producto = (producto - 1);
    maquina_expendedora();
  }
}
