//library directives
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

//stk directives
#include "../../MCAL/STK/MSTK_Interface.h"

//gpio directives
#include "../../MCAL/GPIO/MGPIO_Interface.h"

//led matrix directives
#include "HLEDMATRIX_Cfg.h"
#include "HLEDMATRIX_Interface.h"
#include "HLEDMATRIX_Private.h"

void HLEDMATRIX_voidPrintShape(u8* A_u8ArrayOfRows)
{
    //deactivate all columns
    for(u8 i = 0; i < NUMBER_OF_COLS; i++)
    {
        MGPIO_voidSetPinValue(global_u8ArrayOfColPorts[i], global_u8ArrayOfColPins[i], MGPIO_SET);
    }

    while(1)
	{
        
		for(u8 j = 0; j < NUMBER_OF_COLS; j++)
		{
			//activate column j
			MGPIO_voidSetPinValue(global_u8ArrayOfColPorts[j], global_u8ArrayOfColPins[j], MGPIO_RESET);

			//activate certain rows based on matrix array
			for(u8 i = 0; i < NUMBER_OF_ROWS; i++)
			{
				MGPIO_voidSetPinValue(global_u8ArrayOfRowPorts[i], global_u8ArrayOfRowPins[i], GET_BIT(A_u8ArrayOfRows[i], j));
			}

            //deactivate column j
            MGPIO_voidSetPinValue(global_u8ArrayOfColPorts[j], global_u8ArrayOfColPins[j], MGPIO_SET);

            //delay between frames
			MSTK_voidSetBusyWait(DELAY_PER_FRAME);
		}
	}
}