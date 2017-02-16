/*
 * Programa que permite reproducir música nota a nota a través
 * de un piezo o altavoz.
 * 
 * Recomendaciones:
 *  - Hacer pausas con           silencio(semicorchea);
 *  - Terminar las canciones con silencio(blanca);
 * 
 * @author  Javier Villaverde Ramallo
 * @fecha   17 de Octubre de 2015
 * @version 1.0
 */
 
// Notas musicales.
#define SI0   31
#define DO1   33
#define DOS1  35
#define RE1   37
#define RES1  39
#define MI1   41
#define FA1   44
#define FAS1  46
#define SOL1  49
#define SOLS1 52
#define LA1   55
#define LAS1  58
#define SI1   62
#define DO2   65
#define DOS2  69
#define RE2   73
#define RES2  78
#define MI2   82
#define FA2   87
#define FA    93
#define SOL2  98
#define SOLS2 104
#define LA2   110
#define LAS2  117
#define SI2   123
#define DO3   131
#define DOS3  139
#define RE3   147
#define RES3  156
#define MI3   165
#define FA3   175
#define FAS3  185
#define SOL3  196
#define SOLS3 208
#define LA3   220
#define LAS3  233
#define SI3   247
#define DO4   262
#define DOS4  277
#define RE4   294
#define RES4  311
#define MI4   330
#define FA4   349
#define FAS4  370
#define SOL4  392
#define SOLS4 415
#define LA4   440
#define LAS4  466
#define SI4   494
#define DO5   523
#define DOS5  554
#define RE5   587
#define RES5  622
#define MI5   659
#define FA5   698
#define FAS5  740
#define SOL5  784
#define SOLS5 831
#define LA5   880
#define LAS5  932
#define SI5   988
#define DO6   1047
#define DOS6  1109
#define RE6   1175
#define RES6  1245
#define MI6   1319
#define FA6   1397
#define FAS6  1480
#define SOL6  1568
#define SOLS6 1661
#define LA6   1760
#define LAS6  1865
#define SI6   1976
#define DO7   2093
#define DOS7  2217
#define RE7   2349
#define RES7  2489
#define MI7   2637
#define FA7   2794
#define FAS7  2960
#define SOL7  3136
#define SOLS7 3322
#define LA7   3520
#define LAS7  3729
#define SI7   3951
#define DO8   4186
#define DOS8  4435
#define RE8   4699
#define RES8  4978

// Altavoz
const int speaker = 9;  // PIN9 --(PIEZO)-- GND

// Escala del tiempo
float escala = 1;

// Duración de las notas (Milisegundos)
float semicorchea = 62   * escala;
float corchea     = 125  * escala;
float negra       = 250  * escala;
float blanca      = 500  * escala;
float redonda     = 1000 * escala;

void setup() 
{
  pinMode(speaker, OUTPUT);

  //  tocar(LA5);
  //delay(10000);
  
  actualizarEscala(2.0);
  //cancionTiempo();
  
  actualizarEscala(1.2);
  //cancionTormenta(); 

  actualizarEscala(1.5);
  //greenSleeves();

  actualizarEscala(1.3);
  //hockey();
  
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
}


void actualizarEscala(float escala)
{
  semicorchea = 62   * escala;
  corchea     = 125  * escala;
  negra       = 250  * escala;
  blanca      = 500  * escala;
  redonda     = 1000 * escala;
}



// ----- Canciones -----

// Canción del Tiempo
void cancionTiempo ()
{
  tocar(LA5);
  delay(negra);

  tocar(RE5);
  delay(blanca);

  silencio(semicorchea);
  
  tocar(FA5);
  delay(negra);

  tocar(LA5);
  delay(negra);

  tocar(RE5);
  delay(blanca);

  silencio(semicorchea);
  
  tocar(FA5);
  delay(negra);

  tocar(LA5);
  delay(corchea);

  tocar(DO6);
  delay(corchea);

  tocar(SI5);
  delay(negra);

  tocar(SOL5);
  delay(negra);

  tocar(FA5);
  delay(corchea);

  tocar(SOL5);
  delay(corchea);

  tocar(LA5);
  delay(negra);

  tocar(RE5);
  delay(negra);

  tocar(DO5);
  delay(corchea);

  tocar(MI5);
  delay(corchea);

  tocar(RE5);
  delay(blanca);

  silencio(blanca);
}


// Canción de la tormenta
void cancionTormenta ()
{
    // re fa RE re fa RE
    tocar(RE5);
    delay(corchea);

    tocar(FA5);
    delay(corchea);

    tocar(RE6);
    delay(blanca);

    silencio(semicorchea);

    tocar(RE5);
    delay(corchea);

    tocar(FA5);
    delay(corchea);

    tocar(RE6);
    delay(blanca);

    silencio(semicorchea);

    // MI FA MI FA MI DO la
    tocar(MI6);
    puntillo(negra);

    tocar(FA6);
    delay(corchea);

    tocar(MI6);
    delay(corchea);

    tocar(FA6);
    delay(corchea);

    tocar(MI6);
    delay(corchea);

    tocar(DO6);
    delay(corchea);

    tocar(LA5);
    delay(blanca);

    silencio(semicorchea);

    // la re fa sol la
    tocar(LA5);
    delay(negra);

    tocar(RE5);
    delay(negra);

    tocar(FA5);
    delay(corchea);

    tocar(SOL5);
    delay(corchea);

    tocar(LA5);
    puntillo(blanca);

    silencio(semicorchea);

    // la re fa sol la
    tocar(LA5);
    delay(negra);

    tocar(RE5);
    delay(negra);

    tocar(FA5);
    delay(corchea);

    tocar(SOL5);
    delay(corchea);

    tocar(MI5);
    puntillo(blanca);

// Mitad de la canción

    // RE FA RE RE FA RE
    tocar(RE5);
    delay(corchea);

    tocar(FA5);
    delay(corchea);

    tocar(RE6);
    delay(blanca);

    silencio(semicorchea);

    tocar(RE5);
    delay(corchea);

    tocar(FA5);
    delay(corchea);

    tocar(RE6);
    delay(blanca);

    silencio(semicorchea);

    // MI FA MI FA MI DO la
    tocar(MI6);
    puntillo(negra);

    tocar(FA6);
    delay(corchea);

    tocar(MI6);
    delay(corchea);

    tocar(FA6);
    delay(corchea);

    tocar(MI6);
    delay(corchea);

    tocar(DO6);
    delay(corchea);

    tocar(LA5);
    delay(blanca);

    silencio(semicorchea);

    // la re fa sol
    tocar(LA5);
    delay(negra);

    tocar(RE5);
    delay(negra);

    tocar(FA5);
    delay(corchea);

    tocar(SOL5);
    delay(corchea);

    // la la re
    tocar(LA5);
    delay(blanca);

    silencio(semicorchea);
    
    tocar(LA5);
    delay(negra);

    tocar(RE5);
    delay(blanca);

    silencio(blanca);   
}


// Green Sleeves
void greenSleeves ()
{
   tocar(LA5);
   delay(negra);

   tocar(DO6);
   delay(blanca);

   silencio(semicorchea);

   tocar(RE6);
   delay(negra);

   tocar(MI6);
   puntillo(negra);

   tocar(FA6);
   delay(corchea);

   tocar(MI6);
   delay(negra);

   tocar(RE6);
   delay(blanca);

   silencio(semicorchea);

   tocar(SI5);
   delay(negra);

   tocar(SOL5);
   puntillo(negra);

   tocar(LA5);
   delay(corchea);

   tocar(SI5);
   delay(negra);

   tocar(DO6);
   delay(blanca);

   silencio(corchea);

   tocar(LA5);
   delay(negra);

   silencio(semicorchea);

   tocar(LA5);
   puntillo(negra);

   tocar(SOLS5);
   delay(corchea);

   tocar(LA5);
   delay(negra);

   silencio(semicorchea);

   //7 ----------------------

   tocar(SI5);
   delay(blanca);

   silencio(semicorchea);
   
   tocar(SOLS5);
   delay(negra);

   tocar(MI5);
   delay(blanca);

   silencio(corchea);

   tocar(LA5);
   delay(negra);

   tocar(DO6);
   delay(blanca);

   silencio(semicorchea);

   tocar(RE6);
   delay(negra);

   tocar(MI6);
   puntillo(negra);

   tocar(FA6);
   delay(corchea);

   tocar(MI6);
   delay(negra);

   tocar(RE6);
   delay(blanca);

   silencio(semicorchea);

   tocar(SI5);
   delay(negra);

   tocar(SOL5);
   puntillo(negra);

   tocar(LA5);
   delay(corchea);

   tocar(SI5);
   delay(negra);

   tocar(DO6);
   delay(blanca);

   silencio(semicorchea);
   
   // 13 -------------------

   tocar(DO6);
   puntillo(negra);

   silencio(semicorchea);

   tocar(SI5);
   delay(corchea);

   tocar(LA5);
   delay(negra);

   tocar(SOLS5);
   puntillo(negra);

   tocar(FAS5);
   delay(corchea);

   tocar(SOLS5);
   delay(negra);

   tocar(LA5);
   puntillo(blanca);

   silencio(semicorchea);

   tocar(LA5);
   puntillo(blanca);

   silencio(corchea);

   tocar(SOL6);
   puntillo(blanca);

   silencio(semicorchea);

   tocar(SOL6);
   puntillo(negra);

   tocar(FA6);
   delay(corchea);

   tocar(MI6);
   delay(negra);

   tocar(RE6);
   delay(blanca);

   tocar(SI5);
   delay(negra);

   tocar(SOL5);
   puntillo(negra);

   tocar(LA5);
   delay(corchea);

   tocar(SI5);
   delay(negra);

   silencio(semicorchea);

   // 21 -------------------

   tocar(DO6);
   delay(blanca);

   silencio(semicorchea);

   tocar(LA5);
   delay(negra);

   tocar(LA5);
   puntillo(negra);

   tocar(SOLS5);
   delay(corchea);

   tocar(LA5);
   delay(negra);

   tocar(SI5);
   delay(blanca);

   silencio(semicorchea);

   tocar(SOLS5);
   delay(negra);

   tocar(MI5);
   puntillo(blanca);

   silencio(corchea);

   tocar(SOL6);
   puntillo(blanca);

   silencio(corchea);

   tocar(SOL6);
   puntillo(negra);

   tocar(FA6);
   delay(corchea);

   tocar(MI6);
   delay(negra);

   silencio(semicorchea);

   // 27 ----------------

   tocar(RE6);
   delay(blanca);

   silencio(semicorchea);

   tocar(SI5);
   delay(negra);

   tocar(SOL5);
   puntillo(negra);

   tocar(LA5);
   delay(corchea);

   tocar(SI5);
   delay(negra);

   tocar(DO6);
   puntillo(negra);

   tocar(SI5);
   delay(corchea);

   tocar(LA5);
   delay(negra);

   tocar(SOLS5);
   puntillo(negra);

   silencio(semicorchea);
   
   tocar(FAS5);
   delay(corchea);

   tocar(SOLS5);
   delay(negra);

   tocar(LA5);
   puntillo(blanca);

   silencio(corchea);

   tocar(LA5);
   puntillo(blanca);

   silencio(blanca);
}


// Acorde final de órgano de hockey
void hockey ()
{
  tocar(SI4);
  delay(corchea);

  tocar(MI5);
  delay(corchea);

  tocar(SOLS5);
  delay(corchea);

  tocar(SI5);
  delay(negra);

  tocar(SOLS5);
  delay(corchea);

  tocar(SI5);
  delay(blanca);
  delay(corchea);
}

