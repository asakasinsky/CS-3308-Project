//Bluetooh SendRec class
//based heavily off code found here:
//http://www.raywenderlich.com/73306/arduino-tutorial-integrating-bluetooth-le-and-ios

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#define BLE_UUID [CBUUID UUIDWithString: @"27EC8B94-9C1A-FE12-3669-780CD087A7A4"]

#define RX_UUID [CBUUUID UUIDWithString: @"00000000-0000-0000-0000-000000000000"]

#define TX_UUID [CBUUID UUIDWIthString: @"00000000-0000-0000-0000-000000000000"]

#define RWT_BLE_SERVICE_CHANGED_STATUS_NOTIFICATION @"stuff goes here"

//wrapper around CBPeripheral and acts as its delegate object
//responsible for doing the data transmission to the connected peripheral
@interface BTSendRec : NSObject <CBPeripheralDelegate>
- (instancetype) initWithPeripheral:(CBPeripheral*) peripheral;
- (void) startDiscoveringServices;
- (void) reset;
- (void) peripheral: (CBPeripheral*) peripheral didDiscoverServices: (NSError*) error;
- (void) peripheral: (CBPeripheral*) peripheral didDiscoverCharacteristicsForService: (CBService*) service error: (NSError*) error;
- (void) sendBTServiceNotificationWithIsBluetoothConnected: (BOOL) isBluetoothConnected;
@end
