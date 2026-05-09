# MSP430-LDR_ECE492 
### ECE 492 (Embedded Systems Hardware Design) Project

## 📝 Overview
This project involved the design and manufacturing of a microcontroller-based system focused on analog signal acquisition and real-time user interaction. The system utilizes a photoresistor (LDR) for environmental sensing and a tactile user interface, all managed by a custom-designed PCB and optimized C firmware.

The core of the system is the **MSP430FR2355**, utilizing its 10-bit ADC12 module and hardware timers to create a responsive, low-power monitoring tool.

## 🛠 Hardware Specifications
- **MCU:** MSP430
- **Sensors:** Photoresistor (Analog A1) & Thumbwheel Potentiometer (Analog A2)
- **User Input:** 3x Tactile Pushbuttons (Hardware Interrupts)
- **Visual Output:** 4x LED Status Indicators (Blue, Yellow, Green, Red)

## 📂 Project Structure
- `main.c`: Central application logic and LED threshold management.
- `ADC.c`: 10-bit ADC12 configuration and sampling logic.
- `interrupts.c`: ISRs for Port 2 (Mode switching), Timer B (10Hz trigger), and ADC.
- `ports.c`: GPIO and Peripheral multiplexing setup.
- `timers.c`: Timer_B0 configuration using ACLK (~32.768 kHz).
- `globals.c`: Volatile variable definitions for shared system state.

## ⚙️ Technical Highlights
### 1. Automated ADC Chaining
To minimize CPU overhead, the firmware uses a "chaining" logic within the ADC Interrupt Service Routine. Once the photoresistor is sampled, the ISR automatically reconfigures the multiplexer to sample the thumbwheel, ensuring all sensor data is current without blocking the main loop.

### 2. Interrupt-Driven State Machine
The system switches between three operating modes via Port 2 interrupts:
- **Mode 1:** All-or-nothing binary threshold.
- **Mode 2:** Graduated response (LEDs light up sequentially based on intensity).
- **Mode 3:** Environmental calibration and baseline setting.

### 3. FRAM Optimization
The code specifically manages the `LOCKLPM5` power-on state and utilizes the efficient memory architecture of the MSP430FR series to maintain state across power cycles where necessary.

---
**Author:** Luca  
**Project Date:** May 2026  
**Course:** ECE 492 a
