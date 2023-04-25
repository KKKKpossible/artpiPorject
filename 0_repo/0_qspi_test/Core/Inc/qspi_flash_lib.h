/*
 * qspi_flash_lib.h
 *
 *  Created on: Apr 18, 2023
 *      Author: ksj10
 */

#ifndef INC_QSPI_FLASH_LIB_H_
#define INC_QSPI_FLASH_LIB_H_


#define HW_FLASH_WE    0x06 //  0. Write Enable
#define HW_FLASH_VSRWE 0x50 //  1. Volatile SR Write Enable
#define HW_FLASH_WD    0x04 //  2. Write Disable

#define HW_FLASH_RP    0xAB //  3. Release Power-down / ID
#define HW_FLASH_MD    0x90 //  4. Manufacturer/Device ID
#define HW_FLASH_JEDEC 0x9F //  5. JEDEC ID
#define HW_FLASH_RUID  0x4B //  6. Read Unique ID

#define HW_FLASH_RD    0x03 //  7. Read Data
#define HW_FLASH_FD    0x0B //  8. Fast Read

#define HW_FLASH_PP    0x02 //  9. Page Program

#define HW_FLASH_SE    0x20 // 10. Sector Erase (4KB)
#define HW_FLASH_BE    0x52 // 11. Block Erase (32KB)
#define HW_FLASH_BE64  0xD8 // 12. Block Erase (64KB)
#define HW_FLASH_CE    0x60 // 13. Chip Erase // 0xC7 or 0x60

#define HW_FLASH_RSR1  0x05 // 14. Read Status Register-1
#define HW_FLASH_WSR1  0x01 // 15. Write Status Register-1
#define HW_FLASH_RSR2  0x35 // 16. Read Status Register-2
#define HW_FLASH_WSR2  0x31 // 17. Write Status Register-2
#define HW_FLASH_RSR3  0x15 // 18. Read Status Register-3
#define HW_FLASH_WSR3  0x11 // 19. Write Status Register-3

#define HW_FLASH_RSFDF 0x5A // 20. Read SFDP Register
#define HW_FLASH_ESR   0x44 // 21. Erase Security Register
#define HW_FLASH_PSR   0x42 // 22. Program Security Register
#define HW_FLASH_RSR   0x48 // 23. Read Security Register

#define HW_FLASH_GBL   0x7E // 24. Global Block Lock
#define HW_FLASH_GBU   0x98 // 25. Global Block Unlock
#define HW_FLASH_RBL   0x3D // 26. Read Block Lock
#define HW_FLASH_IBL   0x36 // 27. Individual Block Lock
#define HW_FLASH_IBU   0x39 // 28. Individual Block Unlock

#define HW_FLASH_EPS   0x75 // 29. Erase / Program Suspend
#define HW_FLASH_EPR   0x75 // 30. Erase / Program Resume
#define HW_FLASH_P     0xB9 // 31. Power-down

#define HW_FLASH_ER    0x66 // 32. Enable Reset
#define HW_FLASH_RSD   0x99 // 33. Reset Device

#define HW_FLASH_FRDO  0x3B // 34. Fast Read Dual Output

#define HW_FLASH_FRDIO 0xBB // 35. Fast Read Dual I/O
#define HW_FLASH_MDDIO 0x92 // 36. Mftr./Device ID Dual I/O

#define HW_FLASH_QIPP  0x32 // 37. Quad Input Page Program
#define HW_FLASH_FRQO  0x6B // 38. Fast Read Quad Output

#define HW_FLASH_MDQIO 0x94 // 39. Mftr./Device ID Quad I/O

#define HW_FLASH_FRQ   0xEB // 40. Fast Read Quad I/O

#define HW_FLASH_SBW   0x77 // 41. Set Burst with Wrap


#endif /* INC_QSPI_FLASH_LIB_H_ */
