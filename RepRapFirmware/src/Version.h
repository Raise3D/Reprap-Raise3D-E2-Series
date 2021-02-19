/*
 * Version.h
 *
 *  Created on: 25 Dec 2016
 *      Author: David
 */
/*
 *
 *
 *
 * Version 2.01beta3-4 -----------------Tony-----2019-1-17// Probe modify and merge Leo's version
 */
#ifndef SRC_VERSION_H_
#define SRC_VERSION_H_


#ifndef VERSION
#ifdef RTOS
# define RTOSVER		"(RTOS)"
# define MAIN_VERSION	"2.02"
#else
# define MAIN_VERSION	"1.23"
# define RTOSVER
#endif

# define VERSION MAIN_VERSION RTOSVER
# define RAISEVERSION "0.3.0219beta"
#endif

#ifndef DATE
# define DATE "2018-12-24b1"
#endif

#define AUTHORS "reprappro, dc42, chrishamm, t3p3, dnewman, printm3d"

#endif /* SRC_VERSION_H_ */
