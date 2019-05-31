from smbus import smbus
addr = 0x68
bus = SMBus(1)

number = bus.read_byte(addr)

try:
    while True:
        print(number)
except KeyboardInterrupt:
    print("Stop)