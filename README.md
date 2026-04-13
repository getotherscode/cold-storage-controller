# cold-storage-controller
Refrigeration control system firmware based on STM32 and FreeRTOS, featuring EEV control, VFD compressor management, condenser fan control and RS485 communication.

# build
cd build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ..

# flash download
openocd -f interface/cmsis-dap.cfg -f target/stm32g0x.cfg \
        -c "program D:/GitProject/cold-storage-controller/build/cold-storage-controller.hex verify reset exit"
