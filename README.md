# Precision Electric Vehicle

## Project Overview

The Precision Electric Vehicle is a small, self contained vehicle designed to travel a precise distance as accurately as possible. The project is inspired by the Science Olympiad Electric Vehicle event, where consistency and mechanical reliability matter more than raw speed.

---

## Why I Built This Project

I first became interested in this type of system after watching videos of Science Olympiad Electric Vehicle builds and competitions. What stood out to me was how small mechanical details and software decisions could significantly impact accuracy over long distances.

I chose this project because it forces me to develop skills in multiple areas at once:

* CAD modeling of a lightweight, rigid chassis
* Mechanical transmission using belts, pulleys
* Precision distance sensing with rotary encoders
* Motor control and feedback based distance tracking
* Writing and debugging C++ code on an Arduino platform

This project is meant to be educational first, while still being functional and competition ready.

---

## System Design

### Mechanical Design

The chassis is built primarily from carbon fiber tubes and rods to maximize stiffness while keeping mass low. The frame uses 7 mm carbon fiber tubes as the main structural members, with 4 mm carbon fiber rods acting as the axels.

Four BaneBots T6 wheels are mounted using their respective hubs. The hubs clamp onto 4 mm shafts, which are supported by the 3d-printed frame. Power from the motor is transmitted using a GT2 timing belt rather than direct drive. This is aimed at reducing slippage.

A belt driven system was chosen instead of bevel gears because:

* GT2 belts have minimal backlash
* Belt tension can be adjusted easily
* The system is quieter and more forgiving during testing

### Drive System

The vehicle is driven by a JGB37 520 DC gear motor. This motor was selected because it provides a good balance of torque and speed, making it suitable for controlled acceleration and deceleration.

I plan to add a rotary encoder.  The encoder outputs 600 pulses per revolution, allowing the software to calculate distance traveled with high resolution.

### Electronics and Wiring

The wiring is intentionally simple to reduce points of failure. The core components are:

* Arduino microcontroller
* l298n motor driver
* Rotary encoder
* Power source

---

## Software and Control Logic

The control strategy is based on distance feedback rather than time alone.

Key features of the code include:

* Encoder based distance calculation
* Configurable target distance
* Controlled acceleration at startup
* Gradual deceleration as the vehicle approaches the target distance
* Automatic motor braking once the target distance is reached

Distance is calculated by converting encoder pulses into wheel rotations and then into linear distance using the known wheel circumference. This approach allows for consistent results even if battery voltage changes.

---

## Current Build Status

### Completed

* Initial CAD design of the chassis
* Selection of all mechanical and electrical components
* Basic frame assembly using carbon fiber tubes and rods
* Wheel and bearing mounting
* Initial motor control and encoder reading code
* Fine tuning belt tension and alignment

### In Progress

* Final chassis reinforcement
* Add secondary encoder
* Improving software acceleration and deceleration curves
* Repeatability testing over multiple runs

### Not Yet Done

* Competition level tuning and calibration

---

<img width="717" height="491" alt="image" src="https://github.com/user-attachments/assets/84e45fde-fdce-4e9d-9168-2bec62b5a7b8" />

![unnamed](https://github.com/user-attachments/assets/8045c88b-fc4b-4264-ade2-a38bcde1b4a0)

WIRING DIAGRAM

<img width="1009" height="754" alt="image" src="https://github.com/user-attachments/assets/2ec71202-5ee3-41a4-81d9-ef2a1c99e7b6" />


| Item                                                    | Quantity | Total Price | Shipping | Link                                                                                                                                                                           |
| ------------------------------------------------------- | -------- | ---------- | -------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Carbon Fiber Tube 7mm x 6mm x 1000mm                    | 5        | 17.58      | 8.74     | [https://windcatcherrc.com/product/carbon-fiber-tube-7mm-x-6mm-x-1000mm/](https://windcatcherrc.com/product/carbon-fiber-tube-7mm-x-6mm-x-1000mm/)                             |
| Carbon Fiber Rod 4mm x 1000mm                           | 2        | 8.68       | —        | [https://windcatcherrc.com/product-category/carbon_fiber/carbon-fiber-rod/](https://windcatcherrc.com/product-category/carbon_fiber/carbon-fiber-rod/)                         |
| 600 P/R Rotary Encoder                                  | 1        | 15.59      | 0        | [https://www.amazon.com/Encoder-Incremental-Optical-Measuring-Rotational/dp/B08QS2JCF6](https://www.amazon.com/Encoder-Incremental-Optical-Measuring-Rotational/dp/B08QS2JCF6) |
| JGB37-520 DC Motor                                      | 1        | 19.39      | 0        | [https://www.amazon.com/dp/B0CRDS7QFM?ie=UTF8&th=1](https://www.amazon.com/dp/B0CRDS7QFM?ie=UTF8&th=1)                                                                         |
| BaneBots T6 Wheel, 2-7/8" x 0.6", Hub Mount, 30A, Green | 4        | 13.80      | 9.80     | [https://banebots.com/t61p-293bg/](https://banebots.com/t61p-293bg/)                                                                                                           |
| T61 Hub, 4mm Shaft                                      | 4        | 16.80      | —        | [https://banebots.com/t61h-rm41/](https://banebots.com/t61h-rm41/)                                                                                                             |
| Metric Screw Assortment                                 | 1        | 16.99      | 0        | [https://www.amazon.com/Assortment-M2-M3-M4-M5/dp/B0CBMMPPKF/](https://www.amazon.com/Assortment-M2-M3-M4-M5/dp/B0CBMMPPKF/)                                                   |
| 130-2GT-6 Endless GT2 Belt                              | 1        | 12.99      | 0        | [https://www.amazon.com/RobotDigg-130-2gt-6-Endless-Length-Synchronous/dp/B07B5YYNZG](https://www.amazon.com/RobotDigg-130-2gt-6-Endless-Length-Synchronous/dp/B07B5YYNZG)     |
| Barska 4X Rimfire Rifle Scope                           | 1        | 16.99      | 0        | [https://www.amazon.com/dp/B001JJCI0G/ref=twister_B0CNV76G97](https://www.amazon.com/dp/B001JJCI0G/ref=twister_B0CNV76G97)                                                     |
| GT2 Timing Belt Pulley, 20 Teeth, 4mm Bore              | 1        | 5.99       | 0        | [https://www.amazon.com/WINSINN-Aluminum-Synchronous-Timing-Printer/dp/B07CXSSGF8](https://www.amazon.com/WINSINN-Aluminum-Synchronous-Timing-Printer/dp/B07CXSSGF8)           |
| GT2 Timing Belt Pulley, 16 Teeth, 6mm Bore              | 1        | 6.99       | 0        | [https://www.amazon.com/WINSINN-Aluminum-Synchronous-Timing-Printer/dp/B07CXM18MK](https://www.amazon.com/WINSINN-Aluminum-Synchronous-Timing-Printer/dp/B07CXM18MK)           |
| NEIKO 50458A Snap Ring Assortment                       | 1        | 10.99      | 0        | [https://www.amazon.com/Neiko-50458A-Assortment-Count-Sizes/dp/B000K7GREQ/](https://www.amazon.com/Neiko-50458A-Assortment-Count-Sizes/dp/B000K7GREQ/)                         |
| Grub Screws, 791 PCS Set Screws                         | 1        | 15.89      | 0        | [https://www.amazon.com/Assortment-Stainless-Internal-Cup-Point-Bathroom/dp/B0D1QPKM72](https://www.amazon.com/Assortment-Stainless-Internal-Cup-Point-Bathroom/dp/B0D1QPKM72) |
