# Wattmeter
## Overview
This is part of the whole telemetry which helps to calculate how many energy is used, in how many period, and how fast. This design use a shubt and a gain amplifier which amplify the voltage drop so the esp32 can sense it.

Target of this devices:
1. Can sense volt
2. Can sense current
3. able to data log
4. Can predict SOC/ implemented to BMS

---
## calculation

Problem outline:
- ESP32 can only recieved up to 3.3v
- The voltage that want to be measured is around 24V
- The current that is wanted to be measured is up to 30A

Market/material limitation:
- there is only a 200A/75mv 
- we have a lot of 1k, 2k2, 10k, 47k, 270k resistor


### Voltage divider for volt sense:
$$V_2 =   {\frac{R_2}{R_1+R_2}}\cdot{V_{CC}}$$
$${V_{CC}}\cdot{R_2}  =  (R_1 - R_2)\cdot{V_2} $$
$$\frac{{V_{CC}}\cdot{R_2} + {R_2}\cdot {V_2}}{V_2} = R_1 $$

since $V_2$ is 1 volt (not 3.3V for safety reason) and $V_{CC} = 24$ and $R_2 = 2k2$ at first
$$R_1 = \frac{{24}\cdot{2.2} + {2.2}\cdot {1}}{1}$$
$R_1 =  50K$
Let round it up to 47K since its the closest 

### Current Sense: (WIP)

