deps_config := \
	/Users/namithasarajohn/esp/esp-idf/components/app_trace/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/aws_iot/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/bt/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/driver/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/esp32/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/esp_event/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/esp_http_client/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/esp_http_server/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/ethernet/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/fatfs/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/freemodbus/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/freertos/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/heap/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/libsodium/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/log/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/lwip/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/mbedtls/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/mdns/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/mqtt/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/nvs_flash/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/openssl/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/pthread/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/spi_flash/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/spiffs/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/unity/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/vfs/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/wear_levelling/Kconfig \
	/Users/namithasarajohn/esp/esp-idf/components/app_update/Kconfig.projbuild \
	/Users/namithasarajohn/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/Users/namithasarajohn/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/Users/namithasarajohn/esp/esp-idf/examples/protocols/https_server/main/Kconfig.projbuild \
	/Users/namithasarajohn/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/Users/namithasarajohn/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_TARGET)" "esp32"
include/config/auto.conf: FORCE
endif
ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
