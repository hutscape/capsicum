#include "TimeManager.h"

int currentHour;

TimeManager::TimeManager(long timeZoneOffset, int startTime, int endTime)
    : timeClient(ntpUDP, "pool.ntp.org"), timeZoneOffset(timeZoneOffset), startTime(startTime), endTime(endTime) {}

void TimeManager::init() {
  timeClient.begin();
  timeClient.setTimeOffset(timeZoneOffset);
  currentHour = (timeClient.getHours() + (timeZoneOffset / 3600)) % 24;
}

bool TimeManager::isCurrentTimeInRange() {
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());
  return (currentHour >= startTime && currentHour < endTime);
}
