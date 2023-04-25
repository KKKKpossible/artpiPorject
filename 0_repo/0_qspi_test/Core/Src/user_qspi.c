/*
 * user_qspi.c
 *
 *  Created on: 2023. 4. 17.
 *      Author: ksj10
 */


#include "qspi_flash_lib.h"
#include "user_qspi.h"
#include "quadspi.h"


static uint8_t status_reg[3] = {0, };


static void qspiMemMapModeStart(void);
static void qspiErase(uint32_t start_addr, uint32_t end_addr);
static void qspiEraseSector(int start_sector, int end);
static void qspiEraseBlock32(int sector);
static void readStatusReg(void);



void qspiInit(void)
{
    readStatusReg1();
    readStatusReg2();
    readStatusReg3();

    QSPI_CommandTypeDef cmd = {0, };

    HAL_QSPI_Command(&hqspi, &cmd, 0xFF);
}

void qspiWrite(uint32_t address, uint8_t *p_data, int length)
{
}

static void qspiMemMapModeStart(void)
{

}

