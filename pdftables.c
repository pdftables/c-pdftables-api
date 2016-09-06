#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;

    struct curl_httppost *formpost = NULL;
    struct curl_httppost *lastptr = NULL;

    res = curl_global_init(CURL_GLOBAL_ALL);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_global_init() failed: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "f",
                 CURLFORM_FILE, "example.pdf",
                 CURLFORM_END);

    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "filename",
                 CURLFORM_COPYCONTENTS, "example.pdf",
                 CURLFORM_END);

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        exit(1);
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://pdftables.com/api?key=YOUR_API_KEY&format=xml");
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    curl_easy_cleanup(curl);

    curl_formfree(formpost);
    return 0;
}
