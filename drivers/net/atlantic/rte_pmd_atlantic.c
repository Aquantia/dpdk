/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2018 Aquantia Corporation
 */

#include <rte_ethdev_driver.h>

#include "rte_pmd_atlantic.h"
#include "atl_ethdev.h"

int rte_pmd_atl_dev_led_control(int port, int control)
{
	struct rte_eth_dev *dev;

	RTE_ETH_VALID_PORTID_OR_ERR_RET(port, -ENODEV);

	dev = &rte_eth_devices[port];

	return atl_dev_led_control(dev, control);
}

