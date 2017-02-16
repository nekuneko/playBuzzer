/*
 * Programa que permite reproducir música nota a nota a través
 * de un piezo o altavoz.
 * 
 * Recomendaciones:
 *  - Hacer pausas con           silencio(semicorchea);
 *  - Terminar las canciones con silencio(blanca);
 * 
 * @author  Javier Villaverde Ramallo
 * @fecha   17 de Febrero de 2016
 * @version 2.0
 */

// Tenemos 7 escalas de notas, numeradas de 0 a 6
uint16_t DO[7]    = {33,  65, 131, 262, 523, 1047, 2093};
uint16_t DO_[7]   = {35,  69, 139, 277, 554, 1109, 2217};
uint16_t RE[7]    = {37,  73, 147, 294, 587, 1175, 2349};
uint16_t RE_[7]   = {39,  78, 156, 311, 622, 1245, 2489};
uint16_t MI[7]    = {41,  82, 165, 330, 659, 1319, 2637};
uint16_t FA[7]    = {44,  87, 175, 349, 698, 1397, 2794};
uint16_t FA_[7]   = {46,  93, 185, 370, 740, 1480, 2960};
uint16_t SOL[7]   = {49,  98, 196, 392, 784, 1568, 3136};
uint16_t SOL_[7]  = {52, 104, 208, 415, 831, 1661, 3322};
uint16_t LA[7]    = {55, 110, 220, 440, 880, 1760, 3520};
uint16_t LA_[7]   = {58, 117, 233, 466, 932, 1865, 3729};
uint16_t SI[7]    = {62, 123, 247, 494, 988, 1976, 3951};

// Notas musicales restantes
#define SI0   31
#define DO8   4186
#define DOS8  4435
#define RE8   4699
#define RES8  4978

// Altavoz
const int speaker = 9;  // PIN9 --(PIEZO)-- GND

// Velocidad de reproducción
float tempo = 1.0;

// Escala musical
uint8_t escala = 5;

// Duración de las notas (Milisegundos)
float semicorchea = 62   * tempo;
float corchea     = 125  * tempo;
float negra       = 250  * tempo;
float blanca      = 500  * tempo;
float redonda     = 1000 * tempo;


void setup() 
{
  pinMode(speaker, OUTPUT);

  //tocar(LA[escala]);
  //delay(10000);
  
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


void tocar (float nota)
{
  tone(speaker, nota); 
}


void puntillo (float nota)
{
  if (nota == semicorchea)
    delay(semicorchea + semicorchea/2.0);
  else if (nota == corchea)
      delay(corchea + corchea/2.0);
  else if (nota == negra)
      delay(negra + negra/2.0);
  else if (nota == blanca)
      delay(blanca + blanca/2.0);
  else if (nota == redonda)
      delay(redonda + redonda/2.0);      
}


void silencio (float nota)
{
  noTone(speaker);

  if (nota == semicorchea)
    delay(semicorchea);
  else if (nota == corchea)
      delay(corchea);
  else if (nota == negra)
      delay(negra);
  else if (nota == blanca)
      delay(blanca);
  else if (nota == redonda)
      delay(redonda);
  else
    delay(nota);    
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

    // la re fa sol la
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

    // RE FA RE RE FA RE
    tocar(RE[escala]);
    delay(corchea);

    tocar(FA[escala]);
    delay(corchea);

    tocar(RE[escala]);
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
   tocar(LA[escala+1]);
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

  tocar(SI[escala]);
  delay(blanca);
  delay(semicorchea);
}

