int C = 0;
int Db = 1;
int D = 2;
int Eb = 3;
int E = 4;
int F = 5;
int Gb = 6;
int G = 7;
int Ab = 8;
int A = 9;

int notes[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

int music[] = {C, C, D, C, F, E, C, C, D, C, G, F};

void setup() {
  pinMode(9,OUTPUT);

}

void loop() {

  for(int i = 0; i< 12; i++) {
    tone(9, notes[music[i]]);
    delay(500);
  }
  

}
