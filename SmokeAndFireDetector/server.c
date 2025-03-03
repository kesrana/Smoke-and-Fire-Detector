#include <stdio.h>
#include <curl/curl.h>

#define BASE_URL "https://ensc351-finalproject.onrender.com"

void postSensorValue(const char *sensor, int newValue) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char postUrl[256];
        snprintf(postUrl, sizeof(postUrl), "%s/alert/%s", BASE_URL, sensor);

        char postData[256];
        snprintf(postData, sizeof(postData), "newValue=%d", newValue);

        curl_easy_setopt(curl, CURLOPT_URL, postUrl);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

void getSensorValue(const char *sensor) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char getUrl[256];
        snprintf(getUrl, sizeof(getUrl), "%s/alert/%s", BASE_URL, sensor);

        curl_easy_setopt(curl, CURLOPT_URL, getUrl);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    // Example: Update TMP36 sensor value to 42
    postSensorValue("TMP36", 42);

    // Example: Retrieve MQ2 sensor value
    getSensorValue("MQ2");

    return 0;
}