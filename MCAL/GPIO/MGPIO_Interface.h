#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H

#define MGPIO_PORTA 0
#define MGPIO_PORTB 1
#define MGPIO_PORTC 2

#define MGPIO_INPUT 0
#define MGPIO_OUTPUT 1
#define MGPIO_ALTERNATE_FUNCTION 2
#define MGPIO_ANALOG 3

#define MGPIO_OUTPUT_PUSH_PULL 0
#define MGPIO_OUTPUT_OPEN_DRAIN 1

#define MGPIO_OUTPUT_SPEED_LOW 0
#define MGPIO_OUTPUT_SPEED_MEDIUM 1
#define MGPIO_OUTPUT_SPEED_HIGH 2
#define MGPIO_OUTPUT_SPEED_VHIGH 3

#define MGPIO_NO_PULLUP_PULL_DOWN 0
#define MGPIO_PULLUP 1
#define MGPIO_PULLDOWN 2

#define MGPIO_SET 1
#define MGPIO_RESET 0

/**
 * @brief choose the mode for a specific pin
 * 
 * @param A_u8Port macro for port name <GPIO_PORTA, GPIO_PORTB, GPIO_PORTC>
 * @param A_u8Pin pin numbers from 0 to 15
 * @param A_u8Mode macro for pin mode <MGPIO_INPUT, MGPIO_OUTPUT, MGPIO_ALTERNATE_FUNCTION, MGPIO_ANALOG>
 * 
 * @return void
 */
void MGPIO_voidSetPinMode(u8 A_u8Port, u8 A_u8Pin, u8 A_u8Mode);
/**
 * @brief choose output type for a specific pin
 * 
 * @param A_u8Port macro for port name <GPIO_PORTA, GPIO_PORTB, GPIO_PORTC>
 * @param A_u8Pin pin numbers from 0 to 15
 * @param A_u8OutputType macro for output types <MGPIO_OUTPUT_PUSH_PULL, MGPIO_OUTPUT_OPEN_DRAIN>
 * 
 * @return void
 */
void MGPIO_voidSetPinOutputType(u8 A_u8Port, u8 A_u8Pin, u8 A_u8OutputType);
/**
 * @brief choose output speed for a specific pin
 * 
 * @param A_u8Port macro for port name <GPIO_PORTA, GPIO_PORTB, GPIO_PORTC>
 * @param A_u8Pin pin numbers from 0 to 15
 * @param A_u8OutputSpeed macro for output speeds <MGPIO_OUTPUT_SPEED_LOW, MGPIO_OUTPUT_SPEED_MEDIUM, MGPIO_OUTPUT_SPEED_HIGH, MGPIO_OUTPUT_SPEED_VHIGH>
 * 
 * @return void
 */
void MGPIO_voidSetPinOutputSpeed(u8 A_u8Port, u8 A_u8Pin, u8 A_u8OutputSpeed);
/**
 * @brief choose pull up or pull down configuration
 * 
 * @param A_u8Port macro for port name <GPIO_PORTA, GPIO_PORTB, GPIO_PORTC>
 * @param A_u8Pin pin numbers from 0 to 15
 * @param A_u8PullupPullDown macro for pullup and pulldown configuration <MGPIO_NO_PULLUP_PULL_DOWN, MGPIO_PULLUP, MGPIO_PULLDOWN>
 * 
 * @return void
 */
void MGPIO_voidSetPinPullupPullDown(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PullupPullDown);
/**
 * @brief get input signal from specific pin
 * 
 * @param A_u8Port macro for port name <GPIO_PORTA, GPIO_PORTB, GPIO_PORTC>
 * @param A_u8Pin pin numbers from 0 to 15
 * 
 * @return u8 value of input signal at specific pin
 */
u8 MGPIO_u8GetPinValue(u8 A_u8Port, u8 A_u8Pin);
/**
 * @brief Get input value at the port
 * 
 * @param A_u8Port macro for port name <GPIO_PORTA, GPIO_PORTB, GPIO_PORTC>
 * 
 * @return u16 value of input signals at the port
 */
u16 MGPIO_u8GetPortValue(u8 A_u8Port);
/**
 * @brief Set output pin value
 * 
 * @param A_u8Port macro for port name <GPIO_PORTA, GPIO_PORTB, GPIO_PORTC>
 * @param A_u8Pin pin numbers from 0 to 15
 * @param A_PinValue macro for pin value <MGPIO_SET, MGPIO_RESET>
 * 
 * @return void
 */
void MGPIO_voidSetPinValue(u8 A_u8Port, u8 A_u8Pin, u8 A_PinValue);
/**
 * @brief Set output port value
 * 
 * @param A_u8Port macro for port name <GPIO_PORTA, GPIO_PORTB, GPIO_PORTC>
 * @param A_PortValue value to be set on a port, value in range 0:65535
 * 
 * @return void
 */
void MGPIO_voidSetPortValue(u8 A_u8Port, u16 A_PortValue);
/**
 * @brief Lock configuration of specific pin
 * 
 * @param A_u8Port macro for port name <GPIO_PORTA, GPIO_PORTB, GPIO_PORTC>
 * @param A_u8Pin pin numbers from 0 to 15
 * 
 * @return void
 */
void MGPIO_voidLockPin(u8 A_u8Port, u8 A_u8Pin);

#endif