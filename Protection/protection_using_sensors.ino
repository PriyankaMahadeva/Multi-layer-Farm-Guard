#define TRIG_PIN_1 6
#define ECHO_PIN_1 2

#define TRIG_PIN_2 7
#define ECHO_PIN_2 3

#define PIR_PIN_1 4
#define PIR_PIN_2 5

#define BUZZER_PIN 13

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);

  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  pinMode(PIR_PIN_1, INPUT);
  pinMode(PIR_PIN_2, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Read Ultrasonic sensor 1
  long duration_1, distance_1;
  digitalWrite(TRIG_PIN_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_1, LOW);
  duration_1 = pulseIn(ECHO_PIN_1, HIGH);
  distance_1 = duration_1 * 0.034 / 2;

  // Read Ultrasonic sensor 2
  long duration_2, distance_2;
  digitalWrite(TRIG_PIN_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_2, LOW);
  duration_2 = pulseIn(ECHO_PIN_2, HIGH);
  distance_2 = duration_2 * 0.034 / 2;

  // Read PIR sensor 1
  int pir_1_state = digitalRead(PIR_PIN_1);

  // Read PIR sensor 2
  int pir_2_state = digitalRead(PIR_PIN_2);

  Serial.print("Ultrasonic Sensor 1 Distance: ");
  Serial.print(distance_1);
  Serial.println(" cm");

  Serial.print("Ultrasonic Sensor 2 Distance: ");
  Serial.print(distance_2);
  Serial.println(" cm");

  Serial.print("PIR Sensor 1 State: ");
  Serial.println(pir_1_state);

  Serial.print("PIR Sensor 2 State: ");
  Serial.println(pir_2_state);

  // Check if any sensor is triggered
  if (distance_1 < 20) {
    // If ultrasonic sensor 1 is triggered, turn on the buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Buzzer ON - Ultrasonic Sensor 1");
  } else if (distance_2 < 20) {
    // If ultrasonic sensor 2 is triggered, turn on the buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Buzzer ON - Ultrasonic Sensor 2");
  } else if (pir_1_state == 0) {
    // If PIR sensor 1 is triggered, turn on the buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Buzzer ON - PIR Sensor 1");
  } else if (pir_2_state == 0) {
    // If PIR sensor 2 is triggered, turn on the buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Buzzer ON - PIR Sensor 2");
  } else {
    // If no sensor is triggered, turn off the buzzer
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Buzzer OFF");
  }

  // Delay for stability
  delay(100);
}
