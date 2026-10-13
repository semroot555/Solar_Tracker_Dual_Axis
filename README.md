# Two-Axis Solar Tracker

A two-axis solar tracker prototype made with an Arduino Nano, LDR sensors, SG90 servo motors, and a 3D-printed structure.

## Project overview

The goal of this project was to create a structure that can move horizontally and vertically based on light readings.

Our work focused on:

- programming an Arduino Nano;
- controlling two servo motors;
- preparing a control system using four LDR sensors;
- designing the structure in 3D;
- 3D-printing and assembling the structure;
- testing the movement of the servo motors.

## Project images

### Tinkercad simulation

![Tinkercad simulation](docs/images/tinkercad-simulation.jpg)

### 3D design and printed structure

![3D model](docs/images/3d-model.jpg)

### Final prototype

![Final prototype](docs/images/final-prototype.jpg)

## Components

- Arduino Nano
- Two SG90 servo motors
- Four LDR light sensors
- Four 10 kΩ resistors
- Breadboard
- Jumper wires
- 3D-printed mechanical structure

## How the system works

The Arduino reads the values from four LDR sensors.

The sensors are placed in four positions:

- top-left;
- top-right;
- bottom-left;
- bottom-right.

The Arduino compares the sensor readings. If the left and right readings are different, it moves the horizontal servo. If the top and bottom readings are different, it moves the vertical servo.

A tolerance value is used so that the servos do not move because of very small differences.

## Pin connections

| Component | Arduino pin |
|---|---|
| Top-left LDR | A0 |
| Top-right LDR | A1 |
| Bottom-left LDR | A2 |
| Bottom-right LDR | A3 |
| Horizontal servo | D9 |
| Vertical servo | D10 |

## Code

The folder `code` contains the original Arduino code used for the Tinkercad simulation.

This is the simulation version of the code. It should not be confused with a final tested hardware version.

## 3D modelling and printing

The tracker structure was designed in 3D before being printed.

The design included:

- a fixed base;
- supports for the servo motors;
- a moving arm;
- a platform for the sensors and future solar panel;
- mounting points for the different parts.

The printed parts were assembled with the servo motors and tested for movement.

## Current status

This project focused on Arduino programming, servo movement, 3D modelling, and 3D printing.

We did not measure:

- solar-panel energy production;
- efficiency;
- electrical power;
- energy gain compared with a fixed panel.

These measurements could be added in a future version.

## Future improvements

- Add and calibrate the four LDR sensors.
- Add the final tested hardware code.
- Improve the servo and panel mounting system.
- Test the tracker with a real solar panel.
- Measure the electrical output.
- Improve the stability of the structure.

## Report

The project report is available in the `docs` folder.

