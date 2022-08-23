# QuadLevelShifterTesting
This is test code for a quad 3.3V <--> 5V level shifter.
Assumptions: 5V arduino with 4 digital I/O pins (Actual code: mega) and 2 analog inputs.
Connections: connect each digital I/O pins to its own HVn of level shifter.
Connect LV1 & LV2 and connect these to Analog Input 0
Connect LV3 & LV4 and connect these to Analog Input 1
# Theory
Assert a digital I/O low and high. The associated digital I/O should be configured as an input and should be the same value.
Additionally, Analog Input 0 or 1 should be the expected value - either 0V or 3.3 V
# Pseudo Code
```
loop 1 --> 4
  loop low --> high
    calculate assert pin
              sense pin (digital)
              sense pin (analog)
    set pin modes
    pause
    set output
    pause
    read inputs
    print
    pause
  end value loop
end HVn/LVn & friend loop
```
