#include <iostream>
#include <string>
#include <curl/curl.h>
#include <fstream>

class RESTClient {
    public:
        RESTClient(const std::string& base_url) : m_base_url(base_url) {}
        std::string get(const std::string& endpoint);
    private:
        std::string m_base_url;
        static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
            size_t total_size = size * nmemb;
            userp->append((char*)contents, total_size);
            return total_size;
        }
};

std::string RESTClient::get(const std::string& endpoint) {
    CURL* l_curl = curl_easy_init();
    std::string full_url = m_base_url + endpoint;
    std::string response_data;
    if (l_curl) {
        CURLcode result;
        curl_easy_setopt(l_curl, CURLOPT_URL, full_url.c_str());
        curl_easy_setopt(l_curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(l_curl, CURLOPT_WRITEDATA, &response_data);
        result = curl_easy_perform(l_curl);
        if (result != CURLE_OK) {
            std::cerr << "CURL error: " << curl_easy_strerror(result) << std::endl;
        }
        curl_easy_cleanup(l_curl);
    }
    return response_data;
}

int main()
{
    std::string API_KEY="";
    FILE* file = fopen("../key.txt", "r");
    if (file) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file)) {
            API_KEY.append(buffer);
        }
        fclose(file);
    } else {
        std::cerr << "Failed to open file." << std::endl;
    }
    std::string CITY_NAME;
    std::cout << "Enter City Name: ";
    std::cin >> CITY_NAME;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    RESTClient client("https://api.openweathermap.org/data/2.5/weather?q=" + CITY_NAME + "&appid=" + API_KEY + "&units=imperial");
    std::string response = client.get("/data");
    // [TODO] Parse the response JSON and extract required information
    std::cout << "Response: " << response << std::endl;
    curl_global_cleanup();
    return 0;
}