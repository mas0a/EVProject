# Precision Electric Vehicle

## Project Overview

The **Precision Electric Vehicle** is a small, self contained robotic vehicle designed to travel a precise, user defined distance as accurately and quickly as possible. The project is inspired by the *Science Olympiad Electric Vehicle* event, where consistency, repeatability, and mechanical reliability matter more than raw speed.

This project combines mechanical design, electronics, and embedded software into a single system. The goal is not only to build a competitive vehicle, but also to gain hands on experience in CAD design, mechanical assembly, wiring, and C++ programming.

---

## Why I Built This Project

I first became interested in this type of system after watching videos of Science Olympiad Electric Vehicle builds and competitions. What stood out to me was how small mechanical details and software decisions could significantly impact accuracy over long distances.

I chose this project because it forces me to develop skills in multiple areas at once:

* CAD modeling of a lightweight but rigid chassis
* Mechanical power transmission using belts, pulleys, and hubs
* Precision sensing with rotary encoders
* Motor control and feedback based distance tracking
* Writing and debugging C++ code on an Arduino platform

This project is meant to be educational first, while still being functional and competition ready.

---

## System Design

### Mechanical Design

The chassis is built primarily from carbon fiber tubes and rods to maximize stiffness while keeping mass low. The frame uses **7 mm carbon fiber tubes** as the main structural members, with **4 mm carbon fiber rods** acting as bracing and cross supports.

Four **BaneBots T6 wheels** are mounted using **T61 hubs**. The hubs clamp onto 4 mm shafts, which are supported by the frame. Power from the motor is transmitted using a **GT2 timing belt system** rather than direct drive. This reduces slippage and allows for precise control over wheel rotation.

A belt driven system was chosen instead of gears because:

* GT2 belts have minimal backlash
* Belt tension can be adjusted easily
* The system is quieter and more forgiving during testing

### Drive System

The vehicle is driven by a **JGB37 520 DC gear motor**. This motor was selected because it provides a good balance of torque and speed, making it suitable for controlled acceleration and deceleration.

A rotary encoder is mechanically coupled to the drive system. The encoder outputs **600 pulses per revolution**, allowing the software to calculate distance traveled with high resolution.

### Electronics and Wiring

The wiring is intentionally simple to reduce points of failure. The core components are:

* Arduino microcontroller
* DC motor driver
* Rotary encoder
* Power source

The encoder provides quadrature signals to the Arduino, which counts pulses and determines direction of rotation. The motor driver receives PWM signals from the Arduino to control speed and direction.

A wiring diagram is included in the repository to show all electrical connections clearly.

---

## Software and Control Logic

The software is written in **C++ using the Arduino framework**. The control strategy is based on distance feedback rather than time alone.

Key features of the code include:

* Encoder based distance calculation
* Configurable target distance
* Controlled acceleration at startup
* Gradual deceleration as the vehicle approaches the target distance
* Automatic motor cutoff once the target distance is reached

Distance is calculated by converting encoder pulses into wheel rotations and then into linear distance using the known wheel circumference. This approach allows for consistent results even if battery voltage changes.

---

## Current Build Status

### Completed

* Initial CAD design of the chassis
* Selection of all mechanical and electrical components
* Basic frame assembly using carbon fiber tubes and rods
* Wheel and hub mounting
* Encoder mounting and alignment
* Initial motor control and encoder reading code

### In Progress

* Final chassis reinforcement
* Fine tuning belt tension and alignment
* Improving software acceleration and deceleration curves
* Repeatability testing over multiple runs

### Not Yet Built

* Final enclosure for electronics
* Long term durability testing
* Competition level tuning and calibration

---

## Bill of Materials and Cost Clarification

The table below lists all required parts. The **Total Price** column represents the full cost for that line item as listed by the vendor. Quantity is included for clarity but does not multiply the listed price. Shipping is added once per item when applicable.

The **BOM total including shipping is 197.21 USD**, which matches the spreadsheet calculation.

Some parts have already been purchased using personal funds. The remaining items are what the grant is intended to cover.

---

## Grant Request Explanation

The grant is requested to cover:

* Carbon fiber structural materials
* Wheels and hubs
* Encoder and motor components
* Hardware assortments required for final assembly

These items represent the largest cost barriers to completing and refining the project. Funding these components will allow the project to be fully assembled, tested, and iterated upon without compromising design quality.

The grant total has been updated to match the corrected BOM total to avoid any discrepancies.

---

## Documentation and Screenshots

Additional cart screenshots will be added to show:

* Individual vendor carts
* Price breakdowns
* Shipping costs

This provides full transparency and makes it easier to verify costs.

---

## Conclusion

This project is an ongoing learning experience focused on precision engineering, control systems, and iterative design. With the remaining parts funded, the vehicle can be fully completed, tested, and refined into a reliable precision platform suitable for competition and further experimentation.


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
