import serial
import time



arduino_port = "COM5"  
baud_rate = 9600  


# Establish serial connection
ser = serial.Serial(arduino_port, baud_rate)
time.sleep(2)  # Wait for the connection to initialize


print("Connection established. Reading button state...")
try:
    while True:
        if ser.in_waiting > 0:  # Check if data is available
            data = ser.readline().decode('utf-8').strip()  # Read and decode data
            if data == "1":
                print("Button Pressed")
            elif data == "0":
                print("Button Not Pressed")

except KeyboardInterrupt:
    print("\nExiting...")
finally:
    ser.close()  # Close the serial connection
