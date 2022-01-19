#include <WiFiMulti.h>
#include <SD.h>

WiFiMulti wifiMulti;

void addAPfromSD(const char* fileName="/aps.csv")
{
    String fileLine, ssid, passwd;
    uint8_t cr, comma;
    File accessPoints;

    log_d("AccesPoints Reading...");
    accessPoints = SD.open(fileName, FILE_READ);
    while (accessPoints.available())
    {
        fileLine = accessPoints.readStringUntil('\n');
        cr = fileLine.indexOf('\r');
        if (cr >= 0) { fileLine = fileLine.substring(0, cr); }
        comma = fileLine.indexOf(',');
        if (comma < 0) { break; }
        ssid = fileLine.substring(0, comma);
        passwd = fileLine.substring(comma + 1);
        log_i("SSID: %s", ssid.c_str());
        wifiMulti.addAP(ssid.c_str(), passwd.c_str());
    }
    accessPoints.close();
    return;
}

bool connectToAP()
{
    while (wifiMulti.run() != WL_CONNECTED) {
        log_d("retrying...");
        delay(1000);
    }
    log_i("WiFi connected");
    return true;
}

bool connectToAP(const uint8_t numberOfTrials)
{
    uint8_t count = 0;
    while (wifiMulti.run() != WL_CONNECTED)
    {
        if(++count > numberOfTrials) {
            log_i("The number of trials is exceeded. Connection failure.");
            return false;
        }
        log_d(retrying...);
        delay(1000);
    }
    log_i("WiFi connected");
    return true;
}
