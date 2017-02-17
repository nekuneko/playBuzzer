/*
 * Programa que permite reproducir música nota a nota a través de un piezo o altavoz.
 * 
 * Recomendaciones personales:
 *  - Hacer pausas con           silencio(semicorchea);
 *  - Terminar las canciones con silencio(blanca);
 * 
 * Variables Globales:
 *  - speaker:  pin analógico (pwm) al que se encuentra conectado el polo positivo de buzzer, valor positivo
 *  - tempo:    velocidad de pulsación de las notas musicales, valor positivo flotante
 *  - escala:   nivel de grave a agudo, posibles valores de 1 a 5.
 * 
 * Funciones para crear canciones:
 *  - tocar (uint16_t nota);    // Frecuencia de la nota
 *  - puntillo (float t_nota);  // Duración del tipo de nota para puntillo
 *  - silencio (float t_nota);  // Duración del silencio para cada tipo de nota
 *  - actualizarTempo (float tempo); // Velocidad de pulsación de las notas (tiempos de cada tipo de nota)
 *  
 * Antes de tocar una canción debe usarse la función actualizarTempo(tempo) para establecer
 * la velocidad con la que se toca una canción. Toda canción debe finalizar con silencio(0)
 * para apagar el buzzer y que deje de sonar.
 * 
 * Para crear una canción, crear una función void que tenga como argumento un uint8_t llamado
 * 'escala'. Para tocar una nota hace falta llamar a la función tocar(uint16_t nota) y para
 * establecer la duración temporal hay que invocar inmediatamente a la función delay(t_nota)
 * siendo t_nota cualquier tipo de nota: semicorchea, corchea, negra, blanca, redonda.
 * 
 * @author  Javier Villaverde Ramallo
 * @fecha   17 de Febrero de 2016
 * @version 2.0
 */

// Notas musicales: Tenemos 7 escalas de notas, numeradas de 0 a 6
const uint16_t DO[7]    = {33,  65, 131, 262, 523, 1047, 2093};
const uint16_t DO_[7]   = {35,  69, 139, 277, 554, 1109, 2217};
const uint16_t RE[7]    = {37,  73, 147, 294, 587, 1175, 2349};
const uint16_t RE_[7]   = {39,  78, 156, 311, 622, 1245, 2489};
const uint16_t MI[7]    = {41,  82, 165, 330, 659, 1319, 2637};
const uint16_t FA[7]    = {44,  87, 175, 349, 698, 1397, 2794};
const uint16_t FA_[7]   = {46,  93, 185, 370, 740, 1480, 2960};
const uint16_t SOL[7]   = {49,  98, 196, 392, 784, 1568, 3136};
const uint16_t SOL_[7]  = {52, 104, 208, 415, 831, 1661, 3322};
const uint16_t LA[7]    = {55, 110, 220, 440, 880, 1760, 3520};
const uint16_t LA_[7]   = {58, 117, 233, 466, 932, 1865, 3729};
const uint16_t SI[7]    = {62, 123, 247, 494, 988, 1976, 3951};

// Notas musicales restantes
#define SI0   31
#define DO8   4186
#define DOS8  4435
#define RE8   4699
#define RES8  4978

// Altavoz
const int speaker = 6;  // PIN6 --(PIEZO)-- GND

// Velocidad de reproducción
float tempo = 1.0;

// Escala musical, valor entre 1 y 5, de grave a aguda
uint8_t escala = 3;

// Duración de las notas (Milisegundos)
float semicorchea = 62   * tempo;
float corchea     = 125  * tempo;
float negra       = 250  * tempo;
float blanca      = 500  * tempo;
float redonda     = 1000 * tempo;


void setup() 
{
  pinMode(speaker, OUTPUT);
  delay(1000);
  
  actualizarTempo(2.0);
  //cancionTiempo(escala);
  
  actualizarTempo(1.2);
  //cancionTormenta(escala); 

  actualizarTempo(1.5);
  //greenSleeves(escala);

  actualizarTempo(1.3);
  //hockey(escala);
  
  silencio(0);
}

void loop() { }


void tocar (uint16_t nota)
{
  tone(speaker, nota); 
}


void puntillo (float tipo_nota)
{
  if (tipo_nota == semicorchea)
    delay(semicorchea + semicorchea/2.0);
  else if (tipo_nota == corchea)
      delay(corchea + corchea/2.0);
  else if (tipo_nota == negra)
      delay(negra + negra/2.0);
  else if (tipo_nota == blanca)
      delay(blanca + blanca/2.0);
  else if (tipo_nota == redonda)
      delay(redonda + redonda/2.0);      
}


void silencio (float tipo_nota)
{
  noTone(speaker);

  if (tipo_nota == semicorchea)
    delay(semicorchea);
  else if (tipo_nota == corchea)
      delay(corchea);
  else if (tipo_nota == negra)
      delay(negra);
  else if (tipo_nota == blanca)
      delay(blanca);
  else if (tipo_nota == redonda)
      delay(redonda);
  else
    delay(tipo_nota); // Una nota desconocida de diferente duración   
}


void actualizarTempo (float tempo)
{
  // Duración de las notas (Milisegundos)
  semicorchea = 62   * tempo;
  corchea     = 125  * tempo;
  negra       = 250  * tempo;
  blanca      = 500  * tempo;
  redonda     = 1000 * tempo;
}



// ----- Canciones -----

// Canción del Tiempo
void cancionTiempo (uint8_t escala)
{
  tocar(LA[escala]);
  delay(negra);

  tocar(RE[escala]);
  delay(blanca);

  silencio(semicorchea);
  
  tocar(FA[escala]);
  delay(negra);

  tocar(LA[escala]);
  delay(negra);

  tocar(RE[escala]);
  delay(blanca);

  silencio(semicorchea);
  
  tocar(FA[escala]);
  delay(negra);

  tocar(LA[escala]);
  delay(corchea);

  tocar(DO[escala+1]);
  delay(corchea);

  tocar(SI[escala]);
  delay(negra);

  tocar(SOL[escala]);
  delay(negra);

  tocar(FA[escala]);
  delay(corchea);

  tocar(SOL[escala]);
  delay(corchea);

  tocar(LA[escala]);
  delay(negra);

  tocar(RE[escala]);
  delay(negra);

  tocar(DO[escala]);
  delay(corchea);

  tocar(MI[escala]);
  delay(corchea);

  tocar(RE[escala]);
  delay(blanca);

  silencio(blanca);
}


// Canción de la tormenta
void cancionTormenta (uint8_t escala)
{
    // re fa RE re fa RE
    tocar(RE[escala]);
    delay(corchea);

    tocar(FA[escala]);
    delay(corchea);

    tocar(RE[escala+1]);
    delay(blanca);

    silencio(semicorchea);

    tocar(RE[escala]);
    delay(corchea);

    tocar(FA[escala]);
    delay(corchea);

    tocar(RE[escala+1]);
    delay(blanca);

    silencio(semicorchea);

    // MI FA MI FA MI DO la
    tocar(MI[escala+1]);
    puntillo(negra);

    tocar(FA[escala+1]);
    delay(corchea);

    tocar(MI[escala+1]);
    delay(corchea);

    tocar(FA[escala+1]);
    delay(corchea);

    tocar(MI[escala+1]);
    delay(corchea);

    tocar(DO[escala+1]);
    delay(corchea);

    tocar(LA[escala]);
    delay(blanca);

    silencio(semicorchea);

    // la re fa sol la
    tocar(LA[escala]);
    delay(negra);

    tocar(RE[escala]);
    delay(negra);

    tocar(FA[escala]);
    delay(corchea);

    tocar(SOL[escala]);
    delay(corchea);

    tocar(LA[escala]);
    puntillo(blanca);

    silencio(semicorchea);

    // la re fa sol mi
    tocar(LA[escala]);
    delay(negra);

    tocar(RE[escala]);
    delay(negra);

    tocar(FA[escala]);
    delay(corchea);

    tocar(SOL[escala]);
    delay(corchea);

    tocar(MI[escala]);
    puntillo(blanca);

// Mitad de la canción

    // re fa RE re fa RE
    tocar(RE[escala]);
    delay(corchea);

    tocar(FA[escala]);
    delay(corchea);

    tocar(RE[escala+1]);
    delay(blanca);

    silencio(semicorchea);

    tocar(RE[escala]);
    delay(corchea);

    tocar(FA[escala]);
    delay(corchea);

    tocar(RE[escala+1]);
    delay(blanca);

    silencio(semicorchea);

    // MI FA MI FA MI DO la
    tocar(MI[escala+1]);
    puntillo(negra);

    tocar(FA[escala+1]);
    delay(corchea);

    tocar(MI[escala+1]);
    delay(corchea);

    tocar(FA[escala+1]);
    delay(corchea);

    tocar(MI[escala+1]);
    delay(corchea);

    tocar(DO[escala+1]);
    delay(corchea);

    tocar(LA[escala]);
    delay(blanca);

    silencio(semicorchea);

    // la re fa sol
    tocar(LA[escala]);
    delay(negra);

    tocar(RE[escala]);
    delay(negra);

    tocar(FA[escala]);
    delay(corchea);

    tocar(SOL[escala]);
    delay(corchea);

    // la la re
    tocar(LA[escala]);
    delay(blanca);

    silencio(semicorchea);
    
    tocar(LA[escala]);
    delay(negra);

    tocar(RE[escala]);
    delay(blanca);

    silencio(blanca);   
}


// Green Sleeves
void greenSleeves (uint8_t escala)
{
   tocar(LA[escala]);
   delay(negra);

   tocar(DO[escala+1]);
   delay(blanca);

   silencio(semicorchea);

   tocar(RE[escala+1]);
   delay(negra);

   tocar(MI[escala+1]);
   puntillo(negra);

   tocar(FA[escala+1]);
   delay(corchea);

   tocar(MI[escala+1]);
   delay(negra);

   tocar(RE[escala+1]);
   delay(blanca);

   silencio(semicorchea);

   tocar(SI[escala]);
   delay(negra);

   tocar(SOL[escala]);
   puntillo(negra);

   tocar(LA[escala]);
   delay(corchea);

   tocar(SI[escala]);
   delay(negra);

   tocar(DO[escala+1]);
   delay(blanca);

   silencio(corchea);

   tocar(LA[escala]);
   delay(negra);

   silencio(semicorchea);

   tocar(LA[escala]);
   puntillo(negra);

   tocar(SOL_[escala]);
   delay(corchea);

   tocar(LA[escala]);
   delay(negra);

   silencio(semicorchea);

   //7 ----------------------

   tocar(SI[escala]);
   delay(blanca);

   silencio(semicorchea);
   
   tocar(SOL_[escala]);
   delay(negra);

   tocar(MI[escala]);
   delay(blanca);

   silencio(corchea);

   tocar(LA[escala]);
   delay(negra);

   tocar(DO[escala+1]);
   delay(blanca);

   silencio(semicorchea);

   tocar(RE[escala+1]);
   delay(negra);

   tocar(MI[escala+1]);
   puntillo(negra);

   tocar(FA[escala+1]);
   delay(corchea);

   tocar(MI[escala+1]);
   delay(negra);

   tocar(RE[escala+1]);
   delay(blanca);

   silencio(semicorchea);

   tocar(SI[escala]);
   delay(negra);

   tocar(SOL[escala]);
   puntillo(negra);

   tocar(LA[escala]);
   delay(corchea);

   tocar(SI[escala]);
   delay(negra);

   tocar(DO[escala+1]);
   delay(blanca);

   silencio(semicorchea);
   
   // 13 -------------------

   tocar(DO[escala+1]);
   puntillo(negra);

   silencio(semicorchea);

   tocar(SI[escala]);
   delay(corchea);

   tocar(LA[escala]);
   delay(negra);

   tocar(SOL_[escala]);
   puntillo(negra);

   tocar(FA_[escala]);
   delay(corchea);

   tocar(SOL_[escala]);
   delay(negra);

   tocar(LA[escala]);
   puntillo(blanca);

   silencio(semicorchea);

   tocar(LA[escala]);
   puntillo(blanca);

   silencio(corchea);

   tocar(SOL[escala+1]);
   puntillo(blanca);

   silencio(semicorchea);

   tocar(SOL[escala+1]);
   puntillo(negra);

   tocar(FA[escala+1]);
   delay(corchea);

   tocar(MI[escala+1]);
   delay(negra);

   tocar(RE[escala+1]);
   delay(blanca);

   tocar(SI[escala]);
   delay(negra);

   tocar(SOL[escala]);
   puntillo(negra);

   tocar(LA[escala]);
   delay(corchea);

   tocar(SI[escala]);
   delay(negra);

   silencio(semicorchea);

   // 21 -------------------

   tocar(DO[escala+1]);
   delay(blanca);

   silencio(semicorchea);

   tocar(LA[escala]);
   delay(negra);

   tocar(LA[escala]);
   puntillo(negra);

   tocar(SOL_[escala]);
   delay(corchea);

   tocar(LA[escala]);
   delay(negra);

   tocar(SI[escala]);
   delay(blanca);

   silencio(semicorchea);

   tocar(SOL_[escala]);
   delay(negra);

   tocar(MI[escala]);
   puntillo(blanca);

   silencio(corchea);

   tocar(SOL[escala+1]);
   puntillo(blanca);

   silencio(corchea);

   tocar(SOL[escala+1]);
   puntillo(negra);

   tocar(FA[escala+1]);
   delay(corchea);

   tocar(MI[escala+1]);
   delay(negra);

   silencio(semicorchea);

   // 27 ----------------

   tocar(RE[escala+1]);
   delay(blanca);

   silencio(semicorchea);

   tocar(SI[escala]);
   delay(negra);

   tocar(SOL[escala]);
   puntillo(negra);

   tocar(LA[escala]);
   delay(corchea);

   tocar(SI[escala]);
   delay(negra);

   tocar(DO[escala+1]);
   puntillo(negra);

   tocar(SI[escala]);
   delay(corchea);

   tocar(LA[escala]);
   delay(negra);

   tocar(SOL_[escala]);
   puntillo(negra);

   silencio(semicorchea);
   
   tocar(FA_[escala]);
   delay(corchea);

   tocar(SOL_[escala]);
   delay(negra);

   tocar(LA[escala]);
   puntillo(blanca);

   silencio(corchea);

   tocar(LA[escala]);
   puntillo(blanca);

   silencio(blanca);
}


// Acorde final de órgano de hockey
void hockey (uint8_t escala)
{
  tocar(SI[escala]);
  delay(corchea);

  tocar(MI[escala+1]);
  delay(corchea);

  tocar(SOL_[escala+1]);
  delay(corchea);

  tocar(SI[escala+1]);
  delay(negra);

  tocar(SOL_[escala+1]);
  delay(corchea);

  tocar(SI[escala+1]);
  delay(blanca);
  delay(semicorchea);
}

