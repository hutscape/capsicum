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
