/**
 * \file TD20200421.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to TD20200421
 */

#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// preprocessor symbols
#define VERSION_LENGTH (5)

// preprocessor macros

// enumerated types
typedef enum
{
    E_NO_ERROR = 0,
    E_FILE_OPEN,
    E_FILE_CLOSE,
    E_FILE_WRITE,
    E_FILE_READ,
    E_MALLOC
} eErrorCode;

typedef enum
{
    E_POSITION=1,
    E_GPS,
    E_STATUS

} eMsgType;

// structured types

typedef struct {
    double x;
    double y;
    double z;
} sPosition;

typedef struct {
    uint32_t numSat;
    double dop;
} sGps;

typedef struct {
    bool error;
    char version[VERSION_LENGTH];
} sStatus;

// unions types
typedef union {
    sPosition pos;
    sGps gps;
    sStatus status;
} uData;

typedef struct {
    eMsgType type;
    uData data;
} sMsg;

// functions prototypes
void createMsg(eMsgType type, sMsg *m);

// externals
