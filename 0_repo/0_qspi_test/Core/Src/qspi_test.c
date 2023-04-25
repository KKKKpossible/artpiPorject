/*
 * qspi_test.c
 *
 *  Created on: 2023. 4. 18.
 *      Author: ksj10
 */


#include "qspi_test.h"


static uint8_t status_reg[3] = {0, };
static uint8_t auto_callback = 0;


static void qspiWriteEnable(void);
static void qspiVolatileSRWriteEnable(void);
static void qspiWriteDisable(void);
// static void releasePowerDown(void);
// static void manufactorDevicid(void);
// static void jedecId(void);
// static void readUniqueId(void);
// static void readData(void);
// static void fastRead(void);
// static void pageProgram(void);
static void sectorErase(uint32_t address);
static void blockErase(uint32_t address);
static void blockErase64(uint32_t address);
static void chipErase(void);
static void readStatusReg(void);
static void readStatusReg1(void);
//static void writeStatusReg1(void);
static void readStatusReg2(void);
//static void writeStatusReg2(void);
static void readStatusReg3(void);
//static void writeStatusReg3(void);
//static void readSfdpReg(void);
//static void eraseSecurReg(void);
//static void programSecurReg(void);
//static void readSecurReg(void);
//static void globalBlockLock(void);
//static void globalBlockUnlock(void);
//static void readBlockLock(void);
//static void individualBlockLock(void);
//static void individualBlockUnlock(void);
//static void eraseProgramSuspend(void);
//static void eraseProgramResum(void);
//static void powerDown(void);
static void enableReset(void);
static void resetDevice(void);
//static void fastReadDualOutput(void);
//static void fastReadDualIo(void);
//static void mftrDeviceIdDualIo(void);
static void quadInputPageProgram(uint32_t address, uint8_t *p_data, int length);
//static void fastReadQuadOutput(void);
//static void mftrDeviceIdQuadIo(void);
static void fastReadQuadIo(uint32_t address, uint8_t *p_data, int length);
//static void setBurstWrap(void);

static void memMapStart(void);
static void autopollingMemReady(void);
static void autopollingMemReadyIt(void);
static void cmdWrite(uint8_t tx_cmd);


void qspiTestStart(void)
{
    qspiWriteEnable();
    memMapStart();
}

static void qspiWriteEnable(void)
{
    cmdWrite(HW_FLASH_WE);
}

static void qspiVolatileSRWriteEnable(void)
{
    cmdWrite(HW_FLASH_VSRWE);
}

static void qspiWriteDisable(void)
{
    cmdWrite(HW_FLASH_WD);
}

//static void releasePowerDown(void)
//{
//}

//static void manufactorDevicid(void)
//{
//}

//static void jedecId(void)
//{
//}

//static void readUniqueId(void)
//{
//}

//static void readData(void)
//{
//}

//static void fastRead(void)
//{
//}

//static void pageProgram(void)
//{
//}

static void sectorErase(uint32_t address)
{
    QSPI_CommandTypeDef cmd = {0, };

    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.Instruction = HW_FLASH_SE;
    cmd.AddressMode = QSPI_ADDRESS_1_LINE;
    cmd.AddressSize = QSPI_ADDRESS_24_BITS;
    cmd.Address = address;

    HAL_QSPI_Command(&hqspi, &cmd, 0xFF);
}

static void blockErase(uint32_t address)
{
}

static void blockErase64(uint32_t address)
{
}

static void chipErase(void)
{
    cmdWrite(HW_FLASH_CE);
}

static void readStatusReg(void)
{
    readStatusReg1();
    readStatusReg2();
    readStatusReg3();
}

static void readStatusReg1(void)
{
    QSPI_CommandTypeDef cmd = {0, };

    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.Instruction = HW_FLASH_RSR1;
    cmd.DataMode = QSPI_DATA_1_LINE;
    cmd.NbData = 1;

    HAL_QSPI_Command(&hqspi, &cmd, 0xFF);
    HAL_QSPI_Receive(&hqspi, &status_reg[0], 0xFF);
}

//static void writeStatusReg1(void)
//{
//}

static void readStatusReg2(void)
{
    QSPI_CommandTypeDef cmd = {0, };

    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.Instruction = HW_FLASH_RSR2;
    cmd.DataMode = QSPI_DATA_1_LINE;
    cmd.NbData = 1;

    HAL_QSPI_Command(&hqspi, &cmd, 0xFF);
    HAL_QSPI_Receive(&hqspi, &status_reg[1], 0xFF);
}

//static void writeStatusReg2(void)
//{
//}

static void readStatusReg3(void)
{
    QSPI_CommandTypeDef cmd = {0, };

    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.Instruction = HW_FLASH_RSR3;
    cmd.DataMode = QSPI_DATA_1_LINE;
    cmd.NbData = 1;

    HAL_QSPI_Command(&hqspi, &cmd, 0xFF);
    HAL_QSPI_Receive(&hqspi, &status_reg[2], 0xFF);
}

//static void writeStatusReg3(void)
//{
//}

//static void readSfdpReg(void)
//{
//}

//static void eraseSecurReg(void)
//{
//}

//static void programSecurReg(void)
//{
//}

//static void readSecurReg(void)
//{
//}

//static void globalBlockLock(void)
//{
//}

//static void globalBlockUnlock(void)
//{
//}

//static void readBlockLock(void)
//{
//}

//static void individualBlockLock(void)
//{
//}


//static void individualBlockUnlock(void)
//{
//}

//static void eraseProgramSuspend(void)
//{
//}

//static void eraseProgramResum(void)
//{
//}

//static void powerDown(void)
//{
//}

static void enableReset(void)
{
    cmdWrite(HW_FLASH_ER);
}

static void resetDevice(void)
{
    cmdWrite(HW_FLASH_RSD);
}

//static void fastReadDualOutput(void)
//{
//}

//static void fastReadDualIo(void)
//{
//}

//static void mftrDeviceIdDualIo(void)
//{
//}

static void quadInputPageProgram(uint32_t address, uint8_t *p_data, int length)
{
    QSPI_CommandTypeDef cmd = {0, };

    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.Instruction = HW_FLASH_QIPP;

    cmd.AddressMode = QSPI_ADDRESS_1_LINE;
    cmd.AddressSize = QSPI_ADDRESS_24_BITS;
    cmd.Address = address;

    cmd.DataMode = QSPI_DATA_4_LINES;
    cmd.NbData = length;

    HAL_QSPI_Command(&hqspi, &cmd, 0xFF);

    HAL_QSPI_Transmit(&hqspi, p_data, 0xFF);
}

//static void fastReadQuadOutput(void)
//{
//}

//static void mftrDeviceIdQuadIo(void)
//{
//}

static void fastReadQuadIo(uint32_t address, uint8_t *p_data, int length)
{
    QSPI_CommandTypeDef cmd = {0, };

    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.Instruction = HW_FLASH_FRQ;

    cmd.AddressMode = QSPI_ADDRESS_4_LINES;
    cmd.AddressSize = QSPI_ADDRESS_24_BITS;
    cmd.Address = address;

    cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_4_LINES;
    cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
    cmd.AlternateBytes = 0x00;

    cmd.DataMode = QSPI_DATA_4_LINES;
    cmd.NbData = length;

    cmd.DummyCycles = 4;

    cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
    cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;

    cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    HAL_QSPI_Command(&hqspi, &cmd, 0xFF);
    HAL_QSPI_Receive(&hqspi, p_data, 0xFF);
}

static void memMapStart(void)
{
    QSPI_CommandTypeDef cmd = {0, };
    QSPI_MemoryMappedTypeDef cfg = {0, };

    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.Instruction = HW_FLASH_FRQ;

    cmd.AddressMode = QSPI_ADDRESS_4_LINES;
    cmd.AddressSize = QSPI_ADDRESS_24_BITS;
    cmd.Address = 0;

    cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_4_LINES;
    cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
    cmd.AlternateBytes = 0b00100000;  // 1 << 5

    cmd.DataMode = QSPI_DATA_4_LINES;
    cmd.NbData = 0;

    cmd.DummyCycles = 4;

    cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
    cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;

    cmd.SIOOMode = QSPI_SIOO_INST_ONLY_FIRST_CMD;

    cfg.TimeOutActivation = QSPI_TIMEOUT_COUNTER_DISABLE;

    if(HAL_QSPI_MemoryMapped(&hqspi, &cmd, &cfg) != HAL_OK)
    {
        Error_Handler();
    }

    autopollingMemReadyIt();
}

static void autopollingMemReady(void)
{
    QSPI_CommandTypeDef cmd = {0, };
    QSPI_AutoPollingTypeDef cfg = {0, };

    cmd.Instruction = HW_FLASH_RSR1;
    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.DataMode = QSPI_DATA_1_LINE;

    cfg.Match = 0x00;
    cfg.Mask = 0x01;
    cfg.MatchMode = QSPI_MATCH_MODE_AND;
    cfg.StatusBytesSize = 1;
    cfg.Interval = 0x10;
    cfg.AutomaticStop = QSPI_AUTOMATIC_STOP_ENABLE;

    HAL_QSPI_AutoPolling(&hqspi, &cmd, &cfg, 0xFF);
}

static void autopollingMemReadyIt(void)
{
    QSPI_CommandTypeDef cmd = {0, };
    QSPI_AutoPollingTypeDef cfg = {0, };

    cmd.Instruction = HW_FLASH_RSR1;
    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.DataMode = QSPI_DATA_1_LINE;

    cfg.Match = 0x00;
    cfg.Mask = 0x01;
    cfg.MatchMode = QSPI_MATCH_MODE_AND;
    cfg.StatusBytesSize = 1;
    cfg.Interval = 0x10;
    cfg.AutomaticStop = QSPI_AUTOMATIC_STOP_ENABLE;

    HAL_QSPI_AutoPolling_IT(&hqspi, &cmd, &cfg);
}

static void cmdWrite(uint8_t tx_cmd)
{
    QSPI_CommandTypeDef cmd = {0, };

    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.Instruction = tx_cmd;

    HAL_QSPI_Command(&hqspi, &cmd, 0xFF);

    autopollingMemReady();
}

void HAL_QSPI_StatusMatchCallback(QSPI_HandleTypeDef *hqspi)
{
    auto_callback = 1;
}
