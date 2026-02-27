#ifndef EEPROM_24LC256_H
#define	EEPROM_24LC256_H

#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/system/system.h" 
#include "mcc_generated_files/i2c_host/mssp2.h" 

#define EEPROM_ADDR  0x50 

void EEPROM_WriteByte(uint16_t address, uint8_t data);
uint8_t EEPROM_ReadByte(uint16_t address);

#endif