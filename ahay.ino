
int speakerPin = 8; // kutup + buzzer atau speaker dipasang pada pin 8 Arduino
/*
//LAGU 1 (DO RE MI FA SOL …)
int length = 16; // ini panjang lagu
char notes[] = "cdefgabCCbagfedc"; // ini lagunya
int beats[] = { 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 4 }; // ini ketukannya
*/


// LAGU 2 (Twinkle twinkle)
int length = 15; // ini panjang lagu
char notes[] = "ccggaagffeeddc "; // ini lagunya
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 }; // ini ketukannya

/*
//LAGU 3 (do mi sol Do …Do sol mi do)
int length = 8 ; // ini panjang lagu
char notes[] = "cegCCgec"; // ini lagunya
int beats[] = { 1, 1, 1, 4, 1, 1, 1, 4 }; // ini ketukannya
*/
int tempo = 350;
void playTone(int tone, int duration) {
for (long i = 0; i < duration * 1000L; i += tone * 2) {
digitalWrite(speakerPin, HIGH);
delayMicroseconds(tone);
digitalWrite(speakerPin, LOW);
delayMicroseconds(tone);
}
}
void playNote(char note, int duration) {
char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
for (int i = 0; i < 8; i++) {
if (names[i] == note) {
playTone(tones[i], duration);
}
}
}
void setup() {
pinMode(speakerPin, OUTPUT);
}
void loop() {
for (int i = 0; i < length; i++) {
if (notes[i] == ' ') {
delay(beats[i] * tempo); // rest
} else {
playNote(notes[i], beats[i] * tempo);
}

delay(tempo / 2);
}
}
