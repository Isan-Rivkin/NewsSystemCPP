################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Dispatcher.cpp \
../src/MThread.cpp \
../src/NewsDistribution.cpp \
../src/Producer.cpp \
../src/tests.cpp 

OBJS += \
./src/Dispatcher.o \
./src/MThread.o \
./src/NewsDistribution.o \
./src/Producer.o \
./src/tests.o 

CPP_DEPS += \
./src/Dispatcher.d \
./src/MThread.d \
./src/NewsDistribution.d \
./src/Producer.d \
./src/tests.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -pthread -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


