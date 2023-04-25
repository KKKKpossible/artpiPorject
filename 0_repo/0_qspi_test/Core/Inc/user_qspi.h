/*
 * user_qspi.h
 *
 *  Created on: 2023. 4. 17.
 *      Author: ksj10
 */

#ifndef INC_USER_QSPI_H_
#define INC_USER_QSPI_H_


#include "main.h"
#include "quadspi.h"


void qspiInit(void);
void qspiWrite(uint32_t address, uint8_t *p_data, int length);


#endif /* INC_USER_QSPI_H_ */
