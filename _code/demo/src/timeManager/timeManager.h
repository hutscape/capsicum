#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <NTPClient.h>
#include <WiFiUdp.h>

// Uncomment the line below to enable debug prints
#define DEBUG_TIME_MANAGER

class TimeManager {
private:
  WiFiUDP ntpUDP;
  NTPClient timeClient;

  long timeZoneOffset;
  int startTime;
  int endTime;

public:
  TimeManager(long timeZoneOffset, int startTime, int endTime);
  void init();
  bool isCurrentTimeInRange();
  int extractHour(const String &formattedTime);
};

#endif
