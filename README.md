# Axiom Project (Science Fair Project)

This project uses an ultrasonic sensor and a servo motor to control a gate based on distance measurements. The setup demonstrates how to calculate straight-line distances using the Pythagorean theorem for accurate sensor placement.

## How It Works

- Measures distance using an HC-SR04 ultrasonic sensor.
- Controls a servo gate based on detected distance.
- Uses the Pythagorean theorem to help calculate sensor-to-object range for optimal placement.

## Quick Start

1. Wire the ultrasonic sensor to pins 8 (echo) and 9 (trig) on your Arduino.
2. Connect the servo to pin 10.
3. Upload the `Axiom_Project.ino` file to your Arduino.
4. Adjust the trigger distances in the code as needed.

## Example Calculation

If your sensor is 8.8 cm above the ground and the object is 9 cm away horizontally:
```
hypotenuse = sqrt(8.8^2 + 9^2) ≈ 12.6 cm
```

## Credits

Created by serial-commit-dev for science fair and educational purposes.
