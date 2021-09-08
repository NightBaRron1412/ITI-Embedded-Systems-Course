/** @file Utils.h
 * 
 * @brief A header file including some utilities funtions. 
 *
 * @author Amir Shetaia
 * @version 1.0
 * @date Sep 8, 2021       
 *
 */

#ifndef UTILS_H
#define UTILS_H

//Map function
f64 map(f64 x, f64 in_min, f64 in_max, f64 out_min, f64 out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

#endif /* UTILS_H */

/*** end of file ***/