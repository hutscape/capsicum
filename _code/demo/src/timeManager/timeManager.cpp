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
    Serial.print("Within time range? ");
    if (currentHour >= startTime && currentHour < endTime) {
      Serial.println("Yes");
    } else {
      Serial.println("No");
    }
  #endif

  return currentHour >= startTime && currentHour < endTime;
}

int TimeManager::extractHour(const String &formattedTime) {
  int hour = formattedTime.substring(0, 2).toInt(); // Extracts the hour part
  if (hour == 0 || hour == 12) {
    return hour; // Return 0 or 12 for midnight or noon in 24-hour format
  } else {
    return hour; // Return the hour in 24-hour format
  }
}
