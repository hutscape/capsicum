#include "TimeManager.h"

int currentHour;

TimeManager::TimeManager(long timeZoneOffset, int startTime, int endTime)
    : timeClient(ntpUDP, "pool.ntp.org"), timeZoneOffset(timeZoneOffset), startTime(startTime), endTime(endTime) {}

void TimeManager::init() {
  timeClient.begin();
  timeClient.setTimeOffset(timeZoneOffset);
}

bool TimeManager::isCurrentTimeInRange() {
  timeClient.update();
  String formattedTime = timeClient.getFormattedTime();
  currentHour = extractHour(formattedTime);

  #ifdef DEBUG_TIME_MANAGER
    Serial.print("Get Formatted Time: ");
    Serial.println(timeClient.getFormattedTime());
  #endif

  return currentHour >= startTime && currentHour < endTime;
}

int TimeManager::extractHour(const String &formattedTime) {
  int hour = formattedTime.substring(0, 2).toInt(); // Extracts the hour part
  if (hour == 0 || hour == 12) {
    return 12; // 0 or 12 in 12-hour format represents midnight or noon
  } else {
    return hour % 12; // Convert to 12-hour format if necessary
  }
}
