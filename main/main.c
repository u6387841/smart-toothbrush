#include <driver/adc.h>
// CREDITS
// Analog to Digital Converter code was based off the the following website :
// https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/peripherals/adc.html

// Developing the webserver code was based off the follwoing esp-idf repository (HTTPS SERVER Protocol) : 
// https://github.com/espressif/esp-idf/tree/master/examples/protocols/https_server

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <esp_wifi.h>
#include <esp_event_loop.h>
#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include "tcpip_adapter.h"
#include <time.h>
#include <math.h>

#include <esp_https_server.h>

#define EXAMPLE_WIFI_SSID "Namitha's iPhone"
#define EXAMPLE_WIFI_PASS "rohan123"

int number_of_times = 0;

static const char *TAG="APP";
// G34 IS x channel 6
// G35 IS y channel 7
// G32 IS z channel 4

float x_accel(){
    adc_power_on();
    adc_gpio_init(ADC_UNIT_1, ADC1_CHANNEL_6);

    float xval = 1;
    adc1_config_width(ADC_WIDTH_BIT_12); // configure desired precision, parameter is width_bit 
    adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_DB_11); // x coord configure desired attenuation

    xval = adc1_get_raw(ADC1_CHANNEL_6);

    printf("xval : %f \n", xval);
    return xval;
}

float y_accel(){
    adc_power_on();
    adc_gpio_init(ADC_UNIT_1, ADC1_CHANNEL_7);

    float yval = 1;

    adc1_config_width(ADC_WIDTH_BIT_12); // configure desired precision, parameter is width_bit 
    adc1_config_channel_atten(ADC1_CHANNEL_7,ADC_ATTEN_DB_11); // y coord

    yval = adc1_get_raw(ADC1_CHANNEL_7); 

    printf("yval : %f \n", yval);
    return yval;
}

float z_accel(){
    adc_power_on();
    adc_gpio_init(ADC_UNIT_1, ADC1_CHANNEL_4);

    float zval = 1;

    adc1_config_width(ADC_WIDTH_BIT_12); // configure desired precision, parameter is width_bit 
    adc1_config_channel_atten(ADC1_CHANNEL_4,ADC_ATTEN_DB_11); // y coord

    zval = adc1_get_raw(ADC1_CHANNEL_4); 

    printf("zval : %f \n", zval);
    return zval;
}

float average(int a, int b, int c) {
    float average_accel = sqrt((a * a) + (b * b) + (c * c));
    printf("The final acceleration is : %f \n", average_accel);
    return average_accel;
}

/* An HTTP GET handler */
esp_err_t root_get_handler(httpd_req_t *req)
{

httpd_resp_set_type(req, "text/html");

if (number_of_times == 0){
httpd_resp_send(req, "<head>"
                        "<style type=""text/css"">"
                        "body {color: purple;"
                            "font-family: ""Comic Sans MS"", cursive, sans-serif;}"
                            "</style>"                        
                        "</head>"
                        "<body>"
                        "<h1>Brushing Habits!</h1>"
                            "<style type=""text/css"">"
                            "h1 {margin: 50px 200px 100px;}"
                            "</style>"                        
                        "<h2>Patient Name:____</h2>"
                        "<style type=""text/css"">"
                            "h2 {margin: 50px 200px 100px;}"
                            "</style>"
                        "<h4>Patient Photograph</h4>"
                        "<style type=""text/css"">"
                            "h4 {margin_right: 500px}"
                        "</style>"
                        "<img src=""http://clipart-library.com/images/Bcgrngy7i.png"" alt=""HTML5 Icon"" width=""128"" height=""128"">"
                        "<h3>Patient Details</h3>"
                        "<p1>   Date of Birth:____"
                                "<br />"
                                "Address:____"
                                "<br />" 
                                "Mobile Number:____"
                                "<br />"
                                "Occupation:____"
                                "<br />"
                                "Email Address:____"
                                "<br />"
                                "Medication:____"
                                "<br />"
                                "Allergies:____"
                        "</p1>"
                        "<h5>Patient's Brushing Habits</h5>"
                        "<p2>"
                        "The patient has not brushed today! It's time for you to brush!"
                        "</p2>"
                        "</body>", -1); 
}

if (number_of_times == 1){
 httpd_resp_send(req, "<head>"
                            "<style type=""text/css"">"
                            "body {color: purple;"
                                   "font-family: ""Comic Sans MS"", cursive, sans-serif;}"
                            "</style>"                        
                        "</head>"
                        "<body>"
                        "<h1>Brushing Habits!</h1>"
                            "<style type=""text/css"">"
                            "h1 {margin: 50px 200px 100px;}"
                            "</style>"                        
                        "<h2>Patient Name:____</h2>"
                        "<style type=""text/css"">"
                            "h2 {margin: 50px 200px 100px;}"
                            "</style>"
                        "<h4>Patient Photograph</h4>"
                        "<style type=""text/css"">"
                            "h4 {margin_right: 500px}"
                        "</style>"
                        "<img src=""http://clipart-library.com/images/Bcgrngy7i.png"" alt=""HTML5 Icon"" width=""128"" height=""128"">"
                        "<h3>Patient Details</h3>"
                        "<p1>   Date of Birth:____"
                                "<br />"
                                "Address:____"
                                "<br />" 
                                "Mobile Number:____"
                                "<br />"
                                "Occupation:____"
                                "<br />"
                                "Email Address:____"
                                "<br />"
                                "Medication:____"
                                "<br />"
                                "Allergies:____"
                        "</p1>"
                        "<h5>Patient's Brushing Habits</h5>"
                        "<p2>"
                        "The patient has only brushed once today! Remember to brush before you go to bed!"
                        "</p2>"
                        "</body>", -1); 
}

if (number_of_times == 2) {
 httpd_resp_send(req, "<head>"
                            "<style type=""text/css"">"
                        "body {color: purple;"
                            "font-family: ""Comic Sans MS"", cursive, sans-serif;}"
                            "</style>"                        
                        "</head>"
                        "<body>"
                        "<h1>Brushing Habits!</h1>"
                            "<style type=""text/css"">"
                            "h1 {margin: 40px 200px 100px;}"
                            "</style>"                        
                        "<h2>Patient Name:____</h2>"
                        "<style type=""text/css"">"
                            "h2 {margin: 50px 100px 100px;}"
                            "</style>"
                        "<h4>Patient Photograph</h4>"
                        "<style type=""text/css"">"
                            "h4 {margin_right: 500px}"
                        "</style>"
                        "<img src=""http://clipart-library.com/images/Bcgrngy7i.png"" alt=""HTML5 Icon"" width=""128"" height=""128"">"
                        "<h3>Patient Details</h3>"
                        "<p1>   Date of Birth:____"
                                "<br />"
                                "Address:____"
                                "<br />" 
                                "Mobile Number:____"
                                "<br />"
                                "Occupation:____"
                                "<br />"
                                "Email Address:____"
                                "<br />"
                                "Medication:____"
                                "<br />"
                                "Allergies:____"
                        "</p1>"
                        "<h5>Patient's Brushing Habits</h5>"
                        "<p2>"
                        "The patient has brushed twice today! Good job!"
                        "</p2>"
                        "</body>", -1);
} else {
httpd_resp_send(req, "<head>"
                            "<style type=""text/css"">"
                        "body {color: purple;"
                            "font-family: ""Comic Sans MS"", cursive, sans-serif;}"
                            "</style>"                        
                        "</head>"
                        "<body>"
                        "<h1>Brushing Habits!</h1>"
                            "<style type=""text/css"">"
                            "h1 {margin: 50px 200px 100px;}"
                            "</style>"                        
                        "<h2>Patient Name:____</h2>"
                        "<style type=""text/css"">"
                            "h2 {margin: 50px 200px 100px;}"
                            "</style>"
                        "<h4>Patient Photograph</h4>"
                        "<style type=""text/css"">"
                            "h4 {margin_right: 500px}"
                        "</style>"
                        "<img src=""http://clipart-library.com/images/Bcgrngy7i.png"" alt=""HTML5 Icon"" width=""128"" height=""128"">"
                        "<h3>Patient Details</h3>"
                        "<p1>   Date of Birth:____"
                                "<br />"
                                "Address:____"
                                "<br />" 
                                "Mobile Number:____"
                                "<br />"
                                "Occupation:____"
                                "<br />"
                                "Email Address:____"
                                "<br />"
                                "Medication:____"
                                "<br />"
                                "Allergies:____"
                        "</p1>"
                        "<h5>Patient's Brushing Habits</h5>"
                        "<p2>"
                        "Wow!The patient has brushed more than twice today! Keep it up!"
                        "</p2>"
                        "</body>", -1);
}            
    return ESP_OK;
}

const httpd_uri_t root = {
    .uri       = "/",
    .method    = HTTP_GET,
    .handler   = root_get_handler
};
httpd_handle_t start_webserver(void)
{
    httpd_handle_t server = NULL;

    // Start the httpd server
    ESP_LOGI(TAG, "Starting server");

    httpd_ssl_config_t conf = HTTPD_SSL_CONFIG_DEFAULT();

    extern const unsigned char cacert_pem_start[] asm("_binary_cacert_pem_start");
    extern const unsigned char cacert_pem_end[]   asm("_binary_cacert_pem_end");
    conf.cacert_pem = cacert_pem_start;
    conf.cacert_len = cacert_pem_end - cacert_pem_start;

    extern const unsigned char prvtkey_pem_start[] asm("_binary_prvtkey_pem_start");
    extern const unsigned char prvtkey_pem_end[]   asm("_binary_prvtkey_pem_end");
    conf.prvtkey_pem = prvtkey_pem_start;
    conf.prvtkey_len = prvtkey_pem_end - prvtkey_pem_start;

    esp_err_t ret = httpd_ssl_start(&server, &conf);
    if (ESP_OK != ret) {
        ESP_LOGI(TAG, "Error starting server!");
        return NULL;
    }

    // Set URI handlers
    ESP_LOGI(TAG, "Registering URI handlers");
    httpd_register_uri_handler(server, &root);
    return server;
}

void stop_webserver(httpd_handle_t server)
{
    // Stop the httpd server
    httpd_ssl_stop(server);
}


static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    httpd_handle_t *server = (httpd_handle_t *) ctx;

    switch(event->event_id) {
    case SYSTEM_EVENT_STA_START:
        ESP_LOGI(TAG, "SYSTEM_EVENT_STA_START");
        ESP_ERROR_CHECK(esp_wifi_connect());
        break;
    case SYSTEM_EVENT_STA_GOT_IP:
        ESP_LOGI(TAG, "SYSTEM_EVENT_STA_GOT_IP");
        ESP_LOGI(TAG, "Got IP: '%s'",
                ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));

        /* Start the web server */
        if (*server == NULL) {
            *server = start_webserver();
        }
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        ESP_LOGI(TAG, "SYSTEM_EVENT_STA_DISCONNECTED");
        ESP_ERROR_CHECK(esp_wifi_connect());

        /* Stop the web server */
        if (*server) {
            stop_webserver(*server);
            *server = NULL;
        }
        break;
    default:
        break;
    }
    return ESP_OK;
}

static void initialise_wifi(void *arg)
{
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, arg));
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = EXAMPLE_WIFI_SSID,
            .password = EXAMPLE_WIFI_PASS,
        },
    };
    ESP_LOGI(TAG, "Setting WiFi configuration SSID %s...", wifi_config.sta.ssid);
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
}

void is_brushing() {
    while (average(x_accel(), y_accel(), z_accel()) != 0){
    float ac = average(x_accel(), y_accel(), z_accel());
    printf("The average acceleration is : %f \n", ac);
    if (ac >= 3700){
    number_of_times++;
    break;
  }
  }
}

void app_main()
{
    is_brushing();
    static httpd_handle_t server = NULL;
    ESP_ERROR_CHECK(nvs_flash_init());
    initialise_wifi(&server);
}
