int happybday[] = {
  0,0,1,0,3,2
};

float freq[] = {
  261.625,
  293.664,
  329.627,
  349.228,
  391.995,
  440.000,
  493.883
};

int led = 9;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

float del = 100000;

// the loop routine runs over and over again forever:
void loop() {
  for (int j = 0; j < sizeof(happybday)/sizeof(int); j++) {
    for (int i = 0; i < float(200000/del); i++) {
      digitalWrite(led, 1);
      delayMicroseconds(int(del));
      digitalWrite(led, 0);
      delayMicroseconds(int(del));
    }
    delay(100);
//    del = int(random(10000));
    del = freqToInterval(freq[happybday[j]]);
    Serial.println(freq[j]);
    Serial.println(del);
  }
  //delay(1000);
}

float freqToInterval(float f) {
  float interval = float(1000000)/float(f);
  return interval;
}
