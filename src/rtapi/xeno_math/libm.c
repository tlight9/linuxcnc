/*
rtai/libm/libm.c - module wrapper for SunSoft/FreeBSD/MacOX/uclibc libm
RTAI - Real-Time Application Interface
Copyright (C) 2001   David A. Schleef <ds@schleef.org>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "config.h"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
//#include "rtapi_math.h"

// FIXME make this use rtapi_math.h and rtapi_math_i386.h
#include "xeno_math.h"



MODULE_LICENSE("GPL");

int libm_errno;

int __xeno_math_init(void)
{
    printk(KERN_INFO "Xenomai math [xeno_math]: loaded %s\n", GIT_VERSION);
    return 0;
}

void __xeno_math_exit(void)
{
    printk(KERN_INFO "Xenomai math [xeno_math]: unloaded.\n");
}


// I have no idea why this is needed on precise

#if 0
double __ieee754_pow(double x, double y);
double pow(double x, double y)
{
    return  __ieee754_pow(x,y);
}
#endif


module_init(__xeno_math_init);
module_exit(__xeno_math_exit);


#if defined(RTAPI_XENOMAI_KERNEL)
EXPORT_SYMBOL(fabs);
EXPORT_SYMBOL(frexp);
EXPORT_SYMBOL(floor);
EXPORT_SYMBOL(pow);
#endif

#ifdef CONFIG_KBUILD
EXPORT_SYMBOL(acos);
EXPORT_SYMBOL(asin);
EXPORT_SYMBOL(atan);
EXPORT_SYMBOL(atan2);
EXPORT_SYMBOL(ceil);
EXPORT_SYMBOL(copysign);
EXPORT_SYMBOL(cos);
EXPORT_SYMBOL(cosh);
EXPORT_SYMBOL(exp);
EXPORT_SYMBOL(expm1);
EXPORT_SYMBOL(fabs);
EXPORT_SYMBOL(floor);
EXPORT_SYMBOL(fmod);
EXPORT_SYMBOL(frexp);
EXPORT_SYMBOL(log);
EXPORT_SYMBOL(log10);
EXPORT_SYMBOL(modf);
EXPORT_SYMBOL(pow);
EXPORT_SYMBOL(scalbn);
EXPORT_SYMBOL(sin);
EXPORT_SYMBOL(sinh);
EXPORT_SYMBOL(sqrt);
EXPORT_SYMBOL(tan);
EXPORT_SYMBOL(tanh);

#ifdef CONFIG_RTAI_MATH_C99
EXPORT_SYMBOL(acosh);
EXPORT_SYMBOL(asinh);
EXPORT_SYMBOL(atanh);
EXPORT_SYMBOL(cabs);
EXPORT_SYMBOL(cbrt);
EXPORT_SYMBOL(drem);
EXPORT_SYMBOL(erf);
EXPORT_SYMBOL(erfc);
EXPORT_SYMBOL(gamma);
EXPORT_SYMBOL(gamma_r);
EXPORT_SYMBOL(hypot);
EXPORT_SYMBOL(ilogb);
EXPORT_SYMBOL(j0);
EXPORT_SYMBOL(j1);
EXPORT_SYMBOL(jn);
EXPORT_SYMBOL(ldexp);
EXPORT_SYMBOL(lgamma);
EXPORT_SYMBOL(lgamma_r);
EXPORT_SYMBOL(log1p);
EXPORT_SYMBOL(logb);
EXPORT_SYMBOL(matherr);
EXPORT_SYMBOL(nearbyint);
EXPORT_SYMBOL(nextafter);
EXPORT_SYMBOL(remainder);
EXPORT_SYMBOL(rint);
EXPORT_SYMBOL(rinttol);
EXPORT_SYMBOL(round);
EXPORT_SYMBOL(roundtol);
EXPORT_SYMBOL(scalb);
EXPORT_SYMBOL(signgam);
EXPORT_SYMBOL(significand);
EXPORT_SYMBOL(trunc);
EXPORT_SYMBOL(y0);
EXPORT_SYMBOL(y1);
EXPORT_SYMBOL(yn);
EXPORT_SYMBOL(libm_errno);
#endif /* CONFIG_RTAI_MATH_C99 */
#endif /* CONFIG_KBUILD */
