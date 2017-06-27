#ifndef _SELECT_H_
#define _SELECT_H_
#include <config.h>
#include <command.h>
#include <asm/io.h>
#include <common.h>

#include <ac83xx_gpio_pinmux.h>
#include <pinmux.h>
#include <ac83xx_pinmux_table.h>
#include <asm-arm/arch-ac83xx/ac83xx_i2c.h>
#include <ac83xx_gpio_pinmux_mapping.h>

#include <stdio_dev.h>


void select_setup(int i);
#endif
