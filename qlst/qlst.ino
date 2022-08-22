void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(200);
  }
  Serial.println("Hello!");
  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  Serial.println("Testing quad level shifter");
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(LED_BUILTIN, OUTPUT);

}
