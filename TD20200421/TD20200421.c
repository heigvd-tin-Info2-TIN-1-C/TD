/**
  \file      TD20200421.c
  \brief     unions
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200421.h"

// type E_POSITION: x=1, y=2, z=3
// type E_GPS: numSat=9, dop=0.5
// type E_STATUS: error=false, version="1.0b"
void createMsg( eMsgType type, sMsg *m) {

  switch (type) {

    case E_POSITION:
      m->type = type;   // m->    m is a pointer on a structure
      m->data.pos.x = 1.;
      m->data.pos.y = 2.;
      m->data.pos.z = 3.;
      break;
    case E_GPS:
      m->type = type;
      m->data.gps.numSat = 9;
      m->data.gps.dop = .5;      
      break;
    case E_STATUS:
      m->type = type;
      m->data.status.error = false;
      // m->data.status.version = "1.0b"; // NO !
      strcpy(m->data.status.version, "1.0b");
      break;
    default:
      puts("Unknown msg type");
      break;
    }

    return;
}

// display the content of the message
// if msg is E_POSITION, display x,y,z
// if msg is E_GPS, display numSat and dop
// if msg is E_STATUS, display error and version
void displayMsg(sMsg m) {

  switch (m.type) {
    case E_POSITION:
      puts("POSITION");
      printf("x=%+6.3lf\ny=%+6.3lf\nz=%+6.3lf\n",
             m.data.pos.x, m.data.pos.y, m.data.pos.z);
      break;
    case E_GPS:
      puts("GPS");
      printf("numSat=%u\ndop=%+6.3lf\n",
             m.data.gps.numSat,m.data.gps.dop);
      break;
    case E_STATUS:
      puts("STATUS");
      printf("Error=%s\n", m.data.status.error ? "TRUE" : "FALSE");
      printf("Version=%s\n", m.data.status.version);
      break;
    default:
      puts("Unknown msg type");
      break;
    }
    return;
}

// display the content of the memory starting from address 
// on length bytes in hexadecimal
// display 8 bytes by line
void memoryDump(uint8_t *address, const uint32_t length) {

  uint32_t k = 0;
  for (k = 0; k < length; k++)
  {
    printf("%02X ", *address);
    address++;
    if(k>1 && (k+1)%8==0)
      puts("");
  }
  puts("");
  return;
}


int main(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;

    sMsg msg;

    printf("Size of sMsg: %lu bytes\n", sizeof(sMsg));

    // emitter:
    createMsg(E_POSITION, &msg);
  
    // receiver:
    displayMsg(msg);

    memoryDump((uint8_t*)&msg, sizeof(sMsg));

    return returnCode;
}
