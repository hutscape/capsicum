---
layout: design
title: Design
permalink: /design
sequence: 5

# Design
sub_system: true
terminologies:
  - term: Bell or Doorbell
    definition: Push button on-board the PCB or a physical button beside the door
  - term: Ding Dong
    definition: Bell audio that is played when the door bell is pressed

user_stories:
  - user: host
    actions:
      - goal: disable the ding dong sound within a configurable specified timeout (30s)
        reason: I don't find it annoying to hear the same sound again and again while I get ready to open the door
      - goal: hear ding dong sound when the doorbell is pressed
        reason: I can know that someone is waiting outside
      - goal: disable the ding dong sound during a configurable sleep hour (9pm to 9am)
        reason: I don't want to be disturbed during my sleep hours
      - goal: see a WiFi notification to Zapier
        reason: I can know that someone is waiting outside even if I am not at home
      - goal: work as a normal doorbell when the WiFi is down
        reason: I can still know that someone is waiting outside
  - user: guest
    actions:
      - goal: press the doorbell and hear the ding dong sound
        reason: I can inform the hosts that I am waiting outside
  - user: maintainer
    actions:
      - goal: charge the battery
        reason: the doorbell can be used again for a longer time
---
