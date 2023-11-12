#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <NTPClient.h>
#include <WiFiUdp.h>

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
};

#endif
