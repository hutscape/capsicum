---
layout: power
title: Power
permalink: /power
sequence: 6

# Power
power:
  tree: true
  components: true
  calculation: true
  source: <code>1200mAh</code> Rechargeable 16320 battery
  battery_life: 1.12 year
  charging_duration: ??? hours
  charging_instruction: Plug in a USB-C cable to charge the battery.
---

# Power consumption

Using nRF Power Profiler PPk2, the power consumption of the PCB can be measured. Follow a [simpler ESP32-C3 dev board tutorial](https://hutscape.com/tutorials/nrf-power-profiler-esp32c3) to learn how to use PPK2.

[![Measure power consumption with nRF PPK2]({{ site.url }}/images/power/measure-power-ppk2.jpg)]()

## Power consumption with no optimisation

The average power consumption of the PCB no optimisation:

- with 2 power LEDs
- no firmware optimisation
- radio is on

The average power consumption is:

- `3.87mA` in deep sleep mode
- `25.69mA` for `30s` during the timeout after the bell is pressed and the Ding Dong sound is played
- `31.94mA` for `34s` during the entire cycle of the bell press and going to sleep
- `70.62mA` for `6s` during the Ding Dong sound

<a href="{{ site.github.raw_content_url }}/power/demo-power-consumption-no-optimisation.ppk2" class="button is-info">Download nRF PPK2 file</a>

[![Demo power consumption graph with no optimisation]({{ site.url }}/images/power/demo-power-consumption-no-optimisation.jpg)]({{ site.url }}/images/power/demo-power-consumption-no-optimisation.jpg)

## Power consumption with optimisation

Firmware and hardware optimisation can be done to reduce the power consumption:

- remove the power LEDs, TX and RX LEDs
- optimise the firmware to turn off the WiFi and radio as soon as the function is done: `WiFi.disconnect(true);` and `WiFi.mode(WIFI_OFF);`
- optimise the firmware to not blink the user LED

The average power consumption of the PCB with optimisation:

- `73.04uA` in deep sleep mode
- `17.11mA` for `30s` during the timeout after the bell is pressed and the Ding Dong sound is played
- `24.93mA` for `34s` during the entire cycle of the bell press and going to sleep
- `63.99mA` for `6s` during the Ding Dong sound

<a href="{{ site.github.raw_content_url }}/power/demo-power-consumption-no-led.ppk2" class="button is-info">Download nRF PPK2 file with no LED</a>

<a href="{{ site.github.raw_content_url }}/power/demo-power-consumption-no-radio.ppk2" class="button is-info">Download nRF PPK2 file with no LED and radio/WiFi</a>
[![Demo power consumption graph with optimisation]({{ site.url }}/images/power/demo-power-consumption-optimised.jpg)]({{ site.url }}/images/power/demo-power-consumption-optimised.jpg)

## Battery life calculation

Based on the above values, the battery life can be calculated with this python code:

**Estimated battery life: 410.14 days or 1.12 years**

{% highlight python %}
{% include_relative power/calc_battery_life.py %}
{% endhighlight %}

## Battery measurement simulation

The battery measurement circuit is simulated in [Falstad](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWEDYCYDMqDsrUE4AOLSAgsJLA5ZSZAUwFowwAoMHEXAFk69vYBsvWrSxQQ6aOnEjoSAOIBDAC50QANQD2AG2WKA5nRYB3CQlSdUPdOfBYhrAGadSwsxau100sHKhoWACV3OyEbCzAuHhEQPljoCxiYBBYAY0seTxcqLNkIGHg8IuKiggQse1QhAshWACds8DwLbwdm8TB4eBMJdDaW2zB2yB7UVyGPV1yWfRDwuYEqERYG+dQEMNt0SGjwLpHVrZ252359nvntzI2JY5HNThABXb4i6hq4PHsN9fEPCRYQA).

```
$ 1 0.000005 5.023272298708815 78 5 50 5e-11
172 224 240 176 240 0 7 0 3.3 0 0 0.5 Gate Voltage
w 352 224 352 176 1
f 288 240 352 240 33 1.5 0.02
R 352 176 352 144 0 0 40 4.2 0 0 0.5
c 224 240 288 240 0 0.1 0.000999999998577626 0.001
r 288 192 336 192 0 1000000
w 336 192 352 192 0
w 288 192 288 240 0
g 352 352 352 368 0 0
r 352 256 352 304 0 100000
r 352 304 352 352 0 100000
w 352 304 256 304 0
o 2 64 0 4099 0.001220703125 0.00009765625 0 2 2 3
```

With a p-channel MOSFET, when the gate voltage is `0V` or `LOW`, the battery voltage is measured. When the gate voltage is `3.3V` or `HIGH`, the battery voltage cannot be measured.
