#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

#include "../../MCAL/GPIO/MGPIO_Interface.h"

#include "HSSD_Interface.h"
#include "HSSD_Private.h"
#include "HSSD_Cfg.h"

void HSSD_voidPrintNumber(u8 A_u8Number)
{
    if (A_u8Number >= 0 && A_u8Number <= 9)
        MGPIO_voidSetPortValue(MGPIO_PORTA, global_u8SSDArray[A_u8Number]);
}