void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(200);
  }
  Serial.println("Testing quad level shifter");
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int input_pin = 1; input_pin <= 4; input_pin++ ) {
    for (int expected_value = 0; expected_value <= 1; expected_value++) {
      do_test(input_pin, expected_value);
    }
  }
  Serial.println("All tests completed.");
  delay(5000L);
}

void do_test(int inp, int test_value) {
  int digital_assert_pin;
  int digital_sense_pin;
  int analog_sense_pin;
  int digital_sense_value;
  int analog_sense_value;

  switch (inp) {
    case 1:
      digital_assert_pin = 41;
      digital_sense_pin = 42;
      analog_sense_pin = A0;
      break;
    case 2:
      digital_assert_pin = 42;
      digital_sense_pin = 41;
      analog_sense_pin = A0;
      break;
    case 3:
      digital_assert_pin = 43;
      digital_sense_pin = 44;
      analog_sense_pin = A1;
      break;
    case 4:
      digital_assert_pin = 44;
      digital_sense_pin = 43;
      analog_sense_pin = A1;
      break;
    default:
      Serial.println("illegal pin value");
      delay(999999L);
  }
  switch (test_value) {
    case 0:
    case 1:
      break;
    default:
      Serial.println("illegal test value");
      delay(999999L);
  }

  set_pin_modes(digital_assert_pin, digital_sense_pin);
  delay(1);
  digitalWrite(digital_assert_pin, test_value);
  delay(1);
  digital_sense_value = digitalRead(digital_sense_pin);
  analog_sense_value = analogRead(analog_sense_pin);
  delay(1);
  digital_sense_value = digitalRead(digital_sense_pin);
  analog_sense_value = analogRead(analog_sense_pin);

  Serial.print("P1="); Serial.print(digital_assert_pin);
  Serial.print(" P2="); Serial.print(digital_sense_pin);
  Serial.print(" P3="); Serial.print(analog_sense_pin);
  Serial.print(" TV="); Serial.print(test_value);
  Serial.print(" DO="); Serial.print(digital_sense_value);
  Serial.print(" AO="); Serial.print(analog_sense_value);
  if (test_value != digital_sense_value) {
    Serial.print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  }
  Serial.println();
  delay(1000);
//  while (Serial.available()<=1) {
//    delay(5);
//  }
//  Serial.read();
}

void set_pin_modes(int digital_output_pin, int digital_input_pin) {
  pinMode(digital_output_pin, OUTPUT);
  pinMode(digital_input_pin, INPUT_PULLUP);
}
