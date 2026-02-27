#include "lib_24lc256.h"

void EEPROM_WriteByte(uint16_t address, uint8_t data)
{
    uint8_t packet[3];
    
    packet[0] = (address >> 8) & 0xFF; // High Byte (Pega os bits de cima)
    packet[1] = (address & 0xFF);      // Low Byte (Pega os bits de baixo)
    packet[2] = data;                  // O dado
    
    I2C2_Write(EEPROM_ADDR, packet, 3);
    
    while(I2C2_IsBusy());
}

uint8_t EEPROM_ReadByte(uint16_t address) 
{ 
    uint8_t address_packet[2]; 
    uint8_t data_received = 0xFF;

    address_packet[0] = (address >> 8) & 0xFF; 
    address_packet[1] = (address & 0xFF); 
    
    I2C2_WriteRead(EEPROM_ADDR, address_packet, 2, &data_received, 1); 
    
    while(I2C2_IsBusy()); 
    
    return data_received; 
}