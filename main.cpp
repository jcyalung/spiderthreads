#include <iostream>
#include <string>
#include <curl/curl.h>
#include "include"
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

int main(int argc, char* argv[]) {
    CURL* curl;
    CURLcode res;
    std::string readBuf;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.org");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuf);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed:" << curl_easy_strerror(res) << std::endl;
        }
        else {
            std::cout << "Page downloaded, length: " << readBuf.length() << std::endl;
            //std::cout << readBuf << std::endl;
        }

        curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "curl failed" << std::endl;
    }
    int i;
    for(i = 0; i < argc; i++) {
        std::cout << argv[i] << std::flush << std::endl;
    }
    auto ptr = std::unique_ptr<int>(new int(5));
}
