/*====================================================================================
    EVS Codec 3GPP TS26.443 Nov 04, 2021. Version 12.14.0 / 13.10.0 / 14.6.0 / 15.4.0 / 16.3.0
  ====================================================================================*/

#include "options.h"
#include "prot.h"

/*----------------------------------------------------------------------------------*
 * procedure updt_tar:
 *
 * Update the target vector for codebook search.
 *----------------------------------------------------------------------------------*/
void updt_tar(
    const float *x,    /* i  : old target (for pitch search)     */
    float *x2,   /* o  : new target (for codebook search)  */
    const float *y,    /* i  : filtered adaptive codebook vector */
    const float gain,  /* i  : adaptive codebook gain            */
    const short L      /* i  : subframe size                     */
)
{
    short i;


    for (i = 0; i < L; i++)
    {
        x2[i] = x[i] - gain*y[i];
    }
}
